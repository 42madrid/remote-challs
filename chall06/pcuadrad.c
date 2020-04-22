#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int		isinset(char c, char charset)
{
	if (charset == c)
		return (1);
	return (0);
}

static int		count_str(char const *str, char c)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str && isinset(*str, c))
			str++;
		if (*str && !isinset(*str, c))
		{
			count++;
			while (*str && !isinset(*str, c))
				str++;
		}
	}
	return (count);
}

static char		*malloc_string(char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !isinset(str[i], c))
		i++;
	if (!(word = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] && !isinset(str[i], c))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char		**free_split(char ***tabstr)
{
	int i;

	i = 0;
	while (*tabstr[i])
	{
		free(*tabstr[i]);
		i++;
	}
	free(*tabstr);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	int		len;
	char	**tabstr;
	int		i;

	if (!s)
		return (NULL);
	len = count_str(s, c);
	if (!(tabstr = (char **)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && isinset(*s, c))
			s++;
		if (*s && !isinset(*s, c))
		{
			if (!(tabstr[i] = malloc_string((char*)s, c)))
				return (free_split(&tabstr));
			i++;
			while (*s && !isinset(*s, c))
				s++;
		}
	}
	tabstr[i] = NULL;
	return (tabstr);
}

int     array_len(char **board)
{
    int     i;

    i = -1;
    while (board[++i])
        ;
    return (i);
}

int     check_line(char *line_board, int *set_king, int *least_one_figure)
{
    int     i;

    i = -1;
    while (line_board[++i])
    {
        if (line_board[i] != '.' && line_board[i] != 'K' && line_board[i] != 'P' &&
            line_board[i] != 'B' && line_board[i] != 'R' && line_board[i] != 'Q')
                return (0);
        else if (line_board[i] == 'K')
            *set_king += 1;
        else if (line_board[i] == 'P' || line_board[i] == 'B' || line_board[i] == 'R'
            || line_board[i] == 'Q')
            *least_one_figure += 1;
    }
    return (1);
}

int     check_board(char **board)
{
    int     len_array;
    int     len_line;
    int     set_king;
    int     least_one_figure;
    int     i;

    i = -1;
    len_array = array_len(board);
    if (len_array < 2 || len_array > 9)
        return (0);
    set_king = 0;
    least_one_figure = 0;
    while (board[++i])
    {
        len_line = strlen(board[i]);
        if (i > 0 && len_line != (int)strlen(board[i - 1]))
            return (0);
        if (len_line != len_array || !check_line(board[i], &set_king, &least_one_figure))
            return (0);
    }
    if (set_king == 1 && least_one_figure > 0)
        return (1);
    return (0);
}

int     pawn(char **board, int x, int y, int size)
{
    if (x == 0)
        return (0);
    if (y > 0 && y < size)
    {
        if (board[x - 1][y - 1] == 'K' || board[x - 1][y + 1] == 'K')
            return (1);
    }
    else if (y == 0)
    {
        if (board[x - 1][y + 1] == 'K')
            return (1);
    }
    else if (y == 4)
    {
        if (board[x - 1][y - 1] == 'K')
            return (1);
    }
    return (0);
}

int     move(char **board, int x_pos, int y_pos, int size, int x_counter, int y_counter)
{
    while (1)
    {
        x_pos -= x_counter;
        y_pos -= y_counter;
        if (x_pos < 0 || x_pos > size || y_pos < 0 || y_pos > size)
            break ;
        if (board[x_pos][y_pos] == 'K')
            return (1);
        else if (board[x_pos][y_pos] != '.')
            break ;
    }
    return (0);
}

int     bishop(char **board, int x, int y, int size)
{
    //left up diagonal
    if (y > 0 && x > 0 && move(board, x, y, size, 1, 1))
        return (1);
    //left down diagonal
    if (y > 0 && x < size && move(board, x, y, size, -1, 1))
        return (1);
    //right up diagonal
    if (y < size && x > 0 && move(board, x, y, size, 1, -1))
        return (1);
    //right down diagonal
    if (y < size && x < size && move(board, x, y, size, -1, -1))
        return (1);
    return (0);
}

int     rook(char **board, int x, int y, int size)
{
    //left line
    if (y > 0 && move(board, x, y, size, 0, 1))
        return (1);
    //up line
    if (x > 0 && move(board, x, y, size, 1, 0))
        return (1);
    //right line
    if (y < size && move(board, x, y, size, 0, -1))
        return (1);
    //down line
    if (x < size && move(board, x, y, size, -1, 0))
        return (1);
    return (0);
}

int     resolve_board(char **board)
{
    int     i;
    int     j;
    int     len;

    i = -1;
    len = array_len(board) - 1;
    while (board[++i])
    {
        j = -1;
        while (board[i][++j])
        {
            if (board[i][j] == 'P' && pawn(board, i, j, len))
                return (1);
            else if (board[i][j] == 'B' && bishop(board, i, j, len))
                return (1);
            else if (board[i][j] == 'R' && rook(board, i, j, len))
                return (1);
            else if (board[i][j] == 'Q' && (bishop(board, i, j, len) || rook(board, i, j, len)))
                return (1);
        }
    }
    return (0);
}

int     ft_check_mate(char *board)
{
    char **chessboard;

    if (!board)
        return (1);
    chessboard = ft_split(board, '\n');
    if (!check_board(chessboard))
        return (1);
    if (!resolve_board(chessboard))
        return (1);
    return (0);
}
