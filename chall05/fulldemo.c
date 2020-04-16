int		ft_ie_except_after_c(char* str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'i')
		{
			if (str[i + 1] == 'e')
			{
				if (str[i - 1] == 'c')
					return( 0);
			}	
			else if (str[i - 1] == 'e')
			{
				if (str[i - 2] != 'c')
					return (0);
			}
		}
		i++;
	}
	return (1);
}