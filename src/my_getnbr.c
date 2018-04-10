/*
** EPITECH PROJECT, 2017
** getnbr
** File description:
** nbr
*/

int sign(char const *str)
{
	int n = 1;
	int i = 0;

	while (str && (str[i] == '-' || str[i] == '+')) {
		if (str[i] == '-') {
			n = n * (-1);
			i = i + 1;
		} else if (str[i] == '+') {
			i = i + 1;
		}
	}
	return (n);
}

int count(char const *str)
{
	int n = 1;
	int i = 0;

	while (str && (str[i] == '-' || str[i] == '+')) {
		if (str[i] == '-') {
			n = n * (-1);
			i = i + 1;
		} else if (str[i] == '+') {
			i = i + 1;
		}
	}
	return (i);
}

int my_getnbr(char const *str)
{
	int nb = 0;
	int neg = sign(str);
	int i = count(str);

	while (str && str[i]) {
		if (str[i] >= '0' && str[i] <= '9') {
			nb = nb * 10;
			nb = nb + str[i] - 48;
			i = i + 1;
		} else {
			return (nb * neg);
		}
	}
	return (nb * neg);
}