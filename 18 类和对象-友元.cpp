#include<iostream>
using namespace std;

/*
			友元
*/


// 生活中你的家有客厅(Public)，有你的卧室(Private)
// 客厅所有来的客人都可以进去，但是你的卧室是私有的，也就是说只有你能进去
// 但是呢，你也可以允许你的好闺蜜好基友进去。
// 
// 在程序里，有些私有属性 也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术
// 
// 友元的目的就是让一个函数或者类 访问另一个类中私有成员
//
// 友元的关键字为 friend
//
// 友元的三种实现
//		全局函数做友元
//		类做友元
//		成员函数做友元



// 全局函做友元
class Building
{
	//goodGay全局函数是Building的好朋友，可以访问Building中私有成员
	friend void goodGay(Building* building);

	//goodGay2是本类的好朋友，可以访问Building中私有成员
	friend class goodGay2;

	// 告诉编译器，goodGay3类下的visit成员函数作为本类的好朋友，可以访问私有成员
	//friend void goodGay3::visit();
	// Building类先声明是因为Goodgay类里会用到，Building类滞后Goodgay类的原因是Building类中会利用friend对Goodgay中的成员函数声明
public:
	Building()//一般是类内声明，类外实现
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}

	string m_SittingRoom; //客厅

private:
	string m_BedRoom; //卧室
};
// 全局函数
void goodGay(Building *building)
{
	cout << "好基友的全局函数 正在访问：" << building->m_SittingRoom << endl;//公共函数随便访问

	cout << "好基友的全局函数 正在访问：" << building->m_BedRoom << endl;//friend访问私有成员
}
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	Building building;
	goodGay(&building);
}



// 类做友元
class goodGay2
{
public:
	goodGay2();//一般是类内声明，类外实现
	void visit();//参观函数 访问Building中的属性

	Building* building;

private:

};
goodGay2::goodGay2()
{
	// 创建建筑物对象
	building = new Building;
}
void goodGay2::visit()
{
	cout << "好基友2正在访问：" << building->m_SittingRoom << endl;

	cout << "好基友2正在访问：" << building->m_BedRoom << endl;
}
static void test02()
{
	cout << "-------------test02()-------------" << endl;
	goodGay2 gg;
	gg.visit();
}



// 成员函数做友元
// Building2类先声明是因为Goodgay3类里会用到
class Building2;													//1
class goodGay3
{
public:
	goodGay3();
	void visit();// 让visit函数可以访问Building中的私有成员
	void visit2();// 让visit2函数 不 可以访问Building中的私有成员

	Building2* building;											//2

private:

};

// Building2类滞后Goodgay3类的原因是Building类中会利用friend对Goodgay3中的成员函数声明
class Building2
{
	// 告诉编译器，goodGay3类下的visit成员函数作为本类的好朋友，可以访问私有成员
	friend void goodGay3::visit();									//3
public:
	Building2()//一般是类内声明，类外实现
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}

	string m_SittingRoom; //客厅

private:
	string m_BedRoom; //卧室
};

// 比如在Building2定义之后写构造函数，不然不知道怎么构造出Building2（因为会不知道定义，顺序真的很重要）
goodGay3::goodGay3()
{
	// 创建建筑物对象
	building = new Building2;										//4
}
void goodGay3::visit()
{
	cout << "visit函数正在访问：" << building->m_SittingRoom << endl;
	cout << "visit函数正在访问：" << building->m_BedRoom << endl;
}
void goodGay3::visit2()
{
	cout << "visit2函数正在访问：" << building->m_SittingRoom << endl;
	//cout << "visit2函数正在访问：" << building->m_BedRoom << endl; // 不是好朋友不可以访问
}




static void test03()
{
	cout << "-------------test03()-------------" << endl;
	goodGay3 gg;
	gg.visit();
	gg.visit2();
}


int main18()
{
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}