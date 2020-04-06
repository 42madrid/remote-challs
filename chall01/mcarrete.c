/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mcarrete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 10:00:34 by mcarrete          #+#    #+#             */
/*   Updated: 2020/04/03 11:29:45 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

size_t		ft_strlen(const char *s)
{
	unsigned long	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

int hv_necklace(char *s1, char *s2)
{
	int len_s1;
	int len_s2;
	int i;
	int j;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);

	/*
	** First check if both strings have the same lenght:
	*/
	if(len_s1 != len_s2)
		return (0);
	i = 0;
	/*
	** Locate s1[0] in s2 string:
	*/
	while (s2[i] != s1[0] && s2[i] != '\0')
	{
		i++;
	}
	/*
	** If s2[i] is not the last char, check if the next char is same as s1[0 + 1], 0 + 2 etc
	*/
	j = 1;
	while (s2[i + j] != '\0')
	{
		if (s2[i + j] == s1[0 + j])
			j++;
		else
			return (0);
	}
	/*
	** check if the previous char is same as last char of s1 string:
	*/
	j = 1;
	while ((i - j) >= 1)
	{
		if (s2[i - j] == s1[len_s1 - j])
		{
			j++;
		}
		else
			return (0);
	}
	return (1);
}
