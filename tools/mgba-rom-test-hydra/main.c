/* mgba-rom-test-hydra. Runs multiple mgba-rom-test processes and
 * parses the output to display human-readable progress.
 *
 * Output lines starting with "GBA Debug: :" are parsed as commands to
 * Hydra, other output lines starting with "GBA Debug: " are parsed as
 * output from the current test, and any other lines are parsed as
 * output from the mgba-rom-test process itself.
 *
 * COMMANDS
 * N: Sets the test name to the remainder of the line.
 * R: Sets the result to the remainder of the line, and flushes any
 *    output buffered since the previous R. */
#include <fcntl.h>
#include <poll.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/prctl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_PROCESSES 32 // See also test/test.h

struct Runner
{
    pid_t pid;
    int outfd;
    char rom_path[L_tmpnam];
    char test_name[256];
    size_t input_buffer_size;
    size_t input_buffer_capacity;
    char *input_buffer;
    size_t output_buffer_size;
    size_t output_buffer_capacity;
    char *output_buffer;
};

static unsigned nrunners = 0;
static struct Runner *runners = NULL;

static void handle_read(struct Runner *runner)
{
    char *sol = runner->input_buffer;
    char *eol;
    size_t consumed = 0;
    size_t remaining = runner->input_buffer_size;
    while ((eol = memchr(sol, '\n', remaining)))
    {
        eol++;
        size_t n = eol - sol;
        if (runner->input_buffer_size >= strlen("GBA Debug: ")
         && !strncmp(sol, "GBA Debug: ", strlen("GBA Debug: ")))
        {
            char *soc = sol + strlen("GBA Debug: ");
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

                case 'R':
                    soc += 2;
                    fprintf(stdout, "%s: ", runner->test_name);
                    fwrite(soc, 1, eol - soc, stdout);
                    fwrite(runner->output_buffer, 1, runner->output_buffer_size, stdout);
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
            if (write(STDOUT_FILENO, sol, eol - sol) == -1)
            {
                perror("write failed");
                exit(2);
            }
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
                perror("unlink rom_path failed");
        }
    }
}

static void exit2(int _)
{
    exit(2);
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "usage %s mgba-rom-test rom\n", argv[0]);
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
    if ((elffd = open(argv[2], O_RDONLY)) == -1)
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

    nrunners = sysconf(_SC_NPROCESSORS_ONLN);
    if (nrunners > MAX_PROCESSES)
        nrunners = MAX_PROCESSES;
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
            fprintf(stdout, "%s\n", runners[i].test_name);
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
        if (!tmpnam(runners[i].rom_path))
        {
            perror("tmpnam rom_path failed");
            exit(2);
        }
        int tmpfd;
        if ((tmpfd = open(runners[i].rom_path, O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR)) == -1)
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
            if (execlp("tools/patchelf/patchelf", "tools/patchelf/patchelf", runners[i].rom_path, "gTestRunnerN", n_arg, "gTestRunnerI", i_arg, NULL) == -1)
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
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork mgba-rom-test failed");
            exit(2);
        } else if (pid == 0) {
            if (prctl(PR_SET_PDEATHSIG, SIGTERM) == -1)
            {
                perror("prctl failed");
                _exit(2);
            }
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
            // stdbuf is required because otherwise mgba never flushes
            // stdout.
            if (execlp("stdbuf", "stdbuf", "-oL", argv[1], "-l15", "-ClogLevel.gba.dma=16", "-Rr0", runners[i].rom_path, NULL) == -1)
            {
                perror("execl stdbuf mgba-rom-test failed");
                _exit(2);
            }
        } else {
            runners[i].pid = pid;
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
                    scrollback += (strlen(runners[i].test_name) + winsize.ws_col - 1) / winsize.ws_col;
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
                handle_read(&runners[i]);
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
                    fprintf(stdout, "%s\n", runners[i].test_name);
            }

            fflush(stdout);
        }
    }

    // Reap test runners and collate exit codes.
    int exit_code = 0;
    for (int i = 0; i < nrunners; i++)
    {
        int wstatus;
        if (waitpid(runners[i].pid, &wstatus, 0) == -1)
        {
            perror("waitpid runners[i] failed");
            exit(2);
        }
        if (WIFEXITED(wstatus) && WEXITSTATUS(wstatus) > exit_code)
            exit_code = WEXITSTATUS(wstatus);
    }
    return exit_code;
}
