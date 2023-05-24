#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>// 标准算法头文件

//	1. STL的诞生
//		·长久以来，软件界一直希望建立一种可重复利用的东西
//		·C++的面向对象和泛型编程思想，目的就是复用性的提升
//		·大多情况下，数据结构和算法都未能有一套标准, 导致被迫从事大量重复工作
//		·为了建立数据结构和算法的一套标准诞生了STL
//
// 
//	2. STL基本概念
//		·STL(Standard Template Library, 标准模板库)
//		·STL从广义上分为: 容器(container)算法(algorithm) 选代器(iterator)
//		·容器和算法之间通过迭代器进行无缝连接
//		·STL几乎所有的代码都采用了模板类或者模板函数
// 
// 
//	3. STL六大组件
//	  STL大体分为六大组件，分别是 : 容器、算法、迭代器、仿函数、适配器(配接器)、空间配置器
//		1.容器 : 各种数据结构，如vector、list、deque、set、map等, 用来存放数据
//		2.算法 : 各种常用的算法，如sort、find、copy、for_each等
//		3.选代器 : 扮演了容器与算法之间的胶合剂。
//		4.仿函数 : 行为类似函数，可作为算法的某种策略
//		5.适配器 : 一种用来修饰容器或者仿函数或迭代器接口的东西。
//		6.空间配置器 : 负责空间的配置与管理
// 
// 
//	4. STL中容器、算法、迭代器
// 
//	容器 : 置物之所也
//	STL容器就是将运用最广泛的一些数据结构实现出来
//	常用的数据结构 : 数组, 链表, 树, 栈队列, 集合, 映射表等
//	这些容器分为序列式容器和关联式容器两种 :
//		·序列式容器 : 强调值的排序，序列式容器中的每个元素均有固定的位置
//		·关联式容器 : 二叉树结构，各元素之间没有严格的物理上的顺序关系
//	
//	算法 : 问题之解法也
//	有限的步骤，解决逻辑或数学上的问题，这一门学科我们叫做算法(Algorithms)
//	算法分为 : 质变算法和非质变算法
//		·质变算法 : 是指运算过程中会更改区间内的元素的内容。例如拷贝，替换，删除等等
//		·非质变算法:是指运算过程中不会更改区间内的元素内容，例如查找、计数、遍历、寻找极值等等
//
//	迭代器:容器和算法之间粘合剂
//	提供一种方法，使之能够依序寻访某个容器所合的各个元素，而又无需暴露该容器的内部表示方式
//	每个容器都有自己专属的迭代器
//	迭代器使用非常类似于指针，初学阶段我们可以先理解迭代器为指针
// 
//	迭代器种类:
//		种类				功能										支持运算
//	输入迭代器			对数据的只读访问							只读，支持++、 == 、 !=
//	输出迭代器			对数据的只写访问							只写, 支持++
//	前向迭代器			读写操作，并能向前推进迭代器				读写, 支持++、 == 、!=
//	双向迭代器			读写操作，并能向前和向后操作				读写，支持++、--，
//	随机访问迭代器		读写操作，可以以跳跃的方式访问任意数据，	读写，支持++、-- 、[n]、 - n、<、
//						功能最强的迭代器									<= 、>、 >=
//
//	常用的容器中迭代器种类为双向迭代器，和随机访问迭代器
//
//
//	5. 容器算法迭代器初识
//	了解STL中容器、算法、迭代器概念之后，我们利用代码感受STL的魅力
//	STL中最常用的容器为Vetor，可以理解为数组，下面我们将学习如何向这个容器中插入数据、并遍历这个容器
//		5.1 vector存放内置数据类型
//		容器 : vector
//		算法 : for_each
//		迭代器 : vector<int>::iterator
void myPrint271(int val)
{
	cout << val << endl;
}

static void test01()
{
	cout << "-------------test01()-------------" << endl;
	// 创建一个vector容器（可以理解为数组）
	vector<int> v;

	// 向容器中插入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	// 通过迭代器访问容器中的数据
	vector<int>::iterator itBegin = v.begin();// 起始迭代器，指向容器中第一个元素
	vector<int>::iterator itEnd = v.end();// 结束迭代器，指向容器中最后一个元素的下一个

	// 第一种遍历方式
	while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}

	// 第二种遍历方式
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	// 第三种遍历方式，利用STL提供的遍历算法
	//	回调函数
	//	我是富君：回调函数可以理解为，把整个函数当做一个参数放进去，for_each(v.begin(), v, end(), 函数体)，
	//	不要觉得STL麻烦，算法麻烦，这都是提高运行速度，空间内存的利用问题
	for_each(v.begin(),v.end(),myPrint271);
}



//		5.2 vector存放自定义数据类型
class Person271
{
public:
	Person271() {};
	Person271(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	string m_Name;
	int m_Age;
};
static void test02()
{
	cout << "-------------test02()-------------" << endl;
	vector<Person271>v;
	Person271 p1("孙悟空", 999);
	Person271 p2("韩信", 20);
	Person271 p3("妲己", 18);
	Person271 p4("赵云", 25);
	Person271 p5("安琪拉", 27);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	for (vector<Person271>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << endl;
		cout << "姓名：" << it->m_Name << endl;
		cout << "年龄：" << (*it).m_Age << endl;
		cout << "年龄：" << it->m_Age << endl;
	}
}
// 存放自定义数据类型的指针
static void test03()
{
	cout << "-------------test03()-------------" << endl;
	vector<Person271*>v;
	Person271 p1("孙悟空", 999);
	Person271 p2("韩信", 20);
	Person271 p3("妲己", 18);
	Person271 p4("赵云", 25);
	Person271 p5("安琪拉", 27);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	// 遍历容器
	for (vector<Person271*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it)->m_Name << endl;
		cout << "年龄：" << (*it)->m_Age<< endl;
	}
}



//		5.3 vector容器嵌套容器
// 类似n维数组
static void test04()
{
	cout << "-------------test04()-------------" << endl;
	vector<vector<int>>v;
	// 创建小容器
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	vector<int>v5;

	// 向小容器中添加数据
	for (size_t i = 0; i < 22; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
		v5.push_back(i + 5);
	}
	// 小容器插入到大容器中
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);
	// 遍历数据
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		// (*it)是容器
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << "\t";
		}
		cout << endl;
	}
}


int main27()
{
	test01();
	test02();
	test03();
	test04();
	system("pause");
	return 0;
}