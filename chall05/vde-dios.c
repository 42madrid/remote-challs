int ft_ie_except_after_c(char* str)
{
    char *p;

    if (str)
    {
        p = str;
        while (*str)
        {
            if (*str == 'e')
            {
                if (str != p && (str - 1)!= p)
                    if (*(str - 1) == 'i' && *(str - 2) == 'c')
                        return (0);
                if (*(str + 1))
                    if (*(str + 1) == 'i' && (str == p || *(str - 1) != 'c'))
                        return (0);
            }
            str++;
        }
        return (1);
    }
    return (0);
}
