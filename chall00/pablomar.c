#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			ft_putchar(s[i]);
			i++;
		}
	}
}

static char	ft_calculate_char(int mod, char c)
{
	char	return_char;

	if (mod > 36)
		return (0);
	return_char = '0';
	while (mod--)
	{
		return_char++;
		if (return_char == ':')
			return_char = c;
	}
	return (return_char);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char*)s)[i] = '\0';
		i++;
	}
}

static int	ft_get_len(unsigned long num, unsigned long base)
{
	int		len;

	len = 0;
	while (num)
	{
		num /= base;
		len++;
	}
	return (len);
}

char		*ft_strnew(size_t size)
{
	char *start;

	start = (char *)malloc((size + 2) * sizeof(*start));
	if (!start)
		return (NULL);
	ft_bzero(start, size + 1);
	return (start);
}

static char	*ft_generate_string(unsigned long num, unsigned long base, char c)
{
	unsigned long	sum;
	int				mod;
	int				len;
	char			*str;

	if (num == 0)
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
		str[0] = '#';
        str[1] = '0';
		return (str);
	}
	sum = num;
	len = ft_get_len(num, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (sum)
	{
		mod = sum % base;
		sum /= base;
		str[(len--)] = ft_calculate_char(mod, c);
	}
    str[len] = '#';
	return (str);
}

char		*ft_itoa_base(unsigned long num, unsigned long base, char c)
{
	char	*str;

	str = ft_generate_string(num, base, c);
	return (str);
}

char *hv_rgb2hex(int r, int g, int b)
{
    int     hex_num;
    char    *hex;

    hex_num = (r<<16)|(g<<8)|b;
    if (!(hex = ft_itoa_base(hex_num, 16, 'a')))
		exit(-1);
    return(hex);
}