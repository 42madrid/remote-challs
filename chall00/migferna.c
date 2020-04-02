#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*new;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	return (new);
}

char	*hv_rgb2hex(int r, int g, int b)
{
	char hex[7];
	static char base[] = "0123456789ABCDEF";

	if (r < 0 || r > 255 || g < 0 || r > 255 || b < 0 || b > 255)
		return ("Error: Values not valid");
	hex[0] = '#';
	hex[1] = base[r / 16];
	hex[2] = base[r % 16];
	hex[3] = base[g / 16];
	hex[4] = base[g % 16];
	hex[5] = base[b / 16];
	hex[6] = base[b % 16];
	return (ft_strdup(hex));
}
