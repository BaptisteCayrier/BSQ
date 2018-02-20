/*
** EPITECH PROJECT, 2017
** CPE_BSQ_2017
** File description:
** bsq.c
*/

#include <stdlib.h>
#include "my.h"

char **load_2d_arr_from_file(char const *, int, int, int);

char *draw_square(char *map, int size, int pos_i, int pos_j)
{
	int i = pos_i - size + 1;
	int j = pos_j - size + 1;
	int size_i = 0;
	int size_j = 0;
	int nbr = nbr_len(map) + 1;

	map_size(&size_i, &size_j, map);
	while (map[0] != '\0' && i <= pos_i) {
		while (j <= pos_j) {
			map[(i * size_i + i) + j + nbr] = 'x';
			j += 1;
		}
		j = pos_j - size + 1;
		i += 1;
	}
	return (map);
}

int **bsq_finder_core(int **map, int i, int j)
{
	if (map[i][j] != 0 && map[i - 1][j] <= map[i - 1][j - 1] &&
		map[i - 1][j] <= map[i][j - 1]) {
		map[i][j] = map[i - 1][j] + 1;
	} else if (map[i][j] != 0 && map[i][j - 1] <= map[i - 1][j - 1] &&
		map[i][j - 1] <= map[i - 1][j]) {
		map[i][j] = map[i][j - 1] + 1;
	} else if (map[i][j] != 0 && map[i - 1][j - 1] <= map[i][j - 1] &&
		map[i - 1][j - 1] <= map[i - 1][j]) {
		map[i][j] = map[i - 1][j - 1] + 1;
	}
	return (map);
}

bigger_square_t *check_bigger(int **map, int i, int j,
	bigger_square_t *square)
{
	if (map[i][j] > square->size) {
		square->size = map[i][j];
		square->pos_i = i;
		square->pos_j = j;
		return (square);
	}
	return (square);
}

int **bsq_finder(int **map, char *file)
{
	int i = 1;
	int j = 1;
	bigger_square_t *square = malloc(sizeof(bigger_square_t));
	int size_i = 0;
	int size_j = 0;

	map_size(&size_j, &size_i, file);
	square->size = 0;
	while (i < size_i) {
		while (j < size_j) {
			map = bsq_finder_core(map, i, j);
			check_bigger(map, i, j, square);
			j += 1;
		}
		j = 1;
		i += 1;
	}
	file = draw_square(file,  square->size, square->pos_i, square->pos_j);
	display_char_map(file, size_i, size_j);
	return (map);
}
