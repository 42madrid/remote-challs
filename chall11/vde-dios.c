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

    next = strtok_r(input, "\n", &input);
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
                next = strtok_r(input, "\n", &input);
                while(!strstr(next, statement))
                    next = strtok_r(input, "\n", &input);
            }
        }
        else
        {
            n_line = strtol(next, &statement, 10);
            word = strtok_r(statement, " ", &statement);
            while(word)
            {
                while(isspace(*word))
                    word++;
                asprintf(&output, "%s%s%s", tmp ? tmp: "", tmp ? " ": "", word);
                free(tmp);
                tmp = output;
                word = strtok_r(statement, " ", &statement);
            }
        next = strtok_r(input, "\n", &input);
        }
    }
    free(input);
    return (output);
}
