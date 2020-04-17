/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edramire.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 12:32:50 by edramire          #+#    #+#             */
/*   Updated: 2020/04/16 13:35:02 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static char	*ft_to_lower(char *str, size_t len)
{
	char	*aux;

	aux = malloc(sizeof(char) * (len + 1));
	if (aux == NULL)
		return (NULL);
	aux[len] = '\0';
	while (len > 0 ? len-- : 0)
		aux[len] = str[len] + (str[len] >= 'A' && str[len] <= 'Z' ? 32 : 0);
	return (aux);
}

int			ft_ie_except_after_c(char *str)
{
	size_t	i;
	size_t	len;
	int		resp;
	char	*aux;

	if (str == NULL)
		return (1);
	len = strlen(str);
	aux = ft_to_lower(str, len);
	if (aux == NULL)
		return (1);
	i = -1;
	resp = -1;
	while (++i < len && resp == -1)
	{
		if (aux[i] == 'i')
		{
			if (i + 1 < len && aux[i + 1] == 'e')
				resp = ((i - 1 >= 0) && (aux[i - 1] != 'c') ? 1 : 0);
			else if (i - 1 >= 0 && aux[i - 1] == 'e')
				resp = ((i - 2 >= 0) && (aux[i - 2] == 'c') ? 1 : 0);
		}
	}
	free(aux);
	return (resp == -1 ? 1 : resp);
}
