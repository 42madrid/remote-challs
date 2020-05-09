/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edramire.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 15:19:48 by edramire          #+#    #+#             */
/*   Updated: 2020/05/09 16:59:3 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>

#define MAX_SECONDS 10000000000000000000ULL
#define DAYS_SECONDS 86400
#define HOURS_SECONDS 3600
#define YEAR_SECONDS 31536000


typedef struct	s_time
{
	unsigned long long int	years;
	unsigned int			days;
	unsigned int			hours;
	unsigned int			minutes;
	unsigned int			seconds;
	unsigned int			flags;
}				t_time;

static char		ft_stc_validate_duration(char *seconds)
{
	
	if (seconds == NULL || strlen(seconds) == 0)
		return (1);
	while (*seconds != '\0')
	{
		if (isdigit(*seconds) > 0)
			break;
		else if (*seconds++ != ' ')
			return (1);
	}
	while (*seconds != '\0')
	{
		if (*seconds == ' ')
			break;
		else if (isdigit(*seconds++) == 0)
			return (1);
	}
	while (*seconds != '\0')
	{
		if (*seconds++ != ' ')
			return (1);
	}
	return (0);
}

static unsigned long long int	ft_stc_convert_number(char *seconds)
{
	unsigned long long int	number;
	int						len;

	number = 0;
	len = 0;
	while (*seconds != '\0' && isdigit(*seconds) == 0)
		++seconds;
	while (*seconds != '\0' && isdigit(*seconds) > 0 && len < 20 )
	{
		number = number * 10 + (*seconds++ - '0');
		len += len == 0 && number == 0 ? 0 : 1;
	}
	if (len == 20 && (number != MAX_SECONDS || isdigit(*seconds) > 0))
		return (ULLONG_MAX);
	return (number);
}

static t_time	ft_stc_set_flags(t_time time)
{
	if (time.years > 0)
		time.flags |= 0x10;
	if (time.days > 0)
		time.flags |= 0x8;
	if (time.hours > 0)
		time.flags |= 0x4;
	if (time.minutes > 0)
		time.flags |= 0x2;
	if (time.seconds > 0)
		time.flags |= 0x1;
	return (time);
}
static void		ft_stc_format_time(char *str, char const *txt, int prev,
					int next, unsigned long long int time)
{
	char	*aux;

	if (time == 0)
		return ;
	if (prev > 0)
	{
		aux = strdup(str);
		if (aux == NULL)
			return ;
		sprintf(str, "%s%s %llu %s%s", aux, next > 0 ? "," : " and", time, 
				txt, time > 1 ? "s" : "");
		free(aux);
	}
	else
		sprintf(str, "%llu %s%s", time, txt, time > 1 ? "s" : "");
}

static t_time	ft_st_calculate_seconds(t_time time)
{
	time.days = time.years % YEAR_SECONDS;
	time.years /= YEAR_SECONDS;
	time.hours = time.days % DAYS_SECONDS;
	time.days /= DAYS_SECONDS;
	time.minutes = time.hours % HOURS_SECONDS;
	time.hours /= HOURS_SECONDS;
	time.seconds = time.minutes % 60;
	time.minutes /= 60;
	return (time);
}

char 	*ft_format_duration(char *seconds)
{
	t_time	my_time;
	char	*str;

	if (ft_stc_validate_duration(seconds) > 0)
		return strdup("Invalid input.");
	bzero(&my_time, sizeof(t_time));
	my_time.years = ft_stc_convert_number(seconds);
	if (my_time.years == ULLONG_MAX)
		return strdup("Invalid input.");
	my_time = ft_st_calculate_seconds(my_time);
	my_time = ft_stc_set_flags(my_time);
	if (my_time.flags == 0)
		return (strdup("now"));
	str = malloc(256 * sizeof(char));
	if (str == NULL)
		return (NULL);
	bzero(str, sizeof(char) * 256);
	ft_stc_format_time(str, "year", 0, 0, my_time.years);
	ft_stc_format_time(str, "day", my_time.flags & 0x10, my_time.flags & 0x7,
		my_time.days);
	ft_stc_format_time(str, "hour", my_time.flags & 0x18, my_time.flags & 0x3,
		my_time.hours);
	ft_stc_format_time(str, "minute", my_time.flags & 0x1C, my_time.flags & 0x1,
		my_time.minutes);
	ft_stc_format_time(str, "second", my_time.flags & 0x1E, 0, my_time.seconds);
	return str;
}
