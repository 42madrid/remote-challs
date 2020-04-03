/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmartin-.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:06:55 by gmartin-          #+#    #+#             */
/*   Updated: 2019/10/09 12:40:08 by gmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t x;

	x = 0;
	while (s[x] != '\0')
	{
		x++;
	}
	return (x);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	dst = malloc(sizeof(*dst) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (dst == NULL)
		return (NULL);
	while (s1[x])
	{
		dst[x] = s1[x];
		x++;
	}
	while (s2[y])
	{
		dst[x] = s2[y];
		x++;
		y++;
	}
	dst[x] = '\0';
	return (dst);
}

char	*ft_itoa(int n)
{
	int		aux;
	int		len;
	char	*str;

	aux = n;
	len = 2;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[len] = '\0';
	if (aux / 16 < 1)
		str[0] = '0';
	while (len--)
	{
		if ((n % 16) < 10)
			str[len] = n % 16 + '0';
		if ((n % 16) > 9)
			str[len] = n % 16 + 'W';
		n = n / 16;
	}
	return (str);
}

char	*hv_rgb2hex(int r, int g, int b)
{
	char	*rgb;

	rgb = "#";
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		return ("Error: Introduce numeros >= 0 && <=255.\n");
	rgb = ft_strjoin(rgb, ft_itoa(r));
	rgb = ft_strjoin(rgb, ft_itoa(g));
	rgb = ft_strjoin(rgb, ft_itoa(b));
	return (rgb);
}
