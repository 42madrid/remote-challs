/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   egarcia-.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <emilioggo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 12:25:16 by egarcia-          #+#    #+#             */
/*   Updated: 2020/04/01 12:57:44 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char   *ft_itoa_hex(int nbr)
{
    char *ret;
    int i = 7;

    ret = malloc(sizeof(char) * 8);
    ret[7] = '\0';
    ret[0] = '#';
    while (i--)
    {
        ret[i] = nbr % 16 + (nbr % 16 > 9 ? 'W' : '0');
        nbr /= 16;
    }
    return (ret);
}

char   *hv_rgb2hex(int r, int g, int b)
{
    int nbr;
    
    nbr = r * 65536 + g * 256 + b;
    return(ft_itoa_hex(nbr));
}
