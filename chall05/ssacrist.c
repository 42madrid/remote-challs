#include<ctype.h>

int     ft_ie_except_after_c(char* str)
{
    int     result;
    int     i;

    i = 0;
    result = 1;
    while (str[i])
    {
        while (tolower(str[i]) == 'e')
        {
            while (tolower(str[i + 1]) == 'i' && (tolower(str[i - 1]) != 'c' || !str[i - 1]))
            {    
                result = 0;
                i++;
            }
            i++;
        }
        while (tolower(str[i]) == 'i')
        {
            while (tolower(str[i + 1]) == 'e' && tolower(str[i - 1]) == 'c')
            {    
                result = 0;
                i++;
            }
            i++;
        }
        i++;
    }
    return(result);
}