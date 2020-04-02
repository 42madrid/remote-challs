#include <string.h>

int hv_necklace(char *s1, char *s2)
{
	int		l1;	
	int		i;	
	int		j;	
	int		k;	

	if (!s1 || !s2)
		return (0);
	l1 = strlen(s1);
	i = 0;
	k = 0;
	j = 0;
	if (l1 != (int)strlen(s2))
		return (0);
	if (!strcmp(s1, s2))
		return (1);
	while (i < l1)	
	{
		while (s2[i + j])
		{
			if (s2[i + j] != s1[j])
				break;
			j++;
		}
		while (j < l1)
		{
			if (s2[k] != s1[j])
				break;
			j++;
			k++;
		}
		if (j == l1)
			return (1);
		j = 0;
		k = 0;
		i++;
	}
	return (0);
}
