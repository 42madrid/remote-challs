#include <string.h>

/*
** Pawn's algorithm
*/
int     P_checkmate(int column, int init_pos, char *str) 
{
    int     i;
    int     c;
    int     col_sum;
    int     col_minus;
    int     h;

    col_sum = column + 1;
    col_minus = column - 1;
    i = init_pos;
    h = 1;
    
    /*
    ** The next two loops are nonsense because they work only once. But I don't know any other way.
    */
    while (h == 1)
    {
        if (str[init_pos + 1] == '\n' || init_pos + 1 == (int)strlen(str))
            break;
        if (str[i - 1] == '\n' && i != init_pos)
            break;
        c = 0;
        while (c < col_sum)
        {
            if (str[i] != '\n')
                c++;
            i--;
        }
        if (str[i] == '\n')
            i--;
        if (str[i] != '.' && str[i] != 'K')
            break;
        if (str[i] == 'K')
            return(0);
        h++;
    }
    h = 1;
    i = init_pos;
    while (h == 1)
    {
        if (str[init_pos + 1] == '\n' || init_pos + 1 == (int)strlen(str))
            break;
        else if (str[i - 1] == '\n' && i != init_pos)
            break;
        else
        c = 0;
        while (c < col_minus)
        {
            if (str[i] != '\n')
                c++;
            i--;
        }
        if (str[i] == '\n')
            i--;
        if (str[i] != '.' && str[i] != 'K')
            break;
        if (str[i] == 'K')
            return(0);
        h++;
    }
    return(1);
}

/*
** Bishop's algorithm 
*/
int     B_checkmate(int column, int init_pos, char *str)
{
    int i;
    int c;
    int col_sum;
    int col_minus;

    col_sum = column + 1;
    col_minus = column -1;
    i = init_pos;
    while (i >= 0 && i < (int)strlen(str))
    {
        /* Exception */
        if (str[init_pos + 1] == '\n' || init_pos + 1 == (int)strlen(str)) 
            break;

        /* Pieces in between */
        if (str[i] != '.' && str[i] != 'K')
            break;

        /* Mate */
        if (str[i] == 'K')
            return(0);
        
        /* Stop the loop */
        else if (str[i - 1] == '\n' && i != init_pos)
            break;
        
        /* 
        ** Going through the string for 
        ** 'col_sum'(or col_minus) distance
        ** and run forwards.
        ** Don't count the '\n' in any loop.
        */
        else
        {
            c = 0;
            while (c < col_sum)
            {
                if (str[i] != '\n')
                    c++;
                i++;
            }
        }
        if (str[i] == '\n')
            i++;
    }

    /*
    ** Very similar to the prevoious loop.
    ** 'col_minus' distance and run forwards
    */
    i = init_pos;
    while (i >= 0 && i < (int)strlen(str))
    {
        if (str[init_pos - 1] == '\n' && init_pos != 0)
            break;
        if (str[i] != '.' && str[i] != 'K')
            break;
        if (str[i] == 'K')
            return(0);
        else if (str[i - 1] == '\n' && i != init_pos)
            break;
        else
        {
            c = 0;
            while (c < col_minus)
            {
                if (str[i] != '\n')
                    c++;
                i++;
            }
        }
        if (str[i] == '\n')
            i++;
    }
    /*
    ** 'col_sum' distance and
    ** run backwards
    */
    i = init_pos;
    while (i >= 0 && i < (int)strlen(str))
    {
        if (str[init_pos - 1] == '\n' && init_pos != 0)
            break;
        if (str[i] != '.' && str[i] != 'K')
            break;
        if (str[i] == 'K')
            return(0);
        else if (str[i - 1] == '\n' && i != init_pos)
            break;
        else
        {
            c = 0;
            while (c < col_sum)
            {
                if (str[i] != '\n')
                    c++;
                i--;
            }
        }
        if (str[i] == '\n')
            i--;
    }
    /*
    ** The last loop of this algorith.
    ** 'col_minus' and run backwards
    */
    i = init_pos;
    while (i >= 0 && i < (int)strlen(str))
    {
        if (str[init_pos + 1] == '\n' || init_pos + 1 == (int)strlen(str))
            break;
        if (str[i] != '.' && str[i] != 'K')
            break;
        if (str[i] == 'K')
            return(0);
        else if (str[i - 1] == '\n' && i != init_pos)
            break;
        else
        {
            c = 0;
            while (c < col_minus)
            {
                if (str[i] != '\n')
                   c++;
                i--;
            }
        }
        if (str[i] == '\n')
            i--;
    }
    return(1);
}

