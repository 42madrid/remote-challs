/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antomart.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <Antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 16:28:00 by Antomart          #+#    #+#             */
/*   Updated: 2020/03/30 16:28:00 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strjoin_rgb(char *r, char *g, char *b)
{
    int i;
    int j;
    int c;
    char *str;

    i = ft_strlen(r);
    j = ft_strlen(g);
    c = ft_strlen(b);
    str = (char *)malloc(sizeof(char) *(i + j + c + 2));
    str[0] = '#';
    i = 0;
    j = 0;
    c = 0;
    while (r[i])
    {
        str[i + 1] = r[i];
        i++;
    }
    while (g[j])
    {
        str[i + j + 1] = g[j];
        j++;
    }
    while (b[c])
    {
        str[i + j + c + 1] = b[c];
        c++;
    }
    str[i + j + c + 1] = '\0';
    return (str);
}

char *ft_itoa_base(unsigned int nb)
{
    unsigned int num;
    unsigned int len;
    char *str;
    char *base;

    len = 2;
    num = nb;
    base = "0123456789abcdef";
    str = (char *)malloc(sizeof(char) * (len + 1));
    num = nb;
    if(num <= 15)
    	str[0] = '0';
    if(num == 0)
    {
        str[0] = '0';
        str[1] = '0';
    }
    str[len] = '\0';
    if (!num)
        str[0] = '0';
    while (num)
    {
        str[--len] = base[num % 16];
        num /= 16;
    }
    return (str);
}

char *hv_rgb2hex(int r, int g, int b)
{
    char *red;
    char *green;
    char *blue;
    char *hexa;

    if (!(hexa = malloc(sizeof(char) * 8)))
		return (0);
    if ((r <= 255 && r >= 0) && (b <= 255 && b >= 0) && (g <= 255 && g >= 0))
    {
        red = ft_itoa_base(r);
        green = ft_itoa_base(g);
        blue = ft_itoa_base(b);
        hexa = ft_strjoin_rgb(red, green, blue);
	free(red);
	red = NULL;
	free(green);
	green = NULL;
	free(blue);
	blue = NULL;
        return (hexa);
    }
    else 
        return(NULL);
}

