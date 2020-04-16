/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jtrancos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 13:01:08 by jtrancos          #+#    #+#             */
/*   Updated: 2020/04/16 13:31:06 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_ie_except_after_c(char* str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'e' && str[i + 1] == 'i' && str[i - 1] != 'c')
			return (0);
		if (str[i] == 'i' && str[i + 1] == 'e' && str[i - 1] == 'c')
			return (0);
		i++;
	}
	return (1);
}
/*
**	int	main(void)
**{
**	printf("%d\n", ft_ie_except_after_c("fiery"));
**	return (0);
**}
*/
