#include <tchar.h> 
#include<graphics.h>				     //ͼ�ο� 
#include<stdio.h>					  	 //��׼�������

#define WIDTH 300						 //��������
#define	HEIGHT	30						 //��������

int main0() {
flag:
	HWND hwnd = initgraph(WIDTH, HEIGHT);//ָ�����ھ�� ���������ڵĴ���  
	RECT rect;                			 //���ο���� �������������ڵ���������

	//typedef struct tagRECT
	//{
	//	LONG    left;		//���ο���߽�
	//	LONG    top;		//���ο򶥲��߽�
	//	LONG    right;		//���ο��ұ߽�
	//	LONG    bottom;		//���ο�ײ��߽�
	//} RECT, * PRECT, NEAR* NPRECT, FAR* LPRECT;


	GetWindowRect(hwnd, &rect);//��ȡָ�����ڰ������������ڵľ��ο����
	SetWindowPos(hwnd, HWND_TOPMOST, 700, 647, rect.right - rect.left, rect.bottom - rect.top, 0);
	//HWND_TOPMOST ��ʾ�����ڣ���ʹδ��������ֶ���λ�á�
	// 700, 647    ��ʾ���ô������ϽǷŵ���Ļ�ģ�700��647��
	//rect.right - rect.left Ϊ���ڿ��������������� rect.bottom - rect.top Ϊ���ڸߣ�������������

	setfillcolor(YELLOW);				 //���������ɫΪ ��ɫ 
	solidrectangle(0, 0, WIDTH, HEIGHT); //������

	setfillcolor(RED);				 //���������ɫΪ ��ɫ 
	int i = 0;					         //���嶯̬���εĿ�
	while (i < WIDTH + 1)
	{
		solidrectangle(0, 0, i, HEIGHT); //�滭��̬����
		Sleep(10);					 //1000ms=1s    ��������0��100%Լ 1*300/60=5min
		i++;							 //��̬���εĿ����
	}

	setbkmode(TRANSPARENT);				 //�������ֱ���͸�� ����ַ���
	outtextxy(70, 7, _T("��ʱ��ȥ�����������ˣ�"));

	if (getchar() == '\n')goto flag;		 //���س�����������һ��
	return 0;
}

