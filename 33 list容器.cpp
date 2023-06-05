#include<iostream>
using namespace std;
#include<list>
#include<algorithm>


//	1. list基本概念
//	功能 : 
//		将数据进行链式存储
//	链表(list)是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的
//	链表的组成 : 链表由一系列结点组成
//	结点的组成 : 一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域
//	STL中的链表是一个双向循环链表

//	由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于双向迭代器

//	list的优点 :
//		·采用动态存储分配，不会造成内存浪费和溢出
//		·链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素list的缺点 :
//	list的缺点:
//		·链表灵活，但是空间(指针域)和 时间(遍历)额外耗费较大
// 
//	List有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的.

//	总结: STL中List和vector是两个最常被使用的容器，各有优缺点

void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << endl;
	}
}


//	2. list构造函数
//	功能描述 :
//		·创建list容器
//	函数原型 :
//		list<T> list;			//list采用采用模板类实现,对象的默认构造形式
//		list(beg; end);			//构造函数将[beg,end)区间中的元素拷贝给本身
//		list(n, elem);			//构造函数将n个elem拷贝给本身
//		list(const list& lst);	//拷贝构造函数



//	3. list 赋值和交换
//	功能描述 :
//		·给list容器进行赋值，以及交换list容器
//	函数原型:
//		assign(beg, end);	//将[beg,end)区间中的数据拷贝赋值给本身
//		assign(n, elem);	//将n个elem拷贝赋值给本身。
//		list& operator=(const list& lst);//重载等号操作符
//		swap(lst);			//将lst与本身的元素互换



//	4. list 大小操作
//	功能描述 :
//		·对list容器的大小进行操作
//	函数原型 :
//		size();				//返回容器中元素的个数
//		empty();			//判断容器是否为空
//		resize(num);		//重新指定容器的长度为num，若容器变长，则以默认值填充新位置
							//如果容器变短，则末尾超出容器长度的元素被删除。
//		resize(num, elem);	//重新指定容器的长度为num，若容器变长，则以elem值填充新位置
							//如果容器变短，则末尾超出容器长度的元素被删除



//	5. list 插入和删除
//	功能描述 :
//		·对list容器进行数据的插入和删除
//	函数原型 :
//		push_back(elem);		//在容器尾部加入一个元素
//		pop_back();				//删除容器中最后一个元素。
//		push_front(elem);		//在容器开头插入一个元素
//		pop_front():			//从容开头移除第一个元素
//		insert(pos,elem);		//在pos位置插elem元素的拷贝，返回新数据的位置
//		insert(pos,n,elem);		//在pos位置插入n个elem数据，无返回值
//		insert(pos, beg,end);	//在pos位置插入[beg,end)区间的数据，无返回值.
//		clear();				//移除容器的所有数据
//		erase(beg, end);		//删除[beg,end)区间的数据，返回下一个数据的位置
//		erase(pos);				//删除pos位置的数据，返回下一个数据的位置。
//		remove(elem);			//删除容器中所有与elem值匹配的元素



//	6. list 数据存取
//	功能描述 :
//		·对list容器中数据进行存取
//	函数原型 :
//		front();//返回第一个元素
//		back();	//返回最后一个元素
//	list本质是链表，不是连续线性的内存，所以不能用[]访问
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	//L1[0];//没有[]这种操作
	//	list本质是链表，不是连续线性的内存，所以不能用[]访问
	cout << "第一个元素为：" << L1.front() << endl;
	cout << "最后一个元素为：" << L1.back() << endl;

	// 验证迭代器是不支持随机访问的
	auto it = L1.begin();
	it++;//支持双向
	//it + 1;//酱紫不行，不支持随机访问（判断随机与双向的小技巧）
	cout << "it++ = " << *it << endl;
}



//	7. list 反转和排序
//	功能描述 :
//		·将容器中的元素反转，以及将容器中的数据进行排序
//	函数原型 :
//		reverse();	//反转链表
//		sort();		//链表排序
bool myCompare33(int v1,int v2)// 回调函数
{
	// 降序	就让	第一个数>第二个数
	return v1 > v2;
}
static void test02()
{
	cout << "-------------test02()-------------" << endl;
	list<int>L1;
	L1.push_back(80);
	L1.push_back(50);
	L1.push_back(30);
	L1.push_back(70);
	L1.push_back(20);
	L1.push_back(90);
	L1.push_back(60);
	L1.push_back(10);
	cout << "反转前" << endl;
	printList(L1);
	cout << "反转后" << endl;
	L1.reverse();
	printList(L1);
	cout << "排序后" << endl;
	// 所有不支持随机访问的容器，不可以使用标准算法
	// 不支持随机访问迭代器的容器，内部会提供一些对应算法
	//sort(L1.begin(), L1.end());//这样不行
	L1.sort();//默认升序(会根据量级智能选择算法)
	printList(L1);
	cout << "逆排序后" << endl;
	//ctrl+shift+空格=查看重载信息
	// 重载函数需要提供一个函数或者仿函数（去看19）
	L1.sort(myCompare33);
	printList(L1);
}



// 排序案例
// 案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄和身高
// 规则：按照年龄进行排序(升序)，如果年龄相同按照身高进行排序(降序)
class Person331
{
public:
	Person331(string name, int age, int height)
	{
		m_Name = name;
		m_Age = age;
		m_Height = height;
	}

	string m_Name;
	int m_Age;
	int m_Height;
};
// 指定排序规则
bool myCompare332(Person331 &p1, Person331& p2)// 回调函数
{
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;
	}
	return p1.m_Age < p2.m_Age;
}


static void test03()
{
	cout << "-------------test03()-------------" << endl;
	list<Person331>L1;
	Person331 p1("刘备", 35, 175);
	Person331 p2("曹操", 45, 180);
	Person331 p3("孙权", 40, 170);
	Person331 p4("赵云", 25, 190);
	Person331 p5("张飞", 35, 160);
	Person331 p6("关羽", 35, 200);
	L1.push_back(p1);
	L1.push_back(p2);
	L1.push_back(p3);
	L1.push_back(p4);
	L1.push_back(p5);
	L1.push_back(p6);
	for (list<Person331>::iterator it = L1.begin(); it != L1.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << "\t年龄：" << it->m_Age << "\t身高：" << (*it).m_Height << endl;
	}
	//排序
	cout << "------------------------------" << endl;
	cout << "排序后" << endl;
	L1.sort(myCompare332);
	for (list<Person331>::iterator it = L1.begin(); it != L1.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << "\t年龄：" << it->m_Age << "\t身高：" << (*it).m_Height << endl;
	}
}







int main33()
{
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}