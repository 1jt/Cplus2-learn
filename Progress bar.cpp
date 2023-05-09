#include <tchar.h> 
#include<graphics.h>				     //图形库 
#include<stdio.h>					  	 //标准输入输出
#include<iostream>
using namespace std;
#define WIDTH 300						 //进度条宽
#define	HEIGHT	30						 //进度条高

int mainPb() {
	int all_block_num = 1000;

	//随机数种子
	srand((unsigned int)time(NULL));
	int random = rand();
	// 进度条+随机数
	for (int i = 0; i < all_block_num; i++)
	{
		if (i < all_block_num - 1)
		{
			printf("\r读取中[%.2lf%%]:", i * 100.0 / (all_block_num - 1));
		}
		else
		{
			printf("\r读取完成[%.2lf%%]:", i * 100.0 / (all_block_num - 1));
		}
		int show_num = i * 20 / all_block_num;
		for (int j = 1; j <= show_num; j++)
		{
			std::cout << "█";
			Sleep(1);
		}
		srand((unsigned int)time(NULL));
		random = rand();
		cout << random << "\r";
	}
	system("pause");
flag:
	HWND hwnd = initgraph(WIDTH, HEIGHT);//指定窗口句柄 进度条所在的窗口  
	RECT rect;                			 //矩形框对象 包含标题栏在内的整个窗口

	//typedef struct tagRECT
	//{
	//	LONG    left;		//矩形框左边界
	//	LONG    top;		//矩形框顶部边界
	//	LONG    right;		//矩形框右边界
	//	LONG    bottom;		//矩形框底部边界
	//} RECT, * PRECT, NEAR* NPRECT, FAR* LPRECT;


	GetWindowRect(hwnd, &rect);//获取指定窗口包含标题栏在内的矩形框参数
	SetWindowPos(hwnd, HWND_TOPMOST, 700, 647, rect.right - rect.left, rect.bottom - rect.top, 0);
	//HWND_TOPMOST 表示将窗口（即使未被激活）保持顶级位置。
	// 700, 647    表示将该窗口左上角放到屏幕的（700，647）
	//rect.right - rect.left 为窗口宽（包含标题栏）； rect.bottom - rect.top 为窗口高（包含标题栏）

	setfillcolor(YELLOW);				 //设置填充颜色为 青色 
	solidrectangle(0, 0, WIDTH, HEIGHT); //画矩形

	setfillcolor(RED);				 //设置填充颜色为 青色 
	int i = 0;					         //定义动态矩形的宽
	while (i < WIDTH + 1)
	{
		solidrectangle(0, 0, i, HEIGHT); //绘画动态矩形
		Sleep(10);					 //1000ms=1s    进度条从0到100%约 1*300/60=5min
		i++;							 //动态矩形的宽递增
	}

	setbkmode(TRANSPARENT);				 //设置文字背景透明 输出字符串
	outtextxy(70, 7, _T("是时候去做点别的事情了！"));

	if (getchar() == '\n')goto flag;		 //按回车键，重新来一遍

	return 0;
}

