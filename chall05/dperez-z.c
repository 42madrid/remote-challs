#include <unistd.h>
#include <stdio.h>

int ft_ie_except_after_c(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return(1);
	while(str[i]!='\0')
	{
		if (str[i]=='e')
		{
			if (str[i+1]=='i' && str[i+1]!='\0')
			{
				if (str[i-1]=='c' && (i-1)>=0)
					return(1);
				else 
					return(0);
			}
		}
		if (str[i]=='i')
		{
			if (str[i+1]=='e' && str[i+1]!='\0')
			{
				if (str[i-1]!='c' && (i-1)>=0)
					return(1);
				else 
					return(0);
			}
		}
		i++;
	}
	return(1);
}
