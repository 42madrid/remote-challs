/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rarias-p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 10:40:16 by rarias-p          #+#    #+#             */
/*   Updated: 2020/04/03 10:40:16 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int hv_necklace(char *s1, char *s2)
{
	int	len;
	int	i;
	int j;
	int	k;
	int check;

	if (s1[0] == '\0' && s2[0] == '\0')
		return (1);
	if (strlen(s1) != strlen(s2))
		return (0);
	len = strlen(s1);
	i = 0;
	while (i < len)
	{
		j = 0;
		k = i;
		check = 0;
		while (j < len)
		{
			if (k >= len)
				k = 0;
			if (s1[j] == s2[k])
				check++;
			j++;
			k++;
		}
		if (check == len)
			return (1);
		i++;
	}
	return (0);
}
