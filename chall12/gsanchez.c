/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsanchez.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanchez <gsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:20:06 by gsanchez          #+#    #+#             */
/*   Updated: 2020/05/26 11:07:04 by gsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			paren++;
		else if (*str == ')' && paren > 0)
			paren--;
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
	int		missmatch, paren;

	paren = 0;
	missmatch = 0;
	if (!str || ft_searchunmatch(str))
		return (NULL);
	reverse = strdup(str);
	if (!strchr(reverse, 40))
		return (reverse);
	while (reverse[i])
	{
		if (reverse[i] == '(')
		{
			if (!missmatch)
				start = i;
			missmatch++;
		}
		if (reverse[i] == ')' && missmatch > 0)
		{
			missmatch--;
			if (!missmatch)
			{
				end = i;
				paren = 1;
			}
		}
		if (!missmatch && paren)
		{
			i = start;
			paren = 0;
			ft_strreverse(reverse, start, end);
		}
		i++;
	}
	return (reverse);
}
