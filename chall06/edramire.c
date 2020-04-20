/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edramire.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 11:22:35 by edramire          #+#    #+#             */
/*   Updated: 2020/04/20 21:19:48 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

static int	get_chess_size(char *board, int len)
{
	int		size;
	int		row;
	int		col;

	if (len == 0 || len > 89)
		return (0);
	size = 0;
	row = 0;
	while (*board != '\0')
	{
		col = 0;
		while (*board != '\0' && *board != '\n')
		{
			++col;
			++board;
		}
		if (row == 0)
			size = col;
		else if (col != size)
			return (0);
		++row;
		board += *board == '\n' ? 1 : 0;
	}
	return (row == col ? size : 0);
}

static int	get_king_index(char *board)
{
	int		idx;
	int		king;

	idx = -1;
	king = -1;
	while (board[++idx] != '\0')
	{
		if (board[idx] == 'K')
		{
			if (king >= 0)
				return (-1);
			king = idx;
		}
		else if (strchr(".PBRQ\n", board[idx]) == NULL)
			return (-1);
	}
	return (king);
}

static int	check_mate(int king, int size, char *board, int dx, int dy, char c)
{
	int		row;
	int		col;
	int		t;
	int		idx;

	t = 0;
	row = king / size;
	col = king % size;
	while (++t < size - 1)
	{
		if ((col + t * dx) >= size - 1 || (col + t * dx) < 0 
			|| (row + t * dy) >= size - 1 || (row + t * dy) < 0)
			break ;
		idx = (row + t * dy) * size + col + t * dx;
		if (board[idx] == 'Q' || board[idx] == c)
			return (0);
		else if (board[idx] != '.')
			return (1);
	}
	return (1);
}

int			ft_check_mate(char *board)
{
	int		size;
	int		king;
	int		len;
	int		check;

	if (board == NULL)
		return (1);
	len = strlen(board);
	size = get_chess_size(board, len);
	king = size > 0 ? get_king_index(board) : -1;
	if (king == -1)
		return (1);
	if (king + size + 2 < len && board[king + size + 2] == 'P')
		return (0);
	if (king + size < len && board[king + size] == 'P')
		return (0);
	check = check_mate(king, size + 1, board, 1, 0, 'R');
	check = check == 0 ? 0 : check_mate(king, size + 1, board, -1, 0, 'R');
	check = check == 0 ? 0 : check_mate(king, size + 1, board, 0, 1, 'R');
	check = check == 0 ? 0 : check_mate(king, size + 1, board, 0, -1, 'R');
	check = check == 0 ? 0 : check_mate(king, size + 1, board, 1, 1, 'B');
	check = check == 0 ? 0 : check_mate(king, size + 1, board, 1, -1, 'B');
	check = check == 0 ? 0 : check_mate(king, size + 1, board, -1, 1, 'B');
	check = check == 0 ? 0 : check_mate(king, size + 1, board, -1, -1, 'B');
	return (check);
}
