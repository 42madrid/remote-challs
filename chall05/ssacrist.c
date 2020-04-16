#include<ctype.h>

int     ft_ie_except_after_c(char* str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if (tolower(str[i]) == 'e')
        {
            if (tolower(str[i + 1]) == 'i' && (tolower(str[i - 1]) != 'c' || !str[i - 1]))
                return(0);
        }
        if (tolower(str[i]) == 'i')
        {
            if (tolower(str[i + 1]) == 'e' && tolower(str[i - 1]) == 'c')
                return(0);
        }
        i++;
    }
    return(1);
}