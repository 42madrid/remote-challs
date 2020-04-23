#include <string.h>
#include <stdlib.h>

int		ft_validate_board(char *board)
{
	int	rows;
	int	cols;
	int prevLen;
	int kingFnd;
	int pieceFnd;

	rows = 0;
	cols = 0;
	prevLen = 0;
	kingFnd = 0;
	pieceFnd = 0;
	while (*board != '\0')
	{
		if(!strchr("PBRQK.\n", *board))
			return(1);
		else if(strchr("PBRQ", *board))
			pieceFnd = 1;
		if (*board == 'K' && kingFnd == 1)
			return(1);
		else if (*board == 'K')
			kingFnd = 1;
		if (*board == '\n')
		{
			rows++;
			if ((prevLen != cols && rows > 1) || cols > 9)
				return(1);
			prevLen = cols;
			cols = 0;
			board++;
			continue;
		}
		cols++;
		board++;
	}
	rows++;
	if (prevLen != rows || rows > 9 || kingFnd == 0 || pieceFnd == 0)
		return(1);
	return(0);
}

char	**ft_full_matrix(char **matrix, int len, char* board)
{
	int i;
	i = 0;
	while(i < len)
	{
		strncpy(matrix[i], board, len);
		matrix[i][len] = '\0';
		board += len + 1;
		i++;
	}
	return(matrix);
}

void	ft_free_board(char **matrix)
{
	for(int i = 0; matrix[i]; i++)
		free(matrix[i]);
}

char	**ft_alloc_board(char *board)
{
	int len;
	int j;
	char **matrix;

	len = 1;
	j = 0;
	while (board[j] != '\0')
	{
		if(board[j] == '\n')
			len++;
		j++;
	}
	if(!(matrix = (char**)malloc((len + 1)* sizeof(char*))))
		return (NULL);
	matrix[len + 1] = "\0";
	for (int i = 0; i < len; i++)
	{
		if(!(matrix[i] = (char*)malloc((len + 1) * sizeof(char))))
		{
			ft_free_board(matrix);
			return (NULL);
		}
	}
	matrix = ft_full_matrix(matrix, len, board);
	return (matrix);
}

int		ft_movements(int x, int y, char **matrix_board)
{
	char	piece;
	int		check;
	int		distance;
	int		len;

	len = strlen(matrix_board[0]);
	piece = matrix_board[y][x];
	check = 1;
	if (piece == 'P')
	{
		if (matrix_board[y - 1][x - 1] == 'K' || matrix_board[y - 1][x + 1] == 'K')
			check = 0;
	}
	else if (piece == 'B' || piece == 'Q')
	{
		distance = 1;
		while (y + distance < len || y - distance >= 0)
		{
			if((x + distance < len && 								//If distance is less than the max limit
			(matrix_board[y + distance][x + distance] == 'K' || 	//If the king is upper-right or lower-right
			matrix_board[y - distance][x + distance] == 'K')) || 
			(x - distance >= 0 && 
			(matrix_board[y - distance][x - distance] == 'K'|| 		//If distance is less than the min limit
			matrix_board[y + distance][x - distance] == 'K')))		//If the king is upper-left or lower-left
				check = 0;
			distance++;
		}
	}
	else if (piece == 'R' || piece == 'Q')
	{
		distance = 1;
		while (x + distance < len || x - distance >= 0)
		{
			if((y + distance < len && matrix_board[y+distance][x] == 'K') ||
			(y - distance >= 0 && matrix_board[y-distance][x] == 'K') ||
			matrix_board[y][x + distance] == 'K' ||
			matrix_board[y][x - distance] == 'K')
				check = 0;
			distance++;
		}
	}
	return(check);
}

int		ft_check_mate(char *board)
{
	char **matrix_board;
	if (ft_validate_board(board) == 1)
		return(1);
	matrix_board = ft_alloc_board(board);
	for(int i = 0; matrix_board[i]; i++)
	{
		for(int j = 0; matrix_board[i][j]; j++)
		{
			if(strchr("PBRQ",matrix_board[i][j]))
			{
				if(ft_movements(j, i, matrix_board) == 0)
				{
					ft_free_board(matrix_board);
					return(0);
				}
			}
		}
	}
	return(1);
}
