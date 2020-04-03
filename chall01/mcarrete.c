/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mcarrete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 10:00:34 by mcarrete          #+#    #+#             */
/*   Updated: 2020/04/03 23:39:15 by mcarrete         ###   ########.fr       */
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
	int k;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	/*
	** First check if both strings have the same length:
	*/
	if (len_s1 != len_s2)
		return (0);
	i = 0;
	/*
	** compare each char of s2 to each char of s1. If not the same, move
	** one forward in s2 and compare again to s1 (starting from s1[0]);
	*/
	i = 0;
	k = 0;
	while (s2[i + k] != '\0')
	{
		if (s2[i + k] == s1[i])
		{
			i++;
		}
		else
		{
			k++;
			i = 0;
		}

	}
	/*
	** Once s2 has reached its end, continue comparing to s1[i], now
	** from the start of s2.
	*/
	k = 0;
	while (s1[i] != '\0')
	{
		if (s2[k] == s1[i])
		{
			k++;
			i++;
		}
		else
			return (0);
	}
	return (1);
}
