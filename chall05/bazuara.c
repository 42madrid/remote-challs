/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ie_except_after_c.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 12:44:44 by bazuara           #+#    #+#             */
/*   Updated: 2020/04/16 13:51:24 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		ft_ie_except_after_c(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 1;
	if (len < 3)
		return (1);
	while (i < len)
	{
		if (str[i] == 'i')
		{
			if ((str[i + 1] == 'e') && (str[i - 1] != 'c'))
				return (1);
		}
		if (str[i - 2] == 'c' && str[i - 1] == 'e')
			return (1);
		i++;
	}
	return (0);
}
