#include <stdio.h>
#include <stdlib.h>

int     ft_pawn_check(int **newboard, int y, int x, int size)
{
    if (y == 0)
        return (0);
    if (x > 0 && newboard[y - 1][x - 1] == 'K')
        return (1);
    if (x < size && newboard[y - 1][x + 1] == 'K')
        return (1);
    return (0);
}

void    ft_king_pos(int **newboard, int *y, int *x, int size)
{
    int posx;
    int posy;

    posx = 0;
    posy = 0;
    while (posy < size)
    {
        posx = 0;
        while (posx < size)
        {
            if (newboard[posy][posx] == 'K')
            {
                *y = posy;
                *x = posx;
                return ;
            }
            posx++;
        }
        posy++;
    }
}

int     ft_find_king(int **newboard, int iniy, int inix, int endy, int endx)
{
    int     posx;
    int     posy;

    posy = iniy;
    posx = inix;
    while (posy <= endy)
    {
        posx = inix;
        while (posx <= endx)
        {
            if (newboard[posy][posx] != '.' && newboard[posy][posx] != 'K')
                return (0);
            posx++;
        }
        posy++;
    }
    return (1);
}

int     ft_find_king_d(int **newboard, int iniy, int inix, int endy, int endx)
{
    int     posx;
    int     posy;

    posy = iniy;
    posx = inix;
    while (posy <= endy)
    {
        if (newboard[posy][posx] != '.' && newboard[posy][posx] != 'K')
            return (0);
        if (inix < endx)
            posx++;
        else
            posx--;        
        posy++;
    }
    return (1);
}

int     ft_rook_check(int **newboard, int y, int x, int size)
{
    int kposx;
    int kposy;
    int king_found;

    kposx = 0;
    kposy = 0;
    king_found = 0;
    ft_king_pos(newboard, &kposy, &kposx, size);
    if (kposy == y && kposx > x)
        king_found = ft_find_king(newboard, y, x + 1, kposy, kposx);
    else if (kposy == y && kposx < x)
        king_found = ft_find_king(newboard, kposy, kposx, y, x - 1);
    else if (kposy < y && kposx == x)
        king_found =  ft_find_king(newboard, kposy, kposx, y, x - 1);
    else if (kposy > y && kposx == x)
        king_found = ft_find_king(newboard, y, x + 1, kposy, kposx);
    if (king_found == 1)
        return (1);
    return (0);
}

int     ft_bishop_check(int **newboard, int y, int x, int size)
{
    int kposx;
    int kposy;
    int king_found;

    kposx = 0;
    kposy = 0;
    king_found = 0;
    ft_king_pos(newboard, &kposy, &kposx, size);
    if ((kposy > y && kposx > x) && (y - kposy == kposx - x))
        king_found = ft_find_king_d(newboard, y + 1, x + 1, kposy, kposx);
    else if ((kposy > y && kposx < x) && (kposy - y == x - kposx))
        king_found = ft_find_king_d(newboard, y + 1, x - 1, kposy, kposx);
    else if ((kposy < y && kposx < x) && (y - kposy == x - kposx))
        king_found =  ft_find_king_d(newboard, kposy, kposx, y - 1, x - 1);
    else if ((kposy < y && kposx > x) && (y - kposy == kposx -x))
        king_found = ft_find_king_d(newboard, kposy, kposx, y - 1, x + 1);    
    if (king_found == 1)
        return (1);
    return (0);
}

int     ft_queen_check(int **newboard, int y, int x, int size)
{
    if (ft_rook_check(newboard, y, x, size) == 1)
        return (1);
    else if (ft_bishop_check(newboard, y, x, size) == 1)
        return (1);
    return (0);
}

int     ft_move(int piece, int **newboard, int y, int x, int size)
{
    switch (piece)
    {
        case 'P':
            return (ft_pawn_check(newboard, y, x, size));
        case 'B':
            return (ft_bishop_check(newboard, y, x, size));
        case 'R':
            return (ft_rook_check(newboard, y, x, size));
        case 'Q':
            return (ft_queen_check(newboard, y, x, size));
        default:
            return (0);
    }
}

char    ft_upper(char letter)
{
    if (letter >= 'a' && letter <= 'z')
        return (letter - 32);
    return (letter);
}

int ft_check_moves(int **newboard,int size)
{
    int posx;
    int posy;

    posx = 0;
    posy = 0;
    while (posy < size)
    {
        posx = 0;
        while (posx < size)
        {
            if (ft_move(newboard[posy][posx], newboard, posy, posx, size) == 1)
                return (1);
            posx++;
        }
        posy++;
    }
    return (0);
}

int     ft_check_piece(char piece)
{
    if (piece != 'P' && piece != 'B' && piece != 'R' 
        && piece != 'Q' && piece != 'K' && piece != '.')
        return (0);
    return (1);
}

int     free_exit(int **newboard)
{
    free(newboard);
    return (1);
}

int     ft_valid_pieces(int **newboard, int size)
{
    int posx;
    int posy;
    int king;

    posx = 0;
    posy = 0;
    king = 0;
    while (posy < size)
    {
        posx = 0;
        while (posx < size)
        {
            if (newboard[posy][posx] == 'K')
                king++;
            if (ft_check_piece(newboard[posy][posx]) == 0)
                return (0);
            posx++;
        }
        posy++;
    }
    if (king != 1)
        return (0);
    return (1);
}

int    **ft_get_board(char *board, int size)
{
    int **newboard;
    int posx;
    int posy;
    int pos;

    posx = 0;
    posy = 0;
    pos = 0;
    if (!(newboard = malloc(sizeof(newboard) * size * size)))
        return (0);
    while (posy < size)
    {
        newboard[posy] = malloc(sizeof(newboard) * size);
        while (posx < size)
        {
            newboard[posy][posx] = ft_upper(board[pos]);
            posx++;
            pos++;
        }
        posy++;
        pos++;
        posx = 0;
    }
    return (newboard);
}

int     ft_check_lines(char *board)
{
    int pos;
    int ycount;

    pos = 0;
    ycount = 1;
    while (board[pos])
    {
        if (board[pos] == '\n')
        {
            ycount++;
        }
        pos++;
    }
    return (ycount);
}

int ft_check_square(char *board)
{
    int pos;
    int xcount;
    int ycount;

    ycount = ft_check_lines(board);
    pos = 0;
    xcount = 0;
    while (board[pos])
    {
        if (board[pos] == '\n')
        {
            if (xcount != ycount)
                return (0);
            else
                xcount = 0;
        }
        else
        {
            xcount++;
        }
        pos++;
    }
    if (xcount != ycount)
        return (0);
    return (1);
}

int ft_check_mate(char *board)
{
    int **newboard;
    int size;

    if (ft_check_square(board) == 0)
        return (1);
    size = ft_check_lines(board);
    if (size > 9)
        return (free_exit(newboard));
    newboard = ft_get_board(board, size);
    if (ft_valid_pieces(newboard, size) == 0)
        return (free_exit(newboard));
    if (ft_check_moves(newboard,size) == 0)
        return (free_exit(newboard));
    free_exit(newboard);
    return (0);
}
