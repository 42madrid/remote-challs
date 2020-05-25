#include <string.h>

void    swap_str(char *str, int start, int finish)
{
    char        aux;
    int         i;

    i = start;
    while (i < (finish - start + 1) / 2 + start)
    {
        aux = str[i];
        str[i] = str[finish + start - i];
        str[finish + start - i] = aux;
        //sustituir desplazando posición indicadores
        str[i] == ')' ? str[i] = '(' : (str[i] == '(' ? str[i] = ')' : 0);
        str[finish + start - i] == ')' ? str[finish + start - i] = '(' :
            (str[finish + start - i] == '(' ? str[finish + start - i] = ')' : 0);
        i++;
    }
}

char *ft_reverse_parenthesis(const char *str)
{
    int i, j, level;
    char *aux = strdup(str);

    i = 0;
    level = 0;
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
            if (!level)
                swap_str(aux, i, j);
            else
                return (NULL);
        }
        i++;
    }
    return (aux);
}
