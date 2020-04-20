/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antomart.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <Antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 14:52:37 by Antomart          #+#    #+#             */
/*   Updated: 2020/04/16 14:52:37 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
 
int ft_ie_except_after_c(char* str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (((str[i] == 'i' || str[i] == 'I') && (str[i + 1] == 'e' )) || ((str[i] == 'c' || str[i] == 'C') && (str[i + 1] == 'e') && (str[i + 2] == 'i'))) 
        {
            return (1);
        }
	if (((str[i] == 'e' || str[i] == 'E') && (str[i + 1] == 'i')) || ((str[i] == 'c' || str[i] == 'C') && (str[i + 1] == 'i') && (str[i + 2] == 'e')))
	{
		return(0);
	} 
        i++;
    }
    return (1);
}

