#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int check_is_king(char *board)
{
	int cont;
	int nking;

	nking=0;
	cont = 0;
	while(board[cont]!='\0')
	{
		if(board[cont]=='K')
			nking++;
		cont++;
	}
	if (nking==1)
		return(1);
	return(0);
}

int check_is_pieces(char *board)
{
        int cont;

        cont = 0;
        while(board[cont]!='\0')
        {
                if(board[cont]!='K' && board[cont]!='\0' && board[cont]!='.' && board[cont]!='P' && board[cont]!='R' && board[cont]!='Q' && board[cont]!='B' && board[cont]!='\n')
                        return(0);
                cont++;
        }
        return(1);
}
int check_dimension(char *board)
{
	int col;
	int i;
	int colmax;
	int row;
	int flag;

	i = 0;
	flag = 0;
	row = 0;
	col = 0;
	colmax = 0;
	while (board[i]!='\0')
	{
		if (board[i]=='\n')
		{
			if (flag == 0)
			{
				colmax = col;
				flag = 1;
			}
			row ++;
			if (i+1 != (row*colmax+row))
				return(-1);
		}
		col++;	
		i++;
	}
	if (row != colmax)
		return(-1);
	return(colmax);
}

int ft_strlen(char *board)
{
	int i;
	i = 0;
	while(board[i]!='\0')
		i++;
	return(i);
}

int check_rook(char *board, int row, int king)
{
	int i;
	int n;

	i = king;
	n = 0;
	while(i > 0 && i < ft_strlen(board))
	{
		i = i - n * row;
		if (board[i]=='Q')
			return(1);
		n++;
	}
	i = king;
	n = 0;
	while(i > 0 && i < ft_strlen(board))
        {
                i = i +  n * row;
                if (board[i]=='Q')
                        return(1);
                n++;
        }


	return(0);
}

				
int ft_check_mate(char *board)
{
	int col;
	int i;
	char **table;
	int len;
	int r;
	int c;
	int kc;
	int kr;

	kc = 0;
	kr = 0;
	i = 0;
	col = 0;
	if (board==NULL)
		return(1);
	//check if there is a king
	if (check_is_king(board)== 0)
		return(1);
	//check if correct piece
	if (check_is_pieces(board) == 0)
		return(1);
	//check if square board
	if (check_dimension(board) == -1)
		return(1);
	len = check_dimension(board);
	//size less 9
	if ( len>9) 
		return(1);	
	if(!(table =(char**) malloc(len*sizeof(char*))))
		return(1);
	while (i<len)
	{
		if(!(table[i]=malloc(len*sizeof(char))))
			return(1);
		i++;
	}
	i = 0;
	r=0;
	c=0;
	while (r < len)
	{
		c = 0;
		while(c < len)
		{
			table[r][c]=board[i];
       			if (board[i] == 'K')
			{
				kc = c;
				kr = r;
			}
			i++;
			c++;
		}
		i++;
		r++;
	}
	/*
      	i = 0;
        r = 0;
	c = 0;
	while (r < len)
	{
		c = 0;
		while(c < len)
                {
                        printf("%c",table[r][c]);
                        c++;
                }
                printf("\n");
		r++;
        }
	*/
	i = 0;
	while (kr-i>-1)
	{
		if (table[kr-i][kc]=='Q' || table[kr-i][kc]=='R')
			return(0);
		i++;
	}
	i=0;
	while (kr+i<len)
        {
                if (table[kr+i][kc]=='Q' || table[kr+i][kc]=='R')
                        return(0);
                i++;
        }
	i=0;
	while (kc-i>-1)
        {
		if (table[kr][kc-i]==81 || table[kr][kc-i]==82)
                        return(0);
                i++;
        }
	i=0;
	while (kc+i<len)
        {
                if (table[kr][kc+i]=='Q' || table[kr][kc+i]=='R')
                        return(0);
                i++;
     	}
	//checking bishop
	while (kr-i>-1 && kc-i>-1)
        {
                if (table[kr-i][kc-i]=='Q' || table[kr-i][kc-i]=='B')
                        return(0);
                i++;
        }
        i=0;
        while (kr+i<len && kc-i>-1)
        {
                if (table[kr+i][kc-i]=='Q' || table[kr+i][kc-i]=='B')
                        return(0);
                i++;
        }
        i=0;
        while (kr-i>-1 && kc+i<len)
        {
                if (table[kr-i][kc+i]=='Q' || table[kr-i][kc+i]=='B')
                        return(0);
                i++;
        }
	i = 0;  
	while (kr+i<len && kc+i<len)
        {
                if (table[kr+i][kc+i]=='Q' || table[kr+i][kc+i]=='B')
                        return(0);
                i++;
        }
	//check peon
	if(kr+1<len && kc-1>-1)
		if (table[kr+1][kc-1]=='P')
			return(0);
	if(kr+1<len && kc+1<len)
		if (table[kr+1][kc+1]=='P')
			return(0);
	return(1);
}
