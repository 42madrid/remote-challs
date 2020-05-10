/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estina.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 19:45:09 by estina            #+#    #+#             */
/*   Updated: 2020/05/10 15:34:40 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int		check_input(char *seconds)
{
	int		i;

	if (!*seconds)
		return (0);
	i = strlen(seconds) - 1;
	while (isspace(seconds[i]))
		i--;
	while (i >= 0)
	{
		if (!isdigit(seconds[i]))
			return (0);
		i--;
	}
	return (1);
}

unsigned long long	transform_time(void *y, int z)
{
	unsigned long long	x;

	x = *((unsigned long long *)y) / z;
	*((unsigned long long *)y) %= z;
	return (x);
}

void	append_time(unsigned long long time, char *one, char *more, char *n, char **str)
{
	char	buf[13];

	if (time)
	{
		sprintf(buf, "%llu", time);
		*str = strcat(*str, buf);
		*str = strcat(*str, time == 1 ? one : more);
		if (--(*n) > 1)
			*str = strcat(*str, ", ");
		else if (*n == 1)
			*str = strcat(*str, " and ");
	}
}

char	*human_time(unsigned long long seconds)
{
	unsigned long long	years;
	short				days;
	char				hours, mins;
	char				*new;
	char				number_times;

	years = transform_time(&seconds, 31536000);
	days = transform_time(&seconds, 86400);
	hours = transform_time(&seconds, 3600);
	mins = transform_time(&seconds, 60);
	number_times = (years ? 1 : 0) + (days ? 1 : 0) + (hours ? 1 : 0) +
					(mins ? 1 : 0) + (seconds ? 1 : 0);
	if (!(new = calloc(65, sizeof(char))))
		return (NULL);
	append_time(years, " year", " years", &number_times, &new);
	append_time(days, " day", " days", &number_times, &new);
	append_time(hours, " hour", " hours", &number_times, &new);
	append_time(mins, " minute", " minutes", &number_times, &new);
	append_time(seconds, " second", " seconds", &number_times, &new);
	return (new);
}

char	*ft_format_duration(char *seconds)
{
	unsigned long long	number;

	while (isspace(*seconds))
		seconds++;
	if (!check_input(seconds))
		return ("Invalid input.");
	if (!(number = strtoull(seconds, NULL, 10)))
		return ("now");
	return (human_time(number));
}
