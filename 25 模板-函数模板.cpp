#include<iostream>
using namespace std;
#include <iomanip> // 控制小数位数

// 开启泛型编程的大门，还有STL技术


// 模板的概念
// 模板就是建立通用的模具，大大提高复用性
// 1. 模板不能直接使用，它只是一个框架
// 2. 模板并不万能



//	C++另一种编程思想称为]泛型编程，主要利用的技术就是模板
//	C++提供两种模板机制:函数模板和类模板
// 
// 
//函数模板
// 函数模板作用 :
//	建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个虚拟的类型来代表，将类型参数化
//
// 语法 :
//	template<typename T>
//	函数声明或定义
//
// 解释 :
//	template --- 声明创建模板
//	typename --- 表面其后面的符号是一种数据类型，可以用class代替
//		T	 --- 通用的数据类型，名称可以替换，通常为大写字母



// 两交换个整型函数
void swapInt25(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
// 交换两个浮点型函数
void swapDouble25(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}
// 函数模板
template<typename T> // 声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用的数据类型
// typename可以替换为class
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
// 函数模板注意事项
//	1. 自动类型推导，必须推导出一致的数据类型T，才可以使用
//	2. 模板必须要确定出T的数据类型，才可以使用
template<class T>
void func()
{
	cout << "func的调用" << endl;
}



static	void test01()
{
	cout << "-------------test01()-------------" << endl;
	int a = 10;
	int b = 20;
	swapInt25(a, b);
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;

	// 利用函数模板交换
	// 两种方式使用函数模板
	// 1. 自动类型推导
	mySwap(a, b);
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	// 2. 显示指定类型
	mySwap<int>(a, b);
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;

	double c = 3.1415926;
	double d = 2.7187845;
	swapDouble25(c, d);
	cout << setiosflags(ios::fixed);
	cout << setprecision(7) << "c:" << c << endl;
	cout << setprecision(7) << "d:" << d << endl;
	mySwap(c, d);
	cout << setprecision(7) << "c:" << c << endl;
	cout << setprecision(7) << "d:" << d << endl;
	mySwap<double>(c, d);
	cout << setprecision(7) << "c:" << c << endl;
	cout << setprecision(7) << "d:" << d << endl;

	//	1. 自动类型推导，必须推导出一致的数据类型T，才可以使用
	//mySwap(a, c);// 报错
	
	//	2. 模板必须要确定出T的数据类型，才可以使用
	//func();// 报错
	func<int>();
}



// 案例 -- 数据排序
// 实现通用对数组进行排序的函数
//	1. 利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
//	2. 排序规则从大到小，排序算法为选择排序
//	3. 分别利用char数组和int数组进行测试

// 排序算法
template<class T>
void mySort(T arr[],int len)
{
	for (size_t i = 0; i < len; i++)
	{
		int max = i;//认定最大值的下标
		for(int j =i+1;j<len;j++)
		{
			//认定最大值比遍历出的数值要小，说明j下标的元素才是真正的最大值
			if (arr[max]<arr[j])
			{
				max = j;
			}
		}
		if (max!=i)
		{
			// 交换max和i
			mySwap(arr[max], arr[i]);
		}
	}
}
/// 提供打印数组模板
template<class T>
void printArray(T arr[], int len)
{
	for (size_t i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

static	void test02()
{
	cout << "-------------test02()-------------" << endl;
	char charArr[] = "abskicgwifgiugfc";
	mySort(charArr, sizeof(charArr) / sizeof(char));
	printArray(charArr, sizeof(charArr) / sizeof(char));

	int intArr[] = { 1654,46,4164,6516,6846,646,164,64,4648,76,136,4 };
	mySort(intArr, sizeof(intArr) / sizeof(int));
	printArray(intArr, sizeof(intArr) / sizeof(int));
}



// 普通函数与函数模板的区别
//	1. 普通函数调用时可以发生自动类型转换(隐式类型转换)
//	2. 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
//	3. 如果利用显示指定类型的方式，可以发生隐式类型转换
// 建议使用显示指定类型的方式，调用函数模板，因为可以自己确定通用类型T
int myAdd251(int a, int b)
{
	return a + b;
}
template<class T>
T myAdd252(T a, T b)
{
	return a + b;
}
static	void test03()
{
	cout << "-------------test03()-------------" << endl;
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << "a+b=" << myAdd251(a, b) << endl;
	//	1. 普通函数调用时可以发生自动类型转换(隐式类型转换)
	cout << "a+c=" << myAdd251(a, c) << endl;

	//	2. 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
	cout << "myAdd252(a, b):" << myAdd252(a, b) << endl;
	//cout << "myAdd252(a, c):" << myAdd252(a, c) << endl;

	//	3. 如果利用显示指定类型的方式，可以发生隐式类型转换
	cout << "myAdd252<int>(a, c):" << myAdd252<int>(a, c) << endl;
	// 不能用引用。我的理解：引用实质为const T* temp = &变量；如果刚开始声明了T是int，那这个指针变量类型定好了，不能指向char
}



// 普通函数与函数模板调用规则
//	调用规则如下:
//		1. 如果函数模板和普通函数都可以实现，优先调用普通函数
//		2. 可以通过空模板参数列表来强制调用函数模板
//		3. 函数模板也可以发生重载
//		4. 如果函数模板可以产生更好的匹配, 优先调用函数模板
// 既然提供了函数模板，最好就不要提供普通函数，否则容易出现二义性
void myPrint251(int a, int b)
{
	cout << "调用的普通函数" << endl;
}
template<class T>
void myPrint251(T a, T b)
{
	cout << "调用的函数模板" << endl;
}
//	3. 函数模板也可以发生重载
template<class T>
void myPrint251(T a, T b, T c)
{
	cout << "调用的重载函数模板" << endl;
}
static void test04()
{
	cout << "-------------test04()-------------" << endl;
	int a = 10;
	int b = 20;
	//	1. 如果函数模板和普通函数都可以实现，优先调用普通函数
	myPrint251(a, b);

	//	2. 可以通过空模板参数列表来强制调用函数模板
	myPrint251<>(a, b);

	//	3. 函数模板也可以发生重载
	myPrint251<>(a, b, 100);

	//	4. 如果函数模板可以产生更好的匹配, 优先调用函数模板
	char c1 = 'a';
	char c2 = 'b';
	myPrint251(c1, c2);
}



// 模板的局限性
// 模板并不是万能的
// 如果输入的参数是自定义的数据类型，如何赋值？如何比较？
// C++为了解决这种问题，提供模板的重载，可以为这些特定的类型提供具体化的模板
// 利用具体化的模板，可以解决自定义类型的通用化
// 学习模板并不是为了写模板，而是在STL中能够运用系统提供的模板

// 对比两个数据是否相等函数
class Person251
{
public:
	Person251(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};
template<class T>
bool myCompare251(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// 利用具体化Person的版本实现代码，具体化优先使用
template<> bool myCompare251(Person251& p1, Person251& p2)
{
	if ((p1.name == p2.name) && (p1.age == p2.age))
	{
		return true;
	}
	else
	{
		return false;
	}
}
static void test05()
{
	cout << "-------------test05()-------------" << endl;

	int a = 10;
	int b = 20;
	bool ret1 = myCompare251(a, b);
	if (ret1)
	{
		cout << "a==b" << endl;
	}
	else
	{
		cout << "a!=b" << endl;
	}
	Person251 p1("Tom", 10);
	Person251 p2("Tom", 11);
	bool ret2 = myCompare251(p1, p2);
	if (ret2)
	{
		cout << "p1==p2" << endl;
	}
	else
	{
		cout << "p1!=p2" << endl;
	}

}
int main25()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	system("pause");
	return 0;
}