/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isoria-g.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 16:50:27 by marvin            #+#    #+#             */
/*   Updated: 2020/04/02 16:50:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

int hv_necklance(char *s1, char *s2)
{
    int     i;
    int     j;
    char    *temp;
    int     flag;
    
    i = 0;
    j = 0;
    if (ft_strlen(s1) != ft_strlen(s2))
        return (0);
    while (i < ft_strlen(s1))
        j += s1[i] - s2[i++];
    if (j != 0)
        return (0);
    temp = (char *)malloc(ft_strlen(s2)+ft_strlen(s2)+1);
    i = 0;
    while (i < ft_strlen(s2))
    {
        temp[i] = s2[i];
        temp[i + ft_strlen(s2)] = s2[i];
        i++;
    }
    i = 0;
    while (i < ft_strlen(s1))
    {
        j = 0;
        flag = 0;
        while (j < ft_strlen(s1))
        {
            if (s1[j] == temp[i+j])
                flag++;
            j++;
        }
        if (flag == strlen(s2))
            return (1);
        i++;
    }
    free(temp);
    return (0);
}
