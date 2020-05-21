#include <stdlib.h>
#include <string.h>

int         ft_isdigit(char c)
{
    if (c < '0' || c > '9')
        return (0);
    return (1);
}


int             get_size(unsigned long long num)
{
    int i = 0;

    while (num >= 10)
    {
        i++;
        num /= 10;
    }
    return (i + 1);
}

char			*ft_long_itoa(unsigned long long num)
{
	char		    *str;
	int	index;
	int	size;
    
	size = get_size(num);
	index = 0;
	if (!(str = malloc(sizeof(char) * (size + 1 ))))
		return (0);

	index = size - 1;
	while (num >= 10)
	{
		str[index--] = (num % 10 + 48);
		num /= 10;
	}
	str[index] = (num % 10 + 48);
	str[size] = '\0';
	return (str);
}

unsigned long long  ft_long_atoi(char *str)
{
    unsigned long long num = 0;
    int i = 0;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num);
}

char        *ft_strjoin(char *s1, char*s2)
{
    int i = 0;
    int j = 0;
    char *s3;
    if (!(s3 = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1))))
        return (NULL);
    while (s1[i])
    {
        s3[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        s3[i] = s2[j];
        i++;
        j++;
    }
    s3[i] = '\0';
    return (s3);
}

char        *put_time(int i, char *string, unsigned long long *plural, char **clock)
{
    int flag;
    int j;

    string = ft_strjoin(string, clock[i]);

    if (i == 0)
         string = ft_strjoin(string, " year");
    else if (i == 1)
         string = ft_strjoin(string, " day");
    else if (i == 2)
         string = ft_strjoin(string, " hour");
    else if (i == 3)
         string = ft_strjoin(string, " minute");
    else if (i == 4)
         string = ft_strjoin(string, " second");
    if (plural[i] > 1)
        string = ft_strjoin(string, "s");
    while (i < 4)
    {
        flag = 0;
        j = i + 1;
        while (j < 5)
        {
            if (clock[j] != NULL)
                flag++;
            j++;
        }
        if (flag > 1)
        {
            string = ft_strjoin(string, ", ");
            break;
        }
        else if (flag == 1)
        {
            string = ft_strjoin(string, " and ");
            break;
        }
        i++;
    }
    return (string);
}

char        *get_time(unsigned long long time)
{
    char **clock;
    char *string;
    unsigned long long *plural;
    int i = 0;

    if (!(clock = malloc(sizeof(char *) * 5)))
        return(NULL);
    if (!(plural = malloc(sizeof(unsigned long long) * 5)))
        return(NULL);
    plural[0] = time / 60 / 60 / 24 / 365; // years
    plural[1] = time / 60 / 60 / 24 % 365; // days
    plural[2] = time / 60 / 60 % 24;       // hours
    plural[3] = time / 60 % 60;            // minutes
    plural[4] = time % 60;                 // seconds
    while (i < 5)
    {
        clock[i] = plural[i] > 0 ? ft_long_itoa(plural[i]) : NULL;
        i++;
    }
    string = strdup("");
    i = 0;
    while (i < 5)
    {
        if (clock[i] != NULL) 
            string = put_time(i, string, plural, clock);
        i++;
    }
    return (string);
}

int         check_seconds(char *seconds)
{
    int flag_num = 0;
    int i = 0;
    while (seconds[i] == ' ')
        i++;
    while (seconds[i])
    {
        if (ft_isdigit(seconds[i]) && flag_num == 0)
        {
            while (ft_isdigit(seconds[i]))
                i++;
            flag_num = 1;
        }
        else if (seconds[i] == ' ')
            i++;
        else
            return (0);
    }
    return (1);
}

char        *ft_format_duration(char *seconds)
{
    unsigned long long time = ft_long_atoi(seconds);

    if (!check_seconds(seconds) || !strlen(seconds))
        return ("invalid input");
    if (time > 0)
        return(get_time(time));
    else if (time == 0)
        return ("now");
    else
        return ("invalid input");

}
