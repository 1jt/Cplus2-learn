#include<iostream>
using namespace std;

/*
C++面向对象的三大特性为：
		封装
		继承
		多态
*/
/*

/*
			继承
继承好处：减少重复代码
语法：class 子类 : 继承方式 父类
子类	也称为 派生类
父类	也称为 基类
*/



// 普通实现

// Java页面
//class Java
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登记、注册...（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
//	}
//	void left()
//	{
//		cout << "Java、Python、C++、...（公共分类列表）" << endl;
//	}
//	void content()
//	{
//		cout << "Java学科视频" << endl;
//	}
//};
//// Pytho页面
//class Python
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登记、注册...（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
//	}
//	void left()
//	{
//		cout << "Java、Python、C++、...（公共分类列表）" << endl;
//	}
//	void content()
//	{
//		cout << "Python学科视频" << endl;
//	}
//};
//// C++页面
//class CPP
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登记、注册...（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
//	}
//	void left()
//	{
//		cout << "Java、Python、C++、...（公共分类列表）" << endl;
//	}
//	void content()
//	{
//		cout << "C++学科视频" << endl;
//	}
//};

// 继承实现
// 
// 公共页面
class BasePage
{
public:
	void header()
	{
		cout << "首页、公开课、登记、注册...（公共头部）" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
	}
	void left()
	{
		cout << "Java、Python、C++、...（公共分类列表）" << endl;
	}
};
// Java页面
class Java :public BasePage
{
public:
	void content()
	{
		cout << "Java学科视频" << endl;
	}
};
// Python页面
class Python :public BasePage
{
public:
	void content()
	{
		cout << "Python学科视频" << endl;
	}
};// C++页面
class CPP :public BasePage
{
public:
	void content()
	{
		cout << "C++学科视频" << endl;
	}
};

static void test01()
{
	cout << "-------------test01()-------------" << endl;
	cout << "Java下载视频页面如下：" << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();

	cout << "----------------------------------" << endl;
	cout << "Python下载视频页面如下：" << endl;
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();

	cout << "----------------------------------" << endl;
	cout << "C++下载视频页面如下：" << endl;
	CPP cpp;
	cpp.header();
	cpp.footer();
	cpp.left();
	cpp.content();
}



// 继承方式
// 语法：class 子类 : 继承方式 父类

// 继承方式一共有三种
//		1. 公共继承
//		2. 保护继承
//		3. 私有继承

// 1. 公共继承
//	父类中的公共还是公共，保护还是保护，私有不能继承
// 
// 2. 保护继承
// 父类中的公共变为保护，保护还是保护，私有不能继承
// 
// 3. 私有继承
// 父类中的公共变为私有，保护变为私有，私有不能继承
//

// 1. 公共继承
class Base201
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

// 函数外只能定义全局变量或者对象 ，而不能执行语句及调用函数， 这句话一定要谨记
class Son201:public Base201
{
public:
	void func()
	{
		m_A = 10;// 父类中的公共权限成员，到子类中依然是公共权限
		m_B = 10;// 父类中的保护权限成员，到子类中依然是保护权限
		//m_C = 10;// 父类中的私有权限成员，子类访问不到
	}
};

// 2. 保护继承
class Son202 :protected Base201
{
public:
	void func()
	{
		m_A = 10;// 父类中的公共权限成员，到子类中变为保护权限
		m_B = 10;// 父类中的保护权限成员，到子类中依然是保护权限
		//m_C = 10;// 父类中的私有权限成员，子类访问不到
	}
};

// 3. 私有继承
class Son203 :private Base201
{
public:
	void func()
	{
		m_A = 10;// 父类中的公共权限成员，到子类中变为私有权限
		m_B = 10;// 父类中的保护权限成员，到子类中变为私有权限
		//m_C = 10;// 父类中的私有权限成员，子类访问不到
	}
};
class GrandSon203 :public Son203
{
public:
	void func()
	{
		//m_A = 10;// 父类中的公共权限成员，到子类中变为私有权限，孙子类无法访问
		//m_B = 10;// 父类中的保护权限成员，到子类中变为私有权限，孙子类无法访问
		//m_C = 10;// 父类中的私有权限成员，子类访问不到
	}
};

static void test02()
{
	cout << "-------------test02()-------------" << endl;
	Son201 s1;
	s1.m_A = 100;
	cout << "s1.m_A = " << s1.m_A << endl;
	//s1.m_B = 100;// 保护权限类外访问不到
	Son202 s2;
	//s2.m_A = 100;// 保护权限类外访问不到
	Son203 s3;
	//s3.m_A = 100;// 私有权限类外访问不到

}



