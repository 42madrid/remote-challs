/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jbaringo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 13:22:35 by marvin            #+#    #+#             */
/*   Updated: 2020/04/02 13:22:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		check(int i, char *s1, char *s2)
{
	int	j;

	j = 0;
	while (s1[j])
	{
		if (i == ft_strlen(s2))
			i = 0;
		if (s2[i] != s1[j])
			return (0);
		j++;
		i++;
	}
	return (1);
}

int		hv_necklace(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	if (s1 == "" && s2 == "")
		return (1);
	while (i < ft_strlen(s1))
	{
		if (check(i, s1, s2) == 1)
			return (1);
		i++;
	}
	return (0);
}
