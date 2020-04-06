/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eligero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eligero <eligero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 15:01:31 by eligero           #+#    #+#             */
/*   Updated: 2020/04/02 17:21:49 by eligero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** Freddiemercury 17473 (Chall01) / Necklace
**
** Solved as fast as possible, reusing libft, and obeying the 42 norme.
** Malloc used in order to not overflow the program stack.
** Algorithm takes track of the point of rotation on s1, by using i. Firstly It
** s1[i]...s1[len - 1] into p[0]...p[i], after that it copyies
** s1[0]...s1[i - 1] into p starting at p[i + 1]. Generat all posible rotations
** of the string s1 on the null terminated string p.
** If one of this posible rotation strings generated on p, matches the string
** s2, by using ft_strcmp, then returns 1. Algorithm finishes once occur a
** match or by it has done all posible rotations.
** In order to speed up the algorith, it only calls ft_strcmp if p[0] == s2[0]
**
*/

static size_t		ft_strlen(const char *s)
{
	const char		*str;

	str = s;
	while (*(str++))
		;
	return ((s == NULL) ? 0 : (size_t)(str - s - 1));
}

static int			ft_strcmp(const char *s1, const char *s2)
{
	while(*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

static int			necklace_algorithm(size_t len, char *p, char *s1, char *s2)
{
	size_t			i;
	size_t			j;
	size_t			k;

	i = 0;
	while (i < len)
	{
		j = i;
		k = 0;
		while (s1[j] != '\0')
			p[k++] = s1[j++];
		j = 0;
		while (j < i)
			p[k++] = s1[j++];
		if (*p == *s2)
			if (ft_strcmp(p, s2) == 0)
				return (1);
		i++;
	}
	return (0);
}

int					hv_necklace(char *s1, char *s2)
{
	int				result;
	size_t			len;
	char			*p;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	if ((len = ft_strlen(s1)) != ft_strlen(s2))
		return (0);
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if ((p = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (-1);
	*(p + len) = '\0';
	result = necklace_algorithm(len, p, s1, s2);
	free(p);
	return (result);
}
