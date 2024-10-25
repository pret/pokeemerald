/* mgba-rom-test-hydra. Runs multiple mgba-rom-test processes and
 * parses the output to display human-readable progress.
 *
 * Output lines starting with "GBA Debug: :" are parsed as commands to
 * Hydra, other output lines starting with "GBA Debug: " or with "GBA: "
 * are parsed as output from the current test, and any other lines are
 * parsed as output from the mgba-rom-test process itself.
 *
 * COMMANDS
 * N: Sets the test name to the remainder of the line.
 * L: Sets the filename to the remainder of the line.
 * R: Sets the result to the remainder of the line, and flushes any
 *    output buffered since the previous R.
 * P/K/F/A: Sets the result to the remaining of the line, flushes any
 *    output since the previous P/K/F/A and increment the number of
 *    passes/known fails/assumption fails/fails.
 */
#include <fcntl.h>
#include <math.h>
#include <poll.h>
#include <regex.h>
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#ifndef __APPLE__
#include <sys/prctl.h>
#endif
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include "elf.h"

#define min(a, b) ((a) < (b) ? (a) : (b))

#define MAX_PROCESSES               32 // See also test/test.h
#define MAX_SUMMARY_TESTS_TO_LIST   50
#define MAX_TEST_LIST_BUFFER_LENGTH 256

#define ARRAY_COUNT(arr) (sizeof((arr)) / sizeof((arr)[0]))

struct Runner
{
    pid_t pid;
    int outfd;
    char rom_path[FILENAME_MAX];
    char test_name[256];
    char filename_line[256];
    size_t input_buffer_size;
    size_t input_buffer_capacity;
    char *input_buffer;
    size_t output_buffer_size;
    size_t output_buffer_capacity;
    char *output_buffer;
    int passes;
    int knownFails;
    int knownFailsPassing;
    int todos;
    int assumptionFails;
    int fails;
    int results;
    char failed_TestNames[MAX_SUMMARY_TESTS_TO_LIST][MAX_TEST_LIST_BUFFER_LENGTH];
    char failed_TestFilenameLine[MAX_SUMMARY_TESTS_TO_LIST][MAX_TEST_LIST_BUFFER_LENGTH];
    char knownFailingPassed_TestNames[MAX_SUMMARY_TESTS_TO_LIST][MAX_TEST_LIST_BUFFER_LENGTH];
    char knownFailingPassed_FilenameLine[MAX_SUMMARY_TESTS_TO_LIST][MAX_TEST_LIST_BUFFER_LENGTH];
    char assumeFailed_TestNames[MAX_SUMMARY_TESTS_TO_LIST][MAX_TEST_LIST_BUFFER_LENGTH];
    char assumeFailed_FilenameLine[MAX_SUMMARY_TESTS_TO_LIST][MAX_TEST_LIST_BUFFER_LENGTH];
};

struct Symbol {
    const char *name;
    uint32_t address;
    size_t size;
};

struct SymbolTable {
    struct Symbol *symbols;
    size_t symbols_n;
};

static unsigned nrunners = 0;
static unsigned runners_digits = 0;
static struct Runner *runners = NULL;

// TODO: Build the symbol table on demand.
static struct SymbolTable symbol_table = { NULL, 0 };

static const struct Symbol *lookup_address(uint32_t address)
{
    int lo = 0, hi = symbol_table.symbols_n;
    while (lo < hi)
    {
        int mi = lo + (hi - lo) / 2;
        const struct Symbol *symbol = &symbol_table.symbols[mi];
        if (address < symbol->address)
            hi = mi;
        else if (address >= symbol->address + symbol->size)
            lo = mi + 1;
        else
            return symbol;
    }
    return NULL;
}

#ifndef _GNU_SOURCE
// Very naive implementation of 'memmem' for systems which don't make it
// available by default.
void *memmem(const void *haystack, size_t haystacklen, const void *needle, size_t needlelen)
{
    const char *haystack_ = haystack;
    const char *needle_ = needle;
    for (size_t i = 0; i < haystacklen - needlelen; i++)
    {
        size_t j;
        for (j = 0; j < needlelen; j++)
        {
            if (haystack_[i+j] != needle_[j])
                break;
        }
        if (j == needlelen)
            return (void *)&haystack_[i];
    }
    return NULL;
}
#endif

