/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** my_getnbr
*/

int my_str_isprintable(char const *str);

int calculator(char const *str, int i);

int ten_multi(int nbr, int leng);

int my_put_nbr(int nb);

int my_getnbr(char const *str)
{
	int i = 0;
	int rslt = 0;
	int negative = 1;

	while (str[i] == '-') {
		i = i + 1;
		negative = -1;
	}
	while (str[i] != '\0' && !(str[i] > 47 && str[i] < 58))
		i = i + 1;
	rslt = calculator(str, i);
	if (rslt < 0)
		return (0);
	rslt = rslt * negative;
	return (rslt);
}

int calculator(char const *str, int i)
{
	int leng = 0;
	int nbr;
	int rslt = 0;
	int save_leng;

	while (str[i] > 47 && str[i] < 58) {
		leng = leng + 1;
		i = i + 1;
	}
	i = i - leng;
	save_leng = leng - 1;
	while (str[i] > 47 && str[i] < 58) {
		nbr = str[i] - 48;
		nbr = ten_multi(nbr, save_leng);
		rslt = rslt + nbr;
		i = i + 1;
		save_leng = save_leng - 1;
	}
	return (rslt);
}

int ten_multi(int nbr, int leng)
{
	while (leng > 0) {
		nbr = nbr * 10;
		leng = leng - 1;
	}
	return (nbr);
}
