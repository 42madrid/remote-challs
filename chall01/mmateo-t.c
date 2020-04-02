/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmateo-t.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 16:20:38 by miguel            #+#    #+#             */
/*   Updated: 2020/04/02 23:03:29 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

static int checking(char *s1, char *s2, int len)
{
	int i;
	int j;
	int k;
	int l;

	j = 0;
	i = 0;
	l = 0;
	while (l < len)
	{
		k = 0;

		while (s1[i] != s2[j] && j < len && i < len)
		{
			j++;
		}
		while (k < len)
		{

			if (s1[i] == '\0')
				i = 0;
			if (s2[j] == '\0')
				j = 0;
			if (s1[i] == s2[j])
			{
				i++;
				j++;
			}
			else
			{
				break;
			}
			k++;
			if (k == len)
			{
				return (1);
			}
		}
		l++;
	}
	return (0);
}

int hv_necklace(char *s1, char *s2)
{
	int len_s1;
	int len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);

	if (len_s1 != len_s2)
		return (0);
	if (!len_s1 && !len_s2)
	{
		return (1);
	}
	return (checking(s1, s2, len_s1));
}
