/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmartin-.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:06:55 by gmartin-          #+#    #+#             */
/*   Updated: 2019/04/02 18:40:08 by gmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int hv_necklace(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int len;
    len = ft_strlen(s1);
    if (len != ft_strlen(s2))
        return(0);
    if (len == 0)
        return(1);
    while(l < len)
    {
        l++;
        k = 0;
        while (s1[i] != s2[j])
            i++;
        while (k < len && s1[i] == s2[j])
        {
            j++;
            i++;
            if (s1[i] == '\0')
                i = 0;
            if (s2[j] == '\0')
                j = 0;
            k++;
            if (k == ft_strlen(s2) && s1[i] == s2[j])
                return(1);
        }
    }
    return(0);
}
