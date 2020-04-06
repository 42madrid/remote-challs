/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrosario.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikiencolor <mikiencolor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 21:21:08 by mikiencolor       #+#    #+#             */
/*   Updated: 2020/04/02 22:12:13 by mikiencolor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int    ft_strlen(char const *s)
{
	char const *ptr;

	ptr = s;
	while (*ptr++ != 0)
	{
	}
	return (--ptr - s);
}

int             ft_strcmp(char const *s1, char const *s2, unsigned int n)
{
	unsigned char u1;
	unsigned char u2;

	while (n-- > 0)
	{
		u1 = (unsigned char)*s1++;
		u2 = (unsigned char)*s2++;
		if (u1 != u2)
			return (u1 - u2);
		if (u1 == '\0')
			return (0);
	}
	return (0);
}

int             hv_necklace(char *s1, char *s2)
{
    unsigned int     len;
    int              i;

    if (!s1 || !s2 || ((len = ft_strlen(s1)) != ft_strlen(s2)))
        return (0);
    if (*s2 == *s1 && (!(ft_strcmp(s1, s2, len))))
        return (1);
    else
    {
        i = 0;
        while (s2[i])
        {
            if (s2[i] != *s1)
                i++;
            else
            {
                if (!(ft_strcmp(s1, &s2[i], len - i)) && \
                (!(ft_strcmp(&s1[len - i], s2, i))))
                    return (1);
                else
                    i++;                
            }
        }
    }
    return (0);
}