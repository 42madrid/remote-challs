#include <string.h>
#include <stdlib.h>

#define VSEMPERE_P 1
#define VSEMPERE_B 2
#define VSEMPERE_R 4
#define VSEMPERE_Q 8

static void ft_prepare_map(char *board, int *king, int *board_side)
{
    int offset;
    int real;

    real = 0;
    offset = 0;
    while (board[real + offset])
    {
        if (board[real + offset]=='P')
            board[real] = 1;
        else if (board[real + offset]=='B')
            board[real] = 2;
        else if (board[real + offset]=='R')
            board[real] = 4;
        else if (board[real + offset]=='Q')
            board[real] = 8;
        else if (board[real + offset]=='K')
        {
            *king = real;
            board[real] = 16;
        }
        else if (board[real + offset]=='\n')
        {
            if (!*board_side)
                *board_side = real;
            offset++;
            continue ;
        }
        else
            board[real] = 32;
        real++;
    }
}

static int      ft_check_south_east(char *board, int ring, int board_size, int king)
{
    int         row_chk;
    int         max;

    max = board_size * board_size;
    row_chk = king + (ring *  board_size);
    
    return (((row_chk) % board_size < (row_chk + ring) % board_size) && 
        (row_chk + ring) < max &&
        (board[row_chk + ring] & (VSEMPERE_B | VSEMPERE_Q | (ring == 1 ? VSEMPERE_P : 0))) ? 1 : 0);
}

static int      ft_check_north_west(char *board, int ring, int board_size, int king)
{
    int         row_chk;
    int         max;

    max = board_size * board_size;
    row_chk = king - (ring *  board_size);
    
    return (((row_chk) % board_size > (row_chk - ring) % board_size) && 
        (row_chk - ring) >= 0  &&
        (board[row_chk - ring] & (VSEMPERE_B | VSEMPERE_Q)) ? 1 : 0);
}

static int      ft_check_south_west(char *board, int ring, int board_size, int king)
{
    int         row_chk;
    int         max;

    max = board_size * board_size;
    row_chk = king + (ring *  board_size);
    
    return (((row_chk) % board_size > (row_chk - ring) % board_size) && 
        (row_chk - ring) >= 0 &&
        (board[row_chk - ring] & (VSEMPERE_B | VSEMPERE_Q | (ring == 1 ? VSEMPERE_P : 0))) ? 1 : 0);
}

static int      ft_check_north_east(char *board, int ring, int board_size, int king)
{
    int         row_chk;
    int         max;

    max = board_size * board_size;
    row_chk = king - (ring *  board_size);
    
    return (((row_chk) % board_size < (row_chk + ring) % board_size) && 
        (row_chk + ring) < max &&
        (board[row_chk + ring] & (VSEMPERE_B | VSEMPERE_Q)) ? 1 : 0);
}

static int      ft_check_north(char *board, int ring, int board_size, int king)
{
    int         row_chk;
    int         max;

    max = board_size * board_size;
    row_chk = king - (ring *  board_size);
    
    return (row_chk >= 0 &&
        (board[row_chk] & (VSEMPERE_Q | VSEMPERE_R)) ? 1 : 0);
}

static int      ft_check_south(char *board, int ring, int board_size, int king)
{
    int         row_chk;
    int         max;

    max = board_size * board_size;
    row_chk = king + (ring *  board_size);
    
    return (row_chk < max &&
        (board[row_chk] & (VSEMPERE_Q | VSEMPERE_R)) ? 1 : 0);
}

static int      ft_check_east(char *board, int ring, int board_size, int king)
{
    int         row_chk;
    int         max;

    max = board_size * board_size;
    row_chk = king + ring;
    
    return (((king) % board_size < (row_chk) % board_size) && 
        row_chk < max &&
        (board[row_chk] & (VSEMPERE_Q | VSEMPERE_R)) ? 1 : 0);
}

static int      ft_check_west(char *board, int ring, int board_size, int king)
{
    int         row_chk;
    int         max;

    max = board_size * board_size;
    row_chk = king - ring;
    
    return (((king) % board_size > (row_chk) % board_size) && 
        row_chk >= 0 &&
        (board[row_chk] & (VSEMPERE_Q | VSEMPERE_R)) ? 1 : 0);
}

static int     ft_check_mate_ring(char *board, int king,
    int ring, int board_size)
{
    if (ring >= board_size)
        return (2);

    return (ft_check_south_east(board, ring, board_size, king) || 
        ft_check_north_west(board, ring, board_size, king) ||
        ft_check_south_west(board, ring, board_size, king) ||
        ft_check_north_west(board, ring, board_size, king) ||
        ft_check_north_east(board, ring, board_size, king) ||
        ft_check_north(board, ring, board_size, king) ||
        ft_check_south(board, ring, board_size, king) ||
        ft_check_east(board, ring, board_size, king) ||
        ft_check_west(board, ring, board_size, king) ? 1 : 0);
}

static int      ft_check_map(char *board)
{
    int pos = 0;
    int board_side = 0;
    int king = 0;

    if (!board)
        return (0);
    while (*board)
    {
        if (!board_side && *board=='\n')
        {
            board++;
            board_side = pos;
            continue ;
        }
        else if (board_side && *board=='\n')
        {
            if (pos % board_side)
                return (0);
            board++;
            continue;
        }
        else if (!strchr("PBRQK.\n", *board))
            return (0);
        else if (*board=='K')
            king++;
        board++;
        pos++;
    }
    return (king != 1 ? 0 : 1);
}

int             ft_check_mate(char *board_param)
{
    int hit;
    int king;
    int board_side = 0;
    int ring;
    char *board;

    if (!ft_check_map(board_param))
        return (1);
    if (!(board = malloc(sizeof(char) * strlen(board_param))))
        return (1);
    strcpy(board, board_param);
    ft_prepare_map(board, &king, &board_side);
    ring = 1;
    while (!(hit = ft_check_mate_ring(board, king, ring, board_side)))
        ring++;
    free(board);
    if (hit == 1)
        return (0);
    else
        return (1);
}
