#include <stdlib.h>
#include <string.h>

static char    *rotate(char *str, size_t len)
{
    char    temp;
    char    *dst;
    size_t  i;

    i = 0;
    temp = str[0];
    dst = strdup(str);
    while (i < len - 1)
    {
        dst[i] = str[i + 1];
        i++;
    }
    dst[i] = temp;
    return (dst);
}

int hv_necklace(char *s1, char *s2)
{
    size_t  len;
    int     i;

    len = strlen(s1);
    if (len != strlen(s2))
        return (0);
    if (len == 0)
        return (1);
    if (strcmp(s1, s2) == 0)
        return (1);
    i = 0;
    while (i < len)
    {
         if (strcmp(s1, s2) == 0)
            return (1);
        s1 = rotate(s1, len);
        i++;
    }
    return (0);
}