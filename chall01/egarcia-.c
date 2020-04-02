/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   egarcia-.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <emilioggo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 15:26:48 by egarcia-          #+#    #+#             */
/*   Updated: 2020/04/02 16:30:13 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *s1)
{
    int i;

    i = 0;

    while (s1[i])
        i++;
    return (i);
}

int ft_strcmp(char *s1, char *s2)
{
    while (*s1 || *s2)
    {
        if (*s1 != *s2)
            return (1);
        s1++;
        s2++;
    }
    return 0;
}

int hv_necklace(char *s1, char *s2)
{
    int i;
    int len;
    char *aux;
    int j;
    
    len = ft_strlen(s1);
    i = len;
    j = 0;
    aux = malloc(sizeof(char) *  (len * 2 + 1));
    while (s1[j])
    {
        aux[j] = s1[j];
        j++;
    }
    aux[j] = 0;
    if (len == 0 && ft_strlen(s2) == 0)
        return 1;
    while (len--)
    {
        if (ft_strcmp(aux, s2) == 0)
            return (1);
        aux[i] = *aux;
        aux[i + 1] = 0;
        aux++;
    }
    return (0);
}
/*
int main()
{
    printf("%d\n", hv_necklace("nicole", "icolen"));
    printf("%d\n",hv_necklace("nicole", "lenico"));
    printf("%d\n",hv_necklace("nicole", "coneli"));
    printf("%d\n",hv_necklace("aabaaaaabaab", "aabaabaabaaa"));
    printf("%d\n",hv_necklace("abc", "cba"));
    printf("%d\n",hv_necklace("xxyyy", "xxxyy"));
    printf("%d\n",hv_necklace("xyxxz", "xxyxz"));
    printf("%d\n",hv_necklace("x", "x"));
    printf("%d\n",hv_necklace("x", "xx"));
    printf("%d\n",hv_necklace("x", ""));
    printf("%d\n", hv_necklace("", ""));
    return 0;
}
*/