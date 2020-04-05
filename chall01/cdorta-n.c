/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdorta-n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdorta-n <cdorta-n@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 12:51:10 by cdorta-n          #+#    #+#             */
/*   Updated: 2020/04/02 12:51:10 by cdorta-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int			ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned int	c;

	c = 0;
	while ((c < n) && (s1[c] != '\0' || s2[c] != '\0'))
	{
		if (s1[c] != s2[c])
			return ((unsigned char)s1[c] - (unsigned char)s2[c]);
		else
			c++;
	}
	return (0);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*p;
	size_t				c;

	c = 0;
	if (s == NULL)
		return (NULL);
	if (!(p = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (c < len)
	{
		p[c] = s[start];
		c++;
		start++;
	}
	p[c] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*p;
	int			i;
	int 		j;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (!(p = malloc(sizeof(*p) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (p);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int 	hv_necklace(char *s1, char *s2)
{
	char    *temp1;
    char    *temp2;
    int        i;
    int        j;

    if ((i = ft_strlen(s1)) != (j = ft_strlen(s2)))
        return(0);
    temp1 = (char *)malloc(sizeof(*s1) * (i + 1));
    temp2 = (char *)malloc(sizeof(*s1) * (i + 1));
    while (i >= 0)
    {
        if (ft_strncmp(s1,s2, ft_strlen(s1)) == 0)
        {
            free(temp1);
            free(temp2);
            return (1);
        }
        temp1[0] = s2[j - 1];
		temp1[1] = '\0';
        temp2 = ft_substr(s2, 0, s2[j - 2]);
        s2 = ft_strjoin(temp1, temp2);
        i--;
    }
        free(temp1);
        free(temp2);
    return (0);
}