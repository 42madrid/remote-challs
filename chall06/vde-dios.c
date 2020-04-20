#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_element{
    int x;
    int y;
}       t_element;

int ft_check_format(char *board)
{
    char *set = ".KPBRQ\n";
    int i;
    int size;
    int len;

    //Valid charset
    i = -1;
    len = strlen(board);

    while(++i < len)
        if (!strchr(set, board[i]))
            return (0);
    //Valid square
    if (len > 89)
        return (0);
    size = sqrt(len);
    i = size;
    while (board[i] && i < len)
    {
        if (board[i] != '\n')
            return (0);
        i += size + 1;
    }
    //Only one king
    if (strchr(strchr(board, 'K') + 1, 'K'))
        return (0);
    return (1);
}

int ft_get_king_pos(char *board)
{
    int pos;

    while (board[pos] != 'K')
        pos++;
    return (pos);
}

t_element ft_element_coord(int pos, int size)
{
    t_element el;

    el.x = pos / (size + 1);
    el.y = pos - (size + 1) * el.x;
    return (el);
}

int     ft_check_enemy(char *board, char *set, int pos, int size, t_element king, t_element enemy)
{
    if (strchr(set, board[pos]))
    {
        enemy = ft_element_coord(pos, size);
        if (board[pos] == 'R' || board[pos] == 'Q')
        {
            if ((enemy.x == king.x ||enemy.y == king.y))
                return (0);
        }
        else
        {
            if (abs((enemy.x - king.x) / (enemy.y - king.y)) == 1)
            {
                if (board[pos] == 'P')
                {
                    if (abs(enemy.x - king.x) == 1)
                        return (0);
                }
                else
                    return (0);
            }
        }
    }
    return (1);
}

int ft_check_mate(char *board)
{
    int pos;
    int size;
    t_element king;
    t_element enemy;
    char *set = "PBRQ";

    if (!ft_check_format(board))
        return (1);
    size = sqrt(strlen(board));
    pos = ft_get_king_pos(board);
    king = ft_element_coord(pos, size);
    //Check forward
    while(board[pos])
    {
        if(!ft_check_enemy(board, set, pos, size, king, enemy))
            return (0);
        pos++;
    }
    //Check backward
    pos = ft_get_king_pos(board);
    while(pos >= 0)
    {        
        if(!ft_check_enemy(board, set, pos, size, king, enemy))
            return (0);
        pos--;
    }
    return (1);
}
