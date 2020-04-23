#include <string.h>
#define MAX_SQUARE				9
#define IS_INSIDE(x, y, size)	(x >= 0 && y >= 0 && x < size && y < size)

typedef int		(*f_chess)(char *, int, int, int);

typedef enum	e_chess_status {
	CHESS_ERROR    = -1,
	CHESS_MATE     =  0,
	CHESS_SAFE     =  1,
}				t_chess_status;

typedef enum	e_chess_piece {
	PIECE_NONE		= '.',
	PIECE_PAWN		= 'P',
	PIECE_BISHOP	= 'B',
	PIECE_ROOK		= 'R',
	PIECE_QUEEN		= 'Q',
	PIECE_KING		= 'K',
}				t_chess_piece;

static int		compute_pos(int x, int y, int size) {
	return (x + y * (size + 1));
}

static int		chess_unknwn(char *board, int x, int y, int size) {
	return (CHESS_ERROR);
}

static int		chess_case(char *board, int x, int y, int size) {
	return (CHESS_SAFE);
}

static int		chess_pawn(char *board, int x, int y, int size) {
	if (y == 0)
		return (CHESS_SAFE);
	if (x != 0 && board[compute_pos(x-1, y-1, size)] == 'K')
		return (CHESS_MATE);
	if (board[compute_pos(x+1, y-1, size)] == 'K')
		return (CHESS_MATE);
	return (CHESS_SAFE);
}

static int		piece_move(char *board, int x, int y, int xd, int yd, int size) {
	while (IS_INSIDE(x+xd, y+yd, size) && board[compute_pos(x+xd, y+yd, size)] == '.') {
		x += xd;
		y += yd;
	}
	if (!IS_INSIDE(x+xd, y+yd, size) || board[compute_pos(x+xd, y+yd, size)] != 'K')
		return (CHESS_SAFE);
	return (CHESS_MATE);
}

static int		chess_bishop(char *board, int x, int y, int size) {
 	if (piece_move(board, x, y, 1, 1, size) == CHESS_MATE)
 		return (CHESS_MATE);
 	if (piece_move(board, x, y, -1, -1, size) == CHESS_MATE)
 		return (CHESS_MATE);
 	if (piece_move(board, x, y, 1, -1, size) == CHESS_MATE)
 		return (CHESS_MATE);
	if (piece_move(board, x, y, -1, 1, size) == CHESS_MATE)
		return (CHESS_MATE);
	return (CHESS_SAFE);
}

static int		chess_rook(char *board, int x, int y, int size) {
	if (piece_move(board, x, y, 0, 1, size) == CHESS_MATE)
		return (CHESS_MATE);
	if (piece_move(board, x, y, 0, -1, size) == CHESS_MATE)
		return (CHESS_MATE);
	if (piece_move(board, x, y, 1, 0, size) == CHESS_MATE)
		return (CHESS_MATE);
	if (piece_move(board, x, y, -1, 0, size) == CHESS_MATE)
		return (CHESS_MATE);
	return (CHESS_SAFE);
}

static int		chess_queen(char *board, int x, int y, int size) {
	if (chess_bishop(board, x, y, size) == CHESS_MATE) {
		return (CHESS_MATE);
	}
	if (chess_rook(board, x, y, size) == CHESS_MATE)
		return (CHESS_MATE);
	return (CHESS_SAFE);
}

static void		init_moves(f_chess *moves) {
	int i = 0;

	while (i < 255)
		moves[i++] = &chess_unknwn;
	moves['\n']			= &chess_case;
	moves['\0']			= &chess_case;
	moves[PIECE_NONE]	= &chess_case;
	moves[PIECE_PAWN]	= &chess_pawn;
	moves[PIECE_BISHOP]	= &chess_bishop;
	moves[PIECE_ROOK]	= &chess_rook;
	moves[PIECE_QUEEN]	= &chess_queen;
	moves[PIECE_KING]	= &chess_case;
}

static int		get_size(char *board) {
	int		height = 1;
	int		width = -1;
	char	*tmp = board;

	while ((tmp = strchr(tmp, '\n'))) {
		if (tmp - board != width && width != -1)
			return (-1);
		width = tmp - board;
		height++;
		board = (++tmp);
	}
	if (height != width || height * width > 81 || strlen(board) != width)
		return (-1);
	return (width);
}

static int		count_kings(char *board) {
	int kings = 0;

	while ((board = strchr(board, 'K'))) {
		board++;
		kings++;
	}
	return (kings);
}

int				ft_check_mate(char* board) {
	int		x = 0;
	int		y = 0;
	int		status = CHESS_SAFE;
	int		size;
	char 	*tmp = board;
	f_chess	moves[255];
	
	if (count_kings(board) != 1)
		return (1);
	if ((size = get_size(board)) == -1)
		return (1);
	init_moves(moves);
	while (*tmp) {
		status = moves[*tmp](board, x, y, size);
		if (status != CHESS_SAFE)
			break ;
		y += *tmp == '\n';
		x++;
		x *= *(tmp++) != '\n';
	}
	return (status != CHESS_MATE ? 1 : 0);
}
