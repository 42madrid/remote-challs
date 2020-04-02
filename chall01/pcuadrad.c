#include <stdio.h>

int     ft_strlen(char *s1)
{
    int     i;

    i = 0;
    while (s1[i])
        i++;
    return (i);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

/*
**  Function int hv_necklace(char *s1, char *s2)
**
**  vars: 
**      - is1: counter of the s1 string
**      - is2: counter of the s2 string
**      - lens1: length if the s1 string 
**      - saves1: number of the last difference between characters in the string
**      - i: auxiliar counter
**
**  return value (int):
**      1 if both strings are equal independently of how they start
**      0 if not are equal
**
**  Explanation:
**      We compare the first string with the second one until we have a match, 
**      once it matches we continue comparing until we reach the end of the second string.
**      Once we reach the end we see if something has been saved in the variable
**      save1 (it would be that something has not previously matched), if so, we start
**      to compare the first string again from the beginning to the character where
**      they naturally started to match.
*/

int hv_necklace(char *s1, char *s2)
{
    int     is1;
    int     lens1;
    int     is2;
    int     saves1;
    int     i;

    is1 = -1;
    saves1 = -1;
    lens1 = ft_strlen(s1);
    if (lens1 != ft_strlen(s2))
        return (0);
    if (!ft_strcmp(s1, s2))
        return (1);
    while (s1[++is1])
    {
        is2 = 0;
        if (s1[is1] != s2[is2])
            saves1 = is1;
        while (s1[is1 + is2] == s2[is2] && s2[is2] && s1[is1 + is2])
        {
            is2++;
            if ((is1 + is2) >= lens1 && saves1 != -1)
            {
                i = 0;
                while (i < saves1 && s1[i] == s2[is2 + i])
                    i++;
                if (i == saves1)
                    return (1);
            }
        }
    }
    return (0);
}
