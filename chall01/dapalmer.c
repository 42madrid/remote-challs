#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	len = -1;
	while (s1[++len])
		dest[len] = s1[len];
	dest[len] = '\0';
	return (dest);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2++)
			return (*(unsigned char *)s1 - *(unsigned char *)--s2);
        s1++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
    int i;

	i = 0;
	while (s[i++])
		;
	return ((s == NULL) ? 0 : i - 1);
}

char	*ft_substr(char *s, char end, unsigned int start, size_t len)
{
	size_t	i;
	char	*tab;

	i = 0;
	if (!s)
		return (NULL);
	if (!(tab = (char *)malloc((len + 2) * sizeof(char))))
		return (NULL);
	while (i < len)
	{
		tab[i] = s[start + i];
		i++;
	}
    free(s);
    tab[i] = end;
	tab[i + 1] = '\0';
	return (tab);
}

int     hv_necklace(char *s1, char *s2)
{
    char *tmp;

    if (!s1 || !s2 || ft_strlen(s1) != ft_strlen(s2))
        return (0);
    if (ft_strcmp(s1, s2) == 0)
        return (1);

    tmp = ft_strdup(s1);
    while(*(s1++) != '\0')
    {
        if (!ft_strcmp(tmp, s2))
        {
            free(tmp);
            return (1);
        }
        tmp = ft_substr(tmp, tmp[0], 1, ft_strlen(tmp) - 1);
    }
    free(tmp);
    return (0);
}
