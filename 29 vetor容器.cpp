#include<iostream>
using namespace std;
#include<vector>

//	1. vector基本概念
//	功能 :
//		·vector数据结构和数组非常相似，也称为单端数组
//	vector与普通数组区别 :
//		·不同之处在于数组是静态空间，而vector可以动态扩展
//	动态扩展 :
//		·并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间(俗称“搬家”)
//			常用迭代器：v.begin()	第一个元素				v.end()	   最后一个元素的后一位
//						v.rend()	第一个元素前一个位置	v.rbegin() 最后一个元素
//		·vertor容器的迭代器是支持随机访问的迭代器



//	2. vector构造函数
//	功能描述 :
//		·创建vector容器
//	函数原型 :
//		vector<T> v; I				//采用模板实现类实现，默认构造函数
//		vector(v.begin()，v.end());	//将v[begin0,end0)区间中的元素拷贝给本身.
//		vector(n, elem);			//构造函数将n个elem拷贝给本身
//		vector(const vector& vec);	//拷贝构造函数

//打印容器接口
void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	// 1
	vector<int> v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	// 2
	vector<int> v2(v1.begin() + 1, v1.end());//左闭右开
	printVector(v2);
	// 3	n个elem方式构造
	vector<int> v3(10, 100);
	printVector(v3);
	// 4	拷贝
	vector<int> v4(v3);
	printVector(v4);
}



//	3.  vector赋值操作
//	功能描述:
//		`给vector容器进行赋值
//	函数原型 :
//		vector& operator=(const vector& vec);	//重载等号操作符
//		assign(beg, end);						//将[beg, end)区间中的数据拷贝赋值给本身
//		assign(n, elem);						//将n个elem拷贝赋值给本身
static void test02()
{
	cout << "-------------test02()-------------" << endl;
	vector<int> v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	vector<int> v2;
	// 1
	v2 = v1;
	printVector(v2);
	// 2
	vector<int> v3;
	v3.assign(v1.begin() + 1, v1.end() + 1);//左闭右开（玩玩嘛）
	printVector(v3);
	// 3
	vector<int> v4;
	v4.assign(10, 100);
	printVector(v4);
}



//	4. vector容量和大小
//	功能描述 :
//		·对vector容器的容量和大小操作
//	函数原型 :
//		empy();					//判断容器是否为空
//		capacity();				//容器的容量
//		size();					//返回容器中元素的个数
//		resize(int num);		//重新指定容器的长度为num，若容器变长，则以默认值填充新位置
//								//如果容器变短，则末尾超出容器长度的元素被删除
//		resize(int num, elem);	//重新指定容器的长度为num，若容器变长，则以elem值填充新位置
								//如果容器变短，则夫尾超出容器长度的元素被删除
static void test03()
{
	cout << "-------------test03()-------------" << endl;
	vector<int> v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	vector<int> v2;
	if (!v1.empty())
	{
		cout << "v1不为空" << endl;
		cout << "v1的容量为" << v1.capacity() << endl;// 可能会预留些位置
		cout << "v1的大小为" << v1.size() << endl;
	}
	// 重新指定大小
	v1.resize(15, 100);
	printVector(v1);
	v1.resize(5);
	printVector(v1);
}



//	5. vector插入和删除
//	功能描述 :
//		·对vector容器进行插入、删除操作
//	函数原型 :
//		push_back(ele);										//尾部插入元素ele
//		pop_back();											//删除最后一个元素
//		insert(const_iterator pos, ele);					//选代器指向位置pos插入元素ele
//		insert(const_iterator pos，int count, ele);			//选代器指向位置pos插入count个元素ele
//		erase(const_iterator pos);							//删除迭代器指向的元素
//		erase(const_iterator start， const iterator end);	//删除选代器从start到end之间的元素
//		clear();											//删除容器中所有元素
static void test04()
{
	cout << "-------------test04()-------------" << endl;
	vector<int> v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	v1.pop_back();
	printVector(v1);
	v1.insert(v1.begin(), 100);
	printVector(v1);
	v1.insert(v1.begin(), 2, 200);
	printVector(v1);
	v1.erase(v1.begin());
	printVector(v1);
	v1.erase(v1.begin() + 1, v1.end() - 1);
	printVector(v1);
	v1.clear();
	printVector(v1);
}



//	6. vector数据存取
//	功能描述 :
//		·对vector中的数据的存取操作
//	函数原型 :
//		at(int idx);	//返回索引idx所指的数据
//		operator[];		//返回索引idx所指的数据
//		front();		//返回容器中第一个数据元素
//		back();			//返回容器中最后一个数据元素
static void test05()
{
	cout << "-------------test05()-------------" << endl;
	vector<int> v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << "v1[i]:" << v1[i] << endl;
	}
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << "v1[i] = " << v1.at(i) << endl;
	}
	cout << "v1.front() = " << v1.front() << endl;
	cout << "v1.back() = " << v1.back() << endl;
}



//	7. vector互换容器
//	功能描述 :
//		·实现两个容器内元素进行互换
//	函数原型 :
//		swap(vec);		// 将vec与本身的元素互换
static void test06()
{
	cout << "-------------test06()-------------" << endl;
	vector<int> v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	vector<int> v3(10, 100);
	printVector(v3);
	// 1
	v1.swap(v3);
	printVector(v1);
	printVector(v3);
	// 2
	swap(v1, v3);
	printVector(v1);
	printVector(v3);
}
// 实际用途
// 巧用swap可以收缩内存空间
static void test07()
{
	cout << "-------------test07()-------------" << endl;
	vector<int> v1;
	for (size_t i = 0; i < 100000; i++)
	{
		v1.push_back(i);
	}
	cout << "v1的容量为" << v1.capacity() << endl;// 发现扩展到13万了
	cout << "v1的大小为" << v1.size() << endl;

	v1.resize(3);
	cout << "v1的容量为" << v1.capacity() << endl;// 发现仍然是13万
	cout << "v1的大小为" << v1.size() << endl;

	//巧用swap收缩内存空间
	vector<int>(v1).swap(v1);//vector<int>(v1)是匿名对象
	//vector<int>(v);会被系统默认为对象声明
	cout << "v1的容量为" << v1.capacity() << endl;
	cout << "v1的大小为" << v1.size() << endl;
}



//	8. vector预留空间
//	功能描述 :
//		·减少vector在动态扩展容量时的扩展次数
//	函数原型 :
//		reserve(int len);	//容器预留len个元素长度，预留位置不初始化，元素不可访问。
static void test08()
{
	cout << "-------------test08()-------------" << endl;
	vector<int> v1;
	int num = 0;//统计开辟次数
	int* p = NULL;
	for (size_t i = 0; i < 100000; i++)
	{
		v1.push_back(i);
		if (p != &v1[0])
		{
			p = &v1[0];
			num++;
		}
	}
	cout << "v1的容量为" << v1.capacity() << endl;// 发现扩展到13万了
	cout << "v1的大小为" << v1.size() << endl;
	cout << "num = " << num << endl;// 分配了30次
	// 利用reserve预留空间
	vector<int> v2;
	v2.reserve(100000);
	num = 0;//统计开辟次数
	p = NULL;
	for (size_t i = 0; i < 100000; i++)
	{
		v2.push_back(i);
		if (p != &v2[0])
		{
			p = &v2[0];
			num++;
		}
	}
	cout << "v2的容量为" << v2.capacity() << endl;// 容量就是100000
	cout << "v2的大小为" << v2.size() << endl;
	cout << "num = " << num << endl;//就分配一次
	
}


int main29()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	system("pause");
	return 0;
}