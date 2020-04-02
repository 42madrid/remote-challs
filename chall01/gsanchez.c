int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static int	ft_check(char *s1, char *s2, int start)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[start])
			return (0);
		i++;
		start++;
		if (!s1[start])
			start = 0;
	}
	return (1);
}

int	hv_necklace(char *s1, char *s2)
{
	int	start;

	if (!*s1 && !*s2)
		return (1);
	else if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	start = 0;
	while (s1[0] != s2[start] && start < ft_strlen(s1))
		start++;
	while (start < ft_strlen(s1))
	{
		if (ft_check(s1, s2, start))
			return (1);
		start++;
	}
	return (0);
}
