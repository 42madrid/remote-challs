#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define isinset(a, b) (a == b) ? 1 : 0

static int		count_str(char const *str, char c)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str && isinset(*str, c))
			str++;
		if (*str && !isinset(*str, c))
		{
			count++;
			while (*str && !isinset(*str, c))
				str++;
		}
	}
	return (count);
}

static char		*malloc_string(char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !isinset(str[i], c))
		i++;
	if (!(word = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] && !isinset(str[i], c))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char		**free_split(char ***tabstr)
{
	int i;

	i = 0;
	while (*tabstr[i])
	{
		free(*tabstr[i]);
		i++;
	}
	free(*tabstr);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	int		len;
	char	**tabstr;
	int		i;

	if (!s)
		return (NULL);
	len = count_str(s, c);
	if (!(tabstr = (char **)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && isinset(*s, c))
			s++;
		if (*s && !isinset(*s, c))
		{
			if (!(tabstr[i] = malloc_string((char*)s, c)))
				return (free_split(&tabstr));
			i++;
			while (*s && !isinset(*s, c))
				s++;
		}
	}
	tabstr[i] = NULL;
	return (tabstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;

	if (!s1 && !s2)
		return (NULL);
	else if (s1 && !s2)
		return (strdup(s1));
	else if (!s1 && s2)
		return (strdup(s2));
	else
	{
		if (!(joined = (char*)malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 2))))
			return (NULL);
        strcat(strcat(strcpy(joined, s1), " "), s2);
		return (joined);
	}
}

char    *parseSpaces(char *string)
{
    char    **temp;
    char    *ret = NULL;
    char    *tmp;
    int     i;

    temp = ft_split(string, ' ');
    i = -1;
    while (temp[++i])
    {
        if (!ret)
        {
            ret = strdup(temp[i]);
            free(temp[i]);
        }
        else
        {
            tmp = ft_strjoin(ret, temp[i]);
            free(ret);
            free(temp[i]);
            ret = tmp;
        }
    }
    free(temp);
    return (ret);
}

char    *isGotoStatement(char *str)
{
    regex_t regex;

    if ((regcomp(&regex, "^goto", 0)))
        return (NULL);
    if (!(regexec(&regex, str, 0, NULL, 0)))
    {
        regfree(&regex);
        return (strrchr(str, ' ') + 1);
    }
    regfree(&regex);
    return (NULL);
}

int     infinity_loop(char **gotos, char *newGoto)
{
    int     i;

    i = -1;
    while(gotos[++i])
        if (!strcmp(gotos[i], newGoto))
            return (1);
    return (0);
}

char    *treat_code(char **instr)
{
    char    *ret = NULL;
    char    *tmp;
    char    *pattern = NULL;
    char    **last_pattern = NULL;
    int     countGoto = 1;
    int     idx = 0;

    while (instr[idx])
    {
        if (pattern)
        {
            if (strnstr(instr[idx], pattern, strlen(pattern)))
            {
                idx--;
                pattern = NULL;
            }
        }
        else if ((pattern = isGotoStatement(instr[idx])))
        {
            if (last_pattern && infinity_loop(last_pattern, pattern))
            {
                free(last_pattern);
                return (NULL);
            }
            if (!last_pattern)
            {
                if (!(last_pattern = malloc(sizeof(char*) * (countGoto + 1))))
                    return (NULL);
            }
            else
            {
                if (!(last_pattern = realloc(last_pattern, sizeof(char*) * (++countGoto + 1))))
                    return (NULL);
            }
            last_pattern[countGoto - 1] = pattern;
            last_pattern[countGoto] = NULL;
            idx = -1;
        }
        else
        {
            tmp = strchr(instr[idx], ' ');
            if (!ret)
                ret = strdup(tmp + 1);
            else
            {
                tmp = ft_strjoin(ret, tmp + 1);
                free(ret);
                ret = tmp;
            }
        }
        idx++;
    }
    if (last_pattern)
        free(last_pattern);
    return (ret);
}

void    free_all(char **tofree)
{
    int     i;

    i = -1;
    while (tofree[++i])
        free(tofree[i]);
    free(tofree);
}

char    *ft_goto_parser(const char *code)
{
    char    **parseCode;
    char    *ret;
    int     i;

    if (!(parseCode = ft_split(code, '\n')))
        return (NULL);
    i = -1;
    while (parseCode[++i])
    {
        ret = parseSpaces(parseCode[i]);
        free(parseCode[i]);
        parseCode[i] = ret;
    }
    if (!(ret = treat_code(parseCode)))
    {
        free_all(parseCode);
        return (strdup("Infinite loop !"));
    }
    free_all(parseCode);
    return (ret);
}
