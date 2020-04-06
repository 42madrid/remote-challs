/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antomart.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <Antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 13:17:05 by Antomart          #+#    #+#             */
/*   Updated: 2020/04/02 13:17:05 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_strcmp(char *s1, char *s2)
{
    int i;
    int flag;

    flag = 0;
    i = 0;
    while (s1[i])
    {
        if (s1[i] > s2[i] || s1[i] < s2[i])
            flag = 1;
        i++;
    }
    return (flag);
}

char *ft_strdup(char *s1)
{
    int i;
    int len;
    char *s2;

    i = 0;
    len = ft_strlen(s1);
    s2 = (char *)malloc(sizeof(char) * (len + 1));
    while (s1[i])
    {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';
    return (s2);
}

char *switch_one(char *s1)
{
    char	aux;
	char	*sdest;
	int     len;
    int     i;
    
    i = 0;
    len = ft_strlen(s1);
    aux = s1[0];
    sdest = ft_strdup(s1);
    while (i < len - 1)
    {
        sdest[i] = s1[i + 1];
        i++;
    }
    sdest[i] = aux;
    return (sdest);
}

int hv_necklace(char *s1, char *s2)
{
    int i;
    int len;
    i = 0;
    len = ft_strlen(s1);
   
    if (len != ft_strlen(s2))
        return (0);
    
    if (ft_strlen(s1) == 0 && ft_strlen(s2) == 0)
        return (1);
    while (i < len)
    {
        if (ft_strcmp(s1, s2) == 0)
            return (1);
        s1 = switch_one(s1);
        i++;
    }
    return (0);
}
