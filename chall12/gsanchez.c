#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int ft_searchunmatch(const char *stro)
{
	int paren = 0;
	int open = 0;
	char *str = (char*) stro;

	while (*str)
	{
		if (*str == '(')
		{
			open = 1;
			paren++;
		}
		else if (*str == ')' && open)
		{
			open = 0;
			paren--;
		}
		str++;
	}
	if (paren)
		return (1);
	return (0);
}

static void	ft_swap(char *a, char *b)
{
	char aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

static void ft_strreverse(char *str, int start, int end)
{
	int j;

	j = end;
    for (int i = start; i < end; i++)
		ft_swap(&str[i], &str[end--]);
	for (int i = start; i < (j + 1); i++)
	{
		if (str[i] == ')')
			str[i] = '(';
		else if (str[i] == '(')
			str[i] = ')';
	}
}

char *ft_reverse_parenthesis(const char *str)
{
	char	*reverse;
	int		start, end;
	int		i = 0;
	int		j;

	if (!str || ft_searchunmatch(str))
		return (NULL);
	reverse = strdup(str);
	if (!strchr(reverse, 40))
		return (reverse);
	j = strlen(reverse);
	while (reverse[i])
	{
		while (reverse[i] != '(' && i < j)
			i++;
		start = i;
		i++;
		while (reverse[j] != ')' && j > i)
			j--;
		end = j;
		j--;
		ft_strreverse(reverse, start, end);
	}
	return (reverse);
}
