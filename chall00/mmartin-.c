/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmartin-.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 20:29:48 by mmartin-          #+#    #+#             */
/*   Updated: 2020/03/30 22:33:30 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

/*
**	DESCRIPTION
**		Converts input RGB to hexadecimal base
**	HOW ITS DONE
**		(Compiled using clang for Ubuntu WSL)
**
**		Checks for invalid input, when verified converts it to hex
**		using sprintf and shifting bits to place them in the right order
**			r: 16 g: 16 b: 16
**			00000000000100000001000000010000
**		the real number in this case is 1052688, converted to hex is 101010.
**		I use the precision flag in sprintf to grant the 1st character, in some
**		cases (where nums are low) it would be omitted.
**		Finally the string is duplicated in heap and returned
**	RETURN VALUES
**		NULL if r, g, b is invalid or there was an error duplicating the string
*/

char	*hv_rgb2hex(int r, int g, int b)
{
	char			*str;

	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (NULL);
	sprintf(str, "#%.6x", r << 16 | g << 8 | b);
	return ((char *)strdup(str));
}
