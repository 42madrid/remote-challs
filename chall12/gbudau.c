#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static bool		valid_parenthesis(const char *str)
{
	size_t	open;

	open = false;
	while (*str)
	{
		if (*str == '(')
			open++;
		else if (*str == ')')
		{
			if (!open)
				return false;
			else
				open--;
		}
		str++;
	}
	return (!open);
}

static size_t		max_opened(const char *str)
{
	size_t	open;
	size_t	max;

	open = 0;
	max = 0;
	while (*str)
	{
		if (*str == '(')
			open++;
		else if (*str == ')')
		{
			if (max < open)
				max = open;
			open--;
		}
		str++;
	}
	return (max);
}

static void		swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void		reverse_str(char *str, size_t start, size_t end)
{
	while (start < end)
	{
		swap(&str[start], &str[end]);
		start++;
		end--;
	}
}

static void		invert_paranthesis(char *str, size_t start, size_t end)
{
	while (start <= end)
	{
		if (str[start] == ')')
			str[start] = '(';
		else if (str[start] == '(')
			str[start] = ')';
		start++;
	}
}

char		*ft_reverse_parenthesis(const char *str)
{
	char	*data;
	size_t	length;
	size_t	*stack;
	size_t	i;
	size_t	j;

	if (valid_parenthesis(str) == false)
		return (NULL);
	if ((data = strdup(str)) == NULL)
		return (NULL);
	if ((length = max_opened(str)) == 0)
		return(data);
	if ((stack = malloc(sizeof(*stack) * length)) == NULL)
	{
		free(data);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (data[i])
	{
		if (data[i] == '(')
		{
			stack[j] = i + 1;
			j++;
		}
		else if (data[i] == ')')
		{
			invert_paranthesis(data, stack[j - 1], i - 1);
			reverse_str(data, stack[j - 1], i - 1);
			j--;
		}
		i++;
	}
	free(stack);
	return (data);
}
