# include <stdlib.h>

static size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

static char		*ft_strstr(const char *big, const char *little)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (big[i])
	{
		while (big[i + j] == little[j] && big[i + j])
			j++;
		if (little[j] == '\0')
			return ((char *)(big + i));
		j = 0;
		i++;
	}
	return (NULL);
}

static char ft_check_exception(char *str)
{
	char	*exc;
	char	*f;
	size_t	strl;

	exc = "sleigh stein fahrenheit deifies either nuclei reimburse ancient juicier societies";
	if (!(f = ft_strstr(exc, str)))
		return (0);
	strl = ft_strlen(str);
	return (((f > exc && *(f - 1) == ' ') || f == str) && (f[strl] == '\0' || f[strl] == ' ') ? 1 : 0);
}

int			ft_ie_except_after_c(char* str)
{
	char	*f;
	
	if (!str)
		return (1);
	if ((f = ft_strstr(str, "ie")))
	{
		return (f == str || *(f - 1) != 'c' || ft_check_exception(str) ? 1 : 0);
	}
	else if ((f = ft_strstr(str, "ei")))
	{
		return ((f > str && *(f - 1) == 'c') || ft_check_exception(str) ? 1 : 0);
	}
	else
		return (1);
}
