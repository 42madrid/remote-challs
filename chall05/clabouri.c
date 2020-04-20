#include <string.h>

int ft_ie_except_after_c(char *str) {
	char *tmp = str;

	if (strstr(str, "cie"))
		return (0);

	while ((tmp = strstr(tmp, "ei"))) {
		if (tmp == str || *(tmp - 1) != 'c')
			return (0);
		tmp++;
	}

	return (1);
}
