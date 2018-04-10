/*
** EPITECH PROJECT, 2017
** my_putchar
** File description:
** puts_char
*/

void write(int, char*, int);

void my_putchar(char c)
{
	write(1, &c, 1);
}
