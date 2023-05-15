#include<iostream>
using namespace std;
#include<string>

/*
C++中的面对对象来源于生活，每个对象也都会有初始化设置以及 对象销毁前的清理数据的设置
*/

//1. 构造函数和析构函数
//	对象的初始化和清理也是两个非常重要的安全问题
//	一个对象或者变量没有初始状态，对其使用后果是未知
//	同样的使用完一个对象或变量，没有及时清理，也会造成一定的安全问题
// 
//	C++利用了构造函数和析构函数解决上述问题，这两个函数将会被编译器自动调用，完成对象初始化和清理工作。
//	对象的初始化和清理工作是编译器强制要我们做的事情，因此如果我们不提供构造和析构，编译器会提供
//	*编译器提供的构造函数和析构函数是空实现*
//	**构造函数 : 主要作用在于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无须手动调用。
//	**析构函数 : 主要作用在于对象销毁前系统自动调用，执行一些清理工作。


// 构造函数语法：类名(){}
// 1. 构造函数，没有返回值也不写void
// 2. 函数名称与类名相同
// 3. 构造函数可以有参数，因此可以发生重载
// 4. 程席在调用对象时候会自动调用构造，无须手动调用,而且只会调用一次

// 析构函数语法:类名()小
// 1. 析构函数，没有返回值也不写void
// 2. 函数名称与类名相同, 在名称前加上符号 ~
// 3. 析构函数不可以有参数，因此不可以发生重载
// 4. 程序在对象销毁前会自动调用析构，无须手动调用.而目只会调用一次

class Person15//如果在多个文件中定义一个类，那么每个文件中的定义必须是完全相同的，因此这儿的类名和之前不能一样
{
public:
	Person15();
	~Person15();

private:

};

Person15::Person15()
{
	cout << "Person15的构造函数的调用" << endl;
}

Person15::~Person15()
{
	cout << "Person15的析构函数的调用" << endl;
}

static void test01()//这儿加static是因为void test01()已经在文件11中有了，所以加个限制范围
//当然加个占位参数也可以 例如 void test01(int = 10)
{
	cout << "-------------test01()-------------" << endl;
	Person15 p;// 栈上的数据，test01()执行完就会释放这个对象，释放前会执行析构函数
}


// 构造函数的分类及调用
/*
两种分类方式
	按参数分为: 有参构造和无参构造
	按类型分为: 普通构造和拷贝构造

三种调用方式
	括号法
	显示法
	隐式转换法
*/
class Person151//如果在多个文件中定义一个类，那么每个文件中的定义必须是完全相同的，因此这儿的类名和之前不能一样
{
public:
	Person151();//无参构造（默认构造）
	Person151(int a);//有参构造
	Person151(const Person151 &p);// 拷贝构造构造（除了拷贝就是普通构造）
	~Person151();

	int age;
private:

};
Person151::Person151()//无参构造（默认构造）
{
	cout << "Person151的无参构造函数的调用" << endl;
}
Person151::Person151(int a)//有参构造
{
	age = a;
	cout << "Person151的有参构造函数的调用" << endl;
}
Person151::Person151(const Person151 &p)// 拷贝构造构造（除了拷贝就是普通构造）
{
	//将传入的人身上的所有属性，拷贝到我身上（夺舍）
	age = p.age;
	cout << "Person151的拷贝构造函数的调用" << endl;
}

Person151::~Person151()
{
	cout << "Person151的析构函数的调用" << endl;
}
static void test02()
{
	cout << "-------------test02()-------------" << endl;
	// 1. 括号法
	Person151 p11;// 默认构造函数的调用
	Person151 p12(10);// 有参构造函数的调用
	Person151 p13(p12);// 拷贝构造函数的调用
	cout << "p12的年龄：" << p12.age << endl;
	p12.age = 15;
	cout << "p12的年龄：" << p12.age << endl;
	cout << "p13的年龄：" << p13.age << endl;//两次输出不一样，说明不是同一块儿内存，是真的拷贝
	// 注意事项1：
	// 调用默认构造函数的时候，不要加()
	// 因为下面这行代码，编译器会认为是一个函数的声明，不会认为在创建对象
	//Person151 p1();//例如
	void func();//一个函数体内部是可以写函数声明的


	// 2. 显示法
	Person151 p21;// 默认构造函数的调用
	Person151 p22 = Person151(10);
	Person151 p23 = Person151(p22);
	Person151(10);//匿名对象	特点：当前执行结束后，系统会立即回收掉匿名函数(aaaaa输出之前就没了)
	cout << "aaaaa" << endl;
	// 注意事项2
	// 不要利用拷贝对象构造函数 初始化匿名对象
	// Person151(p23); //会发生重定义错误，编译器会认为 Person151(p23) == Person151 p23; 编译器会认为是一个对象声明


	// 3. 隐式转换法
	Person151 p31 = 10;// 相当于写了 Person151 p31 = Person151(10);
	Person151 p32 = p31;// 拷贝构造
}


