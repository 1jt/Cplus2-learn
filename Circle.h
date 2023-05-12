#pragma once
#include<iostream>//智能提示：ctrl + J
using namespace std;
#include"Point.h"

//圆类
class Circle
{
public:
	void setR(int r);

	int getR();

	void setCenter(Point center);

	Point getCenter();


private:
	int m_R;

	// 在类中可以让另一个类作为本类中的成员
	Point m_Center;//圆心
};