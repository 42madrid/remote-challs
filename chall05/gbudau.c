#include <ctype.h>

int	ft_ie_except_after_c(char *str)
{
	char *start;

	start = str;
	while (*str)
	{
		if (tolower(*str) == 'c')
		{
			if (*(str + 1) && tolower(*(str + 1)) == 'i' &&
							tolower(*(str + 2)) == 'e')
				return (0);
		}
		else if (tolower(*str) == 'e')
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
