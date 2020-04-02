static int check_necklace(char *s1, char *s2)
{
	int	i;
       	int	j;
	int	k;
	int	l;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	while (s2[i])
	{
		if (s2[i] == s1[j])
		{
			j = 0;
			while (s1[j] && s2[i + j] && s2[i + j] == s1[j])
				j++;
			if (!s2[i + j])
				break;
		}
		i++;
	}
	k = 0;
	l = j;
	while (s1[j] && s2[k] && k < i)
	{
		if (s2[k] != s1[j])
			break;
		k++;
		j++;
	}
	return (i + l == j && !s1[i + l] && !s2[j]);
}

int hv_necklace(char *s1, char *s2)
{
	if (!check_necklace(s1, s2))
		return (check_necklace(s2, s1));
	return (1);
}
