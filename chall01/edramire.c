/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edramire.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 17:15:16 by edramire          #+#    #+#             */
/*   Updated: 2020/04/02 17:56:05 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int hv_necklace(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*ptr;
	int		index;

	len_s1 = strlen(s1);
	len_s2 = strlen(s2);
	if (len_s1 != len_s2)
		return (0);
	else if (len_s1 == 0)
		return (1);
	ptr = s2;
	while (ptr != NULL)
	{
		ptr = strchr(ptr, *s1);
		if (ptr == NULL)
			return (0);
		index = (ptr - s2) / sizeof(char);
		if (strncmp(s1, ptr, len_s2 - index) == 0 &&
			strncmp(s1 + (len_s1 - index), s2, index) == 0)
			break;
		++ptr;
	}
	return (1);
}
