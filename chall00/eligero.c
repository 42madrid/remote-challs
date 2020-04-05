/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eligero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eligero <eligero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 19:50:31 by eligero           #+#    #+#             */
/*   Updated: 2020/03/31 00:44:49 by eligero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** Ojo de Sauron (Chall00) / RGB to Hexadecimal
**
** Solved with embedded system mindset.
** Integer focus range is [0, 255], it means 2 ascii characters. That is the
** output string always will have 7 characters ('#' + 3 x 2 character), so I
** created dinamically an array of 8 positions, in order to null terminating the
** string.
** I did a fast bit-level algorithm to translate number to hex character.
** By right displacing four times, at bit level, de variable is the same as
** divide by 2^4 = 16 the variable, but faster, e.g from 0xAF i get 0xA.
** By doing the bit level AND with 0x0F i get the remainder, e.g from 0xAF
** i get 0xF. In order to store any hex digit 4 bits are needed.
** Finally returning the dynamic allocated string.
*/

char			*hv_rgb2hex(int r, int g, int b)
{
	static char	digs[] = "0123456789abcdef";
	char		*s;
	int			i;
	int			color;

	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (NULL);
	if ((s = (char *)malloc(sizeof(char) * 8)) == NULL)
		return (NULL);
	*s++ = '#';
	i = 0;
	color = r;
	while (i < 3)
	{
		*s++ = digs[color >> 4];
		*s++ = digs[color & 0x0F];
		color = (i == 0) ? g : b;
		i++;
	}
	*s = '\0';
	return (s - (7 * sizeof(char)));
}