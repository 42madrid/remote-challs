/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mpernia-.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 18:35:22 by mpernia-          #+#    #+#             */
/*   Updated: 2020/04/02 21:17:20 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(const char *s1, const char *s2, int n)
{
	int i;

	i = 0;
	while (n-- && (*(s1 + i) || *(s2 + i)))
	{
		if (*((unsigned char*)s1 + i) != *((unsigned char*)s2 + i))
			return (*((unsigned char*)s1 + i) - *((unsigned char*)s2 + i));
		++i;
	}
	return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (*(s + i))
			++i;
	}
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, int len)
{
	int	needle_size;
	int	haystack_size;
	int	i;

	needle_size = ft_strlen(needle);
	if (!needle_size)
		return ((char*)haystack);
	i = 0;
	haystack_size = ft_strlen(haystack);
	while (len-- >= needle_size && (haystack_size - i) >= needle_size)
	{
		if (*(haystack + i) == *needle &&
				!ft_strncmp(haystack + i, needle, needle_size))
			return ((char*)haystack + i);
		++i;
	}
	return (0);
}

int find_str(char *s1, char *s2, int len)
{
	char *aux;
	int n;

	n = len;
	aux = s2;
	while(*aux != '\0' && ft_strnstr(s1, aux, n) == 0)
	{
		aux++;
		n--;
	}
	if (ft_strnstr(s1, aux, n) != 0)
	{
		aux = s1 + n;
		n = len - n;
		if (ft_strncmp(aux, s2, n) == 0)
			return (1);
	}
	return (0);
}

int hv_necklace(char *s1, char *s2)
{
	int len;

	if (!s1 || !s2)
		return(0);
	len = ft_strlen(s1);
    if (len != ft_strlen(s2))
        return (0);
	if (ft_strncmp(s1, s2, len) == 0)
		return (1);
	return(find_str(s1, s2, len));
}
