#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *ft_goto_parser(const char *code)
{
	char *parser;
	char *word;
	char *str;
	char *ptr;
	char *tmp;

	if (!(parser = malloc(strlen(code) + 1)))
		return (NULL);
	str = strdup(code);
	ptr = strtok(str, "\n");
	while(ptr != NULL)
	{
		if (strstr(ptr, "goto") != NULL)
		{
			ptr += 4;
			while (isspace(*ptr) || !isdigit(*ptr))
				ptr++;
			tmp = strstr(code, ptr) + strlen(ptr);
			ptr = strstr(tmp, ptr);
		}
		while (isspace(*ptr) || isdigit(*ptr))
			ptr++;
		word = strdup(ptr);
		strlcat(word, " ", sizeof(word));
		strlcat(parser, word, strlen(word) * sizeof(parser));
		ptr = strtok(NULL, "\n");
	}
	return (parser);
}

int main()
{
	const char *code = (
		"5 HERE\n"
		"10 IS\n"
		"goto 40\n"
		"20 JUST rAnDoM TEXT\n"
		"30 AND\n"
		"40 MORE RANDOM text\n"
	);
	char *out = ft_goto_parser(code);
	printf("%s", out);
	free(out);
}
