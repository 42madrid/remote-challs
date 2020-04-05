/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estina.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 13:19:46 by estina            #+#    #+#             */
/*   Updated: 2020/04/02 14:29:15 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_check(char *s1, char *s2, int j)
{
	int		i;
	
	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[j])
			return (0);
		i++;
		j++;
		if (!s2[j])
			j = 0;
	}
	return (1);
}

int		hv_necklace(char *s1, char *s2)
{
	int		size_s1;
	int		size_s2;
	int		j;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	if (size_s1 != size_s2)
		return (0);
	if (!size_s1)
		return (1);
	j = 0;
	while (j < size_s2)
	{
		if (ft_check(s1, s2, j))
			return (1);
		j++;
	}
	return (0);
}
