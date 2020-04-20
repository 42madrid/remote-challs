#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_element{
    int x;
    int y;
    int pos;
    int side;
    char id;
}       t_element;

int ft_check_format(char *board)
{
    int i = -1;
    int len = strlen(board);;
    int side;

    //Valid charset?
    while(++i < len)
        if (!strchr(".KPBRQ\n", board[i]))
            return (0);
    //Valid square?
    if (len > 89)
        return (0);
    side = sqrt(len);
    i = side;
    while (board[i] && i < len)
    {
        if (board[i] != '\n')
            return (0);
        i += side + 1;
    }
    //Only one king?
    if (strchr(strchr(board, 'K') + 1, 'K'))
        return (0);
    return (1);
}

t_element ft_element_coord(int pos, int side, char *board)
{
    t_element el;

    el.x = pos / (side + 1);
    el.y = pos - (side + 1) * el.x;
    el.pos = pos;
    el.id = board[pos];
    el.side = side;
    return (el);
}

int     ft_check_colission(t_element king, t_element enemy, char *board)
{
    int x = enemy.x - king.x;;
    int y = enemy.y - king.y;;
    
    while (abs(x) > 1 ||abs(y) > 1)
    {
        if (x)
            x = x - (x > 0 ? 1 : -1);
        if (y)
            y = y - (y > 0 ? 1 : -1);
        if (board[(king.side + 1) * (king.x + x) + (king.y + y)] != '.')
            return (1);
    }
    return (0);
}

int     ft_check_enemy(t_element king, t_element enemy, char *board)
{
    int delta_x = (enemy.x - king.x);
    int delta_y = (enemy.y - king.y);

    if (strchr("RQ", enemy.id))
         if ((enemy.x == king.x ||enemy.y == king.y))
             return(!ft_check_colission(king, enemy, board));
    if (strchr("QB", enemy.id))
        if (delta_x && delta_y && abs(delta_y/ delta_x) == 1)
             return(!ft_check_colission(king, enemy, board));
    if (enemy.id == 'P')
        if (delta_y == 1 && abs(delta_x) == 1)
             return(!ft_check_colission(king, enemy, board));
    return (0);
}

int ft_check_mate(char *board)
{
    int pos = 0;
    int side;
    t_element king;
    t_element enemy;

    if (!ft_check_format(board))
        return (1);
    side = sqrt(strlen(board));
    while (board[pos] != 'K')
        pos++;
    king = ft_element_coord(pos, side, board);
    pos = 0;
    while(board[pos])
    {
        if (strchr("RQPB", board[pos]))
        {
            enemy = ft_element_coord(pos, side, board);
            if(ft_check_enemy(king, enemy, board))
                return (0);
        }
        pos++;
    }
    return (1);
}
