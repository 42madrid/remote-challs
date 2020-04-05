#include <string.h>

int hv_necklace(char *s1, char *s2)
{
    int     i;
    int     j;
    int     k;

    i = 0;
    k = 0;
    if (strlen(s1) != strlen(s2))
        return (0);
    while (k < strlen(s1))
    {
        j = 0;
        while (j < strlen(s2))
        {
            if (s1[i] != s2[j])
            {
                break;
            }
            i++;
            j++;
            if (i >= strlen(s1))
                i = 0;
        }
        if (j == strlen(s2))
            return (1);
        k++;
        i++;
    }
    if (s1 == "" && s2 == "")
        return (1);
    return (0);
}
