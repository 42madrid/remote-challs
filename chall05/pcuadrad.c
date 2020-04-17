#include <stdio.h>

int     find(char *str, char *to_find)
{
    int     i;
    int     j;

    i = -1;
    while (str[++i] && (j = -1))
        while (to_find[++j] && str[i + j] && str[i + j] == to_find[j])
            if (!to_find[j + 1])
                return (i);
    return (-1);
}

int     ft_ie_except_after_c(char *str)
{
    int coincidence;

    if ((!str) || ((coincidence = find(str, "ei")) != -1 && (coincidence == 0 || str[coincidence - 1] != 'c')) ||
        ((coincidence = find(str, "ie")) != -1 && str[coincidence - 1] == 'c'))
        return (0);
    return (1);
}
