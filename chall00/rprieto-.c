#include <stdlib.h>

void color2hex(int color, char *string);

char	*hv_rgb2hex(int r, int g, int b)
{
	char *hex_string;

	hex_string = malloc(sizeof(char) * 8);
	hex_string[0] = '#';
	color2hex(r, &hex_string[1]);
	color2hex(g, &hex_string[3]);
	color2hex(b, &hex_string[5]);
	hex_string[7] = '\0';
	return (hex_string);
}

void	color2hex(int color, char *string)
{
	char	*hex_characters;

	hex_characters = "0123456789abcdef";
	if (color > 15)
	{
		*(string++) = hex_characters[color / 16];
		*string = hex_characters[color % 16];
	}
	else
	{
		*(string++) = '0';
		*string = hex_characters[color];
	}
}
