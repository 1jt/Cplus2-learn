#include<iostream>
using namespace std;

// 函数默认参数
int func(int a,int b,int c)
{
	return a + b + c;
}
int func2(int a, int b = 20, int c = 30)
{
	return a + b + c;
}
// 注意事项：
// 1. 如果某个位置已经有了默认参数，那么从这个位置往后，从左到右都必须有默认值
// 2. 如果函数声明有默认参数，函数实现就不能有默认参数（声明和实现只能有一个有默认参数）
int func3(int a = 10, int b = 10);
// 这时候下面如果默认参数有就会有报错，因为如果值不一样就会有歧义
int func3(int a, int b)
{
	return a + b;
}


// 函数占位参数
int func4(int a, int = 10)
{
	// 占位参数 还可以有默认参数
	return a;
}


// 函数重载
void func5()
{
	cout << "func5的调用" << endl;
}
void func5(int a)
{
	cout << "func5(int a)的调用" << endl;
}
void func5(double a)
{
	cout << "func5(double a)的调用" << endl;
}

// 函数重载注意事项
	// 1. 引用作为重载的条件
void func6(int& a)//如果直接传入10，相当于int &a = 10;不合法
{
	cout << "func6(int &a)的调用" << endl;

}
void func6(const int& a)//如果直接传入10，相当于const int &a = 10;合法
{
	cout << "func6(const int& a)的调用" << endl;
}
	// 2. 函数重载遇到默认函数
void func7(int a, int b = 10)
{
	cout << "func7(int a, int b)的调用" << endl;
}
void func7(int a)
{
	cout << "func7(int a)的调用" << endl;
}


int main13()
{
	// 函数默认参数
	// C++中，函数的形参列表中的形参是可以有默认值的
	// 返回值类型 函数名(参数=默认){}
	// 如果我们自己传入数据，就用自己的数据，如果没有，那么用默认值
	cout << "func:" << func(10, 20, 30) << endl;
	cout << "func2(10):" << func2(10) << endl;
	cout << "func2(10, 30):" << func2(10, 30) << endl;
	cout << "func3:" << func3() << endl;


	// 函数占位参数
	// C++中函数的形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置
	// 返回值类型 函数名(数据类型){}
	// 现阶段其存在意义不大，但是后续会用到
	// 占位参数 还可以有默认参数
	cout << "func4:" << func4(10,10) << endl;
	

	// 函数重载
	// 函数名可以相同，提高复用性
	// 满足条件：
	// 1. 同一个作用域下
	// 2. 函数名称相同
	// 3. 函数参数类型不同 或者个数不同 或者顺序不同（返回值不可以作为重载条件！）
	func5();
	func5(10);
	func5(10.05);

	// 函数重载注意事项
	// 1. 引用作为重载的条件
	int a = 10;
	func6(a);
	func6(10);
	// 2. 函数重载遇到默认函数
	//func7(10);//当函数重载碰到默认参数，会出现二义性，报错，尽量避免这种情况
	// 但是因为满足重载条件，所以编译是可以通过的

	system("pause");
	return 0;
}