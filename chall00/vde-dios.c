#include <stdlib.h>

char	*hv_rgb2hex(int r, int g, int b)
{
	char	*rgb;

	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return (0);
	if (!(rgb = malloc((8) * sizeof(char))))
		return (0);
	rgb[0] = '#';
	rgb[1] = r & 0xF0 ? (((r & 0xF0) >> 4) > 9 ? ((r & 0xF0) >> 4) + 'a' - 10 : ((r & 0xF0) >> 4) + '0') : 0 + '0';
	rgb[2] = r & 0x0F ? ((r & 0x0F) > 9 ? (r & 0x0F) + 'a' - 10 : (r & 0x0F) + '0') : 0 + '0';
	rgb[3] = g & 0xF0 ? (((g & 0xF0) >> 4) > 9 ? ((g & 0xF0) >> 4) + 'a' - 10 : ((g & 0xF0) >> 4) + '0') : 0 + '0';
	rgb[4] = g & 0x0F ? ((g & 0x0F) > 9 ? (g & 0x0F) + 'a' - 10 : (g & 0x0F) + '0') : 0 + '0';
	rgb[5] = b & 0xF0 ? (((b & 0xF0) >> 4) > 9 ? ((b & 0xF0) >> 4) + 'a' - 10 : ((b & 0xF0) >> 4) + '0') : 0 + '0';
	rgb[6] = b & 0x0F ? ((b & 0x0F) > 9 ? (b & 0x0F) + 'a' - 10 : (b & 0x0F) + '0') : 0 + '0';
	rgb[7] = '\0';
	return (rgb);
}
