#include<iostream>
#include<set>
using namespace std;

//	1. set基本概念
//	简介 :
//		·所有元素都会在插入时自动被排序
//	本质 :
//		·set / multiset属于关联式容器，底层结构是用二叉树实现
//	set和multiset区别
//		·set不允许容器中有重复的元素
//		·multiset允许容器中有重复的元素
 
 

//	2. set构造和赋值
//	功能描述 : 
//		·创建set容器以及赋值
//	构造:
//		set<T> st;			//默认构造函数:
//		set(const set& st);	//拷贝构造函数
//	赋值:
//		set& operator=(const set& st);	//重载等号操作符
void printSet(const set<int> &st)
{
	for (set<int>::const_iterator it = st.begin(); it != st.end(); it++)
	{
		cout << (*it) << " ";
	}
	cout << endl;
}
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	set<int>s1;
	// 插入数据只有insert的方式
	s1.insert(50);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	s1.insert(10);
	s1.insert(10);// 自动报错+无法插入重复的(插了白插)
	printSet(s1);
	set<int>s2(s1);
	printSet(s2);
}



//	3. set大小和交换
//	功能描述 :
//		·统计set容器大小以及交换set容器
//	函数原型 :
//		size();		//返回容器中元素的数目
//		empty();	//判断容器是否为空
//		swap(st);	//交换两个集合容器



//	4. set插入和删除
//	功能描述 :
//		·set容器进行插入数据和删除数据
//	函数原型
//		insert(elem);	//在容器中插入元素
//		clear();		//清除所有元素
//		erase(pos);		//删除pos迭代器所指的元素，返回下一个元素的迭代器
//		erase(beg,end);	//删除区间[beg,end)的所有元素，返回下一个元素的迭代器
//		erase(elem);	//删除容器中值为elem的元素



//	5. set查找和统计
//	功能描述 :
//		·对set睿器进行查找数据以及统计数据
//	函数原型 :
//		find(key);	//查找key是否存在,若存在，返回该键的元素的迭代器;若不存在，返回set.end():
//		count(key);	//统计key的元素个数



//	6. set和multiset区别
//	学习目标 :
//		·掌握set和multiset的区别
//	区别 :
//		·set不可以插入重复数据，而multiset可以
//		·set插入数据的同时会返回插入结果，表示插入是否成功multiset不会检测数据，因此可以插入重复数据
void printMultiSet(const multiset<int>& st)
{
	for (multiset<int>::const_iterator it = st.begin(); it != st.end(); it++)
	{
		cout << (*it) << " ";
	}
	cout << endl;
}
static void test02()
{
	cout << "-------------test02()-------------" << endl;
	set<int>s1;
	// 插入数据只有insert的方式
	pair<set<int>::iterator, bool> ret = s1.insert(10);
	if (ret.second)
	{
		cout << "第一次插入成功" << endl;
	}
	else
	{
		cout << "第一次插入成失败" << endl;
	}
	ret = s1.insert(10);
	if (ret.second)
	{
		cout << "第二次插入成功" << endl;
	}
	else
	{
		cout << "第二次插入失败" << endl;
	}
	printSet(s1);

	multiset<int>s2;
	s2.insert(10);
	s2.insert(10);
	printMultiSet(s2);
}



//	7. pair对组创建
//	功能描述 :
//		·成对出现的数据，利用对组可以返回两个数据
//	两种创建方式 :
//		pair<type, type> p(value1, value2);
//		pair<type, type> p = make_pair(value1, value2);
static void test03()
{
	cout << "-------------test03()-------------" << endl;
	// 1
	pair<string, int>p1("Tom", 20);
	cout << "姓名：" << p1.first << "\t年龄：" << p1.second << endl;
	// 2 
	pair<string, int>p2 = make_pair("Jerry", 30);
	cout << "姓名：" << p2.first << "\t年龄：" << p2.second << endl;
}



//	8. set容器排序 I
//	学习目标 :
//		·set容器默认排序规则为从小到大，掌握如何改变排序规则
// 主要技术点:
//		·利用仿函数，可以改变排序规则
class myCompare34//会调用构造函数所以重载（）
{
public:
	//vs2019中重载（）记得加个const   如bool  operator()(int x, int y) const
	//任意修改它所在的类的成员的操作都是不允许的（因为隐含了对this指针的const引用）；
	bool operator()(int v1, int v2) const//报错的话 得在仿函数后面加一个const
	{
		//cout << "ljt" << endl;
		//仿函数不是数据类型，可以在operator()里面加入一个输出语句
		//它会输出所有值，也就是说，它插入的时候遍历了这个容器，提供的这个返回真插在前面
		return v1 > v2;
	}
};
// 1. set排序内置数据类型
static void test04()
{
	cout << "-------------test04()-------------" << endl;
	set<int>s1;
	s1.insert(50);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	s1.insert(10);
	printSet(s1);

	// 修改规则（要在创建之前制订规则）
	set<int,myCompare34>s2;//得写为set<类型>，即里面必须得是一个类型，不能放函数，而仿函数本质上是一个类型！！
	//仿函数本质是类，但是功能上却是方法
	//会调用构造函数所以重载()
	s2.insert(50);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);
	s2.insert(10);
	for (set<int, myCompare34>::const_iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << (*it) << " ";
	}
	cout << endl;
}

// 2. set排序自定义数据类型
class Person341
{
public:
	Person341(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	string m_Name;
	int m_Age;
};
class myCompare342
{
public:
	bool operator()(const Person341& p1, const Person341& p2) const
	{
		// 按照年龄，降序
		return p1.m_Age > p2.m_Age;
	}
};
static void test05()
{
	cout << "-------------test05()-------------" << endl;
	// 自定义数据类型，都会指定排序规则
	set<Person341,myCompare342>s1;
	Person341 p1("刘备", 35);
	Person341 p2("曹操", 45);
	Person341 p3("孙权", 15);
	Person341 p4("赵云", 25);
	Person341 p5("张飞", 33);
	Person341 p6("关羽", 34);
	//如果没有排序规则也就不知道怎么插入
	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);
	s1.insert(p5);
	s1.insert(p6);
	//如果没有排序规则也就无法排序
	for (set<Person341, myCompare342>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << "\t年龄：" << it->m_Age << endl;
	}
	cout << endl;
	

}
int main34()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	system("pause");
	return 0;
}