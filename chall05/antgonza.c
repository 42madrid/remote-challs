/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antgonza.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 11:39:53 by antgonza          #+#    #+#             */
/*   Updated: 2020/04/16 12:11:58 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	if (!*needle)
		return ((char *)haystack);
	if (ft_strlen(needle) > ft_strlen(haystack) || len == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + j] == needle[j] && haystack[i + j] != '\0'
					&& needle[j] != '\0' && (i + j) < len)
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		else
			j = 0;
		i++;
	}
	return (NULL);
}

int		ft_ie_except_after_c(char *str)
{
	size_t	i;

	i = ft_strlen(str);
	if ((!(ft_strnstr(str, "ei", i)) && (!(ft_strnstr(str, "ie", i)))))
		return (1);
	if (ft_strnstr(str, "cei", i) || (ft_strnstr(str, "ie", i)))
	{
		if (ft_strnstr(str, "cie", i))
			return (0);
		return (1);
	}
	return (0);
}
