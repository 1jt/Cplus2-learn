#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//	1. 谓词概念
//	概念 :
//		·返回bool类型的仿函数称为谓词
//		·如果operator()接受一个参数，那么叫做一元谓词
//		·如果operator()接受两个参数，那么叫做二元谓词

//	一元谓词
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

// 二元谓词
class MyCompare37
{
public:
	bool operator()(int val,int val2)
	{
		return val > val2;
	}
};

static void test01()
{
	cout << "-------------test01()-------------" << endl;
	vector<int>v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//	一元谓词
	// 查找容器中有没有大于5的数字
	// predicate(Pred) 即谓词
	//GreaterFive()创建匿名函数对象
	/*	在这个代码（find_if源码）中，可以看出 "_First" 是一个迭代器的原因有两个：

		变量名的命名方式：在 C++ 中，迭代器通常以类似指针的方式来命名，以表明它们是用于遍历容器中元素的指针。
		在这个代码中，"_First" 表示容器中的第一个元素，这种命名方式非常符合迭代器的命名规范。

		函数参数类型的定义：在这个代码中，函数签名中的 "_InIt" 表示输入迭代器（input iterator），
		它是一种迭代器类型，用于遍历容器中的元素，并且只能向前移动，不能进行随机访问。
		因此，在这个代码中，"_First" 是一个输入迭代器，用于指定查找算法的起始位置。

		综上所述，可以看出 "_First" 是一个迭代器，并且它是一个输入迭代器，用于遍历容器中的元素。*/
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());//return _First 返回的是一个迭代器
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到大于5的数字为："<<*it << endl;
	}

	//二元谓词
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	// 使用函数对象，改变算法策略，变为排序规则从大到小
	sort(v.begin(), v.end(),MyCompare37());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


int main37()
{
	test01();
	system("pause");
	return 0;
}