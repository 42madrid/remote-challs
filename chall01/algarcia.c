#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int		ft_strlen(char *s1)
{
	int i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

int		ft_compare(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (s1[i] == s2[j])
		{
			i++;
			j = 0;
		}			
		else
			j++;
		if (s2[j] == '\0')
			return (0);
	}
	return (1);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	str = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return(str);
}

int		ft_order(char *s1, char *s2)
{
	int		i;
	int		contador;
	char	tmp;
	char	*aux;

	i = 0;
	contador = 0;
	aux = ft_strdup(s1);
	while (aux[i])
	{
		if (aux[i] == s2[i])
			i++;
		else
		{
			tmp = aux[0];
			while (aux[i + 1] != '\0')
			{
				aux[i] = aux[i + 1];
				i++;
			}
			aux[ft_strlen(aux) - 1] = tmp;
			aux[ft_strlen(aux)] = '\0';
			i = 0;
			contador++;
			i = 0;
		}
		if (contador > ft_strlen(s1))
		{
			free(aux);
			return(0);
		}
	}
	free(aux);
	return (1);
}

int hv_necklace(char *s1, char *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return(0);
	else if (ft_compare(s1, s2) == 0)
		return(0);
	else if (ft_order(s1, s2) == 0)
		return(0);
	else
	return(1);	
}

int main()
{
	printf("%d", hv_necklace("nicole", "icolen")); printf(" == 1\n");
    printf("%d", hv_necklace("nicole", "lenico")); printf(" == 1\n");// == 1
    printf("%d", hv_necklace("nicole", "coneli")); printf(" == 0\n");// == 0
    printf("%d", hv_necklace("aabaaaaabaab", "aabaabaabaaa")); printf(" == 1\n");// == 1
    printf("%d", hv_necklace("abc", "cba")); printf(" == 0\n");// == 0
    printf("%d", hv_necklace("xxyyy", "xxxyy")); printf(" == 0\n");// == 0
    printf("%d", hv_necklace("xyxxz", "xxyxz")); printf(" == 0\n");// == 0
    printf("%d", hv_necklace("x", "x")); printf(" == 1\n");// == 1
    printf("%d", hv_necklace("x", "xx")); printf(" == 0\n");// == 0
    printf("%d", hv_necklace("x", "")); printf(" == 0\n");// == 0
    printf("%d", hv_necklace("", "")); printf(" == 1\n");// == 1
    printf("%d", hv_necklace("", "a")); printf(" == 0\n");// == 1
	return (0);
}