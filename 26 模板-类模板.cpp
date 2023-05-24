#include<iostream>
using namespace std;
// 第一种解决方式，直接包含源文件
//#include"Person267.cpp"

// 第二种解决方式，将.h和.cpp中的内容写到一起，将后缀改为.hpp（一看就知道是类模板）
#include"Person267.hpp"
#include"MyArray.hpp"

//类模板

// 类模板作用 :
//	建立一个通用类，类中的成员、数据类型可以不具体制定，用用一个虚拟的类型来代表
//
// 语法 :
//	template<typename T>
//	类
//
// 解释 :
//	template --- 声明创建模板
//	typename --- 表面其后面的符号是一种数据类型，可以用class代替
//		T	 --- 通用的数据类型，名称可以替换，通常为大写字母

template<class NameType,class AgeType>
class Person261
{
public:
	Person261(NameType name, AgeType age)
	{
		m_Name = name;
		m_Age = age;
	}
	void showPerson()
	{
		cout << "name:" << m_Name << endl;
		cout << "age:" << m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;

};
static	void test01()
{
	cout << "-------------test01()-------------" << endl;
	Person261<string, int> p1("孙悟空", 99);
	p1.showPerson();
}



// 类模板与函数模板区别
//	类模板与函数模板区别主要有两点
//		1. 类模板没有自动类型推导的使用方式
//		2. 类模板在模板参数列表中可以有默认参数
template<class NameType, class AgeType = int>
class Person262
{
public:
	Person262(NameType name, AgeType age)
	{
		m_Name = name;
		m_Age = age;
	}
	void showPerson()
	{
		cout << "name:" << m_Name << endl;
		cout << "age:" << m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};
static	void test02()
{
	cout << "-------------test02()-------------" << endl;

	//	1. 类模板没有自动类型推导的使用方式
	//Person262 p1("孙悟空", 99); // 报错
	Person262<string, int> p1("孙悟空", 1000);// 只能用显示指定类型
	p1.showPerson();

	//	2. 类模板在模板参数列表中可以有默认参数
	Person262<string> p2("猪八戒", 999);// 只能用显示指定类型
	p2.showPerson();
}



// 类模板中成员函数创建时机

// 类模板中成员函数和普通类中成员函数创建时机是有区别的
//	1. 普通类中的成员函数一开始就可以创建
//	2. 类模板中的成员函数在调用时才创建
// 在调用阶段才创建是为了保证模板的通用性
class Person263
{
public:
	void showPerson1()
	{
		cout << "Person263 show"<< endl;
	}
};
class Person264
{
public:
	void showPerson2()
	{
		cout << "Person264 show" << endl;
	}
};
template<class T>
class MyClass261
{
public:
	T obj;

