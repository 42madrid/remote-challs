#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *ft_goto_parser_solution(const char *code)
{
    char    positions[4200][10];
    char    goto_label[10], line_label[10], word[42];
    char    *dest, *q = NULL;
    char    *ret = (char *)malloc(sizeof(char) * strlen(code) + 1);
    size_t  idx, i, j, y = 0;

    idx = 0;
    i = 0;
    while (code[idx])
    {
        if (strncmp(&code[idx], "goto", 4) == 0)
        {
            sscanf(&code[idx], "goto %s", &goto_label[1]);
            goto_label[0] = '\n';
            for (j = 0; j < i; j++)
                if (strcmp(positions[j], goto_label) == 0)
                    return strdup("Infinite loop !");
            dest = strstr(code, goto_label);
            idx = dest - code;
        }
        else
        {
            sscanf(&code[idx], "%s", &line_label[1]);
            line_label[0] = '\n';
            strcpy(positions[i++], line_label);
            dest = strchr(&code[idx], ' ') + 1;
            idx = dest - code;
            while (code[idx] != '\n') {
                while (isblank(code[idx]))
                    idx++;
                if (code[idx] != '\n') {
                    if (!q)
                        q = ret;
                    else
                        *q++ = ' ';
                    sscanf(&code[idx], "%s", word);
                    for (j = 0; j < strlen(word); j++)
                        *q++ = word[j];
                    while (code[idx] != '\n' && !isblank(code[idx]))
                        idx++;
                }
            }
            idx++;
        }
    }
    ret[q - ret] = '\0';
    return ret;
}
