#include <string.h>
#include <ctype.h>

int		ft_ie_except_after_c(char* str)
{
	char *start;

	start = str;
	while (*str)
	{
		if (tolower(*str) == 'c')
			if (tolower(*(str + 1)) == 'i')
				return (0);
		if (tolower(*str) == 'e')
		{
			if (str - start > 0 && tolower(*(str - 1)) == 'c')
			{
				str++;
				continue;
			}
			if (tolower(*(str + 1)) == 'i')
				return (0);
		}
		str++;
	}
	return (1);
}
