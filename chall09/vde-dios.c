#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

unsigned long long     ft_ultimate_atoull(char *str)
{
    unsigned long long num;
    char               *aux;

    if (!*str)
        return (ULLONG_MAX);
    while (isspace(*str))
        str++;
    if (!isdigit(*str))
        return (ULLONG_MAX);
    num = strtoull(str, &aux, 10);
    while (*aux)
    {
        if (!isspace(*aux))
            return (ULLONG_MAX);
        aux++;
    }
    return (num);
}

char                    *ft_format_duration(char *seconds)
{
    unsigned long long  num;
    unsigned long long  div;
    long int            time[] = {31536000, 86400, 3600, 60, 1};
    char                *units[] = {"year", "day", "hour", "minute", "second"};
    char                *conversion;
    char                *tmp;
    int                 i;

    num = ft_ultimate_atoull(seconds);
    i = 0;
    tmp = NULL;
    if (num == ULLONG_MAX)
        return ("Invalid input.");
    if (!num)
        return ("now");
    while(i < 5)
    {
        if (num > time[i])
        {
            div = num / time[i];
            if (!(num % time[i]))
                asprintf(&conversion, "%s%llu %s%s", !tmp ? "" : tmp, div, units[i], div > 1 ? "s" : "");
            else if (!(num % time[i + 1]))
                asprintf(&conversion, "%s%llu %s%s and ", !tmp ? "" : tmp, div, units[i], div > 1 ? "s" : "");
            else
                asprintf(&conversion, "%s%llu %s%s, ", !tmp ? "" : tmp, div, units[i], div > 1 ? "s" : "");
            free(tmp);
            tmp = conversion;
            num = num % time[i];
        }
        i++;
    }
    return (conversion);
}
