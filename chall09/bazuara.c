/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bazuara.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 14:07:16 by bazuara           #+#    #+#             */
/*   Updated: 2020/05/09 15:26:12 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_format_duration(char *seconds)
{
	int sc;
	int	mn;
	int	hr;
	int dy;
	int yr;

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
	return ("return");
}

int	main(void)
{
	//ft_format_duration("60");
	ft_format_duration("31536000");
}
