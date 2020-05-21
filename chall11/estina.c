#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

static void	put_line(char **response, char *token)
{
	char	*line = NULL;
	char	*aux;

	while (isdigit(*token) || isspace(*token))
		token++;
	line = strsep(&token, " ");
	while (line)
	{
		if (*line)
		{
			aux = *response;
			if (!aux)
				asprintf(response, "%s", line);
			else
			{
				asprintf(response, "%s %s", aux, line);
				free(aux);
			}
		}
		line = strsep(&token, " ");
	}
}

static char	*return_infinite(char **duplicate, char **response)
{
	if (*response)
		free(*response);
	return (strdup("Infinite loop !"));
}

char		*ft_goto_parser(const char *code)
{
	int		label;
	int		loop = -1;
	char	*response = NULL;
	char	*duplicate = strdup(code);
	char	*token = strsep(&duplicate, "\n");

	while (token)
	{
		if (isdigit(token[0]))
			put_line(&response, token);
		else
		{
			label = atoi(token + 4);
			if (loop == -1)
				loop = label;
			else if (loop == label)
				return (return_infinite(&duplicate, &response));
			token = strsep(&duplicate, "\n");
			while (token)
			{
				if (isdigit(token[0]))
					if (atoi(token) == label)
					{
						put_line(&response, token);
						break ;
					}
				token = strsep(&duplicate, "\n");
				if (!token)
				{
					free(duplicate);
					if (label == loop)
						return (return_infinite(&duplicate, &response));
					duplicate = strdup(code);
					token = strsep(&duplicate, "\n");
				}
			}
		}
		token = strsep(&duplicate, "\n");
	}
	return (response);
}
