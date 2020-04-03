
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

int     main(void)
{
    int result;
    result = hv_necklace("nicole", "papa");
    printf("El resultado para nicole, papa %d\n", result);

    result = hv_necklace("nicole", "icolen");
    printf("El resultado para nicole, icolen %d\n", result); 

    result = hv_necklace("nicole", "lenico");
    printf("El resultado para nicole, lenico %d\n", result);

    result = hv_necklace("nicole", "coneli");
    printf("El resultado para nicole, coneli %d\n", result);

    result = hv_necklace("aabaaaaabaab", "aabaabaabaaa");
    printf("El resultado para aabaaaaabaab, aabaabaabaaa %d\n", result);

    result = hv_necklace("abc", "cba");
    printf("El resultado para abc, cba %d\n", result);

    result = hv_necklace("xxyyy", "xxxyy");
    printf("El resultado para xxyyy, xxxyy %d\n", result);

    result = hv_necklace("xyxxz", "xxyxz");
    printf("EL resultado para xyxxz, xxyxz %d\n", result);

    result = hv_necklace("x", "x");
    printf("El resultado para x, x %d\n", result);

    result = hv_necklace("x", "xx");
    printf("El resultado para x, xx %d\n", result);

    result = hv_necklace("x", "");
    printf("El resultado para x, null %d\n", result);

    result = hv_necklace("", "");
    printf("El resultado para (null, null) %d\n", result);

    return (0);    
}