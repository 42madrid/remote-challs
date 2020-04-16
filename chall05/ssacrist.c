 #include <string.h>

int ft_ie_except_after_c(char* str)
{
    int  len;
    int  result;
    int  i;
    
    len = strlen(str);
    i = 0;
    result = 1;
    while (i < len)
    {
        while (str[i] == 'e')
        {
            while (str[i + 1] == 'i' && (str[i - 1] != 'c' || !str[i - 1]))
            {    
                result = 0;
                i++;
            }
            i++;
        }
        while (str[i] == 'i')
        {
            while (str[i + 1] == 'e' && str[i - 1] == 'c')
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