#include <stdlib.h>

char	hex(char n)
{
	return (n > 9 ? (n + 'a' -10) : (n + '0'));
}

char	*hv_rgb2hex(int r, int g, int b)
{
	char	*rgb;

	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return (0);
	if (!(rgb = malloc((8) * sizeof(char))))
		return (0);
	rgb[0] = '#';
	rgb[1] = r & 0xF0 ? hex((r & 0xF0) >> 4) : 0 + '0';
	rgb[2] = r & 0x0F ? hex(r & 0x0F) : 0 + '0';
	rgb[3] = g & 0xF0 ? hex((g & 0xF0) >> 4) : 0 + '0';
	rgb[4] = g & 0x0F ? hex(g & 0x0F) : 0 + '0';
	rgb[5] = b & 0xF0 ? hex((b & 0xF0) >> 4) : 0 + '0';
	rgb[6] = b & 0x0F ? hex(b & 0x0F) : 0 + '0';
	rgb[7] = '\0';
	return (rgb);
}
