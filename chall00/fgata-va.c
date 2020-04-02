#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char			*ft_rev_str(char *str)
{
	char *result;
	int i;
	int j;

	if(!(result= (char*)malloc(sizeof(char) * strlen(str)))){
		return(NULL);
	}
	i = 0;
	j = strlen(str) - 1;
	while(j >= 0)
	{
		result[i] = str[j];
		i++;
		j--;
	}
	result[i] = '\0';
	free(str);
	return(result);
}

char				*dec_to_hex(int x)
{
	char			*hex;
	int				n;
	int				i;

	i = 0;
	if(!(hex = malloc(sizeof(char) * 3)))
		return(NULL);
	if(x == 0)
	{
		strcpy(hex, "00");
		return(hex);
	}
	while (x > 0)
	{
		n = x % 16;
		x /= 16;
		if(n > 9)
				hex[i] = (n - 10) + 'a';
		else
				hex[i] = n + '0';
		i++;
	}
	if(i == 1)
	{
		hex[i] = '0';
		i++;
	}
	hex[i] = '\0';
	hex = ft_rev_str(hex);
	return (hex);
}

void		join_n_free(int c, char *hex)
{
	char	*buff;

	buff = dec_to_hex(c);
	strcat(hex, buff);
	free(buff);
}

char		*hv_rgb2hex(int r, int g, int b)
{
	char	*hex;

	if ((r > 255 || r < 0) || (g > 255 || g < 0) ||
	(b > 255) || (b < 0))
		return (NULL);
	if(!(hex = malloc(sizeof(char *) * 2)))
		return (NULL);
	hex[0] = '#';
	hex[1] = '\0';
	join_n_free(r, hex);
	join_n_free(g, hex);
	join_n_free(b, hex);
	return(hex);
}

