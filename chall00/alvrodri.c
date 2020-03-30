#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_itoa_base(unsigned int nbr, char *base, int len)
{
	unsigned int	n;
	int				i;
	char			*str;

	n = nbr;
	i = 2;
	while ((n /= len) > 0)
		i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	while (i--)
	{
		str[i] = (nbr % len >= 10) ? base[nbr % len] : (nbr % len) + '0';
		nbr /= len;
	}
	str[0] = '#';
	return (str);
}

char	*hv_rgb2hex(int r, int g, int b)
{
    unsigned int	hex = r << 16 | g << 8 | b;
	return (ft_itoa_base(hex, "0123456789abcdef", 16));
}