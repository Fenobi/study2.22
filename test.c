#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu()
{
	printf("***************************************\n");
	printf("***************  1.��ʼ   *************\n");
	printf("***************  0.����   *************\n");
	printf("***************************************\n");
	
}
void game()
{
	char board[ROW][COL];

	//��ʼ������
	Initboard(board, ROW, COL);
	system("cls");

	//��ӡ����
	DisplayBoard(board, ROW, COL);

	char x = 0;//������Ϸ״̬
	while (1)
	{
		printf("                 ���⣺\n");
		printf("         ���ڵ����µ������������\n");
		printf("������Ϸ����ҪĿ�����õ��Ի�ʤ����ƽ��\n");
		printf("\n\n");
		//�������
		PlayerMove(board, ROW, COL);
		system("cls");
		DisplayBoard(board, ROW, COL);

		//�ж����ʤ��
		x = IsWin(board, ROW, COL);
		if (x != 'J')
		{
			break;
		}

		//��������
		ComputerMove(board, ROW, COL);
		system("cls");
		DisplayBoard(board, ROW, COL);

		//�жϵ���ʤ��
		x = IsWin(board, ROW, COL);
		if (x != 'J')
		{
			break;
		}
	}
	//�ж�����״̬
		if(x=='*')
		{
			printf("��Ϸ��������һ�ʤ\n");
			printf("ûӮ������������������������\n");
		}
		else if(x=='#')
		{
			printf("��Ϸ���������Ի�ʤ\n");
		}
		else
		{
			printf("��Ϸ������ƽ��\n");
		}
}


int main()
{
	srand((unsigned int)time(NULL));
	int n = 0;
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
		{
			game();

			break;
		}
		case 0:
		{
			printf("�˳�\n");
			break;
		}
		default:
		{
			printf("ѡ�����������ѡ��\n");
			break;
		}
		}
	} while (n);
	return;
}