// 拷贝函数调用时机
// C++中拷贝构造函数调用时机通常有三种情况
//		1. 使用一个已经创建完毕的对象来初始化一个新对象
//		2. 值传递的方式给函数参数传值
//		3. 以值方式返回局部对象
static void test03()
{
	cout << "-------------test03()-------------" << endl;
// 1. 使用一个已经创建完毕的对象来初始化一个新对象
	Person151 p11(20);
	Person151 p12(p11);
}

// 2. 值传递的方式给函数参数传值
static void doWork(Person151 p)//值传递的方法，拷贝一个临时副本
{

}
static void test04()
{
	cout << "-------------test04()-------------" << endl;
	Person151 p;
	doWork(p);
}

// 3. 以值方式返回局部对象
static Person151 doWork2()
{
	Person151 p1;
	cout << "aaaaa" << (int*)&p1 << endl;
	return p1;// 这里第一行的p1是个局部变量，而返回时候的第三行的p1是值传递，得拷贝一下，相当于p1(第一行)拷贝给p1(第三行)
	// 但是这里编译器给优化了！！！所以没有发生拷贝，故而地址也是一样的
}
static void test05()
{
	cout << "-------------test05()-------------" << endl;
	Person151 p = doWork2();
	cout << "aaaaa" << (int*)&p << endl;
}


// 构造函数调用规则
// 默认情况下，c++编译器至少给一个类添加3个函数
//	1. 默认构造函数(无参，函数体为空)
//	2. 默认析构函数(无参，函数体为空)
//	3. 默认拷贝构造函数，对属性进行值拷贝（所以拷贝构造函数一般不要自己写）

// 构造函数调用规则如下
//	1. 如果用户定义有参构造函数，c++不在提供默认无参构造，但是会提供默认拷贝构造
//  2. 如果用户定义拷贝构造函数，c++不会再提供其他构造函数
class Person152
{
public:
	Person152();
	Person152(int a);//有参构造
	//Person152(const Person151& p);// 拷贝构造构造（除了拷贝就是普通构造）
	~Person152();
	int age;
};
Person152::Person152()//无参构造（默认构造）
{cout << "Person152的无参构造函数的调用" << endl;}
Person152::Person152(int a)//有参构造
{age = a;cout << "Person152的有参构造函数的调用" << endl;}
//Person152::Person152(const Person152& p)// 拷贝构造构造（除了拷贝就是普通构造）
//{age = p.age;cout << "Person152的拷贝构造函数的调用" << endl;}
Person152::~Person152()
{cout << "Person152的析构函数的调用" << endl;}

static void test06()//类得写到函数前面
{
	cout << "-------------test06()-------------" << endl;
	Person152 p;
	p.age = 18;
	Person152 p2(p);//拷贝构造被注释掉了，但是C++提供默认拷贝构造函数
	cout << "p2的年龄为：" << p2.age << endl;
}
static void test07()
{
	cout << "-------------test07()-------------" << endl;
	// Person152 p;//如果无参构造注释掉了，那这行就会报错，因为我们用户提供了有参构造，这时候c++不在提供默认无参构造
	Person152 p(28);//，但是会提供默认拷贝构造
	// Person152 p(28);//果无参和有参构造都注释掉了，那这行也会报错，因为我们用户提供了拷贝构造，c++不会再提供其他构造函数
	Person152 p2(p);//
	//只有拷贝构造函数时，怎么创建第一个对象呢？
	cout << "p2的年龄为：" << p2.age << endl;
}


