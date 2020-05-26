#include <stdlib.h>
#include <string.h>

char *ft_reverse_parenthesis(const char *str);
static char *reverse(const char *str, int size);
static int ft_reverse_parenthesis_left(char *const str, int pos, int *end_block_left);
static int ft_reverse_parenthesis_right(char *const str, int pos, int len, int *ini_block_right);

static void ft_swap_blocks(char *const str, int end_left_block, int ini_right_block)
{
    char *tmp;
    int len;

    len = strlen(str);
    tmp = calloc(len + 1, sizeof(char));
    strcat(tmp, &str[len - ini_right_block]);
    strncat(tmp, &str[end_left_block], ini_right_block - end_left_block);
    strncat(tmp, str, end_left_block);
    memmove(str, tmp, len);
    free(tmp);
    tmp = 0;
}

static int ft_look_for_left_parenthesis(const char *str, int start)
{
    int open_parenthesis;
    int i;

    open_parenthesis = 0;
    i = start;
    while (i >= 0) {
        if (str[i] == ')')
            open_parenthesis++;
        else if (str[i] == '(')
        {
            if (!open_parenthesis)
                return (i);
            else
                open_parenthesis--;
        }
        
        i--;
    }
    return (-1);
}

static int ft_look_for_right_parenthesis(const char *str)
{
    int open_parenthesis;
    int i;

    open_parenthesis = 0;
    i = 0;
    while (str[i]) {
        if (str[i] == '(')
            open_parenthesis++;
        else if (str[i] == ')')
        {
            if (!open_parenthesis)
                return (i);
            else
                open_parenthesis--;
        }
        i++;
    }
    return (-1);
}

static char *reverse(const char *str, int size)
{
    int i;
    int block_end;
    char *ret;

    if (!(ret = calloc(strlen(str) + 1, sizeof(char))))
        return 0;

    block_end = size;
    i = 0;
    while (i < size && str[i])
    {
        if (str[i] == ')')
            block_end = size;
        else if (str[i] == '(')
        {
            if ((block_end = ft_look_for_right_parenthesis(&str[i])) < 0)
            {
                free(ret);
                return 0;
            }

        } else {
            ret[i] = str[block_end];
            ret[block_end] = str[i];
        }
        block_end--;
        i++;
    }

    return ret;
}

static int ft_reverse_parenthesis_left(char *const str, int i, int *end_block_left)
{
    char *block;
    char block_chr;

    *end_block_left = ft_look_for_right_parenthesis(&str[i + 1]);
    if (*end_block_left < 0)
        return (0);
    block_chr = str[i + 1 + *end_block_left + 1];
    str[i + 1 + *end_block_left + 1] = 0;
    if (!(block = ft_reverse_parenthesis(&str[i + 1])))
        return (0);
    memcpy(&str[i + 1], block, *end_block_left);
    free(block);
    str[i + 1 + *end_block_left + 1] = block_chr;
    return (1);
}

static int ft_reverse_parenthesis_right(char *const str, int i, int len, int *ini_block_right)
{
    char *block;
    char block_chr;

    *ini_block_right = ft_look_for_left_parenthesis(str, len - i);
    if (*ini_block_right < 0)
        return (0);
    block_chr = str[len - i + 1];
    str[len - i + 1] = 0;
    if (!(block = ft_reverse_parenthesis(&str[i + 1])))
        return (0);
    strcpy(&str[*ini_block_right + 1], block);
    free(block);
    str[len - i + 1] = block_chr;
    return (1);
}

char *ft_reverse_parenthesis(const char *str)
{
    int len;
    int i;
    char *rev;
    int end_block_left;
    int ini_block_right;

    if (!str)
        return strdup("NULL");
    len = strlen(str);
    if (!(rev = calloc(len + 1, sizeof(char))))
        return strdup("NULL");
    memcpy(rev, str, len);
    i = 0;
    while (i < (len - i) && rev[i]) {
        if (rev[i] == '(')
        {
            if (!ft_reverse_parenthesis_left(rev, i, &end_block_left)) {
                free(rev);
                rev = 0;
                return strdup("NULL");
            }
        }
        if (rev[len - i] == ')' && (i + 1 + end_block_left) < (len - i))
        {
            if (!ft_reverse_parenthesis_right(rev, i, len, &ini_block_right)) {
                free(rev);
                rev = 0;
                return strdup("NULL");
            }
        }

        if (rev[i] == '(' && rev[len - i] == ')')
        {
            if (ini_block_right != -1)
               ft_swap_blocks(&rev[i], end_block_left, ini_block_right);
            i = i + 1 + end_block_left + 1;
        }
        else if (str[i] == '(') {
            if (str[i + 1 + end_block_left] != ')' && str[i + 1 + end_block_left])
                ft_swap_blocks(&rev[i],  end_block_left, 1);
            i = i + 1 + end_block_left + 1;
        }
        else if (str[len - i] == ')') {
            if (ini_block_right != i && ini_block_right > -1)
                ft_swap_blocks(&rev[i], 1, ini_block_right);
            i = len - i + 1;
        }
        else {
            rev[i] = str[len - i - 1];
            rev[len - i - 1] = str[i];
            i++;
        }
        ini_block_right = -1;
        end_block_left = -1;
    }
    return (rev);
}


#include <stdio.h>
int main(void) {
    char *rev;

    printf("hola %s\n", (rev = ft_reverse_parenthesis("hola")));
    free(rev);
    printf("h(ol)a %s\n", (rev = ft_reverse_parenthesis("h(ol)a")));
    free(rev);
    return (0);
}