#pragma once
#include<iostream>//������ʾ��ctrl + J
using namespace std;

//����
class Point
{
public:
	void setX(int x);

	int getX();

	void setY(int y);

	int getY();

private:
	int m_X;
	int m_Y;
};