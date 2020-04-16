/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdorta-ntest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdorta-n <cdorta-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 16:18:15 by cdorta-n          #+#    #+#             */
/*   Updated: 2020/04/16 16:48:51 by cdorta-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_ie_except_after_c(char *str)
{
	int c;

	c = 0;
	while (str[c + 1] != '\0')
	{
		if (str[c] == 'e' && str[c + 1] == 'i'
		&& str[c - 1] != 'c')
			return (0);
		else if (str[c] == 'i' && str[c + 1] == 'e'
		&& str[c - 1] == 'c')
			return (0);
		else
			c++;
	}
	return (1);
}
