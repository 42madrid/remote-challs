#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

char *ft_goto_parser(const char *code)
{
    char *next;
    char *word;
    char *aux = NULL;
    char *output = NULL;
    char *tmp = NULL;
    long n_line = 0;
    char *input = strdup(code);

    next = strtok_r(input, "\n", &input);
    while (next)
    {
        if (!isdigit(*next))
        {
            aux = next;
            while(!isdigit(*aux))
                aux++;
            next = strtok_r(input, "\n", &input);
            while(!strstr(next, aux))
            {
                next = strtok_r(input, "\n", &input);
                if (!next)
                    return (strdup("Infinite loop !"));
            }
        }
        else
        {
            while (isdigit(*next))
                next++;
            word = strtok_r(next, " ", &next);
            while(word)
            {
                while(*word && isspace(*word))
                    word++;
                if (*word){
                    asprintf(&output, "%s%s%s", tmp ? tmp: "", tmp ? " ": "", word);
                    free(tmp);
                    tmp = output;
                }
                word = strtok_r(next, " ", &next);
            }
            next = strtok_r(input, "\n", &input);
        }
    }
    free(input);
    return (output);
}