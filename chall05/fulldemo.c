int		ft_ie_except_after_c(char* str)
{
	int i;
	int rule;

	i = 0;
	rule = 1;
	while (str[i] != '\0')
	{
		if (str[i] == 'i')
		{
			if (str[i + 1] == 'e')
			{
				if (str[i - 1] == 'c')
				{
					rule = 0;
					break;
				}
			}	
			else if (str[i - 1] == 'e')
			{
				if (str[i - 2] != 'c')
				{
					rule = 0;
					break;
				}
			}
		}
		i++;
	}
	return (rule);
}