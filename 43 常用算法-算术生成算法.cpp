#include<iostream>
#include<algorithm>
#include<numeric>
#include<functional>
#include<vector>
using namespace std;


//	5. 常用算术生成算法
//	学习目标 :
//		·掌握常用的算术生成算法
//	注意:
//		·算术生成算法属于小型算法，使用时包合的头文件为 #include <numeric>
//	算法简介 :
//		·accumulate// 计算容器元素累计总和
//		·fill		// 向容器中添加元素


// 1.accumulate
//	功能描述 :
//		·计算区间内 容器元素累计总和
//	函数原型 :
//		·accumulate(iterator beg, iterator end, value);
//			计算容器元素累计总和
//			beg 开始选代器
//			end 结束选代器
//			value 起始值


// 2.fill
//	功能描述 :
//		·向容器中填充指定的元素
//	函数原型 :
//		·fill(iterator beg, iteraton, end, value);
//			向容器中填充元素
//			beg 开始选代器
//			end 结束选代器
//			value 填充的值


class myPrint43
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
	
	vector<int>v1;
	for (size_t i = 0; i < 101; i++)
	{
		v1.push_back(i);
	}
	// 1.accumulate
	int total = accumulate(v1.begin(), v1.end(), 0);
	cout << "total=" << total << endl;
	total = accumulate(v1.begin(), v1.end(), 1000);
	cout << "total=" << total << endl;

	// 2.fill
	fill(v1.begin(), v1.end(), 100);
	for_each(v1.begin(), v1.end(), myPrint43());
	cout << endl;
}



int main43()
{
	test01();
	system("pause");
	return 0;
}