#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef	struct			s_time
{
	unsigned long long	years;
	unsigned long long	days;
	unsigned long long	hours;
	unsigned long long	minutes;
	unsigned long long	seconds;
}						t_time;

unsigned long long parser(unsigned long long seconds, unsigned long long d)
{
	return seconds/d;
}

char *generate_output(t_time time, int count_units)
{
	char *format = NULL;
	char tmp[100];
	char *minutes_count;
	char *seconds_count;
	char *hours_count;
	char *years_count;
	char *months_count;
	char *days_count;

	if (!(format = malloc(500)))
		return NULL;
	minutes_count = time.minutes > 1 ? "minutes" : "minute";
	seconds_count = time.seconds > 1 ? "seconds" : "second";
	hours_count = time.hours > 1 ? "hours" : "hour";
	years_count = time.years > 1 ? "years" : "year";
	days_count = time.days > 1 ? "days" : "day";

	if (time.years)
	{
		sprintf(tmp, "%llu %s", time.years, years_count);
		strcat(format, tmp);
		if (count_units > 2)
		{
			strcat(format, ", ");
			count_units--;
		}
		else if (count_units == 2)
		{
			strcat(format, " and ");
		}
	}
	if (time.days)
	{
		sprintf(tmp, "%llu %s", time.days, days_count);
		strcat(format, tmp);
		if (count_units > 2)
		{
			strcat(format, ", ");
			count_units--;
		}
		else if (count_units == 2)
			strcat(format, " and ");
	}
	if (time.hours)
	{
		sprintf(tmp, "%llu %s", time.hours, hours_count);
		strcat(format, tmp);
		if (count_units > 2)
		{
			strcat(format, ", ");
			count_units--;
		}
		else if (count_units == 2)
			strcat(format, " and ");
	}
	if (time.minutes)
	{
		sprintf(tmp, "%llu %s", time.minutes, minutes_count);
		strcat(format, tmp);
		if (count_units > 2)
		{
			strcat(format, ", ");
			count_units--;
		}
		else if (count_units == 2)
			strcat(format, " and ");
	}
	if (time.seconds)
	{
		sprintf(tmp, "%llu %s", time.seconds, seconds_count);
		strcat(format, tmp);
	}

	return (format);
}

char *parser_format(char *s)
{
	char *out;
	int count_units = 0;

	t_time time;
	time.seconds = strtoull(s, NULL, 10);
	time.minutes = 0;
	time.hours = 0;
	time.days = 0;
	time.years = 0;
		
	if (time.seconds == 0) {
		return ("now");
	}
	if (time.seconds > 31536000)
	{
		time.years = parser(time.seconds, 31536000);
		time.seconds = time.seconds % 31536000;
		count_units++;
	}
	if (time.seconds > 86400)
	{
		time.days = parser(time.seconds, 86400);
		time.seconds = time.seconds % 86400;
		count_units++;
	}
	if (time.seconds > 3600)
	{
		time.hours = parser(time.seconds, 3600);
		time.seconds = time.seconds % 3600;
		count_units++;
	}
	if (time.seconds > 60)
	{
		time.minutes = parser(time.seconds, 60);
		time.seconds = time.seconds % 60;
		count_units++;
	}
	if (time.seconds > 0)
		count_units++;
	
	out = generate_output(time, count_units);
	return (out);
}

int	is_valid(char *seconds)
{
	char *ptr = strtok(strdup(seconds), " ");
	int num_digits = 0;
	while (ptr)
	{
		while (*ptr)
		{
			if (!isdigit(*ptr))
				return (0);
			ptr++;
		}
		num_digits++;
		ptr = strtok(NULL, " ");
	}
	if (num_digits > 1)
		return 0;
	return (1);
}

char *ft_format_duration(char *seconds)
{
	char *out;
	while (isspace(*seconds))
		seconds++;

	if (*seconds && is_valid(seconds))
		out = parser_format(seconds);
	else
		out = "Invalid input.";
	return out;
}
