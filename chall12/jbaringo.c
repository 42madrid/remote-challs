#include <stdlib.h>
#include <string.h>

char *ft_substr(char *str, int start, int finish)
{
	char *s;
	int i = 0;

    if (!(s = malloc(sizeof(char) * ((finish - start) + 1))))
        return (NULL);
    while (str[start] && start < finish)
    {
        s[i] = str[start];
        start++;
        i++;
    }
	s[i] = '\0';
	return (s);
}

int check_parenthesis(char *str)
{
    int left = 0;
    int right = 0;
    int i = 0;

    while (str[i])
    {
        if (str[i] == '(')
            left++;
        else if (str[i] == ')')
            right++;
        i++;
    }
    if (left != right)
        return (-1);
    return (left);
}

char *reverse_str(char *str)
{
    char *s;
    int len = strlen(str);
    int i = 1;

    if (!(s = malloc(sizeof(char) * len + 3)))
        return (NULL);
    s[0] = '(';
    len--;
    while (len >= 0)
    {
        if (str[len] == '(')
            s[i] = ')';
        else if (str[len] == ')')
            s[i] = '(';
        else
            s[i] = str[len];
        i++;
        len--;
    }
    s[i] = ')';
    s[i +1] = '\0';
    return (s);
}

char *join(char *s, char *reverted, int start, int end)
{
    char *s2;
    int i = 0;
    int j = 0;
    int k = 0;

    if (!(s2 = malloc(sizeof(char) * strlen(s) + 1)))
        return (NULL);
    while (s[i])
    {
        if (i == start)
        {
            while (i < end)
            {
                s2[j] = reverted[k];
                j++;
                k++;
                i++;
            }
        }
        s2[j] = s[i];
        j++;
        i++;
    }
    s2[j] = '\0';
    return (s2);
}

char *ft_reverse_parenthesis(const char *str)
{
    char *s = strdup(str);
    int parenthesis;
    int i = 0;
    int left = 0;
    int flag = 0;
    int j = 0;

    if ((parenthesis = check_parenthesis(s)) == -1)
        return(strdup("NULL"));
    while (parenthesis > 0)
    {
        if (s[i] == '(')
            left++;
        if (left == parenthesis)
        {
            j = i;
            while (s[j])
            {
                if (s[j] == '(')
                    flag++;
                if (s[j] == ')')
                {
                    flag--;
                    if (flag == 0)
                        break;
                }
                j++;
            }
            s = join(s, reverse_str(ft_substr(s, i + 1, j)), i, j);
            parenthesis--;
            i = 0;
            left = 0;
        }
        else
            i++;
    }
    return (s);
}
