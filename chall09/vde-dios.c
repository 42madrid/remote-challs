#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int                     ft_sign_or_space(char str)
{
    if (str == '-')
        return (-1);
    else if (str == '+' ||str == ' ')
        return (1);
    return (0);
}

unsigned long long     ft_ultimate_atoull(char *str)
{
    int sign;
    unsigned long long num;
    char *p;

    sign = 1;
    p = NULL;
    if (!*str)
        return (ULLONG_MAX);
    while (*str && ft_sign_or_space(*str))
    {
        sign = sign * ft_sign_or_space(*str);
        str++;
    }
    num = strtoull(str, &p, 10);
    while (*p)
    {
        if (*p != ' ' && (*(p - 1) < '0' ||*(p - 1) > '9'))
            return (ULLONG_MAX);
        p++;
    }
    if (sign < 0)
        return (ULLONG_MAX);
    return (num * sign);
}

char                    *ft_itoa(unsigned long long num)
{
    unsigned long long  aux;
    int                 length;
    char                *conversion;

    length = 0;
    aux = num;
    while (aux)
    {
        aux = aux / 10;
        length++;
    }
    if (!(conversion = malloc((length + 1) * sizeof(char))))
        return (NULL);
    conversion[length] = '\0';
    length--;
    while (num)
    {
        conversion[length] = num % 10 + '0';
        num = num / 10;
        length--;
    }
    return (conversion);
}

char                    *ft_strcat_alloc(char *dest, char *src)
{
    char        *new;
    int         i;

    i = 0;
    if (!(new = malloc((strlen(dest) + strlen(src) + 1) * sizeof(char))))
        return (NULL);
    sprintf(new, "%s%s", dest, src);
    free(dest);
    free(src);
    return (new);
}

char                    *ft_set_units(unsigned long long unit, int i)
{
    char *str;

    if (i == 0)
        return (ft_strcat_alloc(ft_itoa(unit), unit > 1 ? strdup(" years") : strdup(" year")));
    else if (i == 1)
        return (ft_strcat_alloc(ft_itoa(unit), unit > 1 ? strdup(" days") : strdup(" day")));
    else if (i == 2)
        return (ft_strcat_alloc(ft_itoa(unit), unit > 1 ? strdup(" hours") : strdup(" hour")));
    else if (i == 3)
        return (ft_strcat_alloc(ft_itoa(unit), unit > 1 ? strdup(" minutes") : strdup(" minute")));
    return (ft_strcat_alloc(ft_itoa(unit),  unit > 1 ? strdup(" seconds") : strdup(" second")));
}

char                    *ft_create_sentence(char **conversion)
{
    char        *sentence;
    int         length;

    length = 0;
    while(conversion[length])
        length++;
    length--;
    sentence = conversion[length--];
    if (length >= 0)
    {
        sentence = ft_strcat_alloc(strdup(" and "), sentence);
        sentence = ft_strcat_alloc(conversion[length], sentence);
    }
    length--;
    while (length >= 0)
    {
        sentence = ft_strcat_alloc(strdup(", "), sentence);
        sentence = ft_strcat_alloc(conversion[length], sentence);
        length--;
    }
    return (sentence);
}

char                    *ft_format_duration(char *seconds)
{
    unsigned long long  num;
    unsigned long long  unit; 
    long int            time[5];
    char                *conversion[6];
    int                 i;
    int                 k;

    //seconds in unit: time[years|days|hours|minutes|seconds]
    time[0] = 31536000;
    time[1] = 86400;
    time[2] = 3600;
    time[3] = 60;
    time[4] = 1;
    num = ft_ultimate_atoull(seconds);
    i = 0;
    k = 0;
    if (num == ULLONG_MAX)
        return ("Invalid input.");
    if (!num)
        return ("now");
    while(i < 5)
    {
        if (num > time[i])
        {
            unit = num / time[i];
            num = num % time[i];
            conversion[k] = ft_set_units(unit, i);
            k++;
        }
        i++;
    }
    conversion[k] = NULL;
    return (ft_create_sentence(conversion));
}
