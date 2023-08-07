#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

/**
 * _is_elf - Check if the file is an ELF.
 * @header: ELF header
 * Return: void
 */
void _is_elf(char *header)
{
	if (header[0] != 0x7f || header[1] != 'E' || header[2] != 'L' || header[3] != 'F')
		dprintf(STDERR_FILENO, "Error: File is not ELF type"), exit(98);
}

/**
 * print_magic - Print ELF magic numbers.
 * @header: ELF header
 * Return: void
 */
void print_magic(char *header)
{
	int i;

	printf("ELF Header:\n  Magic:   ");

	for (i = 0; i < 15; i++)
		printf("%02x ", (unsigned int)header[i]);
	printf("%02x", (unsigned int)header[i]);

	printf("\n");
}

/**
 * print_class - Print ELF class.
 * @header: ELF header
 * @is64: 1 for 64 bits; 0 for 32 bits; others: unknown
 * Return: No Return
 */
void print_class(char *header, int is64)
{
	if (header[4] != 1 && header[4] != 2)
	{
		printf("<unknown: %02hx is not a class>\n", header[4]);
		return;
	}
	printf("Class:                             ");
	if (is64 == 0)
		printf("ELF32\n");
	else if (is64 == 1)
		printf("ELF64\n");
}

/**
 * print_data - Print ELF data encoding.
 * @header: ELF header
 * Return: void
 */
void print_data(char *header)
{
	printf("Data:                              2's complement, ");
	if (header[5] == 1)
		printf("little endian\n");
	else if (header[5] == 2)
		printf("big endian\n");
	else
		printf("<unknown: %02hx is not an ELF data>\n", header[4]);
}

/**
 * print_version - Print ELF version.
 * @header: ELF header
 * Return: void
 */
void print_version(char *header)
{
	printf("  %-35s", "Version:");
	if (header[6] == EV_CURRENT)
	{
		printf("%d (current)\n", header[6]);
	}
	else if (header[6] != EV_CURRENT)
	{
		printf("%d\n", header[6]);
	}
}

/**
 * print_os_abi - Print ELF OS/ABI.
 * @header: ELF header
 * Return: void
 */
void print_os_abi(char *header)
{
	printf("  %-35s", "OS/ABI:");

	switch (header[7])
	{
	case 0: printf("UNIX - System V\n"); break;
	case 1: printf("UNIX - HP-UX\n"); break;
	case 2: printf("UNIX - NetBSD\n"); break;
	case 3: printf("UNIX - Linux\n"); break;
	case 4: printf("UNIX - GNU Hurd\n"); break;
	case 6: printf("UNIX - Solaris\n"); break;
	case 7: printf("UNIX - AIX\n"); break;
	case 8: printf("UNIX - IRIX\n"); break;
	case 9: printf("UNIX - FreeBSD\n"); break;
	case 10: printf("UNIX - Tru64\n"); break;
	case 11: printf("UNIX - Novell Modesto\n"); break;
	case 12: printf("UNIX - OpenBSD\n"); break;
	case 13: printf("UNIX - Open VMS\n"); break;
	case 14: printf("UNIX - NonStop Kernel\n"); break;
	case 15: printf("UNIX - AROS\n"); break;
	case 16: printf("UNIX - Fenix OS\n"); break;
	case 17: printf("UNIX - CloudABI\n"); break;
	default: printf("<unknown: %02hx>\n", header[7]); break;
	}
}

/**
 * print_abiv - Print ELF ABI version.
 * @header: ELF header
 * Return: void
 */
void print_abiv(char *header)
{
	printf("  %-35s", "ABI Version:");
	printf("%d\n", header[8]);
}

/**
 * print_type - Print ELF type.
 * @header: ELF header
 * @is64: 1 for 64 bits; 0 for 32 bits
 * Return: void
 */
void print_type(char *header, unsigned int is64)
{
	int xtype = 17;

	(void) is64;

	if (header[5] == 1)
		xtype = 16;

	printf("  %-35s", "Type:");

	switch (header[xtype])
	{
	case 0: printf("NONE\n"); break;
	case 1: printf("REL (Relocatable file)\n"); break;
	case 2: printf("EXEC (Executable file)\n"); break;
	case 3: printf("DYN (Shared object file)\n"); break;
	case 4: printf("CORE (Core file)\n"); break;
	default: printf("<unknown>: %02x\n", header[xtype]); break;
	}
}

/**
 * print_entry_point_address - Print entry point address.
 * @header: ELF header
 * @is64: 1 for 64 bits; 0 for 32 bits
 * Return: void
 */
void print_entry_point_address(char *header, unsigned int is64)
{
	int count = 27, i;

	printf("  %-35s0x", "Entry point address:");

	if (is64 == 1)
		count = 31;

	if (header[5] == 1)
	{
		/* Little Endian */
		i = count;
		while (header[i] == 0 && i > 24)
			i--;
		printf("%x", header[i]);
		i--;

		while (i >= 24)
		{
			printf("%02x", (unsigned char) header[i]);
			i--;
		}
	}
	else
	{
		/* Big Endian */

		i = 24;
		while (header[i] == 0)
			i++;
		printf("%x", header[i]);
		i++;

		while (i <= count)
		{
			printf("%02x", (unsigned char) header[i]);
			i++;
		}
	}
	printf("\n");
}

/**
 * main - Entry point of the program.
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0
 */
int main(int argc, char **argv)
{
	int fd_elf, r_elf, close_elf, is64 = 0;
	char header[16];

	/* Check for valid arguments */
	if (argc != 2)
		dprintf(STDERR_FILENO, "Wrong number of arguments\n"), exit(98);
	if (argv[1] == 0)
		dprintf(STDERR_FILENO, "Please enter a name, Null error\n"), exit(98);

	/* Open the ELF file */
	fd_elf = open(argv[1], O_RDONLY);
	if (fd_elf == -1)
		dprintf(STDERR_FILENO, "Can't open file\n"), exit(98);

	/* Read the first 32 bytes of the ELF header */
	r_elf = read(fd_elf, header, 32);
	if (r_elf == -1)
		dprintf(STDERR_FILENO, "Error Reading File\n"), exit(98);

	/* Check if it's an ELF file */
	_is_elf(header);

	/* Determine if it's 64-bit or 32-bit ELF */
	if (header[4] == 2)
		is64 = 1;

	/* Print various header information */
	print_magic(header);
	print_class(header, is64);
	print_data(header);
	print_version(header);
	print_os_abi(header);
	print_abiv(header);
	print_type(header, is64);
	print_entry_point_address(header, is64);

	/* Close the ELF file */
	close_elf = close(fd_elf);
	if (close_elf == -1)
		dprintf(STDERR_FILENO, "Error closing FD Elf\n"), exit(98);

	return (0);
}
