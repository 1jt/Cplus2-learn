#include<iostream>
#include<string>

using namespace std;

/*
			运算符重载
*/


// 对于内置数据类型，编译器知道如何进行运算，但是自定义的数据类型呢？
// 对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
// 对于内置的不可改变
// 不要滥用运算符重载

// operator 是 C++ 的一个关键字，它和运算符（如 =）一起使用，表示一个运算符重载函数，
// 在理解时可将 operator 和待重载的运算符整体（如 operator=）视为一个函数名。

// 两种方式：通过成员函数重载	通过全局函数重载



// 加号运算符重载
// 作用：实现两个自定义数据类型相加的运算
// p1 operator+ p2
class Person191
{
public:
	// 1. 通过成员函数重载
	Person191 operator+(Person191& p)
	{
		Person191 temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}
	int m_A;
	int m_B;
};
// 2. 通过全局函数重载
//Person191 operator+(Person191& p1, Person191& p2)
//{
//	Person191 temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}

// 运算符重载，也可以发生函数重载
Person191 operator+(Person191& p1, int num)
{
	Person191 temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}

static void test01()
{
	cout << "-------------test01()-------------" << endl;
	Person191 p1;
	p1.m_A = 10;
	p1.m_B = 11;
	Person191 p2;
	p2.m_A = 12;
	p2.m_B = 13;

	Person191 p3 = p1 + p2;
	cout << "p3.m_A:" << p3.m_A << endl;
	cout << "p3.m_B:" << p3.m_B << endl;
	// 成员函数重载本质调用
	//Person191 p3 = p1.operator+(p2);
	// 成员函数重载本质调用
	//Person191 p3 = operator+(p1, p2);

	// 运算符重载，也可以发生函数重载
	p3 = p3 + 15;
	cout << "p3.m_A:" << p3.m_A << endl;
	cout << "p3.m_B:" << p3.m_B << endl;

}



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



// 递增运算符重载
// 作用：通过重载递增运算符，实现自己的整型数据
class MyInteger19
{
	friend ostream& operator<<(ostream& out, MyInteger19 myint);
public:
	MyInteger19()
	{
		m_Num = 0;
	}
	// 重载前置++运算符
	MyInteger19& operator++()// 不需要传参数
		// 返回值是引用类型，是为了链式编程思想，可以一直对一个数据进行递增	e.g.:++(++a)	(都怪拷贝构造)
	{
		// 先进行++运算
		m_Num++;
		// 再将自身做一个返回
		return *this;
	}

	// 重载后置++运算符
	// int代表占位参数，可以用于区分前置和后置递增
	MyInteger19 operator++(int)
		// 返回值不是引用类型了！！因为返回的temp只是一个临时变量，结束后就被释放掉了，再引用就会出错
		// 所以不可以链式编程了哦（原生的也不可以）
	{
		// 先记录当时结果
		MyInteger19 temp = *this;
		// 再递增
		m_Num++;
		// 最后将记录结果返回
		return temp;
	}

private:
	int m_Num;
};
// 为递增运算符重载一下
ostream& operator<<(ostream& out, MyInteger19 myint)
{
	cout << myint.m_Num << endl;
	return cout;
}
static void test03()
{
	cout << "-------------test03()-------------" << endl;
	MyInteger19 myint;
	cout << "myint.m_int:" << myint << endl;
	cout << "++myint:" << ++myint << endl;
	cout << "++(++myint):" << ++(++myint) << endl;
	cout << "myint++:" << myint++ << endl;
	cout << "m_int:" << myint << endl;
	//cout << "(myint++)++:" << (myint++)++ << endl;// 后置递增不可以链式运算(本来原生的也不可以)
}



//	赋值运算符重载
//	c++编译器至少给一个类添加4个函数
//		1.默认构造函数(无参，函数体为空)
//		2.默认析构函数(无参，函数体为空)
//		3.默认拷贝构造函数，对属性进行值拷贝
//		4.赋值运算符 operator=, 对属性进行值拷贝
// 
//	如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题
class Person193
{
public:
	Person193(int age)
	{
		m_Age = new int(age);
	}
	~Person193()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}

	// 重载	赋值运算符
	Person193& operator=(Person193 &p)
	{
		// 编译器提供的是浅拷贝
		// m_Age = p.m_Age;

		// 应该先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
		if (m_Age!=NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		// 深拷贝
		m_Age = new int(*p.m_Age);

		// 也可以直接
		//*m_Age = *p.m_Age;
		// 直接改堆区数据，试了这里没问题

		// 返回对象自身
		return *this;
	}

	int* m_Age;
};
static void test04()
{
	cout << "-------------test04()-------------" << endl;
	Person193 p1(18);
	cout << "p1的年龄为:" << *p1.m_Age << endl;
	Person193 p2(20);
	cout << "p2的年龄为:" << *p2.m_Age << endl;

	p1 = p2;// 如果不重载的话，会做一个简简单单的值拷贝，如果直接释放的话会由于浅拷贝而报错（重复释放）
	cout << "p1的年龄为:" << *p1.m_Age << endl;
	cout << "p2的年龄为:" << *p2.m_Age << endl;

	int a = 10;
	int b = 20;
	int c = 30;
	c = b = a;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;//都等于10（即a）

	Person193 p3(30);
	*p1.m_Age = 18;
	p3 = p2 = p1;
	cout << "p1的年龄为:" << *p1.m_Age << endl;
	cout << "p2的年龄为:" << *p2.m_Age << endl;
	cout << "p3的年龄为:" << *p3.m_Age << endl;
}



// 关系运算符重载
// 作用：实现两个自定义数据类型比较的运算
class Person194
{
public:
	Person194(string m_Name,int m_Age)
	{
		this->m_Name = m_Name;
		this->m_Age = m_Age;
	}
	
	//	重载 == 号
	bool operator==(Person194& p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return  true;
		}
		else
			return false;
	}
	//	重载 != 号
	bool operator!=(Person194& p)
	{
		if (this->m_Name != p.m_Name || this->m_Age != p.m_Age)
		{
			return  true;
		}
		else
			return false;
	}


	string m_Name;
	int m_Age;
};
static void test05()
{
	cout << "-------------test05()-------------" << endl;
	Person194 p1("ljt", 22);
	Person194 p2("ljtt", 22);
	if (p1 == p2)
	{
		cout << "p1和p2是相等的" << endl;
	}
	else
	{
		cout << "p1和p2是不相等的" << endl;
	}
	if (p1 != p2)
	{
		cout << "p1和p2是不相等的" << endl;
	}
	else
	{
		cout << "p1和p2是相等的" << endl;
	}
}



// 函数调用运算符重载
//	函数调用运算符()也可以重载
//	由于重载后使用的方式非常像函数的调用，因此称为仿函数
//	仿函数没有固定写法，非常灵活

//	打印输出类
class MyPrint19
{
public:
	// 重载函数调用运算符
	void operator()(string test)
	{
		cout << "test为：" << test << endl;
	}
};
//	仿函数没有固定写法，非常灵活
//	加法类
class MyAdd19
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};

static void test06()
{
	cout << "-------------test06()-------------" << endl;
	MyPrint19 myprint;
	myprint("hello world");// 由于使用起来非常类似于函数调用，因此称为仿函数
	MyAdd19 myadd;
	int ret = myadd(100, 101);
	cout << "ret=" << ret << endl;

	// 匿名函数对象
	cout << MyAdd19()(102, 103) << endl;
}


int main19()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	system("pause");
	return 0;
}