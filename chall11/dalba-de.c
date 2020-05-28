#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int		ft_malloc_str(const char *code)
{
	int i;

	i = 0;
	while (code[i] != '\n')
		i++;
	return (i);
}

char    *ft_goto_parser(const char *code)
{
	char	*str;
	char	*num;
	char	*ret;
	int		j;
	int		k;

	str = malloc(strlen(code));
	num = NULL;
	j = 0;
	while (*code)
	{
		if (num == NULL)
		{
			if (*code == 'g')
			{
				while (*code < '0' || *code > '9')
					code++;
				num = malloc(ft_malloc_str(code) + 2);
				k = 0;
				while (*code >= '0' && *code <= '9')
				{
					num[k++] = *code++;
				}
				num[k++] = ' ';
				num[k] = '\0';
			}
			while (*code >= '0' && *code <= '9')
				code++;
			while (*code == ' ')
				code++;
			while (*code != '\n')
			{
				while (*code != ' ' && *code != '\n')
					str[j++] = *code++;
				while (*code == ' ')
					code++;
				if (*(code + 1) != '\0')
					str[j++] = ' ';
			}
			if (num == NULL && str[j - 1] != ' ' && str[j] != '\0')
				str[j++] = ' ';
			code++;
		}
		else
		{
			ret = strstr(code, num);
			code = ret;
			if (code == NULL)
				return ("Infinite loop !");
			free (num);
			num = NULL;
		}
	}
	return (str);

}
