/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darodrig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <darodrig@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 13:42:57 by darodrig          #+#    #+#             */
/*   Updated: 2020/04/02 13:42:57 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
** The function creates a temporary concatenation of s2 twice,
** so that s1 has to appear in the same order there. Both strings need to be
** the same length.
*/

int hv_necklace(char *s1, char *s2)
{
	char *twice;
	int ret;

	if (strlen(s1) != strlen(s2))
		return (0);
	twice = malloc(strlen(s2) * 2 * sizeof(char) + 1);
	strcpy(twice, s2);
	strcat(twice, s2);
	if (strstr(twice, s1) == NULL)
		ret = 0;
	else
		ret =  1;
	free(twice);
	return (ret);
}
