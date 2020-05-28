/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdorta-n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdorta-n <cdorta-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 13:42:55 by cdorta-n          #+#    #+#             */
/*   Updated: 2020/05/21 21:44:23 by cdorta-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
** 'Label' -> Positive Integer
** 'goto' -> goto-statement
** 'whitespaces' -> only 1 space
** 'end-of-line' -> \n
*/

char	*ft_goto_error()
{
	char *error = "Infinite loop !";
	return (error);
}

int		ft_goto_statement(const char *code, int num, int c)
{
		int i = 0;
		int exp = 1;
		int nums;
		int aux;
		int aux2;

		nums = num;
		aux = nums;
		while (num > 9)
		{
			num /= 10;
			exp *= 10;
		}
		aux2 = exp;
		while (code[c] != '\0')
		{
			if (code[c] == (num + 48))
			{
				while (exp >= 10)
				{
					c++;
					nums %= exp;
					exp /= 10;
					num = (nums / exp) + 48;
					if (!(code[c] == num))
					{
						nums = aux;
						exp = aux2;
						num = nums / exp;
						break ;
					}
				}
				if (exp < 10)
					return (c);
			}
			c++;
		}
		return (0);
}

int 	ft_goto_aux(const char *code)
{
	int c = 0;
	int i = 0;
	int num = 0;
	
	while (code[c] != '\0')
	{
		if (code[c] == 'g' && code[c + 1] == 'o' && code[c + 2] == 't' && code[c + 3] == 'o')
		{
			while (code[c] < '0' || code[c] > '9')
				c++;
			while (code[c] >= '0' && code[c] <= '9')
			{
				num = num * 10 + (code[c] - 48);
				c++;
			}
			if ((ft_goto_statement(code, num, c) < c))
				return (-1);
			c = ft_goto_statement(code, num, c);
		}
		else
		{
			if (code[c] != '\0' && code[c] != '\n')
			{
				while ((code[c] >= '0' && code[c] <= '9') || code[c] == ' ')
						c++;
				while (code[c] != '\n' && code[c] != '\0')
				{
					if (code[c] == ' ')
					{
						i++;
						while (code[c] == ' ')
							c++;
					}
					else
					{
						i++;
						c++;
					}
				}
				if (code[c] == '\n')
				{
					if (code[c - 1] != ' ')
						i++;
					c++;
				}
			}
		}	
	}
	i--;
	return (i);
}

char	*ft_goto_answer(const char *code, int i)
{
	char *str;
	int c = 0;
	int num = 0;
	
	if (!(str = malloc(i * 4)))
		return (NULL);

	i = 0;
	while (code[c] != '\0')
	{
		if (code[c] == 'g' && code[c + 1] == 'o' && code[c + 2] == 't' && code[c + 3] == 'o')
		{
			while (code[c] < '0' || code[c] > '9')
				c++;
			while (code[c] >= '0' && code[c] <= '9')
			{
				num = num * 10 + (code[c] - 48);
				c++;
			}
			if ((ft_goto_statement(code, num, c) < c))
				return (ft_goto_error());
			c = ft_goto_statement(code, num, c);

		}
		else
		{
			if (code[c] != '\0' && code[c] != '\n')
			{
				while ((code[c] >= '0' && code[c] <= '9') || code[c] == ' ')
						c++;
				while (code[c] != '\n' && code[c] != '\0')
				{	
					if (code[c] == ' ')
					{
						str[i] = ' ';
						i++;
						while (code[c] == ' ')
							c++;
					}
					else
					{
						str[i] = code[c];
						i++;
						c++;
					}
				}
				if (code[c] == '\n')
				{
					if (code[c - 1] != ' ')
					{
						str[i] = ' ';
						i++;
					}
					c++;
				}
			}
		}	
	}
	str[--i] = '\0';
	return (str);
}

char	*ft_goto_parser(const char *code)
{
	int i;
	
	if ((i = ft_goto_aux(code)) < 0)
		return (ft_goto_error());
	return (ft_goto_answer(code, i));
}
