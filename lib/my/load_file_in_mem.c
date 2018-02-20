/*
** EPITECH PROJECT, 2017
** load_file_in_mem.c
** File description:
** load_file_in_mem.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int fs_open_file(char const *filepath);

char *load_file_in_mem(char const *filepath)
{
	struct stat stat_file;
	int fd = fs_open_file(filepath);
	char *file;
	int file_size;

	stat(filepath, &stat_file);
	file_size = ((long long)stat_file.st_size);
	file = malloc(sizeof(char) * (file_size + 1));
	read(fd, file, (long long)stat_file.st_size);
	file[file_size] = '\0';
	return (file);
}
