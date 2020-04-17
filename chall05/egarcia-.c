#include <stdio.h>

#define funtion(x)       printf(x" = %d\n", ft_ie_except_after_c(x));

int     ft_ie_except_after_c(char* str)
{
    while (*str)
    {
        if (*(str + 2) && *str == 'c' && *(str + 1) == 'i' && *(str + 2) == 'e')
            return(0);
        else if (*(str + 1) && *str == 'e' && *(str + 1) == 'i' && *(str - 1) != 'c')
            return 0;
        str++;
    }
    return(1);
}

/*
int main()
{
    funtion("sleigh");
    funtion("zombie");
    funtion("transceiver")
    funtion("veil");
    funtion("icier");
    funtion("e");
    funtion("c");
    return 0;
}
*/