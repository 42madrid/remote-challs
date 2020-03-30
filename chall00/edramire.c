/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edramire.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 23:29:35 by edramire          #+#    #+#             */
/*   Updated: 2020/03/31 00:01:45 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*hv_rgb2hex(int r, int g, int b)
{
	char	*str;
	int		digit;

	if (r < 0 || g < 0 || b < 0)
		return (NULL);
	str = malloc(sizeof(char) * 8);
	if (str == NULL)
		return (NULL);
	*str = '#';
	digit = r >> 4 & 0xF;
	str[1] = digit + (digit > 9 ? 'W' : '0');
	digit = r & 0xF; 
	str[2] = digit + (digit > 9 ? 'W' : '0');
	digit = g >> 4 & 0xF;
	str[3] = digit + (digit > 9 ? 'W' : '0');
	digit = g & 0xF; 
	str[4] = digit + (digit > 9 ? 'W' : '0');
	digit = b >> 4 & 0xF;
	str[5] = digit + (digit > 9 ? 'W' : '0');
	digit = b & 0xF; 
	str[6] = digit + (digit > 9 ? 'W' : '0');
	str[7] = '\0';
	return (str);
}
