/*
** EPITECH PROJECT, 2017
** CPE_BSQ_2017
** File description:
** main.c
*/

#include <stdlib.h>
#include "my.h"

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	char *file;
	int **map_int;

	if (argc != 2)
		exit (EXIT_ARG);
	file = load_file_in_mem(argv[1]);
	map_size(&j, &i, file);
	if (i == 1 || j == 1) {
		exception(file);
	} else {
		map_int = load_map_to_int(argv[1], i, j, nbr_len(file));
		map_int = bsq_finder(map_int, file);
		free(map_int);
	}
	return (0);
}
