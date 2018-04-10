/*
** EPITECH PROJECT, 2017
** my
** File description:
** header
*/

#ifndef MY_H_
#define MY_H_
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

char *get_next_line(int fd);
char *check_return(char *str);
int start(char **str, int fd);
char *my_custom_dup(char *str, int pos, char **str2);
void advance_pointer_str(char **str, int pos);
char *read_next_n_bytes(int fd);
int my_strlen(char *);
char *my_strcat(char *, char *);
#endif

#ifndef  READ_SIZE
#define  READ_SIZE (10)
#endif  /* !READ_SIZE  */