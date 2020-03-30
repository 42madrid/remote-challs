/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fjimenez.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:26:53 by fernando          #+#    #+#             */
/*   Updated: 2020/03/30 23:25:28 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return ((size_t)i);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*ps1;
	char	*res;

	ps1 = (char*)s1;
	i = 0;
	while (ps1[i] != '\0')
		i++;
	if (!(res = (char*)malloc(i + 1)))
		return (NULL);
	i = 0;
	while (ps1[i] != '\0')
	{
		res[i] = ps1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int     ft_len_num(int n)
{
	int len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	if (len == 1)
		len = 2;
	return (len);
}

char    *ft_int_to_str(int n, int len, char *hex)
{
	hex[len--] = '\0';
	if (n == 0)
	{
		hex[0] = '0';
		hex[1] = '0';
	}
	if (n <= 16 & n != 0)
		hex[0] = '0';
	while (n > 0)
	{
		if (n % 16 <= 9)
			hex[len--] = 48 + (n % 16);
		else
			hex[len--] = 87 + (n % 16);
		n = n / 16;
	}
	return (hex);
}

char    *ft_itohex(int n)
{
	char	*hex;
	int		len;

	len = ft_len_num(n);
	if (!n)
		len = 1;
	if (!(hex = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	return (hex = ft_int_to_str(n, len, hex));
}

char *ft_three_join(char *sr, char *sg, char *sb, int len)
{
    char *dest;
	char *tmp;
	char *tmp2;
    int i;
    int j;
    int k;
	int l;

    if (!(dest = (char*)malloc(sizeof(char) * len + 1)))
        return (NULL);
	i = -1;
	while (++i < 1)
		*(dest + i) = '#';
    j = -1;
    while (++j < ft_strlen(sr))
		*(dest + i++) = *(sr + j);
    k = -1;
    while (++k < ft_strlen(sg))
        *(dest + i++) = *(sg + k);
	l = -1;
    while (++l < ft_strlen(sb))
        *(dest + i++) = *(sb + l);
	*(dest + i++) = '\0';
	return (dest);	
}

char *hv_rgb2hex(int r, int g, int b)
{
    int len;
    char *aux;
    char *tmp;
    char *rgb;
    char *color_r;
    char *color_g;
    char *color_b;

	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		return (ft_strdup("Error : Para rgb inserta valores entre 0 y 255"));
    len = ft_len_num(r) + ft_len_num(g) + ft_len_num(b);
    color_r = ft_itohex(r);
    color_g = ft_itohex(g);
    color_b = ft_itohex(b);
    rgb = ft_three_join(color_r, color_g, color_b, len);
    free(color_r);
    free(color_g);
    free(color_b);
    return (rgb);  
}
