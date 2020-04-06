#include <stdlib.h>

int	ft_strlen(char *s)
{
	int l;

	l = 0;
	while(s[l])
		l++;
	return(l);
}

int	ft_compare(char *s1, int *s2, int len)
{
	int l;

	l = 0;
	while(l < len)
	{
		if (s1[l] == s2[l])
			l++;
		else
			return(0);
	}
	return(1);
}

int	hv_necklace(char *s1, char *s2)
{
	int				l;
	int				q;
	int				len_s1;
	int				len_s2;
	unsigned char	aux;
	int				*tmp;

	l = 0;
	q = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s1 != len_s2)
		return (0);
	tmp = (int *)malloc(sizeof(int) * len_s1);
	while(s2[q])
	{
		tmp[q] = s2[q];
		q++;
	}
	if(ft_compare(s1, tmp, len_s1))
	{
		free(tmp);
		return (1);
	}
	while (s1[l])
	{
		q = 0;
		while(len_s1)
		{
			if(ft_compare(s1, tmp, len_s1))
				return (1);
			aux = tmp[q];
			tmp[q] = tmp[q + 1];
			tmp[q + 1] = aux;
			q++;
			len_s1--;
		}
		l++;
	}
	free(tmp);
	return (0);
}
