#include<iostream>
#include<algorithm>
#include<numeric>
#include<functional>
#include<vector>
using namespace std;


//	概述:
//		·算法主要是由头文件 <algorithm> <functional> <numeric>组成
//		·<algorithm>是所有STL头文件中最大的一个，范围涉及到比较、交换、查找、遍历操作、复制、修改等等
//		·<numeric>体积很小，只包括几个在序列上面进行简单数学运算的模板函数
//		·<functional>定义了一些模板类, 用以声明函数对象


//	1. 常用遍历算法
//	学习目标 :
//		·掌握常用的遍历算法
//	算法简介 :
//		for_each	//遍历容器
//		transform	//搬运容器到另一个容器中
//		find
// 1.for_each
//	功能描述
//		·实现遍历容器
//	函数原型
//		·for_each(iterator beg, iterator end, func);
//			遍历算法 遍历容器元素
//			beg 开始选代器
//			end 结束选代器
//			_func函数或者函数对象
void myPrint391(int& val)
{
	cout << val << " ";
}
class myPrint392
{
public:
	void operator()(int& val)
	{
		cout << val << " ";
	}
};
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	vector<int> v1;
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(2);
	v1.push_back(5);
	v1.push_back(1);
	for_each(v1.begin(), v1.end(), myPrint391);//myPrint391其实是函数指针，但是没讲
	cout << endl;
	for_each(v1.begin(), v1.end(), myPrint392());
	cout << endl;
}
// 2.transform
//	功能描述 :
//		·搬运容器到另一个容器中
//	函数原型 :
//		·transform(iterator beg1, iterator end1, iterator beg2, func);
//			beg1 源容器开始选代器
//			end1 源容器结束迭代器
//			beg2 目标容器开始迭代器
//			_func函数或者函数对象
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
	vector<bool> v2;//不同容器之间也可以搬运
	v2.resize(v1.size());//得先开辟，不然搬运不了
	transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


int main39()
{
	test01();
	test02();
	system("pause");
	return 0;
}