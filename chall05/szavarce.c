int ft_found(char *find, char *in_str)
{
    int pos;
    int posb;
    int ret;

    pos = 0;
    posb = 0;
    ret = 1;
    while (in_str[pos] != '\0')
    {
        posb = 0;
        ret = 1;
        while (find[posb])
        {
            if (find[posb] != in_str[pos + posb])
                ret = 0;
            posb++;
        }
        if (ret == 1)
            return (1);
        pos++;
    }
    return (0);
}

int ft_ie_except_after_c(char* str)
{
    if (!str[0])
        return (0);
    if (ft_found("ei",str) && ft_found("cei",str))
        return (1);
    if (ft_found("ei",str) && !ft_found("cei",str))
        return (0);        
    if (ft_found("ie",str) && !ft_found("cie",str))
        return (1);
    if (ft_found("ie",str) && ft_found("cie",str))
        return (0);
    if (!ft_found("ie",str) && !ft_found("ei",str))
        return (1);
    return (0);
}
