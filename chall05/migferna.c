#include <unistd.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!(*s++))
			return (NULL);
	return ((char *)s);
}

int	ft_ie_except_after_c(char* str)
{
	char *it;
	char *prev;
	char *next;

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
