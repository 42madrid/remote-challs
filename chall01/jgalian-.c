#include	<unistd.h>
#include	<stdlib.h>

int	ft_strlen(const char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
int	check_slide(int i, int len2, char *s1, char *s2, char *aux);

int	hv_necklace(char *s1, char *s2)
{
	char	*aux;
	int	i;
	int	len1;
	int	len2;

	i = 0;
	aux = NULL;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1 && !s2)
		return (1);
	if (len1 != len2 || !s1 || !s2)
		return (0);
	if (!ft_strncmp(s1, s2, len2))
		return (1);
	return (check_slide(i, len2, s1, s2, aux));
}

int	check_slide(int i, int len2, char *s1, char *s2, char *aux)
{
	int	j;

	s2 = ft_strdup(s2);
	while (i++ < len2)
	{
		aux = (char*)malloc(len2 + 1);
		j = 1;
		while (j < len2)
		{
			aux[j - 1] = s2[j];
			j++;
		}
		aux[j - 1] = s2[0];
		aux[j] = '\0';
		if (!ft_strncmp(s1, aux, len2))
		{
			free(s2);
			free(aux);
			return (1);
		}
		free(s2);
		s2 = ft_strdup(aux);
		free(aux);
	}
	free(s2);
	return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i] || str1[i] == '\0' || str2[i] == '\0')
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*str1;
	char	*str2;
	size_t	i;

	i = 0;
	str1 = (char *)s1;
	str2 = (char*)malloc(ft_strlen(str1) + 1);
	if (str2 == NULL)
		return (NULL);
	while (str1[i] != '\0')
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}
