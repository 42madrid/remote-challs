#include <stdlib.h>

/*
** simple swap function
*/
static char	*str_swap(char *str, int start, int end)
{
	char	tmp;

	while (start < end)
	{
		tmp = str[start];
		str[start++] = str[end];
		str[end--] = tmp;
	}
	return (str);
}

/*
** shift bits to create the rgb color
*/
int	create_rgb_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

/*
** allocate memory and convert color to hex
*/
char   *hv_rgb2hex(int r, int g, int b)
{
	char		*hex_rgb;
	unsigned	color;
	int		rest;
	int		i;

	hex_rgb = malloc(8);
	if (hex_rgb == NULL)
		return (NULL);
	color = create_rgb_color(r, g, b);
	i = 0;
	while (i < 6)
	{
		rest = color % 16;
		if (rest >= 10)
			hex_rgb[i++] = 'a' + (rest - 10);
		else
			hex_rgb[i++] = '0' + rest;
		color /= 16;
	}
	hex_rgb[i++] = '#';
	hex_rgb[i] = '\0';
	str_swap(hex_rgb, 0 , i - 1);
	return (hex_rgb);
}
