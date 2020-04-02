#include <string.h>
#include <stdlib.h>

void		ft_slide_char(char *dst, size_t len)
{
	int		j;
	char	aux[len];

	j = 0;
	while (dst[j + 1])
	{
		aux[j] = dst[j + 1];
		j++;
	}
	aux[j++] = dst[0];
	aux[j] = '\0';
	strcpy(dst, aux);
}

int			hv_necklace(char *s1, char *s2)
{
	char	*src;
	size_t	len;
	size_t	i;

	if(!s1 || !s2)
		return (0);
	len = strlen(s1);
	if (len != strlen(s2))
		return (0);
	if(!(src = (char *)malloc(len + 1)))
		return (0);
	strcpy(src, s1);
	i = 0;
	while (i < len)
	{
		if(strcmp(src, s2) == 0)
		{
			free(src);
			return (1);
		}
		ft_slide_char(src, len);
		i++;
	}
	free(src);
	return (0);
}
