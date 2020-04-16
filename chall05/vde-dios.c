int ft_ie_except_after_c(char* str)
{
    if (str)
    {
        while (*str)
        {
            if (*str == 'e' && *(str + 1))
            {
                if (*(str - 1) == 'i' && *(str - 2) == 'c')
                    return (0);
                if (*(str + 1) == 'i' && *(str - 1) != 'c')
                    return (0);
            }
            str++;
        }
        return (1);
    }
    return (0);
}