/*
** Rook's algorithm 
*/
int     R_checkmate(int column, int init_pos, char *str)
{
    int     i;
    int     c;

    /*
    ** Is the King in the same row? 
    */
    i = init_pos;
    while (i >= 0 && i < (int)strlen(str) && str[i] != '\n')
    {
        i++;
        if (str[i] != '.' && str[i] != 'K')
            break;
        if (str[i] == 'K')
            return(0);
    }
    i = init_pos;
    while (i >= 0 && i < (int)strlen(str) && str[i] != '\n')
    {
        i--;
        if (str[i] != '.' && str[i] != 'K')
            break;
        if (str[i] == 'K')
            return(0);
    }
    
    /*
    ** Is the King in the same column? 
    */
    i = init_pos;
    while (i >= 0 && i < (int)strlen(str))
    {
        c = 0;
        while (c < column)
        {
            if (str[i] != '\n')
                c++;
            i++;
        }
        if (str[i] == '\n')
            i++;
        if (str[i] != '.' && str[i] != 'K')
            break;
        if (str[i] == 'K')
            return(0);
    }
    i = init_pos;
    while (i >= 0 && i < (int)strlen(str))
    {
        c = 0;
        while (c < column)
        {
            if (str[i] != '\n')
                c++;
            i--;
        }
        if (str[i] == '\n')
            i--;
        if (str[i] != '.' && str[i] != 'K')
            break;
        if (str[i] == 'K')
            return(0);
    }
    return(1);
}

/*
** To find the position of the pieces in the string from main.
** The order variable indicates how many times that piece is on the board.
*/
int     find_position(int piece, int order, char *str)
{
    int i;
    int c;

    i = 0;
    c = 0;
    while(str[i])
    {
        if (str[i] == piece)
        {
            c++;
            if (c == order)
                return(i);
        }
        i++;
    }
    return(1);
}

/*
** To count how many times each piece is on the board.
** It also counts spaces (.) and EOFs ('\n').
*/
int     count_pieces(int piece, char *str)
{
    int i;
    int nr_pieces;

    i = 0;
    nr_pieces = 0;
    while(str[i])
    {
        if (str[i] == piece)
            nr_pieces++;
        i++;
    }
    return(nr_pieces);
}

/*
** To find different number of rows and columns
*/
int     check_board(char *str)
{
    int columns;
    int rows;
    int j;

    columns = (strlen(str)) / (count_pieces('\n', str) + 1);
    rows = 1;
    j = columns;
    while (str[j])
    {
        if (str[j] != '\n')
            return(0);
        j = j + columns + 1;
        rows++;
    }
    if (rows != columns)
        return (0);
    if (rows > 9)
        return(0);
    return(1);
}

/*
** To check errors from pieces
*/
int    ft_check_errors(char *str)
{
    if (check_board(str) == 0)
        return(1);
    
    /* To find unsuppoerted pieces */
    if (count_pieces('P', str) + count_pieces('B', str)
                    + count_pieces('R', str) + count_pieces('Q', str)
                    + count_pieces('K', str) + count_pieces('.', str)
                    + count_pieces('\n', str) != (int)strlen(str))
        return(1);
    if (count_pieces('K', str) != 1)
        return(1);
    
    /* To check the numbers of EOFs */
    if ( (((int)strlen(str) + 1) % (count_pieces('\n', str) + 1)) != 0)
        return(1);
    return(0);
}

int		ft_check_mate(char *str)
{
    int     i;
    int     j;
    int     size;
    int     pos;

    if (ft_check_errors(str) == 1)
        return(1);
    
    /* Size is the number os colums/rows of the board */
    size = ( ( strlen(str) ) / ( count_pieces('\n', str) + 1) );
    j = 1;
    
    /* Are Pawns check the King? */
    i = count_pieces('P', str);
    while (j <= i)
    {
        pos = find_position('P', j, str);
        if (P_checkmate(size, pos, str) == 0)
            return(0);
        j++;
    }
    
    /* Are Bishops check the King? */
    j = 1;
    i = count_pieces('B', str);
    while (j <= i)
    {
        pos = find_position('B', j, str);
        if (B_checkmate(size, pos, str) == 0)
            return(0);
        j++;
    }
    
    /* Are Rooks check the King? */
    j = 1;
    i = count_pieces('R', str);
    while (j <= i)
    {
        pos = find_position('R', j, str);
        if (R_checkmate(size, pos, str) == 0)
            return(0);
        j++;
    }
    
    /* Are Queen check the King? */
    j = 1;
    i = count_pieces('Q', str);
    while (j <= i)
    {
        pos = find_position('R', j, str);
        if (B_checkmate(size, pos, str) == 0)
            return(0);
        if (R_checkmate(size, pos, str) == 0)
            return(0);
        j++;
    }
    return(1);
}