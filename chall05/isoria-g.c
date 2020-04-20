/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isoria-g.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 18:48:01 by marvin            #+#    #+#             */
/*   Updated: 2020/04/16 18:48:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

int ft_check(char *str)
{
    if (strstr(str, "aei") != NULL || strstr(str, "bei") != NULL ||
        strstr(str, "dei") != NULL || strstr(str, "eei") != NULL ||
        strstr(str, "fei") != NULL || strstr(str, "gei") != NULL ||
        strstr(str, "hei") != NULL || strstr(str, "iei") != NULL ||
        strstr(str, "jei") != NULL || strstr(str, "kei") != NULL ||
        strstr(str, "lei") != NULL || strstr(str, "mei") != NULL ||
        strstr(str, "nei") != NULL || strstr(str, "ñei") != NULL ||
        strstr(str, "oei") != NULL || strstr(str, "pei") != NULL ||
        strstr(str, "qei") != NULL || strstr(str, "rei") != NULL ||
        strstr(str, "sei") != NULL || strstr(str, "tei") != NULL ||
        strstr(str, "uei") != NULL || strstr(str, "vei") != NULL ||
        strstr(str, "wei") != NULL || strstr(str, "xei") != NULL ||
        strstr(str, "yei") != NULL || strstr(str, "zei") != NULL ||
        strstr(str, "cie") != NULL)
        return (0);
    else
        return (1);
}

int ft_ie_except_after_c(char* str)
{
    if (ft_strlen(str) <= 1)
        return (1);
    else if (ft_strlen(str) == 2 && str != "ei")
        return (1);
    else if (ft_strlen(str) > 2 && ft_check(str) == 1)
        return (1);
    else
        return (0);
}