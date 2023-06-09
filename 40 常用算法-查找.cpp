#include<iostream>
#include<algorithm>
#include<numeric>
#include<functional>
#include<vector>
using namespace std;


//	2. 常用查找算法
//	学习目标 :
//		·掌握常用的查找算法
//	算法简介 :
//		find			//查找元素
//		find_if			//按条件查找元素
//		adjacent_find	//查找相邻重复元素
//		binary_search	//二分查找法
//		count			//统计元素个数
//		count_if		//按条件统计元素个数



// 1.find
//	功能描述:
//		·查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()
//	函数原型 :
//		·find(iterator beg, iterator end, value);
//			按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
//			beg 开始选代器
//			end 结束选代器
//			value 查找的元素
class Person401
{
public:
	Person401(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	bool operator==(const Person401& p)
	{
		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name)
		{
			return true;
		}
		return false;
	}
	string m_Name;
	int m_Age;
};
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	//查找内置数据类型
	vector<int>v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到：" << *it << endl;
	}

	//查找自定义数据类型
	vector<Person401>v2;
	Person401 p1("刘备", 35);
	Person401 p2("曹操", 45);
	Person401 p3("孙权", 15);
	Person401 p4("赵云", 25);
	Person401 p5("张飞", 33);
	Person401 p6("关羽", 34);
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);
	v2.push_back(p5);
	v2.push_back(p6);
	vector<Person401>::iterator it2 = find(v2.begin(), v2.end(), p2);//需要重载，不然不知道==怎么操作
	if (it2 == v2.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到：" << it2->m_Name << endl;
	}
}



// 2.find_if
//	功能描述:
//		·按条件查找元素
//	函数原型 :
//		·find_if(iterator beg, iterator end, _Pred);
//			按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
//			beg开始选代器
//			end 结束选代器
//			_Pred 函数或者谓词 (返回bool类型的仿函数)
class GreaterFive40
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
class Greater20
{
public:
	bool operator()(Person401 &p)
	{
		return p.m_Age > 20;
	}
};
static void test02()
{
	cout << "-------------test02()-------------" << endl;
	//查找内置数据类型
	vector<int>v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive40());
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到大于5的数字为：" << *it << endl;
	}

	//查找自定义数据类型
	vector<Person401>v2;
	Person401 p1("刘备", 35);
	Person401 p2("曹操", 45);
	Person401 p3("孙权", 15);
	Person401 p4("赵云", 25);
	Person401 p5("张飞", 33);
	Person401 p6("关羽", 34);
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);
	v2.push_back(p5);
	v2.push_back(p6);
	vector<Person401>::iterator it2 = find_if(v2.begin(), v2.end(), Greater20());
	if (it2 == v2.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到年龄大于20的人：" << it2->m_Name << endl;
	}
}



// 3.adjacent find
//	功能描述
//		·查找相邻重复元素
//	函数原型 :
//		·adjacent find(iterator beg, iterator end);
//			查找相邻重复元素,返回相邻元素的第一个位置的迭代器
//			beg 开始选代器
//			end 结束选代器
static void test03()
{
	cout << "-------------test03()-------------" << endl;
	//查找内置数据类型
	vector<int>v;
	v.push_back(0);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);
	v.push_back(3);//能找到这个
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到的数字为：" << *it << endl;
	}
}



// 4.binary_search
//	功能描述 :
//		·查找指定元素是否存在
//	函数原型 :
//		·bool binary_search(iterator beg, iterator end, value);
//			查找指定的元素，查到 返回true 否则false
//			注意: 在无序序列中不可用
//			beg 开始选代器
//			end 结束选代器
//			value 查找的元素
static void test04()
{
	cout << "-------------test04()-------------" << endl;
	//查找内置数据类型
	vector<int>v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	// 容器必须有序，如果无序，结果未知
	bool it = binary_search(v.begin(), v.end(), 6);
	if (it == false)
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到" << endl;
	}
}



// 5.count
//	功能描述 :
//		·统计元素个数
//	函数原型 :
//		·count(iterator beg, iterator end, value);
//			统计元素出现次数
//			beg 开始选代器
//			end 结束选代器
//			value 统计的元素
class Person402
{
public:
	Person402(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	bool operator==(const Person402& p)
	{
		if (this->m_Age == p.m_Age)
		{
			return true;
		}
		return false;
	}
	string m_Name;
	int m_Age;
};
static void test05()
{
	cout << "-------------test05()-------------" << endl;
	//查找内置数据类型
	vector<int>v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	v.push_back(5);
	v.push_back(5);

	int num = count(v.begin(), v.end(), 5);
	cout << "5的个数为：" << num << endl;

	//查找自定义数据类型
	vector<Person402>v2;
	Person402 p1("刘备", 35);
	Person402 p2("曹操", 45);
	Person402 p3("孙权", 15);
	Person402 p4("赵云", 25);
	Person402 p5("张飞", 35);
	Person402 p6("关羽", 35);
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);
	v2.push_back(p5);
	v2.push_back(p6);
	v2.push_back(p6);
	v2.push_back(p6);
	int num2 = count(v2.begin(), v2.end(), p1);
	cout << "和刘备一个岁数的人有：" << num2 << endl;
}



// 6.count if
//	功能描述:
//		·按条件统计元素个数函数原型
//		·count if (iterator beg, iterator end, Pred);
//			按条件统计元素出现次数
//			beg 开始选代器
//			end 结束选代器
//	_Pred 谓词




int main40()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	system("pause");
	return 0;
}