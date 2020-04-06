/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jtrancos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 19:06:50 by jtrancos          #+#    #+#             */
/*   Updated: 2020/04/02 20:56:22 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
int hv_necklace(char *s1, char *s2)
{
	int i;
	int j;
	int q;
	int h;

	i = 0;
	if (strcmp(s1, s2) == 0)
		return (1);
	if (strlen(s1) != strlen (s2))
		return (0);
	if (s1[i] == s2[strlen(s2) - 1])
	{
		if (s1[i + 1] == s2[j])
		{
			if (s1[i + 2] == s2[j + 1])
			return (1);
		}
	}
	q = strlen(s2);
	while (s1[i] != s2[q])
		q--;
	h = q;
	if (s1[i + 1] == s2[h + 1])
	{
		if (s1[strlen(s1) - 1] == s2[h - 1])
		{
			
			return (1);
		}
	}

	return (0);
}
/*
int main ()
{
	printf("%d\n", hv_necklace("nicole", "icolen"));
	printf("%d\n", hv_necklace("nicole", "lenico"));
	printf("%d\n", hv_necklace("nicole", "coneli"));
	printf("%d\n", hv_necklace("aabaaaaabaab", "aabaabaabaaa"));
	printf("%d\n", hv_necklace("abc", "cba"));
	printf("%d\n", hv_necklace("xxyyy", "xxxyy"));
	printf("%d\n", hv_necklace("xyxxz", "xxyxz"));
	printf("%d\n", hv_necklace("x", "x"));
	printf("%d\n", hv_necklace("x", "xx"));
	printf("%d\n", hv_necklace("x", ""));
	printf("%d\n", hv_necklace("", ""));
}*/