// Similar to 'fwrite(buffer, 1, size, f)' except that anything which
// looks like the output of '%p' (i.e. '<0x\d{7}>') is translated into
// the name of a symbol (if it represents one).
static void fprint_buffer(FILE *f, const char *buffer, size_t size)
{
    const char *buffer_end = buffer + size;
    while (buffer < buffer_end)
    {
        // Find the next '<0x'.
        char *buffer_ = memmem(buffer, buffer_end - buffer, "<0x", 3);

        // No '<0x' or could not possibly match, print everything.
        if (buffer_ == NULL || buffer_end - buffer_ < 11 || buffer_[10] != '>')
        {
            fwrite(buffer, 1, buffer_end - buffer, f);
            break;
        }

        // Print everything before the '<0x'.
        fwrite(buffer, 1, buffer_ - buffer, f);
        buffer = buffer_;

        unsigned long address = strtoul(buffer + 3, &buffer_, 16);
        // Un-mirror EWRAM/IWRAM/ROM addresses.
        switch (address & 0xF000000)
        {
        case 0x2000000: address = address & 0x203FFFF; break;
        case 0x3000000: address = address & 0x3007FFF; break;
        case 0x7000000: address = address & 0x70003FF; break;
        case 0xA000000: address = address & 0x9FFFFFF; break;
        case 0xB000000: address = address & 0x9FFFFFF; break;
        case 0xC000000: address = address & 0x9FFFFFF; break;
        case 0xD000000: address = address & 0x9FFFFFF; break;
        }

        // Not a 7-digit address, print the '<0x' part and loop.
        if (buffer_ != buffer + 10)
        {
            fwrite(buffer, 1, 3, f);
            buffer += 3;
            continue;
        }

        const struct Symbol *symbol = lookup_address(address);

        // Not a symbol, print the parsed part and loop.
        if (symbol == NULL)
        {
            fwrite(buffer, 1, 11, f);
            buffer += 11;
            continue;
        }

        if (symbol->address == address)
            fprintf(f, "<%s>", symbol->name);
        else
            fprintf(f, "<%s+0x%lx>", symbol->name, address - symbol->address);

        buffer += 11;
    }
}

