/*******************************************

		文件名称：Game2048
		文件描述：实现经典手机游戏“2048”
		编译环境：VS2013，VC++6.0
		作者相关：雷小航
		最后修改：2016年8月8日

*******************************************/

#include "stdafx.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>//键盘操作
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
int print();
int PanDuan();
int Add(int );
int Move();//移动，
int MoveUp();
int MoveDown();
int MoveLeft();
int MoveRight();
char * Tookit(int a , int n);//将字符数字转化成字符串
void s_int(); //将整形数组转化成字符数组
int WeiShu(int a);//求的整数的位数

int Map[4][4];
char S_Map[16][5];
int main()
{
	//PlaySound (TEXT("D:\\zzz\\zzd.wav"), NULL, SND_ASYNC | SND_NODEFAULT);

	//PlaySound (TEXT("yisheng.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
	int flg = 1;
	system("COLOR 5F");
	memset(Map,0,sizeof(Map));//初始化
	flg = Add(0);//	
	print();

	while (Move())
	{
		//游戏移动
		fflush(stdin);
		system("cls");//清除屏幕
		
		print();

	}		
	printf("\t\t\t%s\n","Game Over");

	printf("测试一\n");

	printf("哈哈\n");

	return 1;
}

int PanDuan()
{
	//判断是否结束

	for (int k = 0; k < 4 ;k++)
	{
		for (int l = 0 ; l< 4 ; l++)
		{
			if(Map[k][l] == Map[k][l-1]
			|| Map[k][l] == Map[k][l+1]
			|| Map[k][l] == Map[k+1][l]
			|| Map[k][l] == Map[k-1][l]			
						)
				return 1;//表示游戏继续
		}
	}
	return 0;
}

int print()
{
	s_int();//讲数组内容转换成字符串复制到字符数组;
	printf("\n\n\t游戏目标：拼凑出2048\n");
	printf("\t\t┏━━┳━━┳━━┳━━┓\n");
	printf("\t\t┃    ┃    ┃    ┃    ┃\n");
	printf("\t\t┃%4s┃%4s┃%4s┃%4s┃\n",S_Map[0],S_Map[1],S_Map[2],S_Map[3]);
	printf("\t\t┣━━╋━━╋━━╋━━┫\n");
	printf("\t\t┃    ┃    ┃    ┃    ┃\n");
	printf("\t\t┃%4s┃%4s┃%4s┃%4s┃\n",S_Map[4],S_Map[5],S_Map[6],S_Map[7]);
	printf("\t\t┣━━╋━━╋━━╋━━┫\n");
	printf("\t\t┃    ┃    ┃    ┃    ┃\n");
	printf("\t\t┃%4s┃%4s┃%4s┃%4s┃\n",S_Map[8],S_Map[9],S_Map[10],S_Map[11]);
	printf("\t\t┣━━╋━━╋━━╋━━┫\n");
	printf("\t\t┃    ┃    ┃    ┃    ┃\n");
	printf("\t\t┃%4s┃%4s┃%4s┃%4s┃\n",S_Map[12],S_Map[13],S_Map[14],S_Map[15]);
	printf("\t\t┗━━┻━━┻━━┻━━┛\n");
	return 1;
}

int Move()//移动数字
{
	fflush(stdin);//清空缓冲区
	int flg = 1;
	char Key;

	Key = getch();//直接接收不需要等待回车符

	switch (Key)
	{
	case 72 ://上

		flg = MoveUp();
		break;
	case 80://下

		flg = MoveDown();
		break;
	case 75://左
		flg = MoveLeft();
		break;
	case 77://右

		flg = MoveRight();
		break;
	default:
		break;
	}
	return 1;
}


int Add(int dir)
{
	srand((unsigned int )time(NULL));//随机因子
	int row,col;
	int Num = rand();
	int flag = Num % 2;
	if (flag)
		Num = 2;
	else
		Num = 4;
	row = rand() % 4;//随机行
	col = rand() % 4;//随机列

	//上：1    下：2    左：3   右：4
	if (dir == 0)
	{
		Map[row][col] = Num;
	}
	else if (dir == 1)
	{
		if (Map[3][col] == 0)
		{
			Map[3][col] = Num;
		}
		else
		{
			for (int i = 0 ; i < 4 ; i++)
			{
				if (Map[3][i] == 0)
				{
					Map[3][i] = Num;
					break;
				}
			}
		}
	}
	else if (dir == 2)
	{
		if (Map[0][col] == 0)
		{
			Map[0][col] = Num;
		}
		else
		{
			for (int i = 0 ; i < 4 ; i++)
			{
				if (Map[0][i] == 0)
				{
					Map[0][i] = Num;
					break;
				}
			}
		}
	}
	else if (dir == 3)
	{
		if (Map[row][3] == 0)
		{
			Map[row][3] = Num;
		}
		else
		{
			for (int i = 0 ; i < 4 ; i++)
			{
				if (Map[i][3] == 0)
				{
					Map[i][3] = Num;
					break;
				}
			}
		}
		 
	}
	else if (dir == 4)
	{
		if (Map[row][0] == 0)
		{
			Map[row][0] = Num;
		}
		else
		{
			for (int i = 0 ; i < 4 ; i++)
			{
				if (Map[i][0] == 0)
				{
					Map[i][0] = Num;
					break;
				}
			}
		}
		 
	}	
	if (!PanDuan())
	{
		printf("\t\t\t%s\n","Game Over");
		system("pause");
		exit(1);
	}

	return 0;
}

