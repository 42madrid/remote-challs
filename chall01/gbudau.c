static int check_necklace(char *first, char *second)
{
	int	i;
       	int	j;
	int	start;
	int	checked;

	if (!first || !second)
		return (0);
	i = 0;
	j = 0;
	while (first[i])
	{
		if (first[i] == second[j])
		{
			j = 0;
			while (first[i + j] && second[j] && first[i + j] == second[j])
				j++;
			if (!first[i + j])
				break;
		}
		i++;
	}
	start = 0;
	checked = j;
	while (first[start] && second[j] && start < i)
	{
		if (first[start] != second[j])
			break;
		start++;
		j++;
	}
	return (i + checked == j && !second[i + checked] && !first[j]);
}

int hv_necklace(char *first, char *second)
{
	if (!check_necklace(first, second))
		return (check_necklace(second, first));
	return (1);
}
