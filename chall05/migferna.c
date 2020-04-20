#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!(*s++))
			return (NULL);
	return ((char *)s);
}

size_t	ft_strlen(const char *s)
{
	size_t cont;

	cont = 0;
	while (*s++)
		cont++;
	return (cont);
}

char	*ft_tolower(char *str)
{
	char	*aux;
	int		len;

	len = ft_strlen(str);
	if (!(aux = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*aux = *str + 32;
		else
			*aux = *str;
		aux++;
		str++;
	}
	*aux = '\n';
	return (aux - len);
}

int		ft_ie_except_after_c(char* str)
{
	char *it;
	char *prev;
	char *next;

	str = ft_tolower(str);
	it = str;
	while (it)
	{
		it = ft_strchr(it, 'i');
		if (it != NULL)
		{
			prev = it - 1;
			next = it + 1;
			if (*(prev) && *(prev) == 'e')
			{
				it = prev - 1;
				if (*(it) && *(it) == 'c')
					it = next;
				else
					return (0);
			}
			else if(*(next) && *(next) == 'e')
			{	
				it = next - 2;
				if (*(it) && *(it) == 'c')
					return (0);
				else
					it = next;
			}
			else
				it = next;
		}
		else
			return (1);
	}
	return (1);
}
