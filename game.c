#include "game.h"
//初始化棋盘
void Initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i, j;
	for (i = 0;i <= rows;i++)
	{
		for(j = 0;j <= cols;j++)
		{
			board[i][j] = set;
		}
	}
}
//打印棋盘
void  DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	printf("  ");
	for (j = 1;j <= col;j++)//打印列行号
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1;i <= row;i++)
	{
		printf("%d ", i);//打印行行号
		for (j = 1;j <=col;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
//设置地雷
void Setmine(char board[ROWS][COLS], int row, int col)
{
	int count = ESAY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
			
	}
}
//计算周围地雷个数
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y] +
		mine[x + 1][y - 1] +
		mine[x + 1][y + 1] - 8 * '0';
}
//自己没写出来炸金花
//void panduan(char mine[ROWS][COLS], char show[ROWS][COLS],int x,int y)
//{
//	int count = get_mine_count(mine, x, y);
//	if (count == '0')
//	{
//		show[x][y] = count + '0';
//	}
//}

//炸金花式展开函数
void explode_spread(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{
	//限制非法坐标的展开
	if (x >= 1 && x <= row && y >= 1 && y <= col)
	{
		//计算该位置附近四周地雷的个数
		int count = get_mine_count(mine, x, y);
		//若四周没有一个地雷，则需要向该位置的四周展开，直到展开到某个位置附近存在地雷为止
		if (count == 0)
		{
			//把附近没有地雷的位置变成字符 “空格”
			show[x][y] = '0';
			int i = 0;
			//向四周共8个位置递归调用
			for (i = x - 1; i <= x + 1; i++)
			{
				int j = 0;
				for (j = y - 1; j <= y + 1; j++)
				{
					//限制对点位置的重复展开调用，使得每一个位置只能向四周展开一次
					if (show[i][j] == '*')
					{
						explode_spread(mine, show, row, col, i, j);
					}
				}
			}
		}
		//若四周存在地雷则应该在这个位置上标注上地雷的个数
		else
		{
			show[x][y] = count + '0';
		}
	}
}
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col- ESAY_COUNT)
	{
		printf("请输入要排查位置的坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')//是雷
			{
				printf("很遗憾，你被炸死了！\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				//炸金花展开
				explode_spread(mine,show,row,col,x,y);
				DisplayBoard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
	if(win == row * col - ESAY_COUNT )
	{
		printf("恭喜你！排雷成功！");
		DisplayBoard(mine, ROW, COL);
	}
		
}