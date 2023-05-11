#include<iostream>
using namespace std;

// 全局变量
unsigned int g_a = 10;
unsigned int g_b = 10;

// const修饰的全局变量（全局常量）
const unsigned int c_g_a = 10;
const unsigned int c_g_b = 10;

// 栈区开辟的数据由编译器自动释放
unsigned int* func()
{
	unsigned int a = 10;//局部变量 存放在栈区，栈区的数据在函数执行完后自动释放
	return &a;// 返回局部变量的地址
}
unsigned int* func(unsigned int b)//形参数据也会放在栈区，形参也是局部变量
{
	b = 100;
	unsigned int a = 10;//局部变量 存放在栈区，栈区的数据在函数执行完后自动释放
	return &b;// 返回局部变量的地址
}

// 堆区数据由管理员开辟与释放
unsigned int* func2()
{
	// 利用new关键字	可以将数据开辟到堆区
	unsigned int* p = new unsigned int(10);
	return p;
}

// 1. new的基本用法
unsigned int* func3()
{
	// 在堆区创建整型数据
	// new返回的是该数据类型的指针
	unsigned int* p = new unsigned int(10);
	return p;
}
void test01()
{
	unsigned int* p = func3();
	cout << "func3():" << *p << endl;
	cout << "func3():" << *p << endl;
	cout << "func3():" << *p << endl;
	// 堆区的数据，由程序员管理开辟，程序员管理释放
	// 如果想释放堆区数据，利用关键词delete
	delete p;
	//cout << "func3():" << *p << endl;//内存已经被释放，再次访问就是非法操作，会报错（起码会有警告）
}

void test02()
{
	// 创建10整型数据的数组，在堆区
	int* arr = new int[10]; //10代表数组有10个元素
	for (size_t i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
		cout << "arr[i]:" << arr[i] << endl;
	}
	// 释放堆区数组
	// 释放数组的时候，要加[]才可以
	delete[] arr;


}

int main()
{
	string s = "ljt";
	string seed = "ABCDE";
	for (size_t i = 0; i < 5; i++)
	cout << (s += seed[i]) <<endl;
	/*
	C++程序在执行时，将内存大方向划分为4个区域
	1. 代码区：存放函数体的二进制代码，由操作系统进行管理
	2. 全局区：存放全局变量和静态变量以及常量
	3. 栈区：由编译器自动分配释放，存放函数的参数值，局部变量等
	4. 堆区：由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收

	不同区域存放的数据，赋予不同的生命周期，给我们更大的灵活编程
	*/

	/*
	1.1 程序运行前
	在程序编译后，生成了exe可执行程序，未执行该程序前分为两个区域
	代码区：
		存放CPU执行的机器指令
		代码区是 共享 的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可
		代码区是 只读 的，使其只读的原因是防止程序意外地修改了它的指令
	全局区
		全局变量和静态变量存放在此
		全局区还包含了常量区，字符串常量和其它常量也存放在此
		该区域的数据在程序结束后由操作系统释放
	*/

	// 全局区
	// 全局变量、静态变量、常量

	// 创建普通局部变量
	unsigned int a = 10;
	unsigned int b = 10;

	cout << "局部变量a的地址为：" << &a << endl;
	cout << "局部变量b的地址为：" << &b << endl;

	cout << "全局变量g_a的地址为：" << &g_a << endl;
	cout << "全局变量g_b的地址为：" << &g_b << endl;
	// 会发现不在一个区域里

	// 静态变量，在普通变量前面加static，属于静态变量
	static unsigned int s_a = 10;
	static unsigned int s_b = 10;
	cout << "静态变量s_a的地址为：" << &s_a << endl;
	cout << "静态变量s_b的地址为：" << &s_b << endl;
	// 全局和静态离得很近

	// 常量
	// 字符串常量
	cout << "字符串常量的地址为：" << &"HelloWorld" << endl;
	// 全局、静态和常量离得不远

	//const修饰的全局变量，const修饰的局部变量
	cout << "全局常量c_g_a的地址为：" << (unsigned int)&c_g_a << endl;
	cout << "全局常量c_g_b的地址为：" << (unsigned int)&c_g_b << endl;
	//和上面离得不远

	const unsigned int c_l_a = 10;
	const unsigned int c_l_b = 10;
	cout << "局部常量c_l_a的地址为：" << (unsigned int)&c_l_a << endl;
	cout << "局部常量c_l_b的地址为：" << (unsigned int)&c_l_b << endl;
	// 局部不在全局区


	/*
	1.2 程序运行后
	栈区：
		由编译器自动分配释放，存放函数的参数值，局部变量等
		注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放
	*/
	unsigned int* p = func();
	cout << *p << endl;// 第一次可以打印正确的数字，是因为编译器做了保留
	cout << *p << endl;// 第二次这个数据就不保留了（虽然有时候也保留）

	p = func(1);
	cout << *p << endl;// 
	cout << *p << endl;// 

	/*
	1.2 程序运行后
	堆区：
		由程序员分配释放，若程式员不释放，程序结束时由操作系统回收
		在C++中主要利用new在堆区开辟内存
		释放利用操作符 delete
	*/
	unsigned int* p2 = func2();
	cout << "堆区" << *p2 << endl;
	cout << "堆区" << *p2 << endl;

	// 1. new基本语法
	test01();
	// 2. 在堆区利用new开辟数组
	test02();

	system("pause");
	return 0;
}