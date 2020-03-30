/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darodrig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <darodrig@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 14:35:58 by darodrig          #+#    #+#             */
/*   Updated: 2020/03/30 14:35:58 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*hv_rgb2hex(int r, int g, int b)
{
	char result[7];
	char caps[] = "0123456789abcdef";
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		return (strdup("000000"));
	
	result[0] = caps[r / 16];
	result[1] = caps[r % 16];
	result[2] = caps[g / 16];
	result[3] = caps[g % 16];
	result[4] = caps[b / 16];
	result[5] = caps[b % 16];
	result[6] = 0;
	return (strdup(result));
}
