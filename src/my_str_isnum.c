/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** is_it_a_num
*/

int my_str_isnum(char *str)
{
	int i = 0;
	int n = 0;

	if (!(str))
		return (1);
	while (str[i]) {
		i++;
	}
	n = i;
	i = 0;
	while (i < n) {
		if ((str[i] >= 48  && str[i] <=57) || str[i] == '\0') {
			i++;
		} else {
			return (0);
		}
	}
	return (1);
}