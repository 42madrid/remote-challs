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

char		*ft_goto_parser(const char *code)
{
	int		label;
	char	*response = NULL;
	char	*duplicate = strdup(code);
	char	*token = strsep(&duplicate, "\n");

	while (token)
	{
		if (isdigit(token[0]))
		{
			put_line(&response, token);
		}
		else
		{
			label = atoi(token + 4);
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
					if (response)
						free(response);
					return (strdup("Infinite loop !"));
				}
			}
		}
		token = strsep(&duplicate, "\n");
	}
	return (response);
}