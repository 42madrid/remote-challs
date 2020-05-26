#include <string.h>
#include <stdlib.h>

void	reverse_text(char *str, int start, int end)
{
	int		pos;
	int		pos2;
	char	tmp[end - start + 1];

	pos = 0;
	pos2 = 0;
	while (pos < end - start + 1)
	{
		tmp[pos] = str[start + pos];
		if (tmp[pos] == '(')
			tmp[pos] = ')';
		else if (tmp[pos] == ')')
			tmp[pos] = '(';
		pos++;
	}
	pos2 = pos - 1;
	pos = 0;
	while (pos < end - start + 1)
	{
		str[start + pos] = tmp[pos2--];
		pos++;
	}
}

int		check_first_parenthesis(const char *str)
{
	int		pos;

	pos = 0;
	while (str[pos] && str[pos] != '\0')
	{
		if (str[pos] == '(')
			return (1);
		if (str[pos] == ')')
			return (0);
		pos++;
	}
	return (1);
}

int		count_chars(const char *str, char to_find)
{
	int		pos;
	int		count;

	pos = 0;
	count = 0;
	while (str[pos] && str[pos] != '\0')
	{
		if (str[pos] == to_find)
			count++;
		pos++;
	}
	return (count);
}

char *ft_reverse_parenthesis(const char *str)
{
    int		pos;
    int		count;
	char	*new_str;
	int		start_pos;
	int		end_pos;

	start_pos = 0;
	end_pos = 0;
	if (!(str) || (count_chars(str, '(') != count_chars(str, ')')))
		return (0);
	if (check_first_parenthesis(str) == 0)
		return (0);
	if (!(new_str = malloc(sizeof(char) * strlen(str))))
		return (0);
	strcpy(new_str, str);
    pos = 0;
	count = 0;
	while (new_str[pos] && new_str[pos] != '\0')
	{
		if (new_str[pos] == '(')
		{
			start_pos = pos;
			count = 1;
			while(count != 0)
			{
				pos++;
				if (new_str[pos] == '(')
					count++;
				if (new_str[pos] == ')')
					count--;
			}
			end_pos = pos;
			reverse_text(new_str, start_pos + 1, end_pos - 1);
			pos = start_pos;
		}
		pos++;
	}
	return (new_str);
}
