//#include<iostream>
//using namespace std;
//#include"max.h"
//
//// 函数定义
///*
//	语法：
//	返回值类型 函数名(参数列表) {函数语句}  
//*/
//// 提前告诉编译器函数存在，可以利用函数的声明
//// 声明可以多次，定义只能一次
//void swap(int num1, int num2);
//// 如果不需要返回值，声明的时候写void
//// 当我们做值传递的时候，函数的形参发生改变，并不会影响实参
//
//int add(int num1, int num2)
//{
//	int num = num1 + num2;
//	return num;
//}
//// 函数常见样式
//// 无参无返、有参无返、无参有返、有参有返
//
//// 函数的分文件编写
///*
//	1. 创建后缀名为.h的头文件
//	2. 创建后缀名为.cpp的源文件
//	3. 在头文件中写函数的声明
//	4. 在源文件中写函数的定义
//*/
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = add(10, 20);
//	cout << c << endl;
//	cout << a << endl;
//	cout << b << endl;
//	swap(a, b);
//	cout << a << endl;
//	cout << b << endl;
//	cout << "max(a, b):" << max(a, b) << endl;
//
//	system("pause");
//	return 0;
//}
//
//void swap(int num1, int num2)
//{
//	cout << "before swap" << endl;
//	cout << "num1 = " << num1 << endl;
//	cout << "num2 = " << num2 << endl;
//
//	int tmp = num1;
//	num1 = num2;
//	num2 = tmp;
//
//	cout << "after swap" << endl;
//	cout << "num1 = " << num1 << endl;
//	cout << "num2 = " << num2 << endl;
//}
//// 同名函数可以变变参数
//void swap(int num1, double num2)
//{
//	cout << "before swap" << endl;
//	cout << "num1 = " << num1 << endl;
//	cout << "num2 = " << num2 << endl;
//
//	int tmp = num1;
//	num1 = num2;
//	num2 = tmp;
//
//	cout << "after swap" << endl;
//	cout << "num1 = " << num1 << endl;
//	cout << "num2 = " << num2 << endl;
//}