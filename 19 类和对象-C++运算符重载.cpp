#include<iostream>
using namespace std;

// operator 是 C++ 的一个关键字，它和运算符（如 =）一起使用，表示一个运算符重载函数，
// 在理解时可将 operator 和待重载的运算符整体（如 operator=）视为一个函数名。




// 左移运算符重载
// 作用：可以输出自定义的数据类型

class Person192
{
	// 配合友元技术访问私有变量
	friend ostream& operator<<(ostream& out, Person192& p);
public:

	Person192(int a,int b)
	{
		m_A = a;
		m_B = b;
	}

	// 利用成员函数重载，左移运算符		p.operator<<(cout)	简化版本 p << cout
	// cout本质是一个对象
	// cout是输出流对象（ostream），而且全局只能有一个，所以得用引用的方式传进去
	// 通常不会利用成员函数重载<<运算符，因为无法实现cout在左侧
	void operator<<(ostream& cout)
	{
		cout << "利用成员函数重载左移运算符" << m_A << endl;
		cout << "利用成员函数重载左移运算符" << m_B << endl;
	}

private:
	int m_A;
	int m_B;
};

// 所以只能利用全局函数重载左移运算符
// cout是输出流对象（ostream），而且全局只能有一个，所以得用引用的方式传进去
ostream& operator<<(ostream& out, Person192& p)// 本质	operator<<(cout, p)	简化	cout << p
{
	// 引用本质就是起别名，所以这儿写成out或者cout无所谓，等价的（比如中间用的out，返回用的cout，反正全局只有一个）
	out << "利用全局函数重载左移运算符" << p.m_A << endl;
	out << "利用全局函数重载左移运算符" << p.m_B << endl;

	return cout;
}

static void test02()
{
	cout << "-------------test02()-------------" << endl;
	Person192 p(10, 20);

	//cout << p << endl;// E0349	没有与这些操作数匹配的 "<<" 运算符	
	p << cout;// 成员函数重载，无法实现cout在左侧

	cout << p ;// 全局函数重载
	//cout << p << endl;//会报错，因为是返回值类型是void，想实现得用链式编程思想
	cout << p << endl; // 返回值变为ostream&就好啦

}



int main()
{
	test02();
	system("pause");
	return 0;
}