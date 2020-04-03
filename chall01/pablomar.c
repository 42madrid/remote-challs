
#include <stdio.h>

int     ft_strlen(char const *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int     compare(char *s1, char *s2, int j)
{
    int i;

    i = 0;
    while (s1[i] != '\0')
    {
        if (s1[i] != s2[j])
            return (0);
        i++;
        j++;
        if (s2[j] == '\0')
            j = 0;
    }
    return (1);
}


int     hv_necklace(char *s1, char *s2)
{
    int i;
    int j;
    int len_s1;
    int len_s2;

    i = 0;
    j = 0;
    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);
    if (len_s1 != len_s2)
        return (0);
    if (len_s1 == len_s2 && len_s1 == 1 && s1[i] == s2[j])
        return (1);
    if (len_s1 == len_s2 && len_s1 == 0 && s1[i] == s2[j])
        return (1);
    while (s2[j] != '\0')
    {
        j++; 
         if (compare(s1,s2,j))
            return (1);
    }
    return (0);
}