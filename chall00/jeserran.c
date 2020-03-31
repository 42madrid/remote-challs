/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jeserran.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeserran <jeserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 10:47:54 by jeserran          #+#    #+#             */
/*   Updated: 2020/03/31 11:20:31 by jeserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void		ft_hexadecimal(int num, char *result, int *i)
{
	char	*base;
	int		a;

	base = "0123456789abcdef";
	if (num >= 16)
	{
		a = 1;
		ft_hexadecimal((num / 16), result, i);
	}
	if (num < 16 && a)
	{
		result[*i] = '0';
		(*i)++;
	}
	result[*i] = base[num % 16];
	(*i)++;
}

char	*hv_rgb2hex(int r, int g, int b)
{
	char	*rgb;
    int     i;

	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return ("Error de entrada");
	if (!(rgb = (char *)malloc(sizeof(char) * 2)))
		return ("Error de memoria");
    rgb[0] = '#';
	i = 1;
	ft_hexadecimal(r, rgb, &i);
	ft_hexadecimal(g, rgb, &i);
	ft_hexadecimal(b, rgb, &i);
	rgb[i++] = '\0';
	return (rgb);
}
