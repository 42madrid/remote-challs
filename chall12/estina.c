#include <string.h>
#include <stdio.h>
#include <unistd.h>

static void	ft_turn_parentesis(char *c)
{
	*c = *c == '(' ? ')' : *c == ')' ? '(' : *c;
}

static char* ft_reverse(char *str, int len)
{
	int		i;
	char	c;

	i = len / 2 - 1;
	while (i >= 0)
	{
		ft_turn_parentesis((str + i));
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
		ft_turn_parentesis((str + i));
		i--;
	}
	return (str);
}

static void	pass_flag(char c, int *flag, int *open)
{
	if (c == ')' && *open)
	{
		*open = 0;
		(*flag)--;
	}
	else if (c == '(')
	{
		*open = 1;
		(*flag)++;
	}
}

static int	count_parentesis(const char *str)
{
	int		i;
	int		flag, open;

	i = 0;
	flag = 0;
	while (str[i])
		pass_flag(str[i++], &flag, &open);
	return (open ? open : flag);
}

char		*ft_reverse_parenthesis(const char *str)
{
	char	*copy, *ptr;
	int		i, flag, open;

	if (!str || !*str || count_parentesis(str))
		return (NULL);
	copy = strdup(str);
	ptr = copy;
	while (1)
	{
		ptr = strchr(ptr, '(');
		if (ptr)
		{
			flag = 1;
			i = 1;
			while (ptr[i] && flag > 0)
				pass_flag(ptr[i++], &flag, &open);
			ft_reverse(ptr, i);
			ptr++;
		}
		else
			return (copy);
	}
}
