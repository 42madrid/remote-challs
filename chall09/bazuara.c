/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bazuara.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 14:07:16 by bazuara           #+#    #+#             */
/*   Updated: 2020/05/09 16:38:58 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_format_duration(char *seconds)
{
	int 	sc;
	int		mn;
	int		hr;
	int 	dy;
	int 	yr;
	char	*result;

	sc = atoi(seconds);
	if (sc == 0)
	{
		if (strcmp(seconds, "0") == 0)
			return ("now");
		else
			return ("Invalid input.");
	}
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
	result = calloc(200, sizeof(char));
	sprintf(result, "s:%i m:%i, h:%i, d:%i, y:%i\n", sc, mn, hr, dy, yr);
	//strcpy(seconds, sprintf(seconds, "s:%i m:%i, h:%i, d:%i,  y:%i\n", sc, mn, hr, dy, yr));
	return (result);
}

int	main(void)
{
	//ft_format_duration("60");
//	printf("%s",ft_format_duration(" - - - - - - 42"));
	printf("%d\n", atoi("62")); //62
	printf("%d\n", atoi("3662")); //3662
	printf("%d\n", atoi("0")); //0 
	printf("%d\n", atoi("-1")); //-1
	printf("%d\n", atoi("LOL42LOL")); //0 
	printf("%d\n", atoi("")); //0
	printf("%d\n", atoi("2175984000")); //-2118983296 
	printf("%d\n", atoi("   42")); // 42
	printf("%d\n", atoi(" +  42")); // 0
	printf("%d\n", atoi("   42 1")); //42
	printf("%d\n", atoi("42 1")); //42
	printf("%d\n", atoi("42   "));  //42
	printf("%d\n", atoi("+42")); //42
	printf("%d\n", atoi("--42")); //0
	printf("%d\n", atoi("---42")); //0
	printf("%d\n", atoi(" - - - - - - 42")); //0
	printf("%d\n", atoi("0042")); //42
	printf("%d\n", atoi("0 42")); //0
}
