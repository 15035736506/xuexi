#include"game.h"
void meau()
{
	printf("*****************************\n");
	printf("*****1.play  0.exit**********\n");
	printf("*****************************\n");
}
//��Ϸ�����㷨ʵ��
void game()
{
	char board[ROW][COL] = { 0 };//ȫ���ո�
	int ret = 0;
	//��ʼ������
	Initboard(board, ROW, COL);
	//��ӡ����
	Displayboard(board, ROW, COL);
	//����
	while (1)
	{
		//�������
		Playermmove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);//�ж���Ӯ
		if (ret != 'C')
		{
			break;
		}
		//��������
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
		printf("���Ӯ\n");
	}
	if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	if (ret == 'Q')
	{
		printf("ƽ��\n");
	}
	
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		meau();
		printf("��ѡ��;>(1/0)");
		scanf("%d", &input);
		switch(input)
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

	} while (input);
}
int main()
{
	test();
	return 0;
}