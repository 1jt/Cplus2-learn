#include<iostream>
using namespace std;

// 作用：给变量起别名
// 语法：数据类型 &别名 = 原名
// （类似于不带*的指针）

int main()
{
	int a = 10;
	cout << "修改前：" << a << endl;
	int& b = a;
	b = 20;
	cout << "修改后：" << a << endl;

	// 注意事项
	// 1. 引用必须初始化
	// 2. 引用在初始化后，不可以改变

	system("pause");
	return 0;
}