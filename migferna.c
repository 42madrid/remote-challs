#include <stdio.h>

char *format(char *seconds)
{
	char *format;
	if (*seconds == '0')
		format = "now";
	return (format);
}

int	is_valid(char *seconds)
{
	while (*seconds)
	{
		if (*seconds < '0' || *seconds > '9')
			return 0;
		seconds++;
	}
	return (1);
}

char *ft_format_duration(char *seconds)
{
	char *out;
	//printf("%d", is_valid(seconds));
	if (is_valid(seconds))
		out = format(seconds);
	else
		out = "Invalid input.";
	return out;
}

int main()
{
	printf("%s", ft_format_duration("62"));
	printf("%s", ft_format_duration("3662"));
	printf("%s", ft_format_duration("0"));
	printf("%s", ft_format_duration("-1"));
	printf("%s", ft_format_duration("LOL42LOL"));
	printf("%s", ft_format_duration(""));
	printf("%s", ft_format_duration("2175984000"));
	return (0);
}
