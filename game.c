#include "game.h"
//��ʼ������
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
//��ӡ����
void  DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	printf("  ");
	for (j = 1;j <= col;j++)//��ӡ���к�
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1;i <= row;i++)
	{
		printf("%d ", i);//��ӡ���к�
		for (j = 1;j <=col;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
//���õ���
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
//������Χ���׸���
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
//�Լ�ûд����ը��
//void panduan(char mine[ROWS][COLS], char show[ROWS][COLS],int x,int y)
//{
//	int count = get_mine_count(mine, x, y);
//	if (count == '0')
//	{
//		show[x][y] = count + '0';
//	}
//}

//ը��ʽչ������
void explode_spread(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{
	//���ƷǷ������չ��
	if (x >= 1 && x <= row && y >= 1 && y <= col)
	{
		//�����λ�ø������ܵ��׵ĸ���
		int count = get_mine_count(mine, x, y);
		//������û��һ�����ף�����Ҫ���λ�õ�����չ����ֱ��չ����ĳ��λ�ø������ڵ���Ϊֹ
		if (count == 0)
		{
			//�Ѹ���û�е��׵�λ�ñ���ַ� ���ո�
			show[x][y] = '0';
			int i = 0;
			//�����ܹ�8��λ�õݹ����
			for (i = x - 1; i <= x + 1; i++)
			{
				int j = 0;
				for (j = y - 1; j <= y + 1; j++)
				{
					//���ƶԵ�λ�õ��ظ�չ�����ã�ʹ��ÿһ��λ��ֻ��������չ��һ��
					if (show[i][j] == '*')
					{
						explode_spread(mine, show, row, col, i, j);
					}
				}
			}
		}
		//�����ܴ��ڵ�����Ӧ�������λ���ϱ�ע�ϵ��׵ĸ���
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
		printf("������Ҫ�Ų�λ�õ�����:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')//����
			{
				printf("���ź����㱻ը���ˣ�\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				//ը��չ��
				explode_spread(mine,show,row,col,x,y);
				DisplayBoard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
	if(win == row * col - ESAY_COUNT )
	{
		printf("��ϲ�㣡���׳ɹ���");
		DisplayBoard(mine, ROW, COL);
	}
		
}