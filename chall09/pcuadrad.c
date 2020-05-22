#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SECOND 1
#define MINUTE 60
#define HOUR 3600
#define DAY 86400
#define YEAR 31536000
#define COMMA ", "
#define AND " and "

static char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*tab;

	count = -1;
	if (!s)
		return (NULL);
	if (strlen(s) < start)
		return (strdup(""));
	size = strlen(s + start);
	if (size < len)
		len = size;
	if (!(tab = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (++count < len)
		tab[count] = s[start + count];
	tab[count] = '\0';
	return (tab);
}

static int		isinset(char c, char const *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char     *ft_strtrim(char const *s1, char const *set)
{
	unsigned int		start;
	unsigned int		end;

	if (!s1)
		return (NULL);
	start = 0;
	end = (int)strlen(s1) - 1;
	while (isinset(s1[start], set) && s1[start])
		start++;
	if (s1[start] == '\0')
		return (strdup(""));
	while (isinset(s1[end], set) && s1[end])
		end--;
	return (ft_substr(s1, start, (end - start + 1)));
}

static int      ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

typedef struct	s_unity
{
    int     selected;
    long    value;
    int     time_value;
    char    *time_unity;
}				t_unity;

typedef struct	s_time
{
    t_unity times[5];
    int     sep;
}				t_time;

long long   check_error(char *string)
{
    int     i;
    char    *parse;
    int     neg;
    unsigned long long num;

    neg = 1;
    num = 0;
    parse = ft_strtrim(string, " ");
    if (!parse || !*parse || !strlen(parse))
        return (0);
    i = 0;
    while ((parse[i] == ' ' || parse[i] == '-' || parse[i] == '+') && parse[i])
    {
        if (parse[i] == '-')
            neg *= -1;
		i++;
    }
    if (neg < 0)
        return (0);
    while (parse[i])
    {
        if (!ft_isdigit(parse[i]))
        {
            free(parse);
            return (0);
        }
        num = (num * 10) + (parse[i] - '0');
        i++;
    }
    free(parse);
    return (num + 1);
}

t_unity init_unity(int time_value, char *time_unity)
{
    t_unity ret;

    ret.value = 0;
    ret.selected = 0;
    ret.time_value = time_value;
    ret.time_unity = strdup(time_unity);
    return (ret);
}

t_time  *init(void)
{
    t_time  *ret;

    if (!(ret = (t_time*)malloc(sizeof(t_time))))
        return (NULL);
    ret->sep = 0;
    ret->times[0] = init_unity(YEAR, "years");
    ret->times[1] = init_unity(DAY, "days");
    ret->times[2] = init_unity(HOUR, "hours");
    ret->times[3] = init_unity(MINUTE, "minutes");
    ret->times[4] = init_unity(SECOND, "seconds");
    return (ret);
}

unsigned long long  calculate_time(t_time *Telescopium, t_unity *unity, unsigned long long seconds)
{
    char    *tmp;

    Telescopium->sep += 1;
    unity->selected = 1;
    unity->value = seconds / unity->time_value;
    seconds = seconds % unity->time_value;
    if (unity->value == 1)
    {
        tmp = ft_substr(unity->time_unity, 0, strlen(unity->time_unity) - 1);
        free(unity->time_unity);
        unity->time_unity = tmp;
    }
    return (seconds);
}

char    *make_result(t_time *Telescopium)
{
    char    ret[70];
    char    *tmp;
    int     i;

    i = -1;
    tmp = "";
    while (++i < 5)
    {
        if (Telescopium->times[i].selected)
        {
            sprintf(ret, "%s%ld %s", tmp, Telescopium->times[i].value, Telescopium->times[i].time_unity);
            if (Telescopium->sep > 2)
                strcat(ret, COMMA);
            else if (Telescopium->sep == 2)
                strcat(ret, AND);
            Telescopium->sep--;
            tmp = ret;
        }
        free(Telescopium->times[i].time_unity);
    }
    free(Telescopium);
    tmp = strdup(ret);
    return (tmp);
}

char    *ft_format_duration(char *seconds)
{
    t_time              *Telescopium;
    unsigned long long  second;

    if ((second = check_error(seconds)) == 0)
        return ("Invalid input.");
    second -= 1;
    if (second == 0)
        return (strdup("now"));
    Telescopium = init();
    if (second >= YEAR)
        second = calculate_time(Telescopium, &Telescopium->times[0], second);
    if (second >= DAY)
        second = calculate_time(Telescopium, &Telescopium->times[1], second);
    if (second >= HOUR)
        second = calculate_time(Telescopium, &Telescopium->times[2], second);
    if (second >= MINUTE)
        second = calculate_time(Telescopium, &Telescopium->times[3], second);
    if (second >= SECOND)
        second = calculate_time(Telescopium, &Telescopium->times[4], second);
    return (make_result(Telescopium));
}
