/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** task07
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
	int mod;

	if (nb < 0) {
		my_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 0) {
		if (nb >= 10) {
			mod = (nb % 10);
			nb = (nb - mod) / 10;
			my_put_nbr(nb);
			my_putchar(mod + 48);
		} else {
			my_putchar(48 + (nb % 10));
		}
	}
	return (0);
}
