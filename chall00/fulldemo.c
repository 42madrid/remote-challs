/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fulldemo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulldemo <fulldemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 15:10:57 by fulldemo          #+#    #+#             */
/*   Updated: 2020/04/02 17:27:49 by fulldemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
 
int		ft_strlen(char const *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*dst;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(dst = malloc(sizeof(dst) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (*s1)
	{
		dst[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		dst[i] = *s2;
		i++;
		s2++;
	}
	dst[i] = '\0';
	return (dst);
}

char *converter(unsigned int i)
{
    char a[16] = "0123456789abcdef";
	char *res;

	if (!(res = (char *)malloc(sizeof(char) * 3)))
		return ("NULL");
	res[1] = a[i % 16];
	i /= 16;
	res[0] = a[i % 16];
	res[2] = '\0';

	return (res);
}

char *hv_rgb2hex(int r, int g, int b)
{
	char *res;
	char *tmp;
	char *aux;

	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		return ("Number out of rank");
	if (!(res = (char *)malloc(sizeof(char) * 2)))
		return ("Error malloc");
	res[0] = '#';
	res[1] = '\0';
	tmp = converter(r);
	aux = ft_strjoin(res, tmp);
	free(res);
	res = aux;
	free(tmp);
	tmp = converter(g);
	aux = ft_strjoin(res, tmp);
	free(res);
	res = aux;
	free(tmp);
	tmp = converter(b);
	aux = ft_strjoin(res, tmp);
	free(res);
	res = aux;
	free(tmp);
	return (res);
}
/*
#include <stdio.h>

int main()
{
	printf("%s", hv_rgb2hex(255,0,16));
	system("leaks a.out");
}
/*