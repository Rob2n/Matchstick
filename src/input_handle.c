/*
** EPITECH PROJECT, 2018
** main
** File description:
** input
*/

#include "../include/my.h"

void print_input(int ver)
{
	if (ver == 0)
		write(1, "\nYour turn:\n", 12);
	else if (ver == 1)
		write(1, "Matches: ", 9);
	else
		write(1, "Line: ", 6);
}

int input(gen_t *all)
{
	while (1) {
		print_input(2);
		all->line = get_next_line(0);
		if (all->line == NULL) {
			return (1);
		}
		if (check_bad_line(all) == 1)
			continue;
		print_input(1);
		all->matches = get_next_line(0);
		if (all->matches == NULL) {
			return (1);
		}
		if (check_bad_match(all) == 1)
			continue;
		return (0);
	}
}

int handle_input(char *line, char *matches, int **match_board)
{
	if ((*match_board)[my_getnbr(line) - 1] - my_getnbr(matches) >= 0)
		(*match_board)[my_getnbr(line) - 1] -= my_getnbr(matches);
	return (0);
}

int check_bad_line(gen_t *all)
{
	if (my_str_isnum(all->line) == 1 &&
	(my_getnbr(all->line) > all->nb_lines || my_getnbr(all->line) < 1)) {
		write(1, "Error: this line is out of range\n", 33);
		return (1);
	}
	return (is_valid(all, 0));
}

int check_bad_match(gen_t *all)
{
	if (my_str_isnum(all->matches) == 1 && my_getnbr(all->matches) < 1) {
		write(1, "Error: you have to remove at least one match\n", 45);
		return (1);
	}
	if (my_str_isnum(all->matches) == 1 &&
	my_getnbr(all->matches) > all->max_match) {
		write(1, "Error: you cannot remove more than ", 35);
		my_put_nbr(all->max_match);
		write(1, " matches per turn\n", 18);
		return (1);
	}
	if (my_str_isnum(all->matches) == 1 &&
	my_getnbr(all->matches) > all->match_board[my_getnbr(all->line) - 1]) {
		write(1, "Error: not enough matches on this line\n", 39);
		return (1);
	}
	return (is_valid(all, 1));
}