#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
	if (s1 && s2)
	{
		if (!(str = (char*)malloc((strlen(s1) + strlen(s2) + 1)
			* sizeof(char))))
			return (NULL);
		while (*s1)
			str[i++] = *s1++;
		while (*s2)
			str[i++] = *s2++;
		str[i] = '\0';
		return (str);
	}
	return (0);
}

char   *ft_print_format(int y ,int d, int h, int m, int s)
{
    char *str;
    char *tmp;
    char *years = strdup("");
    char *days = strdup("");
    char *hours = strdup("");
    char *minutes = strdup("");
    char *seconds = strdup("");
    if ( y > 0)
    {

        sprintf(years, "%d", y);
        tmp = y > 1 ? ft_strjoin(years, " years") : ft_strjoin(years, " year");
        free (years);
        years = strdup(tmp);
        free(tmp);
    }
    if ( d > 0)
    {
        if (y > 0)
        {
            tmp = m > 0 ? ft_strjoin(years, ", ") : ft_strjoin(years, " and ");
            free(years);
            years = strdup(tmp);
            free(tmp);
        }
        sprintf(days, "%d", d);
        tmp = d > 1 ? ft_strjoin(days, " days") : ft_strjoin(days, " day");
        free (days);
        days = strdup(tmp);
        free(tmp);
    }
    if (h > 0)
    {
        if (d > 0)
        {
            tmp = m > 0 ? ft_strjoin(days, ", ") : ft_strjoin(days, " and ");
            free(days);
            days = strdup(tmp);
            free(tmp);
        }
        sprintf(hours, "%d", h);
         tmp = h > 1 ? ft_strjoin(hours, " hours") : ft_strjoin(hours, " hour");
        free(hours);
        hours = strdup(tmp);
        free(tmp);
    }
    if (m > 0)
    {
        if (h > 0)
        {
            tmp = s > 0 ? ft_strjoin(hours, ", ") : ft_strjoin(hours, " and ");
            free(hours);
            hours = strdup(tmp);
            free(tmp);
        }
        sprintf(minutes, "%d", m);
        tmp = m > 1 ? ft_strjoin(minutes, " minutes") : ft_strjoin(minutes, " minute");
        free(minutes);
        minutes = strdup(tmp);
        free(tmp); 
    }
    if (s > 0)
    {
        if (m > 0)
        {
           tmp = ft_strjoin (minutes, " and ");
           free(minutes);
           minutes = strdup(tmp);
           free(tmp);
        }
        sprintf(seconds, "%d", s);
        tmp = s > 1 ? ft_strjoin(seconds, " seconds") : ft_strjoin(seconds ," second");
        free(seconds);
        seconds = strdup(tmp);
        free(tmp);
    }
    asprintf(&str, "%s%s%s%s%s",years, days, hours, minutes, seconds);
    free(years);
    free(days);
    free(hours);
    free(minutes);
    free(seconds);
    return(str);
}

char    *ft_format_duration(char *seconds)
{
    long long int n = atoll(seconds);
    int d = 0;
    int h = 0;
    int m = 0;
    int s = 0;
    int y = 0;
    int i = 0;
    
    char *invalidinput = strdup("Invalid input.");
    char *now = strdup("now");

     if (strlen(seconds) == 0)
        return(invalidinput);
    while(seconds[i] == ' ')
            i++;
    int flag = 0;
    while (seconds[i])
    {
        if(!(isnumber(seconds[i])))
        {
            if (seconds[i] == ' ')
                flag = 1;
            else
                return(invalidinput);
        }
        if (isnumber(seconds[i]) && flag == 1)
            return(invalidinput);
        i++;
    }
    if (n == 0)
        return (now);
    while (n > 0)
    {

        if (n >= 31536000)
        {
            y = n / 31536000;
            n %= 31536000;
        }
        else if (n < 31536000 && n >= 86400)
        {
            d = n / 86400;
            n %= 86400;
        }
        else if (n < 86400 && n >= 3600)
        {
            h = n / 3600;
            n %= 3600;
        }
        else if ( n < 3600 && n >= 60)
        {
            m = n / 60;
            n %= 60;
        }
        else if (n < 60)
        {
            s = n;
            n = 0;
        }
    }
    free(invalidinput);
    free(now);
    return(ft_print_format(y,d,h,m,s)); 
}