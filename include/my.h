/*
** EPITECH PROJECT, 2017
** my
** File description:
** header
*/

#ifndef MY_H_
#define MY_H
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "get_next_line.h"

typedef struct gen_s {
	char *line;
	int end;
	int nb_lines;
	char *matches;
	int max_match;
	int *match_board;
	int end_matches;
	int ai_line;
	int ai_match;
	int last_line;
} gen_t;

gen_t *init_all(char **av);
int play_ai(gen_t *all);
int print_move(gen_t *all, int ver);
int is_valid(gen_t *all, int ver);
void print_input(int ver);
int input(gen_t *all);
int handle_input(char *line, char *matches, int **match_board);
int check_bad_line(gen_t *all);
int check_bad_match(gen_t *all);
int *board_create(int nb_lines, int *end_matches);
void print_board_ends(int save);
void display_board(int *match_board, int end_matches, int nb_lines);
int my_getnbr(char const *str);
int my_str_isnum(char *str);
void my_put_nbr(int);
int input(gen_t *all);
int is_last_line(gen_t *all);

#endif