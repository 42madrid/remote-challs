#include<ctype.h>

int     ft_ie_except_after_c(char* str)
{
    while (*str)
    {
        if (tolower(*str) == 'e')
            if (tolower(*(str + 1)) == 'i')
                if (tolower(*(str - 1)) != 'c' || !*(str - 1))
                    return(0);
        if (tolower(*str) == 'i')
            if (tolower(*(str + 1)) == 'e')
                if (tolower(*(str - 1)) == 'c')
                    return(0);
        str++;
    }
    return(1);
}