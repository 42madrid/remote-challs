/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jbaringo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 19:27:18 by marvin            #+#    #+#             */
/*   Updated: 2020/03/30 19:27:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char		*join(int j, char *rgb, char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		rgb[j] = s[i];
		i++;
		j++;
	}
	return (rgb);
}

char		*ft_strjoin(char *r, char *g, char *b)
{
	int		i;
	char	*rgb;

	if (!(rgb = malloc(sizeof(char) * 7)))
		return (NULL);
	rgb[0] = '#';
	join(1, rgb, r);
	join(3, rgb, g);
	join(4, rgb, b);
	rgb[6] = '\0';
	return (rgb);
}

char		*hexadecimal(int n)
{
	char	*hex;
	char	*base = "0123456789ABCDEF";

	if (!(hex = malloc(sizeof(char) * 3)))
		return (NULL);
	hex[0] = base[n / 16];
	hex[1] = base[n % 16];
	hex[2] = '\0';
	return (hex);
}

char		*hv_rgb2hex(int r, int g, int b)
{
	char	*hex;
	char	*red;
	char	*green;
	char	*blue;

	if (r >= 0 && r <= 255 && g >= 0 && g <= 255 &&
		b >= 0 && b <= 255)
	{
		red = hexadecimal(r);
		green = hexadecimal(g);
		blue = hexadecimal(b);
		hex = ft_strjoin(red, green, blue);
		return (hex);
	}
	return ("(null)");
}
