/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isfernan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 19:31:24 by marvin            #+#    #+#             */
/*   Updated: 2020/04/02 19:31:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*s3;
	char		*tmp_s3;
	size_t		i;
	size_t		j;

	j = 0;
	i = 0;
	while (s1[i])
		i += 1;
	while (s2[j])
		j += 1;
	if (!s1 || !s2 || !(s3 = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	tmp_s3 = s3;
	while (*s1 != '\0')
		*tmp_s3++ = *s1++;
	while (*s2 != '\0')
		*tmp_s3++ = *s2++;
	*tmp_s3 = '\0';
	return (s3);
}

int		ft_find(const char *h, const char *needle, size_t i, size_t len)
{
	size_t	c;

	c = 0;
	while (i < len && h[i])
	{
		if (!(h[i] == needle[c]))
			return (0);
		i++;
		c++;
		if (!(needle[c]))
			return (1);
	}
	if (!(needle[c]))
		return (1);
	if (needle[c] == h[i] && !(needle[c]))
		return (1);
	return (0);
}

int		ft_strnstr2(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!(*(needle)))
		return (0);
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			if (ft_find(haystack, needle, i, len))
				return (1);
		}
		i++;
	}
	return (0);
}

int		hv_necklace(char *s1, char *s2)
{
	int		len;
	char	*s3;

	if (!s1[0] && !s2[0])
		return (1);
	len = ft_strlen(s2);
	if (len != ft_strlen(s1))
		return (0);
	s3 = malloc(sizeof(char) * 2 * len);
	s3 = ft_strjoin(s2, s2);
	return (ft_strnstr2(s3, s1, 2 * len));
}
