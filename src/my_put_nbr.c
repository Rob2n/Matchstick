/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** nbr
*/

void my_putchar(char);

int my_put_nbr(int nb)
{
	int c;

	if (nb < 0) {
		nb = nb - (2 * nb);
		my_putchar('-');
	}
	c = nb % 10;
	nb = nb / 10;
	if (nb != 0) {
		my_put_nbr(nb);
	}
	my_putchar(c + 48);
	return (0);
}