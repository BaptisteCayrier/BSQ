/*
** EPITECH PROJECT, 2017
** load_2d_arr_from_file.c
** File description:
** load_2d_arr_from_file.
*/

#include <stdlib.h>
#include "my.h"

char **load_2d_arr_core(char **d_file, int i, int *j, char file_k)
{
	if (file_k != '\n') {
		d_file[i][*j] = file_k;
		*j += 1;
	}
}

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols,
	int number_len)
{
	char **d_file = mem_alloc_2d_array(nb_rows, nb_cols);
	char *file = load_file_in_mem(filepath);
	int k = number_len + 1;
	int i = 0;
	int j = 0;

	while (i < nb_rows) {
		while (j < nb_cols) {
			load_2d_arr_core(d_file, i, &j, file[k]);
			k += 1;
		}
		d_file[i][j] = '\0';
		j = 0;
		i += 1;
	}
	d_file[i] = NULL;
	return (d_file);
}

int **load_map_to_int_core(int **d_file, int i, int *j, char file_k)
{
	if (file_k == '.' && (i == 0 || *j == 0)) {
		d_file[i][*j] = 1;
		*j += 1;
	} else if (file_k == 'o') {
		d_file[i][*j] = 0;
		*j += 1;
	} else {
		d_file[i][*j] = 2;
		*j += 1;
	}
	return (d_file);
}

int **load_map_to_int(char const *filepath, int nb_rows, int nb_cols,
	int number_len)
{
	int **d_file = mem_alloc_2d_array_int(nb_rows, nb_cols);
	char *file = load_file_in_mem(filepath);
	int k = number_len + 1;
	int i = 0;
	int j = 0;

	while (i < nb_rows) {
		while (j < nb_cols && file[k] != '\n') {
			load_map_to_int_core(d_file, i, &j, file[k]);
			k += 1;
		}
		k += 1;
		j = 0;
		i += 1;
	}
	return (d_file);
}