// 深拷贝与浅拷贝
// 面试常见坑
//		浅拷贝 : 简单的赋值拷贝操作
//		深拷贝 : 在堆区重新申请空间，进行拷贝操作
class Person153
{
public:
	Person153();
	Person153(int a,int height);//有参构造
	Person153(const Person153& p);// 自己实现拷贝构造函数，解决浅拷贝带来的问题
	~Person153();
	int age;
	int* m_Height;// 指针，指向身高，把数据开辟到堆区
};
Person153::Person153()//无参构造（默认构造）
{
	cout << "Person153的无参构造函数的调用" << endl;
}
Person153::Person153(int a, int height)//有参构造
{
	age = a;
	m_Height = new int(height);// 用new在堆区开辟数据
	cout << "Person153的有参构造函数的调用" << endl;
}
Person153::Person153(const Person153& p)// 拷贝构造构造（除了拷贝就是普通构造）
{
	age = p.age; 
	//m_Height = p.m_Height; //浅拷贝相当于这样写（编译器默认实现）
	// 深拷贝操作
	m_Height = new int(*p.m_Height);
	cout << "Person153的拷贝构造函数的调用" << endl;
}
Person153::~Person153()
{
	// 析构代码，将堆区开辟数据做释放操作
	if (m_Height != NULL)
	{
		delete m_Height;
		m_Height = NULL;
		cout << " 析构代码，将堆区开辟数据做释放操作" << endl;
	}
	// 如果利用编译器提供的拷贝构造函数，会做浅拷贝操作，拷贝那个变量会崩溃，因为相当于delete了两次
	cout << "Person153的析构函数的调用" << endl;
}
static void test08()//类得写到函数前面
{
	cout << "-------------test08()-------------" << endl;
	Person153 p1(38,183);
	cout << "p1的年龄为：" << p1.age << endl;
	cout << "p1的身高的地址为：" << p1.m_Height << endl;
	cout << "p1的身高为：" << *p1.m_Height << endl;
	Person153 p2(p1);//如果利用编译器提供的拷贝构造函数，会做浅拷贝操作，这时候如果有个delete就会报错，因为该空间已经被释放了
	cout << "p2的年龄为：" << p2.age << endl;
	cout << "p2的身高的地址为：" << p2.m_Height << endl;
	cout << "p2的身高为：" << *p2.m_Height << endl;
}
// 如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题



// 初始化列表
// 语法:构造函数():属性1(值2),属性1(值2)...{}
class Person154
{
public:
	// 传统初始化操作
	//Person154(int a, int b, int c)
	//{
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//}
	// 初始化列表初始化属性
	Person154() :m_A(10), m_B(20), m_C(30) {};
	// 当然也可以这样
	Person154(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {};

	int m_A;
	int m_B;
	int m_C;
};
static void test09()
{
	cout << "-------------test09()-------------" << endl;
	//Person154 p(10, 20, 30);//传统
	Person154 p;//初始化列表
	cout << "m_A=" << p.m_A << "\tm_B=" << p.m_B << "\tm_C=" << p.m_C << endl;
	Person154 p1(30, 20, 10);//初始化列表
	cout << "m_A=" << p1.m_A << "\tm_B=" << p1.m_B << "\tm_C=" << p1.m_C << endl;
}



// 类对象作为类成员
// C++类中的成员可以是另一个类的对象，我们称该成员为 对象成员
// 会先构造出被调用的类（手机 > 人），析构与构造相反
// 手机类
class Phone15
{
public:
	Phone15(string pName)
	{
		cout << "手机的构造" << endl;
		m_PName = pName;
	}
	string m_PName;
	~Phone15()
	{
		cout << "手机的析构" << endl;
	}
};
// 人类
class Person155
{
public:
	// Phone15 m_Phone = pName;//相当于用隐式转换法
	Person155(string name, string pName) :m_Name(name), m_Phone(pName)
	{
		cout << "人类的构造" << endl;
	}
	string m_Name;
	Phone15 m_Phone;

	~Person155()
	{
		cout << "人类的析构" << endl;
	}
};
static void test10()
{
	cout << "-------------test10()-------------" << endl;
	Person155 p("张三","苹果MAX");

	cout << p.m_Name << "拿着" << p.m_Phone.m_PName << endl;
	//Person154 p1(30, 20, 10);//初始化列表
	//cout << "m_A=" << p1.m_A << "\tm_B=" << p1.m_B << "\tm_C=" << p1.m_C << endl;
}



int main15()
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
	test10();
	cout << "-------------main()-------------" << endl;
	Person15 p;// 还没释放，所以还没执行析构函数（按个回车试试）
	system("pause");
	return 0;
}