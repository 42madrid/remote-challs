/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jcervill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcervill <jcervill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:44:33 by jcervill          #+#    #+#             */
/*   Updated: 2020/03/30 20:40:21 by jcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

size_t		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*aux;
	size_t	size;

	size = ft_strlen(s);
	if (!(aux = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	else
	{
		while (*s)
		{
			*aux = *s;
			aux++;
			s++;
		}
		*aux = 0;
		return (aux - size);
	}
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	if (!(str = malloc((sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2)) + 1))))
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = 0;
	return (str);
}

static char            *ft_dec2hex(unsigned int n)
{
    unsigned int        aux;
    int                   len;
    char                *str;

    aux = n;
    len = 1;
    while (aux /= 16)
        len++;
    if ((str = (char*)malloc(sizeof(char) * (len + 1))) == 0)
        return (0);
    str[len] = '\0';
    while (len--)
    {
        if ((n % 16) < 10)
            str[len] = n % 16 + '0';
        if ((n % 16) > 9)
            str[len] = n % 16 + 'W';
        n = n / 16;
    }
    return (str);
}

char *hv_rgb2hex(int r, int g, int b)
{
	char *hex;
	char *aux;

	if (!(hex = (char *)malloc(sizeof(char) * 2)))
		return (0);
	else
	{
		hex[1] = '\0';
		hex[0] = '#';
		if (r > 255 || r < 0 || g > 255 || g < 0
			|| b > 255 || b < 0)
			return (0);
		else
		{
			if (r < 10)
			{
				aux = ft_strjoin(hex, "0");
				hex = ft_strdup(aux);
			}
			aux = ft_strjoin(hex, ft_dec2hex(r));
			hex = ft_strdup(aux);
			free(aux);
			if (g < 10)
			{
				aux = ft_strjoin(hex, "0");
				hex = ft_strdup(aux);
			}
			aux = ft_strjoin(hex, ft_dec2hex(g));
			hex = ft_strdup(aux);
			free(aux);
			if (b < 10)
			{
				aux = ft_strjoin(hex, "0");
				hex = ft_strdup(aux);
			}
			aux = ft_strjoin(hex, ft_dec2hex(b));
			hex = ft_strdup(aux);
			free(aux);
		}
	}
	return (hex);
}
