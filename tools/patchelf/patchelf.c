#include <ctype.h>
#include "elf.h"
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

static bool try_patch_value(const char *sym, char *dest, const char *source, size_t size);

int main(int argc, char *argv[])
{
    int exit_code = 1;

    int fd = -1;
    char *f = MAP_FAILED;

    if (argc < 2 || argc % 2 != 0)
    {
        fprintf(stderr, "Usage: %s <filename> [<symbol> <value>]...\n", argv[0]);
        goto error;
    }

    if ((fd = open(argv[1], O_RDWR)) == -1)
    {
        fprintf(stderr, "open(%s, O_RDWR) failed: %s\n", argv[1], strerror(errno));
        goto error;
    }

    struct stat st;
    if (fstat(fd, &st) == -1)
    {
        perror("stat failed");
        goto error;
    }

    if ((f = mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED)
    {
        perror("mmap failed");
        goto error;
    }

    if (memcmp(f, ELFMAG, 4) != 0)
    {
        fprintf(stderr, "not an ELF file\n");
        goto error;
    }

    const Elf32_Ehdr *ehdr = (Elf32_Ehdr *)f;
    const Elf32_Shdr *shdrs = (Elf32_Shdr *)(f + ehdr->e_shoff);

    if (ehdr->e_shstrndx == SHN_UNDEF)
    {
        fprintf(stderr, "no section name string table\n");
        goto error;
    }
    const Elf32_Shdr *shdr_shstr = &shdrs[ehdr->e_shstrndx];
    const char *shstr = (const char *)(f + shdr_shstr->sh_offset);
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
    {
        fprintf(stderr, "no .symtab section\n");
        goto error;
    }
    if (!shdr_strtab)
    {
        fprintf(stderr, "no .strtab section\n");
        goto error;
    }

    const Elf32_Sym *symtab = (Elf32_Sym *)(f + shdr_symtab->sh_offset);
    const char *strtab = (const char *)(f + shdr_strtab->sh_offset);
    for (int i = 0; i < shdr_symtab->sh_size / shdr_symtab->sh_entsize; i++)
    {
        if (symtab[i].st_name == 0) continue;
        if (symtab[i].st_shndx > ehdr->e_shnum) continue;
        const char *st_name = strtab + symtab[i].st_name;
        const Elf32_Shdr *shdr = &shdrs[symtab[i].st_shndx];
        uint32_t sym_offset = symtab[i].st_value - shdr->sh_addr;
        for (int j = 2; j < argc; j += 2)
        {
            const char *arg_name = argv[j + 0];
            const char *arg_value = argv[j + 1];
            if (strcmp(st_name, arg_name) == 0)
            {
                char *value = (char *)(f + shdr->sh_offset + sym_offset);
                if (!try_patch_value(st_name, value, arg_value, symtab[i].st_size))
                    goto error;
            }
        }
    }

    exit_code = 0;

error:
    if (f != MAP_FAILED)
    {
        if (msync(f, st.st_size, MS_SYNC) == -1)
        {
            perror("msync failed");
            f = MAP_FAILED;
        }
    }
    if (f != MAP_FAILED)
    {
        if (munmap(f, st.st_size) == -1)
        {
            perror("munmap failed");
        }
    }
    if (fd != -1)
    {
        if (close(fd) == -1)
        {
            perror("close failed");
        }
    }

    return exit_code;
}

static int parsexdigit(char c)
{
    if ('0' <= c && c <= '9')
        return c - '0';
    else if ('a' <= c && c <= 'f')
        return c - 'a' + 10;
    else if ('A' <= c && c <= 'F')
        return c - 'A' + 10;
    else
        return -1;
}

static bool try_patch_value(const char *sym, char *dest, const char *source, size_t size)
{
    int i = 0;
    while (*source)
    {
        if (i == size)
        {
            fprintf(stderr, "%s: overflows size (%lu)\n", sym, size);
            return false;
        }
        char c, value;
        switch ((c = *source++))
        {
        case '\\':
            switch ((c = *source++))
            {
            case '0':
                value = 0;
                break;
            case 'x':
                if (!isxdigit((c = *source++)))
                {
                    fprintf(stderr, "%s: illegal escape \\x%c\n", sym, c);
                    return false;
                }
                value = parsexdigit(c);
                if (!isxdigit((c = *source++)))
                {
                    fprintf(stderr, "%s: illegal escape \\x%c%c\n", sym, *(source - 2), c);
                    return false;
                }
                value = value * 16 + parsexdigit(c);
                break;
            default:
                fprintf(stderr, "%s: illegal escape \\%c\n", sym, c);
                return false;
            }
            break;
        default:
            value = c;
            break;
        }
        dest[i++] = value;
    }
    return true;
}
