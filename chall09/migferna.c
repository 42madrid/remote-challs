#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

unsigned long long parser(unsigned long long seconds, unsigned long long d)
{
	return seconds/d;
}

char *generate_output(unsigned long long years, unsigned long long months, 
unsigned long long days, unsigned long long hours, unsigned long long minutes,
 unsigned long long seconds, int count_units)
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
	minutes_count = minutes > 1 ? "minutes" : "minute";
	seconds_count = seconds > 1 ? "seconds" : "second";
	hours_count = hours > 1 ? "hours" : "hour";
	years_count = years > 1 ? "years" : "year";
	months_count = months > 1 ? "months" : "month";
	days_count = days > 1 ? "days" : "day";

	if (years)
	{
		sprintf(tmp, "%llu %s", years, years_count);
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
	if (days)
	{
		sprintf(tmp, "%llu %s", days, days_count);
		strcat(format, tmp);
		if (count_units > 2)
		{
			strcat(format, ", ");
			count_units--;
		}
		else if (count_units == 2)
			strcat(format, " and ");
	}
	if (hours)
	{
		sprintf(tmp, "%llu %s", hours, hours_count);
		strcat(format, tmp);
		if (count_units > 2)
		{
			strcat(format, ", ");
			count_units--;
		}
		else if (count_units == 2)
			strcat(format, " and ");
	}
	if (minutes)
	{
		sprintf(tmp, "%llu %s", minutes, minutes_count);
		strcat(format, tmp);
		if (count_units > 2)
		{
			strcat(format, ", ");
			count_units--;
		}
		else if (count_units == 2)
			strcat(format, " and ");
	}
	if (seconds)
	{
		sprintf(tmp, "%llu %s", seconds, seconds_count);
		strcat(format, tmp);
	}

	return (format);
}

char *parser_format(char *s)
{
	char *out;

	unsigned long long seconds = strtoull(s, NULL, 10);
	unsigned long long minutes = 0;
	unsigned long long hours = 0;
	unsigned long long days = 0;
	unsigned long long months = 0;
	unsigned long long years = 0;
	int count_units = 0;
	
	if (seconds == 0) {
		return ("now");
	}
	if (seconds > 31536000)
	{
		years = parser(seconds, 31536000);
		seconds = seconds % 31536000;
		count_units++;
	}
	if (seconds > 86400)
	{
		days = parser(seconds, 86400);
		seconds = seconds % 86400;
		count_units++;
	}
	if (seconds > 3600)
	{
		hours = parser(seconds, 3600);
		seconds = seconds % 3600;
		count_units++;
	}
	if (seconds > 60)
	{
		minutes = parser(seconds, 60);
		seconds = seconds % 60;
		count_units++;
	}
	if (seconds > 0)
		count_units++;
	
	out = generate_output(years, months, days, hours, minutes, seconds, count_units);
	return (out);
}

int	is_valid(char *seconds)
{
	char *ptr = strtok(strdup(seconds), " ");
	int num_digits = 0;
	while (ptr)
	{
		if (isdigit(*ptr))
		{
			num_digits++;
			ptr = strtok(NULL, " ");
		}
		else
			return 0;
	}
	if (num_digits > 1)
		return 0;
	return (1);
}

char *ft_format_duration(char *seconds)
{
	char *out;
	if (*seconds && is_valid(seconds))
		out = parser_format(seconds);
	else
		out = "Invalid input.";
	return out;
}
