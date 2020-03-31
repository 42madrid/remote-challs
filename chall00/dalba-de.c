#include "stdlib.h"

char    *ft_itoa_base(unsigned long value, unsigned long base)
{
	unsigned long	i;
    int             j;
	char			*hex;
    char            *str;

	i = 1;
    j = 1;
    hex = "0123456789abcdef";
    str = (char*)malloc(sizeof(value) * i);
    str[0] = '#';
	while (value / i > base - 1)
		i *= base;
	while (i != 0)
	{
        str[j] = hex[value / i];
		value %= i;
		i /= base;
        j++;
	}
    str[j] = '\0';
    return (str);
}

char    *hv_rgb2hex(int r, int g, int b)
{
    unsigned int color;
    char *str;

    if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
        return ("Invalid number");
    color = r * 256 * 256 + g * 256 + b;
    str = ft_itoa_base(color, 16);
    return (str);
}
