#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>

//	1. deque容器基本概念
//	功能 :
//		·双端数组，可以对头端进行插入删除操作
//	deque与vector区别 :
//		·vector对于头部的插入删除效率低，数据量越大，效率越低
//		·deque相对而言，对头部的插入删除速度回比vector快
//		·vector访问元素时的速度会比deque快, 这和两者内部实现有关
//	deque内部工作原理:
//		deque内部有个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据
//		中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间
//	vertor容器的迭代器是支持随机访问的迭代器


//	2. deque构造函数
//	功能描述
//		·deque容器构造
//	函数原型 :
//		deque <T> deqT;			//默认构造形式
//		deque(beg, end);		//构造函数将[beg,end)区间中的元素拷贝给本身
//		deque(n, elem);			//构造函数将n个elem拷贝给本身。
//		deque(const deque& deg);//拷贝构造函数

//打印容器接口
void printDeque(const deque<int>& d)//加const限定只读，但iterator也必须变为const_iterator
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)//突然发现deque<int>::const_iterator换位auto也可以
	{
		// *it = 100;//容器中的数据不可以修改
		cout << *it << " ";
	}
	cout << endl;
}
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	// 1
	deque<int> d1;
	for (size_t i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	// 2
	deque<int> d2(d1.begin() + 1, d1.end());//左闭右开
	printDeque(d2);
	// 3	n个elem方式构造
	deque<int> d3(10, 100);
	printDeque(d3);
	// 4	拷贝
	deque<int> d4(d3);
	printDeque(d4);
}



//	3. deque赋值操作
//	功能描述 :
//		·给deque容器进行赋值
//	函数原型 :
//		deque & operator=(const deque & deq);	//重载等号操作符
//		assign(beg， end);						//将[beg,end)区间中的数据拷贝赋值给本身
//		assign(n, elem);						//将n个elem拷贝赋值给本身。



//	4. deque大小操作
//	功能描述 :
//		·对deque容器的大小进行操作
//	函数原型 :
//		·deque.empty();			//判断容器是否为空
//		·deque.size();				//返回容器中元素的个数
//		·deque.resize(num);		//重新指定容器的长度为num,若容器变长，则以默认值填充新位置
									//如果容器变短，则末尾超出容器长度的元素被删除
//		·deque.resize(num, elem);	//重新指定容器的长度为num,若容器变长，则以elem值填充新位置
									//如果容器变短，则末尾超出容器长度的元素被删除。
//	注意deque没有容量的概念



//	5. deque 插入和删除
//	功能描述 :
//		·向deque容器中插入和删除数据
//	函数原型 :
//	两端插入操作:
//		push back(elem);	//在容器尾部添加一个数据
//		push front(elem);	//在容头部插入一个数据
//		pop_back();			//删除容器最后一个数据
//		pop_front();		//删除容器第一个数据
//	指定位置操作:
//		insert(pos, elem);		//在pos位置插入一个elem元素的拷贝，返回新数据的位置
//		insert(pos, n, elem);	//在pos位置插入n个elem数据，无返回值
//		insert(pos, beg, end);	//在pos位置插入[beg,end)区间的数据，无返回值
//		clear();				//清空容器的所有数据
//		erase(beg, end);		//删除[beg,end)区间的数据，返回下一个数据的位置
//		erase(pos);				//删除pos位置的数据，返回下一个数据的位置。



//	6. deque 数据存取
//	功能描述 :
//		·对deque 中的数据的存取操作
//	函数原型 :
//		at(int idx);//返回索引idx所指的数据
//		operator[];	//返回索引idx所指的数据
//		front();	//返回容器中第一个数据元素
//		back();		//返回容器中最后一个数据元素



//	7. deque 排序
//	功能描述 :
//		·利用算法实现对deque容器进行排序
//	算法 :
//		sort(iterator beg，iterator end);	//对beg和end区间内元素进行排序
static void test02()
{
	cout << "-------------test02()-------------" << endl;
	// 1
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(60);
	d1.push_front(50);
	d1.push_front(40);
	printDeque(d1);
	//要有#include<algorithm>
	//对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
	// 所以vetcor容器也可以
	sort(d1.begin(), d1.end());//默认升序
	printDeque(d1);
}



int main30()
{
	test01();
	test02();
	system("pause");
	return 0;
}