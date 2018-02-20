/*
** EPITECH PROJECT, 2017
** CPE_BSQ_2017
** File description:
** display_map.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void display_num_map(int **num_map, int size_i, int size_j)
{
	int i = 0;
	int j = 0;

	while (i < size_i) {
		while (j < size_j) {
			my_put_nbr(num_map[i][j]);
			j += 1;
		}
		my_putchar('\n');
		i += 1;
		j = 0;
	}
}

void display_char_map(char *file, int size_i, int size_j)
{
	int write_size = size_i * (size_j + 1);

	if (file[0] != '\0') {
		while (*file != '\n') {
			file++;
		}
		file++;
		write(1, file, write_size);
	}
}
