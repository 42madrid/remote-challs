#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <errno.h>
#define MAX_SECONDS 10000000000000000000UL
#define YEAR 31536000UL
#define DAY 86400UL
#define HOUR 3600UL
#define MINUTE 60UL
#define ARRAY_SIZE 5

static const char		*unit_time[ARRAY_SIZE] = {"year", "day", "hour", "minute", "second"};

static char				*walk_space(char *seconds)
{
	while (*seconds && *seconds == ' ')
		seconds++;
	return (seconds);
}

static unsigned long	set_error(unsigned long ret, int *err)
{
	*err = 1;
	return (ret);
}

static unsigned long	get_seconds(char *seconds, int *err)
{
	char			*end;
	unsigned long	ul_seconds;

	*err = 0;
	seconds = walk_space(seconds);
	if (*seconds == '\0' || isdigit(*seconds) == 0)
		return (set_error(0, err));
	errno = 0;
	ul_seconds = strtoul(seconds, &end, 10);
	if (errno == ERANGE)
		return (set_error(0, err));
	if (*end != '\0')
	{
		end = walk_space(end);
		if (*end != '\0')
			return (set_error(0, err));
	}
	return (ul_seconds);
}

static unsigned			unit_length(unsigned long unit)
{
	unsigned	length = 0;

	while (unit > 0)
	{
		length++;
		unit /= 10;
	}
	return (length);
}

static unsigned			total_length(unsigned long time[], unsigned *positive)
{
	unsigned				total_len = 0;

	*positive = 0;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (time[i] > 0)
		{
			(*positive)++;
			total_len += unit_length(time[i]) + 1 + strlen(unit_time[i]) + (time[i] > 1);
		}
	}
	return (total_len);
}

static unsigned			separator_length(unsigned positive)
{
	if (positive == 1)
		return (0);
	return (strlen(", ") * (positive - 2) + strlen(" and "));
}

static char				*free_fmt(char *format)
{
	if (format != NULL)
		free(format);
	return (format = NULL);
}

static char				*fill_time(char *format, unsigned long *time, unsigned positive, unsigned length)
{
	int					idx = 0;
	int					ret;
	
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (time[i] > 0)
		{
			ret = snprintf(&format[idx], length, "%lu %s%.*s", time[i], unit_time[i] , time[i] > 1, "s");
			if (ret < 0)
				return (free_fmt(format));
			idx += ret;
			length -=ret;
			if (positive >= 2)
			{
				ret = snprintf(&format[idx] , length, positive > 2 ? ", " : " and ");
				if (ret < 0)
					return (free_fmt(format));
				idx += ret;
				length -= ret;
			}
			positive--;
		}
	}
	return (format);
}

static char				*format_time(unsigned long *time)
{
	unsigned			length;
	unsigned			positive;
	char				*format;

	length = total_length(time, &positive);
	length += separator_length(positive);
	format = malloc(length + 1);
	if (format == NULL)
		return (NULL);
	return (fill_time(format, time, positive, length + 1));
}

static char				*create_date(unsigned long seconds)
{
	enum			e_time{YEARS,DAYS,HOURS,MINUTES,SECONDS};
	unsigned long	time[ARRAY_SIZE];

	time[YEARS] = seconds / YEAR;
	seconds %= YEAR;
	time[DAYS] = seconds / DAY;
	seconds %= DAY;
	time[HOURS] = seconds / HOUR;
	seconds %= HOUR;
	time[MINUTES] = seconds / MINUTE;
	time[SECONDS] = seconds % MINUTE;
	return (format_time(time));
}

char					*ft_format_duration(char *seconds)
{
	unsigned long	ul_seconds;
	int				err;

	if (*seconds == '\0')
		return (strdup("Invalid input."));
	ul_seconds = get_seconds(seconds, &err);
	if (err == 1 || ul_seconds > MAX_SECONDS)
		return (strdup("Invalid input."));
	if (ul_seconds == 0)
		return (strdup("now"));
	return (create_date(ul_seconds));
}
