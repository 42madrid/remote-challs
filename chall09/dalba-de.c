#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct          	s_time
{
  	unsigned long long		year;
	unsigned long long		day;
	unsigned long long		hour;
	unsigned long long		minute;
	unsigned long long 		second;
	char					*str;
	char					*cyear;
	char					*cday;
	char					*chour;
	char					*cminute;
	char					*csecond;
}                       	t_time;

int					check_line(char *str)
{
	int i;

	i = 0;
  	if (str[i] == '\0')
	return (-1);
	while (str[i])
	{
		if (str[i] == ' ' || (str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			return (-1);
	}
	return (0);
}

unsigned long long	ft_atoi(char *line, int *i)
{
	unsigned long long	num;

	num = 0;
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		num = num * 10 + (line[*i] - 48);
		(*i)++;
	}
	return (num);
}

void        fill_second(t_time *t)
{
	char *gap;

	gap = "";
	if (t->year > 0 || t->day > 0 || t->hour > 0 ||t->minute > 0)
		gap = " and ";
	else
		gap = "";
  	t->csecond = malloc(sizeof(t->second) + 9 * sizeof(char));
	if (t->second == 0)
		sprintf(t->csecond, "");
	else if (t->second == 1)
		sprintf(t->csecond, "%s%llu second", gap, t->second);
	else
		sprintf(t->csecond, "%s%llu seconds", gap, t->second);
}

void      fill_minute(t_time *t)
{
	char *gap;

	gap = "";
	if ((t->year > 0 || t->day > 0 || t->hour > 0) && t->second == 0)
		gap = " and ";
	else if ((t->year > 0 || t->day > 0 || t->hour > 0) && t->second > 0)
		gap = " , ";
	else if (t->year == 0 && t->hour == 0 && t->minute == 0)
		gap = "";
  	t->cminute = malloc(sizeof(t->minute) + 8 * sizeof(char));
	if (t->minute == 0)
		sprintf(t->cminute, "");
	else if (t->minute == 1)
		sprintf(t->cminute, "%s%llu minute", gap, t->minute);
	else
		sprintf(t->cminute, "%s%llu minutes", gap, t->minute);
}

void      fill_hour(t_time *t)
{
	char *gap;

	gap = "";
	if ((t->year > 0 || t->day > 0) && (t->second == 0 && t->minute == 0))
		gap = " and ";
	else if ((t->year > 0 || t->day > 0) && (t->second > 0 || t->minute > 0))
		gap = " , ";
	else if (t->year == 0 && t->hour == 0)
		gap = "";
  	t->chour = malloc(sizeof(t->hour) + 6 * sizeof(char));
	if (t->hour == 0)
		sprintf(t->chour, "");
	else if (t->hour == 1)
		sprintf(t->chour, "%s%llu hour", gap, t->hour);
	else
		sprintf(t->chour, "%s%llu hours", gap, t->hour);
}

void      fill_day(t_time *t)
{
  	char *gap;

  	gap = "";
  	if (t->year > 0 && (t->second == 0 && t->minute == 0 && t->hour == 0))
		gap = " and ";
  	else if (t->year > 0 && (t->second > 0 || t->minute > 0 || t->hour > 0))
		gap = " , ";
  	else if (t->year == 0)
		gap = "";
  	t->cday = malloc(sizeof(t->day) + 4 * sizeof(char));
	if (t->day == 0)
		sprintf(t->cday, "");
	else if (t->day == 1)
		sprintf(t->cday, "%s%llu day", gap, t->day);
	else
		sprintf(t->cday, "%s%llu days", gap, t->day);
}

void      fill_year(t_time *t)
{
  	t->cyear = malloc(sizeof(t->year) + 6 * sizeof(char));
	if (t->year == 0)
		sprintf(t->cyear, "");
	else if (t->year == 1)
		sprintf(t->cyear, "%llu year", t->year);
	else
		sprintf(t->cyear, "%llu years", t->year);
}

char				*fill_time(unsigned long long num)
{
	t_time  t;

	t.str = malloc(sizeof(num) + 45 * sizeof(char));
	t.second = num % 60;
	num /= 60;
	t.minute = num % 60;
	num /= 60;
	t.hour = num % 60;
	num /= 24;
	t.day = num % 365;
	t.year = num / 365;
	fill_second(&t);
	fill_minute(&t);
	fill_hour(&t);
	fill_day(&t);
	fill_year(&t); 
	sprintf(t.str, "%s%s%s%s%s", t.cyear, t.cday, t.chour, t.cminute, t.csecond);
	return (t.str);
}

char				*ft_format_duration(char *seconds)
{
	int					i;
	unsigned long long	num;
	char				*ret;

	if (check_line(seconds))
		return ("Invalid input");
	i = 0;
	if (seconds[i] == '0' && seconds[i + 1] == '\0')
		return ("now");
	while (seconds[i])
	{
		while (seconds[i] == ' ')
			i++;
		if (seconds[i] >= '0' && seconds[i] <= '9')
		{
			num = ft_atoi(seconds, &i);
			while (seconds[i])
			{
				if (seconds[i] != ' ')
					return ("Invalid input");
				i++;
			}
		}
	}
	ret = fill_time(num);
	return (ret);
}
