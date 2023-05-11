#include<iostream>
using namespace std;

// 作用：给变量起别名
// 语法：数据类型 &别名 = 原名
// （类似于不带*的指针）
// 官方推荐

// 引用做函数参数
	// 函数传参时，可以利用引用的技术让形参修饰实参
	// 优点：可以简化指针修改实参
	// 1. 值传递	2. 地址传递
	// 3. 引用传递	形参会修饰实参
void swap03(int &aa,int &bb)// 
{
	int temp = aa;
	aa = bb;
	bb = temp;
}


// 引用做函数返回值
	// 1. 注意：不要返回局部变量
int&  test01()
{
	int a = 10;//局部变量存放在四区中的 栈区
	return a;
}
	// 2. 函数的调用可以作为左值
int& test02()
{
	static int a = 10;//静态变量，存放在全局区，全局区上的数据在程序结束后系统释放
	// 可以理解为a是10的别名
	return a;
}


// 打印数据函数
void showValue(const int &val)
{
	//val = 1000; // 单纯打印，不要随便修改
	cout << "val=" << val << endl;
}

int main12()
{
	int a = 10;
	cout << "修改前：" << a << endl;
	int& b = a;
	b = 20;
	cout << "修改后：" << a << endl;

	// 注意事项
	// 1. 引用必须初始化
	// int& c; //是错误的
	// 2. 引用在初始化后，不可以改变
	int c = 30;
	b = c; //赋值操作，而不是更改引用
	cout << a << endl;


	// 引用做函数参数
	// 函数传参时，可以利用引用的技术让形参修饰实参
	// 优点：可以简化指针修改实参
	// 1. 值传递	2. 地址传递
	// 3. 引用传递	形参会修饰实参
	a = 10;
	c = 20;
	cout << "a:" << a << endl;
	cout << "c:" << c << endl;
	swap03(a, c);
	cout << "a:" << a << endl;
	cout << "c:" << c << endl;


	// 引用做函数返回值
	// 1. 注意：不要返回局部变量
	int& ref = test01();
	cout << "ref:" << ref << endl;//第一次编译器可能会做保留
	cout << "ref:" << ref << endl;
	// 2. 函数的调用可以作为左值
	int& ref2 = test02();
	cout << "ref2:" << ref2 << endl;
	cout << "ref2:" << ref2 << endl;
	test02() = 1000;//如果函数的返回值时引用，这个函数调用可以作为左值
	// 个人理解：可以“理解”成：int& a=test02(); a与test02()就是同一个东西了，一个变另一个也变， 可以通过对函数名"test02()"赋值，改变a的值
	cout << "ref2:" << ref2 << endl;
	cout << "ref2:" << ref2 << endl;
	cout << "ref2:" << ref2 << endl;


	// 引用的本质
	// 本质就是一个指针常量（固定指向某个空间）
	// 即 int* const ref = &a;
	// 指向不可改，也说明为什么引用不可更改
	// 直接用ref，相当于编译器自动帮我们转为（解引用）为 *ref


	// 常量引用
	
	//int& ref3 = 10;// 引用必须引到一块合法的内存空间
	const int& ref3 = 10;// 加上const之后，编译器将代码修改为 int temp = 10; int & ref3 = temp;
	// 相当于没有原名，现在只能用别名去操作它了
	//ref3 = 20;// 加入const之后变为只读，不可以修改 
	
	// 主要用来修饰形参，防止误操作
	// 在函数形参列表中，可以加const修饰形参，防止形参改变实参
	a = 100;
	showValue(a);

	system("pause");
	return 0;
}