#include<iostream>
using namespace std;
#include<string>

/*
			C++对象模型和this指针
*/



//类内的  成员变量  和  成员函数  分开存储
//在C++中，只有非静态成员变量才属于类的对象上
class Person171
{

};
static void test01()
{
	cout << "-------------test01()-------------" << endl;

	Person171 p;
	// 空对象占用内存空间为：1
	// C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
	// 每个空对象也应该有一个独一无二的内存地址
	cout << "size of p =:" << sizeof(p) << endl;
	cout << "address of p =:" << &p << endl;
}

class Person172
{
	int m_A;// 非静态成员变量	属于类的对象上的

	static int m_B;// 静态成员变量	不属于类对象上

	void func() {};// 非静态成员函数	不属于类对象上（本质上也只有一份）

	static void func2() {};// 静态成员函数	不属于类对象上
};
int Person172::m_B = 100;

static void test02()
{
	cout << "-------------test02()-------------" << endl;

	Person172 p;
	// 占用内存空间为：4
	// 即m_A
	cout << "size of p =:" << sizeof(p) << endl;
	cout << "address of p =:" << &p << endl;//和test01一个地址，C++对内存真的很抠
}



// this指针的用途
// this指针概念
// 在C++中成员变量和成员函数是分开存储的
// 每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码
// 那么问题是: 这一块代码是如何区分那个对象调用自己的呢 ?
// 
// C++通过提供特殊的对象指针，this指针，解决上述问题。this指针指向被调用的成员函数所属的对象（谁调，this指谁）
// this指针是隐含每一个非静态成员函数内的一种指针
// this指针不需要定义，直接使用即可
// 
// this指针的用途 :
// 当形参和成员变量同名时，可用this指针来区分
// 在类的非静态成员函数中返回对象本身，可使用return * this
class Person173
{
public:
	Person173(int age)
	{
		age = age;//他会认为这三个age是同一份
	}
	int age;// 即从来没给这个赋值
};
class Person174
{
public:
	Person174(int age)
	{
		// this指针指向被调用的成员函数所属的对象
		this->age = age;
	}
	// 如果不加&，就是调用拷贝函数了
	// 如果不加&，每次都会返回一个新的对象，对p2的改变将只发生在第一次
	Person174& PersonAddAge(Person174 &p)// 引用指向本身内存，不用引用就是拷贝了，而拷贝指向另一个内存
	{
		this->age += p.age;// 别人的年龄加自己的年龄

		return *this;//   this指向p2，而*this指向的就是p2这个对象本体
	}

	int age;
};
// 1. 解决名称冲突
static void test03()
{
	cout << "-------------test03()-------------" << endl;

	Person173 p1(18);
	cout << "p1的年龄为:" << p1.age << endl;
	Person174 p2(18);
	cout << "p2的年龄为:" << p2.age << endl;

}
// 2. 返回对象本身用this
static void test04()
{
	cout << "-------------test04()-------------" << endl;

	Person174 p1(10);
	Person174 p2(18);
	p2.PersonAddAge(p1);
	cout << "p2加上p1的年龄为:" << p2.age << endl;

	// 链式编程思想
	// （string + string也是这样）
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
	// 如果不加&，每次都会返回一个新的对象，对p2的改变将只发生在第一次
	cout << "p2再加上p1加上p1加上p1加上p1的年龄为:" << p2.age << endl;
}



// 空指针访问成员函数
// C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针
// 如果用到this指针，需要加以判断保证代码的健壮性
class Person175
{
public:
	void showClassName()
	{
		cout << "this is Person175 class" << endl;
	}
	void showClassAge()
	{
		// 加上这个就不会崩了，可以提高代码健壮性
		/*if (this == NULL)
		{
			cout << "this is NULL pointer" << endl;
			return;
		}*/
		cout << "age=" << this->age << endl;
	}
	int age;

	void showStaticAge()
	{
		cout << "s_age=" << s_age << endl;
	}
	static int s_age;
};
int Person175::s_age = 105;

static void test05()
{
	cout << "-------------test05()-------------" << endl;

	Person175* p = NULL;
	p->showClassName();//代码没崩

	//p->showClassAge();//代码崩了，因为一个空指针没有实体，还想访问age，肯定报错
	// 你连女朋友都没有，怎么会有女朋友的年龄
	p->showStaticAge();// 静态就可以访问
}



// const修饰成员函数
//	常函数:
//		成员函数后加const后我们称为这个函数为常函数
//		常函数内不可以修改成员属性
//		成员属性声明时加关键字mutable（可变的 易变的）后，在常函数中依然可以修改
// 
//	常对象 :
//		声明对象前加const称该对象为常对象
//		常对象只能调用常函数

//	常函数
class Person176
{
public:

	// this指针的本质，是指针常量，指针的指向是不可以修改的，即：
	// Person176* const this;
	// 如果想让this指针指向的值也不可以修改,即：
	// const Person176* const this;// 指针常量加常量指针 = 一点也变不了
	// 在成员函数后面加const，修饰的是this的指向，让this指针指向的值也不可以修改
	void showPerson() const//const必须写在后面，不然就不是常函数了（写在前面就成了修饰返回值类型了）
	{
		//m_A = 100;//不可以随便修改了哦
		this->m_B = 100;//不可以随便修改了哦
		cout << "m_B=" << this->m_B << endl;

		//this = NULL;// this的指向也不可以修改哦
	}
	void func() 
	{
		m_A = 100;
	};//非 常函数

	int m_A;
	mutable int m_B;// 特殊变量，即使在常函数中，也可以修改这个值，加关键字mutable

	// 常对象可以修改静态变量的值
	static int s_A;
};
int Person176::s_A= 105;
static void test06()
{
	cout << "-------------test06()-------------" << endl;

	Person176 p;
	p.showPerson();
}

//	常对象 
static void test07()
{
	cout << "-------------test07()-------------" << endl;

	const Person176 p;//对象前加const，变为常对象
	//p.m_A = 100;//常对象不能随便修改
	p.m_B = 100;// m_B比较特殊，常对象下也能修改
	// 常对象只能调用常函数
	p.showPerson();
	//p.func();//对象包含与成员函数不兼容的类型限定符
	// 不可以调用普通成员函数，因为普通成员函数可以修改属性
	// func()可以随便修改变量，要是能调起来，就可以侧面修改了（比如m_A），所以必不可以调用
	
	
	// 常对象可以修改静态变量的值
	cout << "p.s_A =" << p.s_A << endl;
	p.s_A = 106;
	cout << "p.s_A =" << p.s_A << endl;
}



int main17()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();

	system("pause");
	return 0;
}
