/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#define EXIT_SUCCES	0
#define EXIT_USAGE	1
#define EXIT_ERROR	84
#define EXIT_ARG	84

typedef struct bigger_square_s {
	int size;
	int pos_i;
	int pos_j;
} bigger_square_t;

#ifndef MY_BSQ_H

#define MY_BSQ_H
	int my_getnbr(char const *str);
	int my_putstr(char *str);
	int my_put_nbr(int nb);
	void my_putchar(char c);
	int my_strcmp(char const *s1, char  const *s2);
	int my_strlen(char const *str);
	char *my_strcat(char *dest, char *src);

	char **load_2d_arr_from_file(char const *, int, int, int);
	int **bsq_finder(int **map, char *file);
	int is_square_of_size(char **map, int row, int col, int square_size);
	void display_char_map(char *map, int, int);
	void display_num_map(int **num_map, int size_i, int size_j);
	char *load_file_in_mem(char const *filepath);
	int nbr_len(char *file);
	void map_size(int *i, int *j, char *file);
	int **load_map_to_int(char const *filepath, int nb_rows, int nb_cols,
	int number_len);
	int **mem_alloc_2d_array_int(int nb_rows, int nb_cols);
	char **mem_alloc_2d_array(int nb_rows, int nb_cols);
	int exception(char *file);
#endif /*MY_BSQ_H*/
