#include "game.h"
void menu()
{
	printf("************************************\n");
	printf("******* 1.paly  0.exit *************\n");
	printf("************************************\n");
}
void game()
{
	printf("扫雷\n");
	static char mine[ROWS][COLS] = { 0 };//布置雷
	static char show[ROWS][COLS] = { 0 };//排查雷
	Initboard(mine, ROWS, COLS,'0');
	Initboard(show, ROWS, COLS, '*');//初始化棋盘
	//打印棋盘
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//布雷
	Setmine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//排雷
	Findmine(mine, show, ROW, COL);
}
void test()
{
	
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请选择:>(1/0)");
		scanf("%d", &input);
		switch (input)
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
		
	}
	while (input);
}
int main()
{
	test();
	return 0;
}
