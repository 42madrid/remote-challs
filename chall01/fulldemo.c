/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fulldemo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulldemo <fulldemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 15:52:54 by fulldemo          #+#    #+#             */
/*   Updated: 2020/04/02 17:22:58 by fulldemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int hv_comparer(char *s1, char *s2, int i, int flag)
{
	int j;
	int l1;

	l1 = ft_strlen(s1);
	if (l1 != 0)
		l1 -= 1;
	j = 0;
	if(s2[i] == '\0')
			i = 0;
	while (s2[i] == s1[j] && j != l1)
	{
		i++;
		j++;
		flag++;
		if(s2[i] == '\0')
			i = 0;
	}
	if (s2[i] != s1[j] && j != l1 && flag != l1)
		return (hv_comparer(s1, s2, i + 1, flag));
	if (s2[i] != s1[j] && flag == l1)
		return (0);
	return (1);
}

int hv_necklace(char *s1, char *s2)
{
	int		i;
	int		flag;
	
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	i = 0;
	flag = 0;
	while (s1[0] != s2[i])
		i++;
	return (hv_comparer(s1, s2, i, flag));
}
