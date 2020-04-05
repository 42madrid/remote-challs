#define HEXADEC	"0123456789abcdef"

void    calculate_hex(int c, int color, char *result)
{
    if (c % 2 != 0)
        result[c] = HEXADEC[color / 16];
    else
        result[c] = HEXADEC[color % 16];
}

char    *hv_rgb2hex(int r, int g, int b)
{
    static char     result[7];
    int             i;
    
    result[0] = '#';
    i = 1;
    while (i < 7)
    {
        if (i < 3)
            calculate_hex(i, r, result);
        else if (i < 5)
            calculate_hex(i, g, result);
        else 
            calculate_hex(i, b, result);
        i++;
    }
    return(result);
}