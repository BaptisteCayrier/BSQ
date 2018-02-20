/*
** EPITECH PROJECT, 2017
** mem_alloc_2d_array.c
** File description:
** mem_alloc_2d_array.
*/

#include <stdlib.h>

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
	char **rslt = malloc(sizeof(char *) * (nb_rows + 1));
	int i = 0;

	while (i < nb_rows) {
		rslt[i] = malloc(sizeof(char) * (nb_cols + 1));
		i += 1;
	}
	return (rslt);
}

int **mem_alloc_2d_array_int(int nb_rows, int nb_cols)
{
	int **rslt = malloc(sizeof(int *) * (nb_rows + 1));
	int i = 0;

	while (i < nb_rows) {
		rslt[i] = malloc(sizeof(int) * (nb_cols + 1));
		i += 1;
	}
	return (rslt);
}