// 继承中的对象模型
class Base202
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;// 私有成员只是被隐藏了，但是还是会继承下去
};
class Son204 :public Base202
{
public:
	int m_D;
};
static void test03()
{
	cout << "-------------test03()-------------" << endl;
	// 16
	// 父类中所有非静态成员属性都会被子类继承下去
	// 父类中的私有成员属性，是被编译器给隐藏了，因此是访问不到，但是确实是被继承下去了
	// private保留，这是为了使用父类指针
	cout << "sizeof(Son204):" << sizeof(Son204)<<endl;

	// 报告单个类的布局
	// 电脑右下角打开Developer Command Prompt for VS 2022（开发人员命令提示工具）
	// cd 到当前文件目录下
	// 输入：cl /d1 reportSingleClassLayoutSon204 "20 类和对象-继承.cpp"
	// cl /d1 reportSingleClassLayout类名 文件名
	// 即可查看

	/*
	20 类和对象 - 继承.cpp

		class Son204    size(16) :
		+-- -
		0 | +-- - (base class Base202)
		0      | | m_A
		4      | | m_B
		8      | | m_C
		| +-- -
		12 | m_D
		+ -- -
	*/

}



// 继承中的构造和析构顺序
class Base203
{
public:
	Base203()
	{
		cout << "Base203构造函数！" << endl;
	}
	~Base203()
	{
		cout << "Base203析构函数！" << endl;
	}
	int m_A;
protected:
	int m_B;
private:
	int m_C;// 私有成员只是被隐藏了，但是还是会继承下去
};
class Son205 :public Base203
{
public:
	Son205()
	{
		cout << "Son205构造函数！" << endl;
	}
	~Son205()
	{
		cout << "Son205析构函数！" << endl;
	}
};
static void test04()
{
	cout << "-------------test04()-------------" << endl;
	//Base203 b1;
	Son205 s1;// 白发人送黑发人，先有父类再有子类，子类先走，父类再走
}



// 继承中同名成员处理方式
//	问题: 当子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类中同名的数据呢？
//		访问子类同名成员 直接访问即可
//		访问父类同名成员 需要加作用域
class Base204
{
public:
	Base204()
	{
		m_A = 100;
	}
	void func()
	{
		cout << "Base204-func()调用" << endl;
	}
	void func(int a)
	{
		cout << "Base204-func(int a)调用" << endl;
	}
	int m_A;
};
class Son206 :public Base204
{
public:
	Son206()
	{
		m_A = 200;
	}
	void func()
	{
		cout << "Son206-func()调用" << endl;
	}
	int m_A;
};
static void test05()
{
	cout << "-------------test05()-------------" << endl;
	Son206 s;
	// 1. 同名变量
	// 通过子类对象，访问到父类中同名的成员，需要加作用域
	cout << "Son	下m_A:" << s.m_A << endl;
	cout << "Base	下m_A:" << s.Base204::m_A << endl;

	// 2. 同名函数
	s.func();// 直接调用，调用是子类中的同名成员
	s.Base204::func();// 需要加作用域

	// 如果子类中出现和父类同名的成员函数，子类的同名成员函数会隐藏掉父类中所有同名成员函数
	//s.func(100);// 会报错，子类没有这个重载
	// 如果想访问，得加作用域
	s.Base204::func(100);
}



// 继承中同名静态成员处理方法
//	问题: 继承中同名的静态成员在子类对象上如何进行访问？
//	静态成员和非静态成员出现同名，处理方式一致
//		访问子类同名成员 直接访问即可
//		访问父类同名成员 需要加作用域
class Base205
{
public:
	static void func()
	{
		cout << "Base205-static void func()调用" << endl;
	}
	static void func(int a)
	{
		cout << "Base204-static void func(int a)调用" << endl;
	}
	static int m_A;
};
int Base205::m_A = 100;
class Son207 :public Base205
{
public:
	static void func()
	{
		cout << "Son207-static void func()" << endl;
	}
	static int m_A;
};
int Son207::m_A = 200;
static void test06()
{
	cout << "-------------test06()-------------" << endl;
	// 同名静态变量
	// 1. 通过对象访问
	Son207 s1;
	cout << "通过对象访问" << endl;
	cout << "Son下	m_A:" << s1.m_A << endl;
	cout << "Base下	m_A:" << s1.Base205::m_A << endl;
	// 2. 通过类名访问
	cout << "通过类名访问" << endl;
	cout << "Son下	m_A:" << Son207::m_A << endl;
	cout << "Base下	m_A:" << Base205::m_A << endl;
	cout << "Base下	m_A:" << Son207::Base205::m_A << endl;


	// 同名静态函数
	s1.func();
	s1.Base205::func();
	Son207::func();
	Son207::Base205::func();
	// 如果子类中出现和父类同名静态成员函数，子类的同名成员函数会隐藏掉父类中所有同名静态成员函数
	//Son207::func(100);
	// 如果想访问，得加作用域
	Son207::Base205::func(100);
}



