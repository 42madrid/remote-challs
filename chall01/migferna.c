#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char *ps;

	ps = (unsigned char *)s;
	while (n-- > 0)
		*(ps++) = '\0';
}

size_t	ft_strlen(const char *s)
{
	size_t cont;

	cont = 0;
	while (*s++)
	{
		cont++;
	}
	return (cont);
}

int		hv_necklace(char *s1, char *s2)
{
	int				its2;
	int				pos;
	int				len;
	unsigned int	found;
	int				*mask;

	pos = 0;
	len = ft_strlen(s1);
	if (!(mask = malloc(sizeof(int) * len)))
		return (0);	
	ft_bzero(mask, len);
	if (!s1 || !s2 || ft_strlen(s1) != ft_strlen(s2))
		return (0);
	if (ft_strlen(s1) == 0 && ft_strlen(s2) == 0)
		return (1);
	its2 = 0;
	while (s2[its2])
	{
		found = 0;
		its2 = 0;
		while (s1[pos])
		{
			if (s1[pos] == s2[its2] && mask[pos] == 0)
			{
				mask[pos] = 1;
				found = 1;
				break ;
			}
			else
				pos++;
		}
		if (found == 0)
			return (0);
		while (s2[its2])
		{
			if (s1[pos] == s2[its2])
			{
				pos++;
				its2++;
				if (s1[pos] == '\0')
					pos = 0;
			}
			else
				break ;
		}
		if (its2 == len)
			return (1);
	}
	return (0);
}
