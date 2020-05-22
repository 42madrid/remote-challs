#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *clean_word(const char *code)
{
	char *clean;
	char *str;
	char *ptr;
	char *word;

	if (!(clean = malloc(sizeof(clean) * strlen(code))))
		return (NULL);
	str = strdup(code);
	ptr = strtok_r(str, " ", &str);
	while (ptr != NULL)
	{
		word = strdup(ptr);
		
		ptr = strtok_r(str, " ", &str);
		if (ptr != NULL)
			strlcat(word, " ", sizeof(word));
		strlcat(clean, word, sizeof(word) * strlen(word));
	}
	return (clean);
}

char *ft_goto_parser(const char *code)
{
	char *parser;
	char *word;
	char *str;
	char *ptr;
	char *subcode;
	char *list;
	char *tmp;
	
	if (!(parser = malloc(sizeof(parser) * strlen(code))))
		return (NULL);
	if (!(list = malloc(sizeof(list) * strlen(code))))
		return (NULL);
	str = strdup(code);
	ptr = strtok(str, "\n");
	while(ptr != NULL)
	{
		if (strstr(list, ptr) == NULL)
		{
			strlcat(list, ptr, sizeof(list) * strlen(ptr));

			if (strstr(ptr, "goto") != NULL)
			{
				ptr += 4;
				while (isspace(*ptr) || !isdigit(*ptr))
					ptr++;
				subcode = strstr(code, ptr);

				if (*(subcode - 1) == ' ')
				{
					subcode += strlen(ptr);
					tmp = strdup(strstr(subcode, ptr));
				}
				else
					tmp = strdup(subcode);
				ptr = strtok(tmp, "\n");
			}
			while (isdigit(*ptr))
				ptr++;
			while (isspace(*ptr))
				ptr++;
			word = clean_word(ptr);
			ptr = strtok(NULL, "\n");
			if (ptr != NULL)
				strlcat(word, " ", sizeof(word));
			strlcat(parser, word, strlen(word) * sizeof(parser));
		}
		else
			return strdup("Infinite loop !");
	}
	free(str);
	free(list);
	return (parser);
}