// 多继承语法（奉先语法）
//	C++允许一个类继承多个类 I
// 
//	语法 : class 子类 :继承方式 父类1, 继承方式 父类2...
//	多继承可能会引发父类中有同名成员出现，需要加作用域区分
// 
//	C++实际开发中不建议用多继承
class Base206
{
public:
	Base206()
	{
		m_A = 100;
	}
	int m_A;
};
class Base207
{
public:
	Base207()
	{
		m_A = 200;
	}
	int m_A;
};
// 子类需要继承Base206和Base207
class Son208 :public Base206, public Base207
{
public:
	Son208()
	{
		m_C = 300;
		m_D = 400;
	}
	int m_C;
	int m_D;
};
static void test07()
{
	cout << "-------------test07()-------------" << endl;
	cout << "sizeof(Son208):" << sizeof(Son208) << endl;
	/*
	class Son208    size(16) :
		+-- -
		0 | +-- - (base class Base206)
		0      | | m_A
		| +-- -
		4 | +-- - (base class Base207)
		4      | | m_A
		| +-- -
		8 | m_C
		12 | m_D
		+ -- -
	*/

	// 当父类中出现同名成员，需要加作用域
	Son208 s;
	cout << "s.Base206::m_A:" << s.Base206::m_A << endl;
	cout << "s.Base207::m_A:" << s.Base207::m_A << endl;
}



// 菱形继承问题以及解决方法
//	菱形继承概念:
//		两个派生类继承同一个基类
//		又有某个类同时继承者两个派生类
//		这种继承被称为菱形继承，或者钻石继承

//				动物
//			/			\
//		🐏				🐫
//          \         /
//             羊驼
// 1.羊继承了动物的数据，驼同样继承了动物的数据，当草泥马使用数据时，就会产生二义性
// 2.草泥马继承自动物的数据继承了两份，其实我们应该清楚，这份数据我们只需要一份就可以。

// 动物类
class Animal20
{
public:
	int m_Age;
};
// 利用虚继承，解决菱形继承问题
// 继承之前，加上关键字 virtual 变为虚继承
// Animal20类称为	虚基类
// 🐏类
class Sheep :virtual public Animal20
{

};
// 🐫类
class Camel :virtual public Animal20
{

};
// 羊驼类
class SheepCamel :public Sheep, public Camel
{

};
static void test08()
{
	cout << "-------------test08()-------------" << endl;
	SheepCamel sc;
	sc.Sheep::m_Age = 28;
	sc.Camel::m_Age = 18;
	// 当菱形继承，两个父类拥有相同数据，需要加以作用域区分
	cout << "sc.Sheep::m_Age = " << sc.Sheep::m_Age << endl;
	cout << "sc.Camel::m_Age = " << sc.Camel::m_Age << endl;

	// 这份数据我们知道，只要有一份就可以，菱形继承导致数据有两份，资源浪费
	/*
	class SheepCamel        size(8) :
		+-- -
		0 | +-- - (base class Sheep)
		0      | | +-- - (base class Animal20)
		0      | | | m_Age
		| | +-- -
		| +-- -
		4 | +-- - (base class Camel)
		4      | | +-- - (base class Animal20)
		4      | | | m_Age
		| | +-- -
		| +-- -
		+-- -
	*/

	// 引入虚继承，不会出现不明确的情况
	cout << "sc.m_Age = " << sc.m_Age << endl;
	/*
	class SheepCamel        size(12) :
		+-- -
		0 | +-- - (base class Sheep)
		0      | | {vbptr}															0
	| +-- -
		4 | +-- - (base class Camel)												4
		4      | | {vbptr}
	| +-- -
		+-- -
		+-- - (virtual base Animal20)
		8 | m_Age																	
		+ -- -

		SheepCamel::$vbtable@Sheep@:
	0 | 0
		1 | 8 (SheepCameld(Sheep + 0)Animal20)					// 这个8是偏移量		0 + 8 = 8

		SheepCamel::$vbtable@Camel@:
	0 | 0
		1 | 4 (SheepCameld(Camel + 0)Animal20)											4 + 4 = 8
		vbi : class  offset o.vbptr  o.vbte fVtorDisp
		Animal20       8       0       4 0
	*/

	//	vbptr
	//	v - virtual
	//	b - base
	//  ptr - pointer
	//	虚基类指针，指向一个vbtable（虚基类表）
	//	即最终也只指向同一个数据

}


int main20()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	system("pause");
	return 0;
}