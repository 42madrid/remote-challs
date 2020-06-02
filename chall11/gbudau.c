#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ERROR -1
#define INFINITE_LOOP 1
#define SUCCESS 0
#define MAX(a,b) (((a)>(b))?(a):(b))

static size_t	total_lines(const char *code)
{
	size_t	length;

	length = 1;
	for (; *code; code++)
	{
		if (*code == '\n')
			length++;
	}
	return (length);
}

static void		split_lines(char *copy, char **split)
{
	char	*line;
	size_t	i;

	i = 0;
	while ((line = strsep(&copy, "\n")) != NULL)
	{
		if (*line)
		{
			split[i] = line;
			i++;
		}
	}
	split[i] = NULL;
}

static char		*free_ret(char **unique, size_t length, int flag, char *chain)
{
	for (size_t i = 0; i < length; i++)
		free(unique[i]);
	free(unique);
	if (flag == ERROR || flag == INFINITE_LOOP)
	{
		free(chain);
		chain = NULL;
	}
	if (flag == INFINITE_LOOP)
		return (strdup("Infinite loop !"));
	return (chain);
}

static size_t	count_digits(const char *str)
{
	size_t	count;

	count = 0;
	for (int i = 0; isdigit(str[i]); i++)
		count++;
	return (count);
}

static char		*walk_goto(char *str)
{
	while (*str && isdigit(*str) == 0)
		str++;
	return str;
}

static ssize_t		goto_index(char **split, char *line)
{
	ssize_t	i = 0;
	size_t	len1;
	size_t	len2;

	while (split[i] != NULL)
	{
		if (isdigit(*(split[i])))
		{
			len1 = count_digits(split[i]);
			len2 = strlen(line);
			if (strncmp(split[i], line, MAX(len1, len2)) == 0)
				break;
		}
		i++;
	}
	free(line);
	line = NULL;
	return (split[i] == NULL ? -1 : i);
}

static size_t	fill_chain(char *dst, char *src, size_t index)
{
	char	*word;
	size_t	len;

	while ((word = strsep(&src, " \t\v\f\r")) != NULL)
	{
		if (*word && index != 0)
			dst[index++] = ' ';
		if (*word)
		{
			len = strlen(word);
			strncpy(&dst[index], word, len);
			index +=  len;
		}
	}
	return (index);
}

static char		*process_lines(char **split, size_t len_sp, char *chain, size_t len_ch)
{
	char	**unique;
	char	*line;
	size_t	count;
	size_t	index;
	ssize_t	i;

	if ((unique = calloc(sizeof(*unique), len_sp)) == NULL)
		return (NULL);
	if ((chain = calloc(len_ch + 1, sizeof(char))) == NULL)
		return (free_ret(unique, len_sp, ERROR, chain));
	index = 0;
	i = 0;
	while (split[i] != NULL)
	{
		if (isdigit(*(split[i])))
		{
			if (unique[i] != NULL)
				return (free_ret(unique, len_sp, INFINITE_LOOP, chain));
			count = count_digits(split[i]);
			if ((unique[i] = strndup(split[i], count)) == NULL)
				return (free_ret(unique, len_sp, ERROR, chain));
			index = fill_chain(chain, split[i] + count, index);
		}
		else
		{
			line = walk_goto(split[i]);
			if ((line = strndup(line, count_digits(line))) == NULL)
				return (free_ret(unique, len_sp, ERROR, chain));
			if ((i = goto_index(split, line)) == -1)
				return (free_ret(unique, len_sp, ERROR, chain));
			continue;
		}
		i++;
	}
	return (free_ret(unique, len_sp, SUCCESS, chain));
}

char			*ft_goto_parser(const char *code)
{
	char	**split;
	char	*copy;
	char	*tmp;
	size_t	length;

	if ((copy = strdup(code)) == NULL)
		return NULL;
	length = total_lines(copy);
	if ((split = malloc(sizeof(*split) * (length + 1))) == NULL)
		return NULL;
	tmp = copy;
	split_lines(copy, split);
	copy = process_lines(split, length, copy, strlen(code));
	free(tmp);
	free(split);
	return (copy);
}
