#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int board_check(char *board)
{
	int len;
	int i;
	int king;
	int count;

	i  = 0;
	king = 0;
	count = 0;
	while (board[i] != '\0')
	{
		if (board[i] != '\n' && board[i] != 'K' && board[i] != 'P'
		&& board[i] != 'B' && board[i] != 'R' && board[i] != 'Q' 
		&& board[i] != '.')
			return (0);
		if (board[i] == 'K')
			king++;
		if (board[i] == 'P' || board[i] == 'B' || board[i] == 'R' || board[i] == 'Q')
			count++;
		i++;
	}
	if (king > 1 || king == 0 || count == 0)
		return (0);
	len = 0;
	while (board[len] != '\n' && board[len] != '\0')
		len++;
	return (len);
}

int clear_board(char *str, char **board, int r)
{
	int len;
	int i;

	i = 0;
	if (board)
	{
		len = strlen(board[0]);
		while (i < len)
		{
			free(board[i]);
			i++;
		}
		free(board);
	}
	if (str)
		free(str);
	return (r);
}

char **board_creator(char *board, int len)
{
	char **map;
	char *row;
	int i;
	int length;
	int k;

	i  = 0;
	if (len > 9 || !(map = (char **)malloc(sizeof(char *) * len)))
		return (NULL);
	row = strtok(board, "\n");
	length = strlen(row);
	while (i < len)
	{
		if (!(map[i] = strdup(row)))
			return (NULL);
		row = strtok(NULL, "\n");
		if (row)
			if (strlen(row) != length)
				return (NULL);
		i++;
	}
	return (map);
}
int rook(char **map, int i, int j)
{
	int n;
	int len;

	len = strlen(map[0]) - 1;
	if ((n = j + 1) < len)
	{
		while (n < len && map[i][n] == '.')
			n++;
		if (map[i][n] == 'K')
			return (1);
	}
	if ((n = j - 1) >= 0)
	{
		while (n > 0 && map[i][n] == '.')
			n--;
		if (map[i][n] == 'K')
			return (1);	
	}
	if ((n = i + 1) < len)
	{
		while (n < len && map[n][j] == '.')
			n++;
		if (map[n][j] == 'K')
			return (1);
	}
	if ((n = j - 1) >= 0)
	{
		while (n > 0 && map[n][j] == '.')
			n--;
		if (map[n][j] == 'K')
			return (1);
	}
	return (0);
}

int pawn(char **map, int i, int j)
{
	int len;
	int n;
	int l;
	int r;

	len = strlen(map[0]) - 1;
	if ((n = i - 1) >= 0 )
	{
		if ((l = j - 1) >= 0)
		{
			if (map[n][l] == 'K')
				return (1);
		}
		if ((r = j + 1) <= len)
		{
			if (map[n][r] == 'K')
				return (1);
		}
	}
	return (0);
}

int bishop(char **map, int i, int j)
{
	int n;
	int r;
	int l;
	int len;

	len = strlen(map[0]) - 1;
	if ((n = i - 1) >= 0 && (l = j - 1) >= 0)
	{
		while (n > 0 && map[n][l] == '.')
		{
			if ((l = l - 1) < 0)
				break;
			n--;
		}
		if (l >= 0)
			if (map[n][l] == 'K')
				return (1);
	}
	if ((n = i - 1) >= 0 && (r = j + 1) <= len)
	{
		while (n > 0 && map[n][r] == '.')
		{
			if ((r = r + 1) > len)
				break;
			n--;
		}
		if (r <= len)
			if (map[n][r] == 'K')
				return (1);
	}
	if ((n = i + 1) <= len && (l = j - 1) >= 0)
	{
		while (n < len && map[n][l] == '.')
		{
			if ((l = l - 1) < 0)
				break;
			n++;
		}
		if (l >= 0)
			if (map[n][l] == 'K')
				return (1);
	}
	if ((n = i + 1) <= len && (r = j + 1) <= len)
	{
		while (n < len && map[n][r] == '.')
		{
			if ((r = r + 1) > len)
				break;
			n++;
		}
		if (r <= len)
			if (map[n][r] == 'K')
				return (1);
	}
	return (0);
}


int board_play(char **map, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (map[i][j] != '\0')
		{	
			if (map[i][j] == 'R')
			{
				if (rook(map, i ,j))
					return (0);
			}
			if (map[i][j] == 'P')
			{
				if (pawn(map, i, j))
					return (0);
			}
			if (map[i][j] == 'B')
			{
				if (bishop(map, i, j))
					return (0);
			}
			if (map[i][j] == 'Q')
			{
				if (rook(map, i ,j) || bishop(map, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int ft_check_mate(char *board)
{
	int len;
	char **map;
	char *tokboard;

	if (board)
	{
		if (!(len = board_check(board)))
			return (1);
		if (!(tokboard = strdup(board)))
			return (1);
		if (!(map = board_creator(tokboard, len)))
			return (clear_board(tokboard, NULL, 1));
		if (board_play(map, len))
			return (clear_board(tokboard, map, 1));
		return (clear_board(tokboard, map, 0));
	}
	return (1);
}