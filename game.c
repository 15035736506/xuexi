#include"game.h"
//归零棋盘
void Initboard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			board[i][j] = ' ';
		}
	}
}
//打印棋盘
void Displayboard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j< col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row-1)
		{
			for (j = 0;j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}
//玩家玩
void Playermmove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走:>\n");
	while (1)
	{
		printf("玩家请输入坐标:>");//判断输入合法性
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该位置已经被占用\n");
			}
		}
		else
		{
			printf("输入非法，请重新输入\n");
		}
	}
}
//电脑玩
void Computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走:>\n");
	while (1)
	{
		x = rand() % row;//余数一定小于除数 012
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int isfull(char board[ROW][COL], int row, int col)
{
	int i,j;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (board[i][j] == ' ')
				return 0;//没满
		}
	}
	return 1;
}
char iswin(char board[ROW][COL], int row, int col)
{
	int i;
	//判断行
	for (i = 0; i < row;i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	//判断列
	for (i = 0; i < col;i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//判断斜边
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ')
	{
		return board[0][2];
	}
	if (1 == isfull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}

	