#include <stdlib.h>

char    *hv_rgb2hex(int r, int g, int b) {
    char *letters;
    char *hex;
    
    hex = (char*)malloc(sizeof(char) * 8);
    letters = "0123456789abcdef";
    hex[0] = '#';
    hex[1] = letters[(r / 16)];
    hex[2] = letters[(r - (r / 16) * 16)];
    hex[3] = letters[(g / 16)];
    hex[4] = letters[(g - (g / 16) * 16)];
    hex[5] = letters[(b / 16)];
    hex[6] = letters[(b - (b / 16) * 16)];
    hex[7] = '\0';
    return (hex);
}
