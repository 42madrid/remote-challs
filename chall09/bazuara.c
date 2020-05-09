/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bazuara.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 14:07:16 by bazuara           #+#    #+#             */
/*   Updated: 2020/05/09 15:42:44 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_format_duration(char *seconds)
{
	int 	sc;
	int		mn;
	int		hr;
	int 	dy;
	int 	yr;
	char	*result;

	sc = atoi(seconds);
	mn = sc / 60;
	hr = mn / 60;
	dy = hr / 24;
	yr = dy / 365;
	//printf("respre: s:%i m:%i, h:%i, d:%i,  y:%i\n", sc, mn, hr, dy, yr);
	sc = sc % 60;
	mn = mn % 60;
	hr = hr % 24;
	dy = dy % 365;
	//printf("result: s:%i m:%i, h:%i, d:%i,  y:%i\n", sc, mn, hr, dy, yr);
	result = calloc(999, sizeof(char));
	sprintf(result, "s:%i m:%i, h:%i, d:%i, y:%i\n", sc, mn, hr, dy, yr);
	//strcpy(seconds, sprintf(seconds, "s:%i m:%i, h:%i, d:%i,  y:%i\n", sc, mn, hr, dy, yr));
	return (result);
}

int	main(void)
{
	//ft_format_duration("60");
	printf("%s",ft_format_duration("31536000"));
}
