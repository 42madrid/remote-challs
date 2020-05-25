#include <string.h>

void    swap_str(char *str, int start, int finish)
{
    char        aux;
    int         i;

    i = start + 1;
    while (i < (finish - start + 1) / 2 + start)
    {
        aux = str[i];
        str[i] = str[finish + start - i];
        str[i] == ')' ? str[i] = '(' : (str[i] == '(' ? str[i] = ')' : str[i]);
        aux == ')' ? aux = '(' : (aux == '(' ? aux = ')' : aux);
        str[finish + start - i] = aux;
        i++;
    }
    if ((finish - start + 1) % 2)
        str[i] == ')' ? str[i] = '(' : (str[i] == '(' ? str[i] = ')' : str[i]);
}

char *ft_reverse_parenthesis(const char *str)
{
    int i, j, level;
    char *aux = strdup(str);

    i = -1;
    level = 0;
    while (str[++i])
        str[i] == '(' ? level++ : (str[i] == ')' ? level-- : level);
    if (level)
        return (NULL);
    i = 0;
    while(aux[i])
    {
        if (aux[i] == '(')
        {
            level = 1;
            j = i + 1;
            while (aux[j])
            {
                if (aux[j] == '(')
                    level++;
                else if (aux[j] == ')')
                    level--;
                if (!level)
                    break;
                j++;
            }
            swap_str(aux, i, j);
        }
        i++;
    }
    return (aux);
}
