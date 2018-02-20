/*
** EPITECH PROJECT, 2017
** CPE_BSQ_2017
** File description:
** exception.c
*/

#include "my.h"

int exception(char *file)
{
	int i = 0;
	int k = 0;

	while ((file[i] >= '0' && file[i] <= '9') || file[i] == '\n')
		i += 1;
	k = i;
	while (file[k] != '.' && file[k] != '\0')
		k += 1;
	if (file[k] != '\0')
		file[k] = 'x';
	while (file[i] != '\0') {
		my_putchar(file[i]);
		i += 1;
	}
	return (0);
}
