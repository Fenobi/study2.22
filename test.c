#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu()
{
	printf("***************************************\n");
	printf("***************  1.开始   *************\n");
	printf("***************  0.结束   *************\n");
	printf("***************************************\n");
	
}
void game()
{
	char board[ROW][COL];

	//初始化棋盘
	Initboard(board, ROW, COL);
	system("cls");

	//打印棋盘
	DisplayBoard(board, ROW, COL);

	char x = 0;//接收游戏状态
	while (1)
	{
		printf("                 另外：\n");
		printf("         由于电脑下的棋子是随机的\n");
		printf("所以游戏的主要目的是让电脑获胜或者平局\n");
		printf("\n\n");
		//玩家输入
		PlayerMove(board, ROW, COL);
		system("cls");
		DisplayBoard(board, ROW, COL);

		//判断玩家胜利
		x = IsWin(board, ROW, COL);
		if (x != 'J')
		{
			break;
		}

		//电脑输入
		ComputerMove(board, ROW, COL);
		system("cls");
		DisplayBoard(board, ROW, COL);

		//判断电脑胜利
		x = IsWin(board, ROW, COL);
		if (x != 'J')
		{
			break;
		}
	}
	//判断其他状态
		if(x=='*')
		{
			printf("游戏结束，玩家获胜\n");
			printf("没赢过？？？？？？？？？？？\n");
		}
		else if(x=='#')
		{
			printf("游戏结束，电脑获胜\n");
		}
		else
		{
			printf("游戏结束，平局\n");
		}
}


int main()
{
	srand((unsigned int)time(NULL));
	int n = 0;
	do
	{
		menu();
		printf("请选择：>");
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
			printf("退出\n");
			break;
		}
		default:
		{
			printf("选择错误，请重新选择\n");
			break;
		}
		}
	} while (n);
	return;
}