#include<iostream>
using namespace std;

/*
			对象的初始化和清理2
*/


//静态成员就是在成员变量和成员函数前加上关键字static，称为静态成员
//静态成员分为 :
// 
//	静态成员变量
//		所有对象共享同一份数据
//		在编译阶段分配内存（全局区）
//		类内声明，类外初始化
//	静态成员函数
//		所有对象共享同一个函数
//		静态成员函数只能访问静态成员变量



//	静态成员变量
class Person161
{
public:
//	1. 所有对象共享同一份数据
//	2. 在编译阶段分配内存（全局区）
//	3. 类内声明，类外初始化
	static int m_A; //类内声明

	// 静态成员变量也是有访问权限的
private:
	static int m_B;
};
int Person161::m_A = 100;//类外初始化（这里强调一下，是必须在类外写一下，否则报错，可以不赋初值，默认初值是0）
int Person161::m_B = 200;

static void test01()
{
	cout << "-------------test01()-------------" << endl;
	Person161 p;
	cout << "p.m_A:" << p.m_A << endl;

	// 如果没有类外初始化
	// cout << p.m_A << endl;
	// LNK1120	1 个无法解析的外部命令
	// 一般是链接阶段出现的错误
	// 当去找m_A具体值的时候找不到，但是他觉得这个值已经有了，所以出错了

	Person161 p2;
	p2.m_A = 200;
	cout << "p.m_A:" << p.m_A << endl;//所有对象共享同一份数据	
}
static void test02()
{
	cout << "-------------test02()-------------" << endl;

	// 静态成员变量，不属于某个对象上，所有对象都共享内存
	// 因此静态成员变量有两种访问方式

	// 1. 通过对象进行访问
	Person161 p;
	cout << "p.m_A:" << p.m_A << endl;

	// 2. 通过类名进行访问
	cout << "Person161::m_A:" << Person161::m_A << endl;

	//cout << "Person161::m_B:" << Person161::m_B << endl; // 权限不够，不能访问
}



//	静态成员函数
class Person162
{
public:
	
	static void func()
	{
		m_A = 102;// 静态成员函数可以访问静态成员变量
		//m_B = 200;// 静态成员函数不可以访问非静态成员变量
		// 
		// 静态先加载，非静态未加载，不确定不能调用
		// 静态static成员函数它只属于类本身不属于每一个对象实例，独立存在。非静态成员，仅当实例化对象之后才存在。
		// 静态成员函数产生在前，非静态成员函数产生在后，静态函数无法访问一个不存在的东西。

		// 因为是静态函数，改属性所有对象的属性都会改，所以分不清
		cout << "static void func()的调用" << endl;
	}
	static int m_A;//	静态成员变量
	int m_B;//	非静态成员变量

	// 静态成员变量也是有访问权限的
private:
	static void func2()
	{
		cout << "static void func2()的调用" << endl;
	}
};
int Person162::m_A = 101;

static void test03()
{
	cout << "-------------test03()-------------" << endl;
	// 两种访问方式
	// 1. 通过对象进行访问
	Person162 p;
	cout << "Person162::m_A:" << Person162::m_A << endl;
	p.func();
	cout << "Person162::m_A:" << Person162::m_A << endl;

	// 2. 通过类名进行访问
	Person162::func();

	//Person162::func2();// 权限不够，不能访问
}


int main16()
{
	test01();
	test02();
	test03();

	system("pause");
	return 0;
}