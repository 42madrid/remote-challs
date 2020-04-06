
static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != 0)
		i++;
	return (i);
}

char		*ft_strchr(const char *s, int c)
{
	c = (char)c;
	while (*s)
	{
		if (*s == c)
			break ;
		else
			s++;
	}
	return (*s == c ? (char *)s : 0);
}

int hv_necklace_recursive(char *s1, int is1l, char *s2, char *pos)
{
	int		is1;
	char	*ps2;

	ps2 = ft_strchr(pos, *s1);
	if (!ps2)
		return (0);
	pos = ps2 + 1;
	is1 = 0;
	while (s1[is1])
	{
		if (s1[is1] != *ps2)
		{
			return (hv_necklace_recursive(s1, is1l, s2, pos));
		}
		is1++;
		ps2++;
		if (!*ps2)
			ps2 = s2;
	}
	return (1);
}
int hv_necklace(char *s1, char *s2)
{
	int s1l;

	if ((s1 && !s2) && (!s1 && s2))
		return (0);
	if (!s1 && !s2)
		return (1);
	s1l = ft_strlen(s1);
	if (s1l != ft_strlen(s2))
		return (0);
	return (hv_necklace_recursive(s1, s1l, s2, s2));
}
