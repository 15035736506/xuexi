#include "game.h"
void menu()
{
	printf("************************************\n");
	printf("******* 1.paly  0.exit *************\n");
	printf("************************************\n");
}
void game()
{
	printf("ɨ��\n");
	static char mine[ROWS][COLS] = { 0 };//������
	static char show[ROWS][COLS] = { 0 };//�Ų���
	Initboard(mine, ROWS, COLS,'0');
	Initboard(show, ROWS, COLS, '*');//��ʼ������
	//��ӡ����
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//����
	Setmine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//����
	Findmine(mine, show, ROW, COL);
}
void test()
{
	
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>(1/0)");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
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
