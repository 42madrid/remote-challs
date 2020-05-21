#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

char *ft_goto_parser(const char *code)
{
    char *next;
    char *word;
    char *statement = NULL;
    char *output = NULL;
    char *tmp = NULL;
    long n_line = 0;
    char *input = strdup(code);

    next = strtok(input, "\n");
    while (next)
    {
        if (!strtol(next, &statement, 10) && errno == EINVAL)
        {
            while(!isdigit(*statement))
                statement++;
            if (n_line >= atoi(statement))
                return (strdup("Infinite loop !"));
            else
            {
                next = strtok(NULL, "\n");
                while(!strstr(next, statement))
                    next = strtok(NULL, "\n");
            }
        }
        else
        {
            n_line = strtol(next, &statement, 10);
            word = strtok(statement, " ");
            while(word)
            {
                while(isspace(*word))
                    word++;
                asprintf(&output, "%s%s%s", tmp ? tmp: "", tmp ? " ": "", word);
                free(tmp);
                tmp = output;
                word = strtok(NULL, "\n");
            }
            next = strtok(NULL, "\n");
        }
    }
    free(input);
    return (output);
}
