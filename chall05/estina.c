/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estina.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 14:07:38 by estina            #+#    #+#             */
/*   Updated: 2020/04/16 14:59:57 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	ft_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

static int	ft_check_c(char c, int type)
{
	if (c == 'c')
		return (type ? 1 : 0);
	return (type ? 0 : 1);

}

int			ft_ie_except_after_c(char* str)
{
	int		i;
	int		rule;

	if (!str || !*str)
		return (0);
	i = 0;
	rule = 2;
	while (str[i] && rule)
	{
		if (ft_lower(str[i]) == 'e' && ft_lower(str[i + 1]) == 'i' && i)
			rule = ft_check_c(ft_lower(str[i - 1]), 1);
		if (ft_lower(str[i]) == 'i' && ft_lower(str[i + 1]) == 'e')
			rule = i ? ft_check_c(ft_lower(str[i - 1]), 0) : 1;
		i++;
	}
	return (rule == 2 ? 1 : rule);
}
