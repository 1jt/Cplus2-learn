#include<iostream>
using namespace std;
#include<map>

//	1. map基本概念
//	简介 :
//		·map中所有元素都是pair
//		·pair中第一个元素为key(键值)，起到索引作用，第二个元素为value(实值)
//		·所有元素都会根据元素的键值自动排序
//	本质 :
//		·map / multimap属于关联式容器，底层结构是用二叉树实现
// 优点 :
//		·可以根据key值快速找到value值
// map和multimap区别 :
//		·map不允许容器中有重复key值元素
//		·multimap允许容器中有重复key值元素



//	2. map构造和赋值
//	功能描述
//			·对map容器进行构造和赋值操作作
//	函数原型 :
//	构造:
//		map<T1， T2> mp;	//map默认构造函数
//		map(const map& mp);	//拷贝构造函数
//	赋值:
//		map& operator=(const map& mp);//重载等号操作符



//	3. map大小和交换
//	功能描述 :
//		·统计map容器大小以及交换map容器
//	函数原型 :
//	size();		//返回容器中元素的数目
//	empty();	//判断容器是否为空
//	swap(st);	//交换两个集合容器



//	4. map插入和删除
//	功能描述 :
//		·map容器进行插入数据和删除数据
//	函数原型 :
//		insert(elem);	//在容器中插入元素
//		clear();		//清除所有元素
//		erase(pos);		//删除pos迭代器所指的元素，返回下一个元素的迭代器。
//		erase(beg，end);//删除区间[beg,end)的所有元素，返回下一个元素的迭代器
//		erase(key);		//删除容器中值为key的元素。
void printMap(const map<int, int>& m)
{
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << (*it).first << "\t" << it->second << endl;
	}
}
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	map<int, int>m2;
	m2[4] = 40;
	m2.insert(pair<int, int>(5, 50));
	m2.insert(pair<int, int>(6, 60));
	m2.insert(pair<int, int>(7, 70));
	cout << m2[8] << endl;//中括号不建议去插值
	cout << "-------------m-------------" << endl;
	printMap(m);
	cout << "-------------m2-------------" << endl;
	printMap(m2);
	m.swap(m2);
	cout << "-------------m-------------" << endl;
	printMap(m);
	cout << "-------------m2-------------" << endl;
	printMap(m2);
}



//	5. map查找和统计
//	功能描述 :
//		·对map容器进行查找数据以及统计数据
//	函数原型 :
//		find(key);	//查找key是否存在,若存在，返回该键的元素的迭代器;若不存在，返回map.end():
//		count(key);	//统计key的元素个数



//	6. map容器排序
//	学习目标 :
//		·map容器默认排序规则为 按照key值进行 从小到大排序，掌握如何改变排序规则
//	主要技术点 :
//		·利用仿函数，可以改变排序规则
class myCompare35//会调用构造函数所以重载（）
{
public:
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};
static void test02()
{
	cout << "-------------test02()-------------" << endl;
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	map<int, int,myCompare35>m2;
	// 修改规则（要在创建之前制订规则）
	m2[4] = 40;
	m2.insert(pair<int, int>(5, 50));
	m2.insert(pair<int, int>(6, 60));
	m2.insert(pair<int, int>(7, 70));
	for (map<int, int, myCompare35>::const_iterator it = m2.begin(); it != m2.end(); it++)
	{
		cout << (*it).first << "\t" << it->second << endl;
	}

}



int main35()
{
	test01();
	test02();
	system("pause");
	return 0;
}