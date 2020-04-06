int hv_necklace(char *first, char *second)
{
	int	i;
       	int	j;
	int	checked;

	i = 0;
	j = 0;
	while (first[i])
	{
		if (first[i] == second[j])
		{
			while (first[i + j] && second[j] && first[i + j] == second[j])
				j++;
			if (!first[i + j] || !second[j])
				break;
			j = 0;
		}
		i++;
	}
	i = 0;
	checked = j;
	while (first[i] && second[j] && first[i] == second[j])
	{
		i++;
		j++;
	}
	return (!first[i + checked] && !second[j]);
}
