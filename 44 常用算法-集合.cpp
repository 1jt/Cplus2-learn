#include<iostream>
#include<algorithm>
#include<numeric>
#include<functional>
#include<vector>
using namespace std;


//	6. 常用集合算法
//	学习目标 :
//		·掌握常用的集合算法
//	算法简介 :
//		·set_intersection	// 求两个容器的交集
//		·set_union			// 求两个容器的并集
//		·set_difference	// 求两个容器的差集


// 1.set_intersection
//	功能描述 :
//		·求两个容器的交集
//	函数原型 :
//		·set_intersection(iterator begl, iterator end1, iterator beg2, iterator end2, iterator dest);
//			求两个集合的交集
//			注意:两个集合必须是有序序列
//			beg1 容器1开始选代器
//			end1 容器1结束迭代器
//			beg2 容器2开始选代器
//			end2 容器2结束迭代器
//			dest 目标容器开始选代器


// 2.set union
//	功能描述 :
//		·求两个集合的并集
//	函数原型
//		·set union(iterator begl, iterator end1, iterator beg2, iterator end2, iterator dest);
//			求两个集合的并集
//			注意:两个集合必须是有序序列
//			beg1 容器1开始迭代器
//			end1 容器1结束选代器
//			beg2 容器2开始迭代器
//			end2 容器2结束迭代器
//			dest 目标容器开始选代器


// 3.set difference
//	功能描述 :
//		·求两个集合的差集!
//	函数原型 :
//		·set difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
//			求两个集合的差集
//			注意:两个集合必须是有序序列
//			beg1 容器1开始迭代器
//			end1 容器1结束迭代器
//			beg2 容器2开始迭代器
//			end2 容器2结束迭代器
//			dest 目标容器开始选代器

class myPrint44
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
	vector<int>v2;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	};
	//v1.push_back(3);
	//v2.push_back(3);//无序会出问题

	// 交集
	// 必须有序
	cout << "初始化后：" << endl;
	for_each(v1.begin(), v1.end(), myPrint44());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint44());
	cout << endl;
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v2.begin());
	cout << "交集存放在v2后：" << endl;
	for_each(v1.begin(), v1.end(), myPrint44());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint44());// 发现还是得往新的里塞
	cout << endl;
	cout << "交集存放在vTarget后：" << endl;
	vector<int>vTarget1;
	vTarget1.resize(min(v1.size(), v2.size()));//取小的那个
	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget1.begin());
	// 不然会输出没用的0
	//cout << (*itEnd) << endl;
	for_each(vTarget1.begin(), itEnd, myPrint44());
	cout << endl;

	// 并集
	cout << "并集存放在vTarget后：" << endl;
	vTarget1.resize(v1.size() + v2.size());
	itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget1.begin());
	for_each(vTarget1.begin(), itEnd, myPrint44());
	cout << endl;

	// 差集
	cout << "v1和v2的差集：" << endl;
	vTarget1.resize(max(v1.size(), v2.size()));
	itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget1.begin());
	for_each(vTarget1.begin(), itEnd, myPrint44());
	cout << endl;
	cout << "v2和v1的差集：" << endl;
	vTarget1.resize(max(v1.size(), v2.size()));
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget1.begin());
	for_each(vTarget1.begin(), itEnd, myPrint44());
	cout << endl;
}



int main44()
{
	test01();
	system("pause");
	return 0;
}