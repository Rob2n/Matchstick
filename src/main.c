/*
** EPITECH PROJECT, 2018
** main
** File description:
** prints_a_file
*/

#include "../include/my.h"

int who_won(int end)
{
	if (end == 0) {
		write(1, "You lost, too bad...\n", 21);
		return (2);
	} else if (end == 1) {
		write(1, "I lost... snif... ", 18);
		write(1, "but I'll get you next time!!\n", 29);
		return (1);
	}
	return (0);
}

int is_last_line(gen_t *all)
{
	int i = 0;
	int total = 0;

	while (i != all->nb_lines) {
		total += all->match_board[i];
		i++;
	}
	i = 0;
	while (i != all->nb_lines) {
		if (total == all->match_board[i]) {
			all->last_line = i;
			return (1);
		}
		i++;
	}
	return (0);
}

int is_game_on(gen_t *all)
{
	int i = 0;
	int a = 0;

	while (i != all->nb_lines) {
		a += all->match_board[i];
		i++;
	}
	if (a == 0) {
		return (1);
	}
	return (0);
}

int game_loop(char **av)
{
	gen_t *all = init_all(av);

	display_board(all->match_board, all->end_matches, all->nb_lines);
	while (is_game_on(all) == 0) {
		print_input(0);
		if (input(all) == 1)
			return (0);
		print_move(all, 0);
		handle_input(all->line, all->matches,
		&(all->match_board));
		display_board(all->match_board, all->end_matches,
		all->nb_lines);
		if (is_game_on(all) == 0) {
			play_ai(all);
			display_board(all->match_board, all->end_matches,
			all->nb_lines);
		} else
			all->end = 0;
	}
	return (who_won(all->end));
}

int main(int ac, char **av)
{
	if (ac == 3 && my_str_isnum(av[1]) == 1 && my_str_isnum(av[2]) == 1 &&
	my_getnbr(av[1]) > 0 && my_getnbr(av[1]) < 101 &&
	my_getnbr(av[2]) > 0) {
		return (game_loop(av));
	}
	write(1, "Bad arguments. Usage: ./matchstick x y\n", 49);
	write(1, "x = Number of lines\ny = Maximum number of ", 42);
	write(1, "matchsticks you can take each turn\n", 35);
	return (84);
}