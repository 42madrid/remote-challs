/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdorta-n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdorta-n <cdorta-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 12:28:35 by cdorta-n          #+#    #+#             */
/*   Updated: 2020/04/23 14:02:38 by cdorta-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
** P - Pawn (Peon)
** B - Bishop (Alfil)
** R - Rook (Torre)
** Q - Queen (Reina)
** K - King (Rey)
** Return 0 for true value
** Max Size 9x9, Only 1 King, Separator "\n".
*/

static int		ft_chesstable(int size, char *board)
{
	char table[size][size];
	int c, a, b, j, i, s1, s2;

	j = 0;
	c = 0;
	while (j < size && board[c] != '\0')
	{
		i = 0;
		while (i < size && board[c] != '\0')
		{
			if (board[c] == '\n')
				c++;
			table[j][i] = board[c];
			c++;
			i++;
		}
		j++;
	}

	/*
	** KING POSITION COORDS FOR COMPARE
	*/
	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (table[j][i] == 'K')
			{
				a = i;
				b = j;
				break ;
			}
			i++;
		}
		j++;
	}
	
	//CHECK PAWN POSITION RANGE WITH THE KING
	if (b < size - 1)
	{
		if (!((table[b + 1][a + 1] == '.' || table[b + 1][a + 1] == 'R')
		&& (table[b + 1][a - 1] == '.' || table[b + 1][a - 1] == 'R')))
			return (0);
	}

	/*
	**CHECK COORDS WITH OTHER PIECES
	** FIRST, DIAGONALS WITH THE BISHOP
	** SECOND, AXES WITH THE ROOK
	** THE COMBINATION OF THE OTHER TWO, WE CAN CHECK THE QUEEN
	*/

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (table[j][i] == 'B' || table[j][i] == 'Q')
			{
				if (i - j == a - b)
				{
					s1 = i - 1;
					s2 = j - 1;
					while (s1 != a && s2 != b && table[s2][s1] == '.')
					{
						s2--;
						s1--;
					}
					if (table[s2][s1] == 'K')
						return (0);
					s1 = i + 1;
					s2 = j + 1;
					while (s1 != a && s2 != b && table[s2][s1] == '.')
					{
						s2++;
						s1++;
					}
					if (table[s2][s1] == 'K')
						return (0);
				}
				else if (i + j == a + b)
				{
					s1 = i - 1;
					s2 = j + 1;
					while (s1 != a && s2 != b && table[s2][s1] == '.')
					{
						s2++;
						s1--;
					}
					if (table[s2][s1] == 'K')
						return (0);
					s1 = i + 1;
					s2 = j - 1;
					while (s1 != a && s2 != b && table[s2][s1] == '.')
					{
						s2--;
						s1++;
					}
					if (table[s2][s1] == 'K')
						return (0);
				}
			}
			if (table[j][i] == 'R' || table[j][i] == 'Q')
			{
				if (j == b)
				{	
					s1 = i + 1;
					while (s1 != a && table[j][s1] == '.')
						s1++;
					if (table[j][s1] == 'K')
						return (0);
					s1 = i - 1;
					while (s1 != a && table[j][s1] == '.')
						s1--;
					if (table[j][s1] == 'K')
						return (0);
				}
				if (a == i)
				{	
					s2 = j + 1;
					while (s2 != b && table[s2][a] == '.')
						s2++;
					if (table[s2][a] == 'K')
						return (0);
					s2 = j - 1;
					while (s2 != b && table[s2][a] == '.')
						s2--;
					if (table[s2][a] == 'K')
						return (0);
				}
			}
			i++;
		}
		j++;
	}
	return (1);
}

static int		ft_checkboard(char *board)
{
	int k;
	int e;
	int c;
	int lines;

	e = 0;
	k = 0;
	c = 0;
	lines = 1;
	while (board[c] != '\0' && e == 0)
	{
		if (board[c] == '\n')
		{
			lines++;
			c++;
		}
		else
		{
			if (board[c] == 'K' && k != 1)
				k = 1;
			else if (board[c] == 'K' && k == 1)
				e = -1;
			if (board[c] != '.' && board[c] != 'P' && board[c] != 'B'
			&& board[c] != 'R' && board[c] != 'Q' && board[c] != 'K')
				e = -1;
			c++;
		}
	}
	if (e < 0 || k == 0 || lines > 9)
		return (-1);
	if (((c - (lines - 1))) != lines * lines)
		return (-1);
	return (lines);
}

static int		ft_check_mate(char *board)
{
	int lines;

	if (*board)
	{
		if (!((lines = ft_checkboard(board)) > 0))
			return (1);
		if (!(ft_chesstable(lines, board)))
			return (0);
	}
	return (1);
}
