/*
** EPITECH PROJECT, 2018
** main
** File description:
** prints_a_file
*/

#include "../include/my.h"

char *my_strcat(char *dest, char *src)
{
	int n = 0;
	int i = -1;
	int x = 0;
	int j = 0;
	char *str = NULL;

	while (dest && dest[j++]);
	while (src && src[x++]);
	if (!(dest) && src)
		str = malloc(sizeof(char) * x);
	else
		str = malloc(sizeof(char) * (x + j));
	while (dest && dest[++i])
		str[i] = dest[i];
	while (src[n])
		str[i++] = src[n++];
	return (str);
}

int start(char **str, int fd)
{
	int pos = 0;

	if (fd < 0)
		return (1);
	if (!(*str)) {
		*str  = malloc(sizeof(char) * READ_SIZE + 1);
		pos = read(fd, *str, READ_SIZE);
		if (pos == 0)
			return (1);
		(*str)[pos] = '\0';
	}
	return (0);
}

char *my_custom_dup(char *str, int pos, char **str2)
{
	int i = 0;
	int save = pos;
	char *ret;

	ret = malloc(sizeof(char) * pos + 1);
	while (pos != 0) {
		ret[i] = str[i];
		i++;
		pos--;
	}
	while (save != 0) {
		save--;
		*str2 += 1;
	}
	*str2 += 1;
	return (ret);
}

int core(char *str, int *pos)
{
	while (str && str[*pos]) {
		if (str[*pos] == '\n') {
			return (1);
		}
		*pos += 1;
	}
	return (0);
}

char *get_next_line(int fd)
{
	char *read_head = malloc(sizeof(char) * READ_SIZE + 1);
	int pos = 0;
	int pos2 = 0;
	static char *str;

	if (read_head == NULL || start(&str, fd) == 1)
		return (NULL);
	while (42) {
		if (core(str, &pos) == 1) {
			return (my_custom_dup(str, pos, &str));
		}
		free(read_head);
		read_head = malloc(sizeof(char) * READ_SIZE + 1);
		pos2 = read(fd, read_head, READ_SIZE);
		if (pos2 == 0)
			return (NULL);
		read_head[pos2] = '\0';
		str = my_strcat(str, read_head);
	}
	return (str);
}