/*
** EPITECH PROJECT, 2017
** CPE_BSQ_2017
** File description:
** map_size.c
*/

#include <stdlib.h>
#include "my.h"

int nbr_len(char *file)
{
	int i = 0;

	while (file[i] != '\n'  && file[i] != '\0') {
		i += 1;
	}
	return (i);
}

void map_size(int *i, int *j, char *file)
{
	int k = 0;
	char *nbr = malloc(sizeof(char) * (nbr_len(file) + 1));

	*i = 0;
	*j = 0;
	while (file[k] != '\n' && file[k] != '\0') {
		nbr[k] = file[k];
		k += 1;
	}
	nbr[k] = '\0';
	k += 1;
	*j = my_getnbr(nbr);
	while (file[k - 1] != '\0' && file[k] != '\n' && file[k] != '\0') {
		k += 1;
		*i += 1;
	}
}
