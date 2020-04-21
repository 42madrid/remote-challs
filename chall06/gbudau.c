/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbudau.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 23:10:50 by gbudau            #+#    #+#             */
/*   Updated: 2020/04/21 08:44:37 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#define VALID_PIECES	"PBRQK.\n"
#define ATTACKERS		"PBRQ"
#define KING 			'K'
#define PAWN 			'P'
#define BISHOP 			'B'
#define ROOK 			'R'
#define QUEEN 			'Q'
#define LINE			'\n'
#define MAX_SQUARE_SIZE	9
#define MIN(a, b)		(((a) < (b)) ? (a) : (b))

/*
** A valid board is made of VALID_PIECES characters
** Length of lines should be equal to the number of lines
** There has to be one and only one KING
** Maximum board dimension can be 9 x 9
** The size of the board (N x N) will be assigned to "size"
** Return 1 if its a valid board, 0 otherwise
**
*/

static int	validate_board(char *board, int *size)
{
	int	i;
	int	lines;
	int	king_found;
	int	line_length;

	i = 0;
	king_found = 0;
	line_length = 0;
	lines = 1;
	while (board[i] != '\0')
	{
		if ((strchr(VALID_PIECES, board[i]) == NULL) ||
			(*size == 0 && board[i] == LINE && (*size = i) &&
				*size > MAX_SQUARE_SIZE) ||
			((board[i] == LINE && ++lines) &&
				(*size != line_length || (line_length = 0) || lines > *size)) ||
			(board[i] == KING && ++king_found && king_found != 1))
			return (0);
		line_length = (board[i] != LINE) ? line_length + 1 : line_length;
		i++;
	}
	if ((*size == 0 && (*size = i) && *size > MAX_SQUARE_SIZE) ||
		king_found != 1 || lines != *size)
		return (0);
	return (1);
}

/*
** Verify if KING is one row above on left and right side of the PAWN
** Return 1 if it doesn't find the KING, 0 otherwise
*/

static int	verify_pawn(char *board, int position, int size)
{
	int	row_length;
	
	row_length = size + 1;
	if (position / row_length > 0)
	{
		if (position % row_length  - 1 >= 0)
		{
			if (board[position - row_length - 1] == KING)
				return (0);
		}
		if (position % row_length + 1 <= size)
		{
			if (board[position - row_length + 1] == KING)
				return (0);
		}
	}
	return (1);
}

/*
** Verify if the KING is upwards, downwards, left or right of the ROOK position
** Return 1 if it doesn't find the KING, 0 otherwise
*/

static int	verify_rook(char *board, int position, int size)
{
	int	row_length;
	int	diff;
	int	i;

	row_length = size + 1;
	/* Check upwards */
	if (position / row_length > 0)
	{
		i = row_length;
		diff = position / row_length;
		while (diff > 0)
		{
			if (strchr(ATTACKERS, board[position - i]) != NULL)
				break;
			if (board[position - i] == KING)
				return (0);
			diff--;
			i += row_length;
		}
	}
	/* Check downwards */
	if (position / row_length < size)
	{
		i = row_length;
		diff = size - position / row_length - 1;
		while (diff > 0)
		{
			if (strchr(ATTACKERS, board[position + i]) != NULL)
				break;
			if (board[position + i] == KING)
				return (0);
			i += row_length;
			diff--;
		}
	}
	/* Check right side */
	if (position % row_length > 0)
	{
		i = 1;
		diff = position % row_length;
		while (diff > 0)
		{
			if (strchr(ATTACKERS, board[position - i]) != NULL)
				break;
			if (board[position - i] == KING)
				return (0);
			i++;
			diff--;
		}
	}
	/* Check left side */
	if (position % row_length < size)
	{
		i = 1;
		diff = size - position % row_length - 1;
		while (diff > 0)
		{
			if (strchr(ATTACKERS, board[position + i]) != NULL)
				break;
			if (board[position + i] == KING)
				return (0);
			i++;
			diff--;
		}
	}
	return (1);
}

/*
** Verify if the KING is diagonal up-right, diagonal up-left, diagonal down-left or diagonal down-right of the BISHOP position
** Return 1 if it doesn't find the KING, 0 otherwise
*/

static int	verify_bishop(char *board, int position, int size)
{
	int	row_length;
	int	diff;
	int	i;
	int	j;

	row_length = size + 1;
	/* Check upper-right corner */
	if (position / row_length > 0 && position % row_length < size - 1)
	{
		i = row_length;
		j = 1;
		diff = MIN(position / row_length, size - position % row_length - 1);
		while (diff > 0)
		{
			if (strchr(ATTACKERS, board[position - i + j]) != NULL)
				break;
			if (board[position - i + j] == KING)
				return (0);
			i += row_length;
			j++;
			diff--;
		}
	}

	/* Check upper-left corner */
	if (position / row_length > 0 && position % row_length > 0)
	{
		i = row_length;
		j = 1;
		diff = MIN(position / row_length, position % row_length);
		while (diff > 0)
		{
			if (strchr(ATTACKERS, board[position - i - j]) != NULL)
				break;
			if (board[position - i - j] == KING)
				return (0);
			i += row_length;
			j++;
			diff--;
		}
	}

	/* Check lower-right corner */
	if (position / row_length < size - 1 && position % row_length < size - 1)
	{
		i = row_length;
		j = 1;
		diff = MIN(size - position / row_length - 1, size - position % row_length - 1);
		while (diff > 0)
		{
			if (strchr(ATTACKERS, board[position + i + j]) != NULL)
				break;
			if (board[position + i + j] == KING)
				return (0);
			i += row_length;
			j++;
			diff--;
		}
	}

	/* Check lower-left corner */
	if (position / row_length < size - 1 && position % row_length > 0)
	{
		i = row_length;
		j = 1;
		diff = MIN(size - position / row_length - 1, position % row_length);
		while (diff > 0)
		{
			if (strchr(ATTACKERS, board[position + i - j]) != NULL)
				break;
			if (board[position + i - j] == KING)
				return (0);
			i += row_length;
			j++;
			diff--;
		}
	}
	return (1);
}

/*
** Search for ATTACKERS in the "board" string
** Calls "verify_X" function to check for intersections with the KING
** Return 1 if the ATTACKERS don't intersect with the KING, 0 otherwise
*/

static int	check_board(char *board, int size)
{
	int	i;

	i = 0;
	while (board[i] != '\0')
	{
		if (board[i] == PAWN && (verify_pawn(board, i , size) == 0))
			return (0);
		else if (board[i] == ROOK && (verify_rook(board, i , size) == 0))
			return (0);
		else if (board[i] == BISHOP && (verify_bishop(board, i, size) == 0))
			return (0);
		else if (board[i] == QUEEN && ((verify_rook(board, i , size) == 0) ||
										(verify_bishop(board, i, size) == 0)))
			return (0);
		i++;
	}
	return (1);
}

int			ft_check_mate(char *board)
{
	int		size;
	
	size = 0;
	if (board == NULL || *board == '\0' ||
			validate_board(board, &size) == 0 || size == 1)
		return (1);
	return (check_board(board, size));
}
