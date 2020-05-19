#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

unsigned long long     ft_ultimate_atoull(char *str)
{
    unsigned long long num;
    char               *aux;

    while (isspace(*str))
        str++;
    if (!isdigit(*str))
        return (ULLONG_MAX);
    num = strtoull(str, &aux, 10);
    while (*aux++)
        if (!isspace(*(aux - 1)))
            return (ULLONG_MAX);
    return (num);
}

char                    *ft_format_duration(char *seconds)
{
    unsigned long long  num = ft_ultimate_atoull(seconds);
    unsigned long long  div;
    long int            time[] = {31536000, 86400, 3600, 60, 1};
    char                *units[] = {"year", "day", "hour", "minute", "second"};
    char                *conversion;
    char                *tmp = NULL;
    int                 i = 0;

    if (num == ULLONG_MAX)
        return ("Invalid input.");
    if (!num)
        return ("now");
    while(i < 5)
    {
        if (num > time[i])
        {
            div = num / time[i];
            num = num % time[i];
            if (!(num))
                asprintf(&conversion, "%s%llu %s%s", !tmp ? "" : tmp, div, units[i], div > 1 ? "s" : "");
            else if (!(num % time[i + 1]))
                asprintf(&conversion, "%s%llu %s%s and ", !tmp ? "" : tmp, div, units[i], div > 1 ? "s" : "");
            else
                asprintf(&conversion, "%s%llu %s%s, ", !tmp ? "" : tmp, div, units[i], div > 1 ? "s" : "");
            free(tmp);
            tmp = conversion;
        }
        i++;
    }
    return (conversion);
}
