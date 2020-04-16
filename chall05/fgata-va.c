int		ft_ie_except_after_c(char *str)
{
	int i;
	int follow_rule;

	follow_rule = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == 'e' || str[i] == 'i'))
		{
			if (str[i] == 'i' && str[i + 1] == 'e' && (i > 0 && str[i - 1] == 'c'))
				follow_rule = 0;
			else if (str[i] == 'e' && str[i + 1] == 'i' && (i == 0 || str[i - 1] != 'c'))
				follow_rule = 0;
		}
		i++;
	}
	return (follow_rule);
}
