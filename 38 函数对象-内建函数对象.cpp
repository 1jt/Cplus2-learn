#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;


//	1. 内建函数对象
//	意义概念:
//		·vSTL内建了一些函数对象
//	分类:
//		·算术仿函数
//		·关系仿函数
//		·逻辑仿函数
//	用法 :
//		·这些仿函数所产生的对象，用法和一般函数完全相同
//		·使用内建函数对象，需要引入头文件 #include<functional>



//	2. 算术仿函数
//	功能描述 :
//		·实现四则运算
//		·其中negate是一元运算，其他都是二元运算
//	仿函数原型
//		template<class T> T plus<T>			//加法仿函数
//		template<class T> T minus<T>		//减法仿函数
//		template<class T> T multiplies<T>	//乘法仿函数
//		template<class T> T divides<T>		//除法仿函数
//		template<class T> T modulus<T>		//取模仿函数
//		template<class T> T negate<T>		//取反仿函数
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	//如果能理解negate<>就是个用来执行仿函数的类，
	//而如果你只想执行类的函数不想创建一个类的实例化对象，可以不用创建这个n
	negate<int>n;
	cout << n(50) << endl;
	plus<int>n2;//只有一个int，默认相加的是同类数据结构
	cout << n2(50, 60) << endl;
}



//	3. 关系仿函数
//	功能描述 :
//		·实现关系对比
//	仿函数原型 :
//		template<class T> bool equal to<T>		//等于
//		template<class T> bool not equal to<T>	//不等于
//		template<class T> bool greater<T>		//大于
//		template<class T> bool greater equal<T>	//大于等于
//		template<class T> bool less<T>			//小于
//		template<class T> bool less equal<T>	//小于等于
static void test02()
{
	cout << "-------------test02()-------------" << endl;
	vector<int> v1;
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(2);
	v1.push_back(5);
	v1.push_back(1);
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	sort(v1.begin(), v1.end(), greater<int>());
	//说白了，内建仿函数就是给内置数据类型用的。谓词是给自定义类型用的。
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}



//	4. 逻辑仿函数
//	功能描述:
//		·实现逻辑运算
//	函数原型 :
//		template<class T> bool logical_and <T>	//逻辑与
//		template<class T> bool logical_or <T>	//逻辑或
//		template<class T> bool logical_not<T>	//逻辑非
//	基本用不到
static void test03()
{
	cout << "-------------test03()-------------" << endl;
	vector<bool> v1;
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(2);
	for (vector<bool>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	// 利用逻辑非将容器搬运到容器v2中，并执行取反操作
	vector<bool> v2;
	v2.resize(v1.size());//得先开辟，不然搬运不了
	transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


int main38()
{
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}