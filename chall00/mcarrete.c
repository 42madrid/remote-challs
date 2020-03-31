/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mcarrete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 15:07:53 by mcarrete          #+#    #+#             */
/*   Updated: 2020/03/30 15:36:15 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_itoa_hex(int n)
{
	unsigned	int			nb;
	char					*str;
	unsigned long			rem;
	int						i;

	nb = n;
	i = 0;
	while (nb >= 1)
	{
		nb = nb / 16;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char ) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	i--;
	nb = n;
	while (i >= 0)
	{
		rem = nb % 16;
		str[i] = rem < 10 ? rem + '0' : rem + 'W';
		nb = nb / 16;
		i--;
	}
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned long	i;
	char			*ptr;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char		*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ft_bzero(str, ft_strlen(s1) + ft_strlen(s2) + 1);
	while (j < ft_strlen(s1))
	{
		str[j] = s1[j];
		j++;
	}
	i = j;
	j = 0;
	while (j < ft_strlen(s2))
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	return (str);
}

char *hv_rgv2hex(int r, int g, int b)
{

	char *_r;
	char *_g;
	char *_b;
	char *rgb;

	_r = ft_itoa_hex(r);
	_g = ft_itoa_hex(g);
	_b = ft_itoa_hex(b);
	if (ft_strlen(_r) < 2)
		_r = ft_strjoin("0", _r);
	if (ft_strlen(_g) < 2)
		_g = ft_strjoin("0", _g);
	if (ft_strlen(_b) < 2)
		_b = ft_strjoin("0", _b);
	rgb = ft_strjoin("#", _r);
	rgb = ft_strjoin(rgb, _g);
	rgb = ft_strjoin(rgb, _b);
	return (rgb);
}
