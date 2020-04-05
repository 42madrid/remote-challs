#include <string.h>

int hv_necklace(char *s1, char *s2)
{
    size_t  i;
    size_t  j;
    size_t  c;

    if (strlen(s1) != strlen (s2))
        return (0);
    if (strlen(s1) == 0)
        return (1);
    i = 0;
    j = 0;
    while (i < strlen(s2))
    {
        while (s1[i] != s2[j])
            i++;
        c = 0;
        while (s1[i] == s2[j])
        {
            if (!s1[i + 1])
                i = 0;
            else
                i++;
            if (!s2[j + 1])
                j = 0;
            else
                j++;
            if (c != strlen(s2))
                c++;
            else 
                return (1);
        }
    }
    return (0);
}
