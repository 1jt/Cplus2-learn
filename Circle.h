#pragma once
#include<iostream>//������ʾ��ctrl + J
using namespace std;
#include"Point.h"

//Բ��
class Circle
{
public:
	void setR(int r);

	int getR();

	void setCenter(Point center);

	Point getCenter();


private:
	int m_R;

	// �����п�������һ������Ϊ�����еĳ�Ա
	Point m_Center;//Բ��
};