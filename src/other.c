/*
** EPITECH PROJECT, 2018
** main
** File description:
** other
*/

#include "../include/my.h"

gen_t *init_all(char **av)
{
	gen_t *all = malloc(sizeof(*all));

	all->end = 1;
	all->end_matches = 0;
	all->nb_lines = my_getnbr(av[1]);
	all->match_board = board_create(all->nb_lines, &(all->end_matches));
	all->max_match = my_getnbr(av[2]);
	return (all);
}

int print_move(gen_t *all, int ver)
{
	if (ver == 0 && all->line && all->matches && *(all->line) &&
	*(all->matches) && my_str_isnum(all->line) == 1 &&
	my_str_isnum(all->matches) == 1) {
		write(1, "Player removed ", 15);
		my_put_nbr(my_getnbr(all->matches));
		write(1, " match(es) from line ", 21);
		my_put_nbr(my_getnbr(all->line));
		write(1, "\n", 1);
		return (0);
	} else if (ver == 1) {
		write(1, "\nAI removed ", 12);
		my_put_nbr(all->ai_match);
		write(1, " match(es) from line ", 21);
		my_put_nbr(all->ai_line + 1);
		write(1, "\n", 1);
		return (0);
	}
	return (0);
}

int is_valid(gen_t *all, int ver)
{
	if (ver == 0 && my_str_isnum(all->line) == 0) {
		write(1, "Error: invalid input (positive number expected)\n",
		48);
		input(all);
		return (1);
	}
	if (ver == 1 && my_str_isnum(all->matches) == 0) {
		write(1, "Error: invalid input (positive number expected)\n",
		48);
		free(all->matches);
		input(all);
		return (1);
	}
	return (0);
}

int last_line_ai(gen_t *all)
{
	int save = 0;

	if (all->match_board[all->last_line] <= all->max_match + 1 &&
	all->match_board[all->last_line] != 1) {
		save = all->match_board[all->last_line] - 1;
		all->match_board[all->last_line] -=
		all->match_board[all->last_line] - 1;
		all->ai_match = save;
		all->ai_line = all->last_line;
		print_move(all, 1);
		return (0);
	}
	return (1);
}

int play_ai(gen_t *all)
{
	all->ai_line = -1;
	all->ai_match = -1;
	write(1, "\nAI's turn...", 13);
	if (is_last_line(all) == 1 && last_line_ai(all) == 0)
		return (0);
	srand(time(NULL));
	while (all->ai_line == -1 || all->match_board[all->ai_line] == 0) {
		all->ai_line = rand() % all->nb_lines;
	}
	while (all->ai_match == -1 || all->ai_match > all->max_match ||
	all->ai_match > all->match_board[all->ai_line]) {
		if (all->match_board[all->ai_line] - 1 != 0)
			all->ai_match = 1 + rand() %
		(all->match_board[all->ai_line] - 1);
		else
			all->ai_match = 1;
	}
	all->match_board[all->ai_line] -= all->ai_match;
	print_move(all, 1);
	return (0);
}