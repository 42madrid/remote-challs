/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estina.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 19:45:09 by estina            #+#    #+#             */
/*   Updated: 2020/05/09 22:36:47 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int		check_input(char *seconds)
{
	char	*aux;
	int		space_after_digit;
	int		found_digits;

	if (!*seconds || ((aux = strchr(seconds, '+')) && !isspace(aux[1])))
		return (0);
	space_after_digit = 0;
	found_digits = 0;
	while (*seconds)
	{
		if (isspace(*seconds) && found_digits)
			space_after_digit = 1;
		else if (isdigit(*seconds))
		{
			if (space_after_digit)
				return (0);
			found_digits = 1;
		}
		else if (!isspace(*seconds) && *seconds != '+')
			return (0);
		seconds++;
	}
	return (1);
}

void	transform_time(unsigned long long *x, unsigned long long *y, int z)
{
	*x = *y / z;
	*y %= z;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i, j;

	i = s1 ? strlen(s1) : 0;
	j = strlen(s2);
	if (!(str = malloc(i + j + 1)))
		return (NULL);
	str = s1 ? strcpy(str, s1) : str;
	str = strcat(str, s2);
	return (str);
}

void	count_times(unsigned long long x, char *number_times)
{
	if (x)
		(*number_times)++;
}

char	*append_time(unsigned long long time, char *one, char *more, char *n, char *str)
{
	char	buf[30];

	if (time)
	{
		sprintf(buf, "%llu", time);
		str = ft_strjoin(str, buf);
		str = ft_strjoin(str, time == 1 ? one : more);
		if (--(*n) > 1)
			str = ft_strjoin(str, ", ");
		else if (*n == 1)
			str = ft_strjoin(str, " and ");
	}
	return (str);
}

char	*human_time(unsigned long long seconds)
{
	unsigned long long	years, days, hours, mins;
	char				*new;
	char				number_times;

	transform_time(&years, &seconds, 31536000);
	transform_time(&days, &seconds, 86400);
	transform_time(&hours, &seconds, 3600);
	transform_time(&mins, &seconds, 60);
	number_times = 0;
	count_times(years, &number_times);
	count_times(days, &number_times);
	count_times(hours, &number_times);
	count_times(mins, &number_times);
	count_times(seconds, &number_times);
	new = NULL;
	new = append_time(years, " year", " years", &number_times, new);
	new = append_time(days, " day", " days", &number_times, new);
	new = append_time(hours, " hour", " hours", &number_times, new);
	new = append_time(mins, " minute", " minutes", &number_times, new);
	new = append_time(seconds, " second", " seconds", &number_times, new);
	return (new);
}

char	*ft_format_duration(char *seconds)
{
	unsigned long long	number;

	if (!check_input(seconds))
		return ("Invalid input.");
	while (!isdigit(*seconds))
		seconds++;
	number = strtoull(seconds, NULL, 10);
	if (!number)
		return ("now");
	return (human_time(strtoull(seconds, NULL, 10)));
}
