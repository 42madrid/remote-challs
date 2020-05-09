/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bazuara.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 14:07:16 by bazuara           #+#    #+#             */
/*   Updated: 2020/05/09 20:13:40 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	total;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !s2)
		return (0);
	total = strlen(s1) + strlen(s2);
	if ((new = malloc(((total) * sizeof(char)) + 1)))
	{
		while (i < strlen(s1))
		{
			new[i] = s1[i];
			i++;
		}
		j = 0;
		while (j < strlen(s2))
		{
			new[i + j] = s2[j];
			j++;
		}
		new[i + j] = '\0';
	}
	return (new);
}

char		*ft_strjoin_free(char *str1, char *str2, int i)
{
	char *temp;

	temp = ft_strjoin(str1, str2);
	if (i == 1)
		free(str1);
	else if (i == 2)
		free(str2);
	if (i == 3)
	{
		free(str1);
		free(str2);
	}
	return (temp);
}

char	*ft_format_duration(char *seconds)
{
	int 	sc;
	int		mn;
	int		hr;
	int		dy;
	int		yr;
	char	*result;
	char	temp[50];

	sc = atoi(seconds);
	if (sc <= 0)
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
	//printf("respre: s:%d m:%d, h:%d, d:%d,  y:%d\n", sc, mn, hr, dy, yr);
	sc = sc % 60;
	mn = mn % 60;
	hr = hr % 24;
	dy = dy % 365;
	sprintf(temp, "%d", yr);
	if (yr != 0)
		result = ft_strjoin_free( temp, " años, ", 0);
	sprintf(temp, "%d", dy);
	if (dy != 0)
		result = ft_strjoin_free( result, ft_strjoin_free( temp, " días, ", 0), 3);
	sprintf(temp, "%d", hr);
	if (hr != 0)
		result = ft_strjoin_free( result, ft_strjoin_free( temp, " horas, ", 0), 3);
	sprintf(temp, "%d", mn);
	if (mn != 0)
		result = ft_strjoin_free( result, ft_strjoin_free( temp, " minutos y ", 0), 3);
	sprintf(temp, "%d", sc);
	if (sc != 0)
		result = ft_strjoin_free( result, ft_strjoin_free( temp, " segundos.", 0), 3);
	return (result);
}

int	main(void)
{
	//ft_format_duration("60");
	printf("%s",ft_format_duration("31536001"));
/*	printf("%d\n", atoi("62")); //62
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
	printf("%d\n", atoi("0 42")); //0*/
	system("leaks -fullContent  a.out");
}
