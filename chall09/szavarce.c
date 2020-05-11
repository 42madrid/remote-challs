#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>

static int              len(long nb)
{
        int             len;

        len = 0;
        if (nb == 0)
                return (1);
        if (nb < 0)
        {
                nb = nb * -1;
                len++;
        }
        while (nb > 0)
        {
                nb = nb / 10;
                len++;
        }
        return (len);
}

char                    *ft_itoa(long int n)
{
        char    *str;
        long    num;
        int             i;
        int             totlen;

        num = n;
        num = (num < 0 ? num * -1 : num);
        totlen = len(n);
        i = totlen - 1;
        if (!(str = (char*)malloc((sizeof(char) *
                        (num < 0 ? totlen + 1 : totlen)) + 1)))
                return (NULL);
        str[0] = '-';
        if (num == 0)
                str[0] = '0';
        while (num > 0)
        {
                str[i] = '0' + (num % 10);
                num = num / 10;
                i--;
        }
        str[totlen] = '\0';
        return (str);
}

static int      ft_check(const char *x)
{
    int		pos;
	int		startpos;
	int		endswithspace;
	
    pos = 0;
	startpos = -1;
	endswithspace = 0;
	while (x[pos] != '\0' && x[pos] == ' ')
		pos++;
    while (x[pos])
    {
		if ((x[pos] < '0' || x[pos] > '9') && x[pos] != ' ')
			return (-1);
        if (x[pos] >= '0' && x[pos] <= '9' && startpos == -1)
			startpos = pos;
        else if (x[pos] >= '0' && x[pos] <= '9' && endswithspace == 1)
			return (-1);
		else if (x[pos] == ' ')
			endswithspace = 1;
		pos++;
	}
	if (startpos == 0 && (x[0] < '0' || x[0] > '9'))
	{
		return (-1);
	}
	return (startpos);
}

unsigned long long int	ft_atoi(const char *nptr)
{
    int     					pos;
    unsigned long long int   	result;

    pos = 0;
    result = 0;
    if (pos < 0)
        return (-1);
    while (nptr[pos] != '\0')
    {
		if (nptr[pos] >= '0' && nptr[pos] <= '9')
	      	result = (result * 10) + ((nptr[pos] - 48) % 10);
        pos++;
    }
    return (result);
}

char *ft_format_duration(char *seconds)
{
    unsigned long long int	iseconds;
	unsigned long long int	years;
	int						days;
	int						hours;
	int						minutes;
	int						secs;
	int						posini;
	int						rest;
	char					*dev;

    posini = ft_check(seconds);
	dev = malloc(sizeof(char) * 100);
	if (posini < 0)
		return("Invalid input.");
	else
	{
		iseconds = ft_atoi(seconds + posini);
		if (iseconds == 0)
			return ("now");
		years = iseconds / 31536000;
		rest = iseconds % 31536000;
		if (years ==  1)
			dev = strcat(dev, "1 year");
		else if (years >  1)
		{
			dev = strcat(dev, ft_itoa(years));
			dev = strcat(dev, " years");
		}
		if (rest == 0)
			return (dev);
		days = rest / 86400;
		rest = rest % 86400;
		if (years > 0)
		{
			if (rest == 0)
				dev = strcat(dev, " and ");
		}
		if (strlen(dev) > 0 && rest > 0 && days > 0)
			dev = strcat(dev, ", ");
		if (days ==  1)
			dev = strcat(dev, "1 day");
		else if (days >  1)
		{
			dev = strcat(dev, ft_itoa(days));
			dev = strcat(dev, " days");
		}
		if (rest == 0)		
			return (dev);
		hours = rest / 3600;
		rest = rest % 3600;
		if (rest == 0 && (years > 0 || days > 0))
			dev = strcat(dev, " and ");
		minutes = rest / 60;
		secs = rest % 60;
		if (strlen(dev) > 0 && rest > 0 && hours > 0)
			dev = strcat(dev, ", ");
		if (hours ==  1)
			dev = strcat(dev, "1 hour");
		else if (hours >  1)
		{
			dev = strcat(dev, ft_itoa(hours));
			dev = strcat(dev, " hours");
		}
		if (rest == 0)
			return (dev);
		if (strlen(dev) > 0 && secs > 0 && minutes > 0)
			dev = strcat(dev, ", ");
		else if (strlen(dev) > 0 && secs == 0)
			dev = strcat(dev, " and ");
		if (minutes ==  1)
			dev = strcat(dev, "1 minute");
		else if (minutes >  1)
		{
			dev = strcat(dev, ft_itoa(minutes));
			dev = strcat(dev, " minutes");
		}
		if (secs == 0)
			return (dev);
		if (strlen(dev) > 0)
			dev = strcat(dev, " and ");
		if (secs ==  1)
			dev = strcat(dev, "1 second");
		else if (secs >  1)
		{
			dev = strcat(dev, ft_itoa(secs));
			dev = strcat(dev, " seconds");
		}
		return (dev);
	}
}
