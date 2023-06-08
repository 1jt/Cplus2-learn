#include<iostream>
using namespace std;


//	1. 函数对象概念
//	概念:
//		·重载函数调用操作符的类，其对象常称为函数对象
//		·函数对象使用重载的()时，行为类似函数调用，也叫仿函数.
//	本质 :
//		·函数对象(仿函数)是一个类，不是一个函数



//	2. 函数对象使用
//	特点 :
//		·函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
//		·函数对象超出普通函数的概念，函数对象可以有自己的状态
//		·函数对象可以作为参数传递

//	1. 函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
class MyAdd361
{
public:
	int operator()(int v1,int v2)
	{
		return v1 + v2;
	}
};
//	2. 函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint361
{
public:
	MyPrint361()
	{
		this->count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		this->count++;
	}
	int count;// 内部状态记录调用字次数
};
//	3. 函数对象可以作为参数传递
void doPrint(MyPrint361& mp, string test)
{
	mp(test);
}

static void test01()
{
	cout << "-------------test01()-------------" << endl;
	MyAdd361 myadd;
	cout << myadd(10, 10) << endl;
	MyPrint361 myprint;
	myprint("ljt");
	myprint("ljt");
	myprint("ljt");
	myprint("ljt");
	cout << "调用次数：" << myprint.count << endl;
	doPrint(myprint, "hello world");
}

int main36()
{
	test01();
	system("pause");
	return 0;
}