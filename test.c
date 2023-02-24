#include"game.h"
void meau()
{
	printf("*****************************\n");
	printf("*****1.play  0.exit**********\n");
	printf("*****************************\n");
}
//游戏整个算法实现
void game()
{
	char board[ROW][COL] = { 0 };//全部空格
	int ret = 0;
	//初始化棋盘
	Initboard(board, ROW, COL);
	//打印棋盘
	Displayboard(board, ROW, COL);
	//下棋
	while (1)
	{
		//玩家下棋
		Playermmove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);//判断输赢
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		Computermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	if (ret == '#')
	{
		printf("电脑赢\n");
	}
	if (ret == 'Q')
	{
		printf("平局\n");
	}
	
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		meau();
		printf("请选择;>(1/0)");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}

	} while (input);
}
int main()
{
	test();
	return 0;
}