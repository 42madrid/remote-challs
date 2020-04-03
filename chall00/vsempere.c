#include <stdlib.h>

static char		*ft_itoh(int n)
{
	char 		*str;
	char 		*hexa;
	int			i;

	str = "0123456789abcdef";
	hexa = malloc(sizeof(char) * 7);
	if (!hexa)
		return (0);
	n = 0xFFFFFF & n;
	hexa[0] = '#';
	i = 0;
	while (i < 6)
	{
		hexa[6 - i] = str[(n >> (!i ? 0 : 4 * i)) % 16];
		i++;
	}
	return (hexa);
}

char			*hv_rgb2hex(int r, int g, int b)
{
	int	rgb;

	rgb = 0 + ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return ft_itoh(rgb);
}