	// 类模板中的成员函数
	// 只要不调用就不会创建
	void func1()
	{
		obj.showPerson1();
	}
	void func2()
	{
		obj.showPerson2();
	}
};
static	void test03()
{
	cout << "-------------test03()-------------" << endl;
	MyClass261<Person263>m1;
	m1.func1();
	//m1.func2();// 报错
	MyClass261<Person264>m2;
	m2.func2();
}



// 类模板对象做函数参数

// 学习目标:
// ·类模板实例化出的对象，向函数传参的方式

// 共有三种传入方式
//	1. 指定传入的类型	--- 直接显示对象的数据类型
//	2. 参数模板化		--- 将对象中的参数变为模板进行传递
//	3. 整个类模板化		--- 将这个对象类型 模板化进行传递
// 第一个最常用
// 二三有点像函数模板配合类模板
template<class T1,class T2>
class Person265
{
public:
	Person265(T1 name, T2 age)
	{
		m_Name = name;
		m_Age = age;
	}
	void showPerson()
	{
		cout << "name:" << m_Name << endl;
		cout << "age:" << m_Age << endl;
	}
	T1 m_Name;
	T2 m_Age;
};
//	1. 指定传入的类型	--- 直接显示对象的数据类型
void printPerson265(Person265<string, int>& p)
{
	p.showPerson();
}
//	2. 参数模板化		--- 将对象中的参数变为模板进行传递
template<class T1, class T2>
void printPerson265_2(Person265<T1, T2>& p)
{
	p.showPerson();
	cout << "T1的类型为:" << typeid(T1).name() << endl;
	cout << "T2的类型为:" << typeid(T2).name() << endl;
}
//	3. 整个类模板化		--- 将这个对象类型 模板化进行传递
template<class T>
void printPerson265_3(T &p)
{
	p.showPerson();
	cout << "T的类型为:" << typeid(T).name() << endl;
}
static	void test04()
{
	cout << "-------------test04()-------------" << endl;
	Person265<string, int> p1("孙悟空", 100);
	printPerson265(p1);

	//	2. 参数模板化		--- 将对象中的参数变为模板进行传递
	Person265<string, int> p2("猪八戒", 99);
	printPerson265_2(p2);

	//	3. 整个类模板化		--- 将这个对象类型 模板化进行传递
	Person265<string, int> p3("唐僧", 18);
	printPerson265_3(p3);
}



// 类模板与继承

// 当类模板碰到继承时，需要注意一下几点:
//	1. 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
//  2. 如果不指定，编译器无法给子类分配内存
//	3. 如果想灵活指定出父类中T的类型，子类也需变为类模板
template<class T>
class Base261
{
	T m;
};
//	1. 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
//  2. 如果不指定，编译器无法给子类分配内存
//class Son261 :public Base261// 错误，必须知道父类中的T类型，才能继承给子类
class Son261 :public Base261<int> 
{

};
//	3. 如果想灵活指定出父类中T的类型，子类也需变为类模板
template<class T1,class T2>
class Son262 :public Base261<T2>
{
public:
	Son262()
	{
		cout << "T1的类型为:" << typeid(T1).name() << endl;
		cout << "T2的类型为:" << typeid(T2).name() << endl;
	}
	T1 obj;
};
static void test05()
{
	cout << "-------------test05()-------------" << endl;
	Son261 s1;
	Son262<int, char>s2;
}


// 类模板成员函数类外实现
// 
// 类模板中成员函数类外实现时，需要加上模板参数列表
template<class T1, class T2>
class Person266
{
public:
	Person266(T1 name, T2 age);
	void showPerson();
	