int MoveUp()
{
	int flag = 0;
	int row,col;
	int tep;
	for (col = 0 ; col < 4 ; col++)
	{
		int n = 4;
		while(n--)
		{
			for (row = 0 ; row < 3 ; row++)
			{
				if (Map[row][col] == 0)
				{
					for (tep = row ; tep < 3 ; tep++)
					{
						Map[tep][col]  = Map[tep+1][col];
						Map[tep+1][col] = 0;
						flag = 1;
					}
				}
			}
			for (row = 0 ; row < 3 ; row++)
			{
				if (Map[row][col] == Map[row+1][col])
				{
					Map[row][col] *= 2;
					for (tep = row+1 ; tep < 3 ; tep++)//再次移动
					{
						Map[tep][col]  = Map[tep+1][col];
						Map[tep+1][col] = 0;
						flag = 1;
					}
				}
			}
		}
	}
	if (flag)
		Add(1);
	return 1;
}
int MoveDown()
{
	int flag = 0;
	int row,col;
	int tep;
	for (col = 0 ; col < 4; col++)
	{
		int n = 4;
		while(n--)
		{
			for (row = 3 ; row > 0 ; row--)
			{
				if (Map[row][col] == 0)
				{
					for (tep = row ; tep > 0 ; tep--)
					{
						Map[tep][col]  = Map[tep-1][col];
						Map[tep-1][col] = 0;
						//print();
						flag = 1;
					}
				}
			}
			for (row = 3 ; row > 0 ; row--)
			{
				if (Map[row][col] == Map[row-1][col])
				{
					Map[row][col] *= 2;
					for (tep = row-1 ; tep > 0 ; tep--)//再次移动
					{
						Map[tep][col]  = Map[tep-1][col];
						Map[tep-1][col] = 0;
						flag = 1;
					}
				}
			}
		}
	}
	if (flag)
		Add(2);
	return 1;
}

int MoveLeft()
{
	int flag = 0;
	int row,col;
	int tep;
	for (row = 0 ; row < 4 ; row++)
	{
		int n = 4;
		while(n--)
		{
			for (col = 0 ; col < 3 ; col++)
			{
				if (Map[row][col] == 0)
				{
					for (tep = col ; tep < 3 ; tep++)
					{
						Map[row][tep]  = Map[row][tep+1];
						Map[row][tep+1] = 0;
						flag = 1;
					}
				}
			}
			for (col = 0 ; col < 3 ; col++)
			{
				if (Map[row][col] == Map[row][col+1])
				{
					Map[row][col] *= 2;
					for (tep = col+1 ; tep < 3 ; tep++)//再次移动
					{
						Map[row][tep]  = Map[row][tep+1];
						Map[row][tep+1] = 0;
						flag = 1;
					}
				}
			}
		}
	}
	if (flag)
		Add(3);
	return 1;
	
}
int MoveRight()
{
	
	int flag = 0;
	int row,col;
	int tep;
	for (row = 0 ; row < 4; row++)
	{
		int n = 4;
		while(n--)
		{
			for (col = 3 ; col > 0 ; col--)
			{
				if (Map[row][col] == 0)
				{
					for (tep = col ; tep > 0 ; tep--)
					{
						Map[row][tep]  = Map[row][tep-1];
						Map[row][tep-1] = 0;
						flag = 1;
					}
				}
			}
			for (col = 3 ; col > 0 ; col--)
			{
				if (Map[row][col] == Map[row][col-1])
				{
					Map[row][col] *= 2;
					for (tep = col-1 ; tep > 0 ; tep--)//再次移动
					{
						Map[row][tep]  = Map[row][tep-1];
						Map[row][tep-1] = 0;
						flag = 1;
					}
				}
			}
		}
	}
	if (flag)
		Add(2);
	return 1;
}


void s_int()
{
	char * p =  NULL;
	int index = 0 ;

	int k = 0;

	for (int i = 0 ; i < 4 ; i ++)
	{
		for (int j = 0 ; j < 4 ; j++)
		{
			p = Tookit(Map[i][j],WeiShu(Map[i][j]));
			for (k = 0 ; k < WeiShu(Map[i][j]) ; k++)
			{
				S_Map[index][k] = p[k];
			}
			S_Map[index][k] = '\0';//最后在末尾加0
			index++;
		}
	}
}

int WeiShu(int a)//求的整数的位数
{
	int flg = a / 10;
	if (flg == 0)
	{
		return 1;
	}
	else if ( flg >= 1 && flg <= 9)
	{
		return 2;
	}
	else if (flg >=10 && flg <= 99)
	{
		return 3;
	}
	else if (flg >= 100 && flg <= 999)
	{
		return 4;
	}
	return 5;
}
char * Tookit(int a , int n)
{
	if (n == 1)
	{
		static char p[2] ;

		if (a == 0)
		{
			p[0] = ' ';
			p[1] = '\0';
		}
		else
		{
			p[0] = a + '0';
			p[1] = '\0';
		}
		
		return p;
	}
	if (n == 2)
	{
		int i1[2];
		static char s1[3];
		i1[0] = a / 10;
		s1[0] = i1[0] + '0';

		i1[1] = a % 10;
		s1[1] = i1[1] + '0';
		s1[2] = '\0';

		return s1;
	}
	else if (n == 3)
	{
		int i1[3];
		static char s1[4];
		i1[0] = a / 100;
		s1[0] = i1[0] + '0';

		i1[1] = (a % 100) / 10 ;
		s1[1] = i1[1] + '0';

		i1[2] = a % 10;
		s1[2] = i1[2] + '0';		

		s1[3] = '\0';

		return s1;
	}
	else
	{
		int i[4];
		static char s[5];

		i[0] = a / 1000;
		s[0] = i[0] + '0';

		i[1] = (a % 1000) / 100;
		s[1] = i[1] + '0';

		i[2] = (a % 100) / 10;
		s[2] = i[2] + '0';

		i[3] = a % 10 ; 
		s[3] = i[3] + '0';

		s[4] = '\0';
		return s;
	}
}
