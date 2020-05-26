/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jtrancos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 13:34:09 by jtrancos          #+#    #+#             */
/*   Updated: 2020/05/26 11:32:43 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void	swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	reversing(char *str, int start, int end)
{
	int	q;
	int	i;

	i = start;
	q = end;
	while (i < end)
	{
		swap(&str[i], &str[end]);
		i++;
		end--;
	}
	i = start;
	while (i < (q + 1))
	{
		if (str[i] == ')')
			str[i] = '(';
		else if (str[i] == '(')
			str[i] = ')';
		i++;
	}
}

static int	check_error(const char *str)
{
	int	count;
	char	*temp;

	count = 0;
	temp = strdup(str);
	while (*temp)
	{
		if (*temp == '(' || *temp == ')')
			count++;
		temp++;
	}
	if (count % 2 != 0)
		return (7);
	else
		return (0);
}

char		*ft_reverse_parenthesis(const char *str)
{
	char	*temp;
	int	start;
	int	end;
	int	i;
	int	q;

	i = 0;
	q = strlen(str);
	if (check_error(str) == 0)
		temp = strdup(str);
	else
		temp = strdup("NULL");
	if (strchr(temp, '(') == NULL)
		return (temp);
	while (temp[i])
	{
		while (temp[i] != '(' && i < q)
			i++;
		start = i;
		i++;
		while (temp[q] != ')' && q > i)
			q--;
		end = q;
		q--;
		reversing(temp, start, end);
	}
	return (temp);
}