	T1 m_Name;
	T2 m_Age;
};

// 构造函数的类外实现
template<class T1, class T2>
Person266<T1, T2>::Person266(T1 name, T2 age)
//第一组T1, T2是为了告诉编译器现在是模板的类外实现
{
	m_Name = name;
	m_Age = age;
}
// 成员函数的类外实现
template<class T1, class T2>
void Person266<T1, T2>::showPerson()
{
	cout << "name:" << m_Name << endl;
	cout << "age:" << m_Age << endl;
}
static void test06()
{
	cout << "-------------test06()-------------" << endl;
	Person266<string, int>p1("Tom", 10);
	p1.showPerson();
}



// 类模板分文件编写

// 学习目标:
// ·掌握类模板成员函数分文件编写产生的问题以及解决方式

// 问题 :
// ·类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
// 解决:
//	解决方式1: 直接包含.cpp源文件
//	解决方式2 : 将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制

//template<class T1, class T2>
//class Person267
//{
//public:
//	Person267(T1 name, T2 age);
//	void showPerson();
//
//	T1 m_Name;
//	T2 m_Age;
//};

//// 构造函数的类外实现
//template<class T1, class T2>
//Person267<T1, T2>::Person267(T1 name, T2 age)
////第一组T1, T2是为了告诉编译器现在是模板的类外实现
//{
//	m_Name = name;
//	m_Age = age;
//}
//// 成员函数的类外实现
//template<class T1, class T2>
//void Person267<T1, T2>::showPerson()
//{
//	cout << "name:" << m_Name << endl;
//	cout << "age:" << m_Age << endl;
//}
static void test07()
{
	cout << "-------------test07()-------------" << endl;

	// 第一种解决方式，直接包含源文件
	//#include"Person267.h"会出错，因为类模板中的成员函数一开始不会创建，当包含Person267.h时，编译器不会乖乖生成Person267()和showPerson()函数
	//而Person267.cpp文件编译器也没见过，所以会出现两个外部解析命令出错
	//#include"Person267.cpp"//头文件包含成这个就不会报错，因为Person267.cpp中也#include"Person267.h"，相当于编译器看到了所有的内容，编译自然成功

	// 第二种解决方式，将.h和.cpp中的内容写到一起，将后缀改为.hpp（一看就知道是类模板）

	Person267<string, int>p1("Jerry", 101);
	p1.showPerson();
}



// 类模板与友元

// 学习目标:
// ·掌握类模板配合友元函数的类内和类外实现
// 
//	1. 全局函数类内实现 - 直接在类内声明友元即可
//	2. 全局函数类外实现 - 需要提前让编译器知道全局函数的存在
//总结：谁类外实现捶死谁！


// 通过全局函数 打印Person的信息

//	2. 全局函数类外实现 - 需要提前让编译器知道全局函数的存在
// （全局，所以不要瞎加作用域）

template<class T1, class T2>// Person268是个类模板
class Person268;// 还得让函数知道Person268的存在
template<class T1, class T2>
void printPerson268_2(Person268<T1, T2> &p)// 还得让函数知道Person268的存在
{
	cout << "类外实现" << endl;
	cout << "name:" << p.m_Name << endl;
	cout << "age:" << p.m_Age << endl;
}

template<class T1, class T2>
class Person268
{
	//	1. 全局函数类内实现 - 直接在类内声明友元即可
	friend void printPerson268(Person268<T1,T2> &p)
	{
		cout << "类内实现" << endl;
		cout << "name:" << p.m_Name << endl;
		cout << "age:" << p.m_Age << endl;
	}
	//	2. 全局函数类外实现 - 需要提前让编译器知道全局函数的存在（所以写在上面）
	// 加空模板参数列表，（需要告诉人家这是个模板）
	friend void printPerson268_2<>(Person268<T1, T2> &p);

public:
	Person268(T1 name, T2 age)
	{
		m_Name = name;
		m_Age = age;
	}
private:
	T1 m_Name;
	T2 m_Age;
};
static void test08()
{
	cout << "-------------test08()-------------" << endl;
	//	1. 全局函数类内实现 - 直接在类内声明友元即可
	Person268<string, int>p1("LJT", 22);
	printPerson268(p1);

	//	2. 全局函数类外实现 - 需要提前让编译器知道全局函数的存在
	Person268<string, int>p2("BBX", 18);
	printPerson268_2(p2);
}



// 类模板案例 - 数组类封装

// 案例描述: 实现一个通用的数组类，要求如下:
//	·可以对内置数据类型以及自定义数据类型的数据进行存储
//	·将数组中的数据存储到堆区
//	·构造函数中可以传入数组的容量
//	·提供对应的拷贝构造函数以及operator = 防止浅拷贝问题
//	·提供尾插法和尾删法对数组中的数据进行增加和删除
//	·可以通过下标的方式访问数组中的元素
//	·可以获取数组中当前元素个数和数组的容量

void printArray(MyArray<int>& arr)
{
	for (size_t i = 0; i < arr.getSize(); i++)
	{
		cout << "arr[i]" << arr[i] << endl;
	}
}
class Person269
{
public:
	Person269() {};
	Person269(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	string m_Name;
	int m_Age;
};
void printPerson269(MyArray<Person269>& arr)
{
	for (size_t i = 0; i < arr.getSize(); i++)
	{
		cout << "姓名：" << arr[i].m_Name << endl;
		cout << "年龄：" << arr[i].m_Age << endl;
	}
}

static void test09()
{
	cout << "-------------test09()-------------" << endl;
	MyArray<int> arr1(5);
	for (size_t i = 0; i < 5; i++)
	{
		arr1.Push_Back(i);
	}
	cout << "arr1的打印输出为：" << endl;
	printArray(arr1);
	arr1.Pop_Back();
	cout << "arr1尾删：" << endl;
	cout << "arr1.getSize():" << arr1.getSize() << endl;
	cout << "arr1.getCapacity():" << arr1.getCapacity() << endl;

	MyArray<int>arr2(arr1);
	cout << "arr2的打印输出为：" << endl;
	printArray(arr2);

	MyArray<Person269>arr3(10);
	Person269 p1("孙悟空", 999);
	Person269 p2("韩信", 20);
	Person269 p3("妲己", 18);
	Person269 p4("赵云", 25);
	Person269 p5("安琪拉", 27);
	// 将数据插入数组中
	arr3.Push_Back(p1);
	arr3.Push_Back(p2);
	arr3.Push_Back(p3);
	arr3.Push_Back(p4);
	arr3.Push_Back(p5);

	// 打印数组
	printPerson269(arr3);
	arr3.Pop_Back();
	cout << "arr3尾删：" << endl;
	cout << "arr3.getSize():" << arr3.getSize() << endl;
	cout << "arr3.getCapacity():" << arr3.getCapacity() << endl;

	MyArray<Person269>arr4(arr3);
	cout << "arr4的打印输出为：" << endl;
	printPerson269(arr4);


}



int main26()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	test09();
	system("pause");
	return 0;
}