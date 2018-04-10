/*
** EPITECH PROJECT, 2018
** main
** File description:
** board
*/

#include "../include/my.h"

int *board_create(int nb_lines, int *end_matches)
{
	int i = 0;
	int x = 1;
	int *ret = malloc(sizeof(int) * nb_lines + 1);

	while (nb_lines != 0) {
		ret[i++] = x;
		x += 2;
		nb_lines--;
	}
	*end_matches = x - 2;
	return (ret);
}

void print_board_ends(int save)
{
	for (int a = 0; a != save + 2;a++)
		write(1, "*", 1);
	write(1, "\n", 1);
}

void display_board(int *match_board, int end_matches, int nb_lines)
{
	int i = 0;
	int a;
	int save = end_matches;

	print_board_ends(save);
	while (i != nb_lines) {
		write(1, "*", 1);
		for (a = 1; a < (end_matches + 2 - i * 2) / 2; a++)
			write(1, " ", 1);
		for (int b = 0; match_board[i] != 0 &&
			b != match_board[i]; b++)
			write(1, "|", 1);
		for (a += match_board[i]; a < end_matches + 1; a++)
			write(1, " ", 1);
		write(1, "*\n", 2);
		i++;
	}
	print_board_ends(save);
}