static void handle_read(int i, struct Runner *runner)
{
    char *sol = runner->input_buffer;
    char *eol;
    size_t consumed = 0;
    size_t remaining = runner->input_buffer_size;
    while ((eol = memchr(sol, '\n', remaining)))
    {
        eol++;
        size_t n = eol - sol;
        char *soc;
        if (runner->input_buffer_size >= strlen("GBA: ")
         && !strncmp(sol, "GBA: ", strlen("GBA: ")))
        {
            soc = sol + strlen("GBA: ");
            goto buffer_output;
        }
        else if (runner->input_buffer_size >= strlen("GBA Debug: ")
              && !strncmp(sol, "GBA Debug: ", strlen("GBA Debug: ")))
        {
            soc = sol + strlen("GBA Debug: ");
            if (soc[0] == ':')
            {
                switch (soc[1])
                {
                case 'N':
                    soc += 2;
                    if (sizeof(runner->test_name) <= eol - soc - 1)
                    {
                        fprintf(stderr, "test_name too long\n");
                        exit(2);
                    }
                    strncpy(runner->test_name, soc, eol - soc - 1);
                    runner->test_name[eol - soc - 1] = '\0';
                    break;
                case 'L':
                    soc += 2;
                    if (sizeof(runner->filename_line) <= eol - soc - 1)
                    {
                        fprintf(stderr, "filename_line too long\n");
                        exit(2);
                    }
                    strncpy(runner->filename_line, soc, eol - soc - 1);
                    runner->filename_line[eol - soc - 1] = '\0';
                    break;

                case 'P':
                    runner->passes++;
                    goto add_to_results;
                case 'K':
                    runner->knownFails++;
                    goto add_to_results;
                case 'U':
                    if (runner->knownFailsPassing < MAX_SUMMARY_TESTS_TO_LIST)
                    {
                        strcpy(runner->knownFailingPassed_TestNames[runner->knownFailsPassing], runner->test_name);
                        strcpy(runner->knownFailingPassed_FilenameLine[runner->knownFailsPassing], runner->filename_line);
                    }
                    runner->knownFailsPassing++;
                    goto add_to_results;
                case 'T':
                    runner->todos++;
                    goto add_to_results;
                case 'A':
                    if (runner->assumptionFails < MAX_SUMMARY_TESTS_TO_LIST)
                    {
                        strcpy(runner->assumeFailed_TestNames[runner->assumptionFails], runner->test_name);
                        strcpy(runner->assumeFailed_FilenameLine[runner->assumptionFails], runner->filename_line);
                    }
                    runner->assumptionFails++;
                    goto add_to_results;
                case 'F':
                    if (runner->fails < MAX_SUMMARY_TESTS_TO_LIST)
                    {
                        strcpy(runner->failed_TestNames[runner->fails], runner->test_name);
                        strcpy(runner->failed_TestFilenameLine[runner->fails], runner->filename_line);
                    }
                    runner->fails++;
add_to_results:
                    runner->results++;
                    soc += 2;
                    fprintf(stdout, "[%0*d] %s: ", runners_digits, i, runner->test_name);
                    fwrite(soc, 1, eol - soc, stdout);
                    fprint_buffer(stdout, runner->output_buffer, runner->output_buffer_size);
                    strcpy(runner->test_name, "WAITING...");
                    runner->output_buffer_size = 0;
                    break;

                default:
                    goto buffer_output;
                }
            }
            else
            {
buffer_output:
                if (runner->output_buffer_size + eol - soc >= runner->output_buffer_capacity)
                {
                    runner->output_buffer_capacity *= 2;
                    if (runner->output_buffer_capacity < runner->output_buffer_size + eol - soc)
                        runner->output_buffer_capacity = runner->output_buffer_size + eol - soc;
                    runner->output_buffer = realloc(runner->output_buffer, runner->output_buffer_capacity);
                    if (!runner->output_buffer)
                    {
                        perror("realloc output_buffer failed");
                        exit(2);
                    }
                }
                memcpy(runner->output_buffer + runner->output_buffer_size, soc, eol - soc);
                runner->output_buffer_size += eol - soc;
            }
        }
        else
        {
            fwrite(sol, 1, eol - sol, stdout);
        }
        sol += n;
        consumed += n;
        remaining -= n;
    }

    memcpy(runner->input_buffer, sol, remaining);
    runner->input_buffer_size -= consumed;

    if (runner->input_buffer_size == runner->input_buffer_capacity)
    {
        runner->input_buffer_capacity *= 2;
        runner->input_buffer = realloc(runner->input_buffer, runner->input_buffer_capacity);
        if (!runner->input_buffer)
        {
            perror("realloc input_buffer failed");
            exit(2);
        }
    }
}

static void unlink_roms(void)
{
    for (int i = 0; i < nrunners; i++)
    {
        if (runners[i].rom_path[0])
        {
            if (unlink(runners[i].rom_path) == -1)
            {
                int fd;
                if ((fd = open(runners[i].rom_path, O_RDONLY)) != -1)
                    perror("unlink rom_path failed");
            }
        }
    }
}

static void exit2(int _)
{
    exit(2);
}

static int compare_addresses(const void *a, const void *b)
{
    const struct Symbol *sa = a, *sb = b;
    if (sa->address < sb->address)
        return -1;
    else if (sa->address == sb->address)
        return 0;
    else
        return 1;
}

