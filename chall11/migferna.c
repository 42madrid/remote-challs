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
				//tmp[strlen(tmp) - 1] = '\0';
				//while (ptr != NULL && strstr(ptr, tmp) == NULL) 
				//	ptr = strtok(NULL, "\n");
			}
			while (isdigit(*ptr))
				ptr++;
			while (isspace(*ptr))
				ptr++;
			word = strdup(ptr);
			strlcat(word, " ", sizeof(word));
			strlcat(parser, word, strlen(word) * sizeof(parser));
			ptr = strtok(NULL, "\n");
		}
		else
			return (NULL);
	}
	//free(str);
	free(list);
	return (parser);
}
