char   ft_lower(char letter)
{
    if (letter >= 'A' && letter <= 'Z')
        return (letter + 32);
    return (letter);
}

int ft_ie_except_after_c(char* str)
{
    char *p;

    if (str)
    {
        p = str;
        while (*str)
        {
            if (ft_lower(*str) == 'e')
            {
                if (str != p && (str - 1)!= p)
                    if (ft_lower(*(str - 1)) == 'i' && ft_lower(*(str - 2)) == 'c')
                        return (0);
                if (*(str + 1))
                    if (ft_lower(*(str + 1)) == 'i' && (str == p || ft_lower(*(str - 1)) != 'c'))
                        return (0);
            }
            str++;
        }
        return (1);
    }
    return (0);
}