static void build_symbol_table(void *elf)
{
    if (memcmp(elf, ELFMAG, 4) != 0)
        goto error;

    size_t symbol_table_symbols_c = 1024;
    symbol_table.symbols = malloc(symbol_table_symbols_c * sizeof(*symbol_table.symbols));
    if (symbol_table.symbols == NULL)
        goto error;

    const Elf32_Ehdr *ehdr = (Elf32_Ehdr *)elf;
    const Elf32_Shdr *shdrs = (Elf32_Shdr *)(elf + ehdr->e_shoff);

    if (ehdr->e_shstrndx == SHN_UNDEF)
        goto error;
    const Elf32_Shdr *shdr_shstr = &shdrs[ehdr->e_shstrndx];
    const char *shstr = (const char *)(elf + shdr_shstr->sh_offset);
    const Elf32_Shdr *shdr_symtab = NULL;
    const Elf32_Shdr *shdr_strtab = NULL;
    for (int i = 0; i < ehdr->e_shnum; i++)
    {
        const char *sh_name = shstr + shdrs[i].sh_name;
        if (strcmp(sh_name, ".symtab") == 0)
            shdr_symtab = &shdrs[i];
        else if (strcmp(sh_name, ".strtab") == 0)
            shdr_strtab = &shdrs[i];
    }
    if (!shdr_symtab)
        goto error;
    if (!shdr_strtab)
        goto error;

    const Elf32_Sym *symtab = (Elf32_Sym *)(elf + shdr_symtab->sh_offset);
    const char *strtab = (const char *)(elf + shdr_strtab->sh_offset);
    for (int i = 0; i < shdr_symtab->sh_size / shdr_symtab->sh_entsize; i++)
    {
        if (symtab[i].st_name == 0) continue;
        if (symtab[i].st_shndx > ehdr->e_shnum) continue;
        if (symtab[i].st_value < 0x2000000 || symtab[i].st_size == 0) continue;
        struct Symbol symbol =
        {
            .name = strtab + symtab[i].st_name,
            .address = symtab[i].st_value,
            .size = symtab[i].st_size,
        };
        if (symbol_table.symbols_n == symbol_table_symbols_c)
        {
            symbol_table_symbols_c *= 2;
            void *symbols = realloc(symbol_table.symbols, symbol_table_symbols_c * sizeof(*symbol_table.symbols));
            if (symbols == NULL)
                goto error;
            symbol_table.symbols = symbols;
        }
        symbol_table.symbols[symbol_table.symbols_n++] = symbol;
    }

    qsort(symbol_table.symbols, symbol_table.symbols_n, sizeof(*symbol_table.symbols), compare_addresses);
    return;

error:
    free(symbol_table.symbols);
    symbol_table.symbols = NULL;
    symbol_table.symbols_n = 0;
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        fprintf(stderr, "usage %s mgba-rom-test objcopy rom\n", argv[0]);
        exit(2);
    }

    bool tty = isatty(STDOUT_FILENO);
    if (!tty)
    {
        const char *v = getenv("MAKE_TERMOUT");
        tty = v && v[0] == '\0';
    }

    if (tty)
    {
        char *stdout_buffer = malloc(64 * 1024);
        if (!stdout_buffer)
        {
            perror("malloc stdout_buffer failed");
            exit(2);
        }
        setvbuf(stdout, stdout_buffer, _IOFBF, 64 * 1024);
    }
    else
    {
        setvbuf(stdout, NULL, _IONBF, 0);
    }

    int elffd;
    if ((elffd = open(argv[3], O_RDONLY)) == -1)
    {
        perror("open elffd failed");
        exit(2);
    }

    struct stat elfst;
    if (fstat(elffd, &elfst) == -1)
    {
        perror("stat elffd failed");
        exit(2);
    }

    void *elf;
    if ((elf = mmap(NULL, elfst.st_size, PROT_READ, MAP_PRIVATE, elffd, 0)) == MAP_FAILED)
    {
        perror("mmap elffd failed");
        exit(2);
    }

    build_symbol_table(elf);

    nrunners = 1;
    const char *makeflags = getenv("MAKEFLAGS");
    if (makeflags)
    {
        int e;
        regex_t preg;
        regmatch_t pmatch[4];
        if ((e = regcomp(&preg, "(^| )-j([0-9]*)($| )", REG_EXTENDED)) != 0)
        {
            char errbuf[256];
            regerror(e, &preg, errbuf, sizeof(errbuf));
            fprintf(stderr, "regcomp failed: '%s'\n", errbuf);
            exit(2);
        }
        if (regexec(&preg, makeflags, ARRAY_COUNT(pmatch), pmatch, 0) != REG_NOMATCH)
        {
            if (pmatch[2].rm_so == pmatch[2].rm_eo)
                nrunners = sysconf(_SC_NPROCESSORS_ONLN);
            else
                sscanf(makeflags + pmatch[2].rm_so, "%d", &nrunners);
        }
        regfree(&preg);
    }
    if (nrunners > MAX_PROCESSES)
        nrunners = MAX_PROCESSES;
    runners_digits = ceil(log10(nrunners));
    runners = calloc(nrunners, sizeof(*runners));
    if (!runners)
    {
        perror("calloc runners failed");
        exit(2);
    }
    for (int i = 0; i < nrunners; i++)
    {
        runners[i].input_buffer_capacity = 4096;
        runners[i].input_buffer = malloc(runners[i].input_buffer_capacity);
        runners[i].output_buffer_capacity = 4096;
        runners[i].output_buffer = malloc(runners[i].output_buffer_capacity);
        strcpy(runners[i].test_name, "WAITING...");
        if (tty)
            fprintf(stdout, "[%0*d] %s\n", runners_digits, i, runners[i].test_name);
    }
    fflush(stdout);
    atexit(unlink_roms);
    signal(SIGINT, exit2);
    signal(SIGTERM, exit2);

    // Start test runners.
    pid_t parent_pid = getpid();
    for (int i = 0; i < nrunners; i++)
    {
        int pipefds[2];
        if (pipe(pipefds) == -1)
        {
            perror("pipe failed");
            exit(2);
        }
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork mgba-rom-test failed");
            exit(2);
        } else if (pid == 0) {
            #ifndef __APPLE__
            if (prctl(PR_SET_PDEATHSIG, SIGTERM) == -1)
            {
                perror("prctl failed");
                _exit(2);
            }
            #endif
            if (getppid() != parent_pid) // Parent died.
            {
                _exit(2);
            }
            if (close(pipefds[0]) == -1)
            {
                perror("close pipefds[0] failed");
                _exit(2);
            }
            if (dup2(pipefds[1], STDOUT_FILENO) == -1)
            {
                perror("dup2 stdout failed");
                _exit(2);
            }
            if (close(pipefds[1]) == -1)
            {
                perror("close pipefds[1] failed");
                _exit(2);
            }
            char rom_path[FILENAME_MAX];
            sprintf(rom_path, "/tmp/mgba-rom-test-hydra-%05d", getpid());
            int tmpfd;
            if ((tmpfd = open(rom_path, O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR)) == -1)
            {
                perror("open tmpfd failed");
                _exit(2);
            }
            if ((write(tmpfd, elf, elfst.st_size)) == -1)
            {
                perror("write tmpfd failed");
                _exit(2);
            }
            pid_t patchelfpid = fork();
            if (patchelfpid == -1)
            {
                perror("fork patchelf failed");
                _exit(2);
            }
            else if (patchelfpid == 0)
            {
                char n_arg[5], i_arg[5];
                snprintf(n_arg, sizeof(n_arg), "\\x%02x", nrunners);
                snprintf(i_arg, sizeof(i_arg), "\\x%02x", i);
                if (execlp("tools/patchelf/patchelf", "tools/patchelf/patchelf", rom_path, "gTestRunnerN", n_arg, "gTestRunnerI", i_arg, NULL) == -1)
                {
                    perror("execlp patchelf failed");
                    _exit(2);
                }
            }
            else
            {
                int wstatus;
                if (waitpid(patchelfpid, &wstatus, 0) == -1)
                {
                    perror("waitpid patchelfpid failed");
                    _exit(2);
                }
                if (!WIFEXITED(wstatus) || WEXITSTATUS(wstatus) != 0)
                {
                    fprintf(stderr, "patchelf exited with an error\n");
                    _exit(2);
                }
            }
#ifdef __APPLE__
            pid_t objcopypid = fork();
            if (objcopypid == -1)
            {
                perror("fork objcopy failed");
                _exit(2);
            }
            else if (objcopypid == 0)
            {
                if (execlp(argv[2], argv[2], "-O", "binary", rom_path, rom_path, NULL) == -1)
                {
                    perror("execlp objcopy failed");
                    _exit(2);
                }
            }
            else
            {
                int wstatus;
                if (waitpid(objcopypid, &wstatus, 0) == -1)
                {
                    perror("waitpid objcopy failed");
                    _exit(2);
                }
                if (!WIFEXITED(wstatus) || WEXITSTATUS(wstatus) != 0)
                {
                    fprintf(stderr, "objcopy exited with an error\n");
                    _exit(2);
                }
            }
#endif
            // stdbuf is required because otherwise mgba never flushes
            // stdout.
            if (execlp("stdbuf", "stdbuf", "-oL", argv[1], "-l15", "-ClogLevel.gba.dma=16", "-Rr0", rom_path, NULL) == -1)
            {
                perror("execl stdbuf mgba-rom-test failed");
                _exit(2);
            }
        } else {
            runners[i].pid = pid;
            sprintf(runners[i].rom_path, "/tmp/mgba-rom-test-hydra-%05d", runners[i].pid);
            runners[i].outfd = pipefds[0];
            if (close(pipefds[1]) == -1)
            {
                perror("close pipefds[1] failed");
                exit(2);
            }
        }
    }

    // Process test runner output.
    int openfds = nrunners;
    struct pollfd *pollfds = calloc(nrunners, sizeof(*pollfds));
    if (!pollfds)
    {
        perror("calloc pollfds failed");
        exit(2);
    }
    for (int i = 0; i < nrunners; i++)
    {
        pollfds[i].fd = runners[i].outfd;
        pollfds[i].events = POLLIN;
    }
    while (openfds > 0)
    {
        if (tty)
        {
            struct winsize winsize;
            if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &winsize) == -1)
            {
                perror("ioctl TIOCGWINSZ failed");
                exit(2);
            }
            int scrollback = 0;
            for (int i = 0; i < nrunners; i++)
            {
                if (runners[i].outfd >= 0)
                    scrollback += (3 + runners_digits + strlen(runners[i].test_name) + winsize.ws_col - 1) / winsize.ws_col;
            }
            if (scrollback > 0)
                fprintf(stdout, "\e[%dF\e[J", scrollback);
        }

        if (poll(pollfds, nrunners, -1) == -1)
        {
            perror("poll failed");
            exit(2);
        }
        for (int i = 0; i < nrunners; i++)
        {
            if (pollfds[i].revents & POLLIN)
            {
                int n;
                if ((n = read(pollfds[i].fd, runners[i].input_buffer + runners[i].input_buffer_size, runners[i].input_buffer_capacity - runners[i].input_buffer_size)) == -1)
                {
                    perror("read pollfds[i] failed");
                    exit(2);
                }
                runners[i].input_buffer_size += n;
                handle_read(i, &runners[i]);
            }

            if (pollfds[i].revents & (POLLERR | POLLHUP))
            {
                if (close(pollfds[i].fd) == -1)
                {
                    perror("close pollfds[i] failed");
                    exit(2);
                }
                runners[i].outfd = pollfds[i].fd = -pollfds[i].fd;
                openfds--;
            }
        }

        if (tty)
        {
            for (int i = 0; i < nrunners; i++)
            {
                if (runners[i].outfd >= 0)
                    fprintf(stdout, "[%0*d] %s\n", runners_digits, i, runners[i].test_name);
            }

            fflush(stdout);
        }
    }

    // Reap test runners and collate exit codes.
    int exit_code = 0;
    int passes = 0;
    int knownFails = 0;
    int knownFailsPassing = 0;
    int todos = 0;
    int assumptionFails = 0;
    int fails = 0;
    int results = 0;

    char failed_TestNames[MAX_SUMMARY_TESTS_TO_LIST * MAX_PROCESSES][MAX_TEST_LIST_BUFFER_LENGTH];
    char failed_TestFilenameLine[MAX_SUMMARY_TESTS_TO_LIST * MAX_PROCESSES][MAX_TEST_LIST_BUFFER_LENGTH];

    char knownFailingPassed_TestNames[MAX_SUMMARY_TESTS_TO_LIST * MAX_PROCESSES][MAX_TEST_LIST_BUFFER_LENGTH];
    char knownFailingPassed_FilenameLine[MAX_SUMMARY_TESTS_TO_LIST * MAX_PROCESSES][MAX_TEST_LIST_BUFFER_LENGTH];

    char assumeFailed_TestNames[MAX_SUMMARY_TESTS_TO_LIST * MAX_PROCESSES][MAX_TEST_LIST_BUFFER_LENGTH];
    char assumeFailed_FilenameLine[MAX_SUMMARY_TESTS_TO_LIST * MAX_PROCESSES][MAX_TEST_LIST_BUFFER_LENGTH];

    for (int i = 0; i < nrunners; i++)
    {
        int wstatus;
        if (waitpid(runners[i].pid, &wstatus, 0) == -1)
        {
            perror("waitpid runners[i] failed");
            exit(2);
        }
        if (runners[i].output_buffer_size > 0)
            fwrite(runners[i].output_buffer, 1, runners[i].output_buffer_size, stdout);
        if (WIFEXITED(wstatus) && WEXITSTATUS(wstatus) > exit_code)
            exit_code = WEXITSTATUS(wstatus);
        passes += runners[i].passes;
        knownFails += runners[i].knownFails;
        for (int j = 0; j < runners[i].knownFailsPassing; j++)
        {
            if (j < MAX_SUMMARY_TESTS_TO_LIST)
            {
                strcpy(knownFailingPassed_TestNames[knownFailsPassing], runners[i].knownFailingPassed_TestNames[j]);
                strcpy(knownFailingPassed_FilenameLine[knownFailsPassing], runners[i].knownFailingPassed_FilenameLine[j]);
            }
            knownFailsPassing++;
        }
        todos += runners[i].todos;
        for (int j = 0; j < runners[i].assumptionFails; j++)
        {
            if (j < MAX_SUMMARY_TESTS_TO_LIST)
            {
                strcpy(assumeFailed_TestNames[assumptionFails], runners[i].assumeFailed_TestNames[j]);
                strcpy(assumeFailed_FilenameLine[assumptionFails], runners[i].assumeFailed_FilenameLine[j]);
            }
            assumptionFails++;
        }
        for (int j = 0; j < runners[i].fails; j++)
        {
            if (j < MAX_SUMMARY_TESTS_TO_LIST)
            {
                strcpy(failed_TestNames[fails], runners[i].failed_TestNames[j]);
                strcpy(failed_TestFilenameLine[fails], runners[i].failed_TestFilenameLine[j]);
            }
            fails++;
        }
        results += runners[i].results;
    }

    if (results == 0)
    {
        fprintf(stdout, "\nNo tests found.\n");
    }
    else
    {
        if (fails > 0)
        {
            fprintf(stdout, "\n  \e[31mFAILED\e[0m tests:\n");
            for (int i = 0; i < fails; i++)
            {
                if (i >= MAX_SUMMARY_TESTS_TO_LIST)
                {
                    fprintf(stdout, "  - \e[31mand %d more...\e[0m\n", fails - MAX_SUMMARY_TESTS_TO_LIST);
                    break;
                }
                fprintf(stdout, "  - \e[31m%s\e[0m - %s.\n", failed_TestFilenameLine[i], failed_TestNames[i]);
            }
        }

        if (assumptionFails > 0)
        {
            fprintf(stdout, "\n  Tests with \e[33mASSUMPTIONS_FAILED\e[0m:\n");
            for (int i = 0; i < assumptionFails; i++)
            {
                if (i >= MAX_SUMMARY_TESTS_TO_LIST)
                {
                    fprintf(stdout, "  - \e[33mand %d more...\e[0m\n", assumptionFails - MAX_SUMMARY_TESTS_TO_LIST);
                    break;
                }
                fprintf(stdout, "  - \e[33m%s\e[0m - %s.\n", assumeFailed_FilenameLine[i], assumeFailed_TestNames[i]);
            }
        }

        if (knownFailsPassing > 0)
        {
            fprintf(stdout, "\n  \e[33mKNOWN_FAILING\e[0m tests \e[32mPASSING\e[0m:\n");
            for (int i = 0; i < knownFailsPassing; i++)
            {
                if (i >= MAX_SUMMARY_TESTS_TO_LIST)
                {
                    fprintf(stdout, "  - \e[32mand %d more...\e[0m\n", knownFailsPassing - MAX_SUMMARY_TESTS_TO_LIST);
                    break;
                }
                fprintf(stdout, "  - \e[32m%s\e[0m - %s.\n", knownFailingPassed_FilenameLine[i], knownFailingPassed_TestNames[i]);
            }
        }

        fprintf(stdout, "\n");
        if (fails > 0)
            fprintf(stdout, "- Tests \e[31mFAILED\e[0m :         %d    Add TESTS='X' to run tests with the defined prefix.\n", fails);
        if (knownFails > 0)
            fprintf(stdout, "- Tests \e[33mKNOWN_FAILING\e[0m:   %d\n", knownFails);
        if (assumptionFails > 0)
            fprintf(stdout, "- \e[33mASSUMPTIONS_FAILED\e[0m:    %d\n", assumptionFails);
        if (todos > 0)
            fprintf(stdout, "- Tests \e[33mTO_DO\e[0m:           %d\n", todos);
        if (knownFailsPassing > 0)
            fprintf(stdout, "- \e[32mKNOWN_FAILING_PASSING\e[0m: %d   \e[33mPlease remove KNOWN_FAILING if these tests intentionally PASS\e[0m\n", knownFailsPassing);
        fprintf(stdout, "- Tests \e[32mPASSED\e[0m:          %d\n", passes);
        fprintf(stdout, "- Tests \e[34mTOTAL\e[0m:           %d\n", results);
    }
    fprintf(stdout, "\n");

    fflush(stdout);
    return exit_code;
}
