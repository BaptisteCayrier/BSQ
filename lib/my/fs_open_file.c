/*
** EPITECH PROJECT, 2017
** fs_open_file.c
** File description:
** null
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "stdlib.h"
#include "my.h"

int fs_open_file(char const *filepath)
{
	int fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		exit (84);
	return (fd);
}
