#include<iostream>
using namespace std;
#include"Circle.h"
#include"Point.h"

/*
C++面向对象的三大特性为：
		封装
		继承
		多态
*/
/*
C++认为万事万物皆为对象，对象上有其属性和行为

具有相同性质的对象，我们可以抽象为 类
*/

/*
			封装

封装的意义：
1. 将属性和行为作为一个整体，表现生活中的事物
2. 将属性和行为加以权限控制
*/
// 1. 在设计类的时候，属性和行为写在一起，表现事物
// 语法：class 类名{访问权限：属性/行为};
// 
// 设计一个圆类，求圆的周长
// 2 * PI * 半径
// 圆周率
const double PI = 3.1415926;

class CirclE
{
	//访问权限
	// public	 公共权限	类内可以访问，类外可以访问
	// protected 保护权限	类内可以访问，类外不可以访问 儿子也可以访问父亲中的保护内容
	// private	 私有权限	类内可以访问，类外不可以访问 儿子不可以访问父亲中的保护内容

public://公共权限

	//类中的属性和行为，我们统一称为 成员
	// 属性		成员属性 成员变量
	// 行为		成员函数 成员方法
	//属性
	int m_r;

	//行为
	//获取圆的周长
	double calcuateZC()
	{
		return 2 * PI * m_r;
	}
};

class Student
{
public:
	string m_Name;
	int m_Id;

	void showStudent()
	{
		cout << "姓名：" << m_Name << "\t学号：" << m_Id << endl;
	}
	void setName(string name)
	{
		m_Name = name;
	}
	void setId(int id)
	{
		m_Id = id;
	}
};

// 权限
class Person
{
public:// 公共权限
	string m_Name;

protected:// 保护权限
	string m_Car;

private:// 私有权限
	int m_Password;

public:
	void func()
	{
		m_Name = "张三";
		cout << m_Name << endl;
		//m_Car = "拖拉机";
		//cout << m_Car << endl;//不可以通过public行为访问protected内容
		m_Password = 123456;
		cout << m_Password << endl;
	}
};


// struct和class区别
// 唯一区别在于 默认的访问权限不同
// struct默认权限为公共public
// class 默认权限为私有private
class C1
{
	int m_A; //默认权限 私有
};
struct C2
{
	int  m_A; //默认权限 公共
};


// 成员属性设置为私有
// 优点：
// 1. 将所有成员属性设置为私有，可以自己控制读写权限
// 2. 对于写权限，我们可以检测数据的有效性
class People//多个源文件的注意，类名不能和其他源文件的类名相同哦。
{
public:
	//设置姓名
	void setName(string name)
	{
		m_Name = name;
	}
	//获取姓名
	string getName()
	{
		return m_Name;
	}
	//获取年龄 只读
	int getAge()
	{
		m_Age = 0;//不初始化会有乱码
		return m_Age;
	}
	//设置情人 只写
	void setLover(string lover)
	{
		m_Lover = lover;
	}

private:
	string m_Name;// 可读可写
	int m_Age;// 只读
	string m_Lover;// 只写
};
// 2. 对于写权限，我们可以检测数据的有效性
class People2
{
public:
	//设置姓名
	void setName(string name)
	{m_Name = name;}
	//获取姓名
	string getName()
	{return m_Name;}
	//获取年龄 可读可写 如果想修改，年龄的范围必须是0 ~ 150之间
	int getAge()
	{
		return m_Age;
	}
	//设置年龄
	void setAge(int Age)
	{
		if (Age < 0 || Age>150)
		{
			m_Age = 0;//否则会有乱码
			cout << "你这个老妖精！" << endl;
			return;
		}
		m_Age = Age;
	}
	//设置情人 只写
	void setLover(string lover)
	{m_Lover = lover;}
private:
	string m_Name;// 可读可写
	int m_Age;// 可读可写
	string m_Lover;// 只写
};



// 点和圆的关系案例
// 圆上，圆外，圆内

//class Point
//{
//public:
//	void setX(int x)
//	{
//		m_X = x;
//	}
//	int getX()
//	{
//		return m_X ;
//	}
//	void setY(int y)
//	{
//		m_Y = y;
//	}
//	int getY()
//	{
//		return m_Y;
//	}
//
//private:
//	int m_X;
//	int m_Y;
//};

////圆类
//class Circle
//{
//public:
//	void setR(int r)
//	{
//		m_R = r;
//	}
//	int getR()
//	{
//		return m_R;
//	}
//	void setCenter(Point center)
//	{
//		m_Center = center;
//	}
//	Point getCenter()
//	{
//		return m_Center;
//	}
//
//private:
//	int m_R;
//
//	// 在类中可以让另一个类作为本类中的成员
//	Point m_Center;//圆心
//};
// 判断关系
void isInCircle(Circle &c,Point &p)
{
	int distance =
		(c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	int rDistance = c.getR() * c.getR();
	if (distance==rDistance)
	{
		cout << "点在圆上" << endl;
	}
	else if(distance > rDistance)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
}


int main14()
{
	//实例化（通过一个类，创建一个对象）
	CirclE c1;
	c1.m_r = 10;
	cout << "圆的周长为：" << c1.calcuateZC() << endl;

	Student s1;
	s1.m_Name = "张三";
	s1.m_Id = 1;
	s1.showStudent();
	Student s2;
	s2.setName("李四");
	s2.setId(2);
	s2.showStudent();

	Person p1;
	p1.m_Name = "李四";
	//p1.m_Car = "奔驰";//保护权限内容，在类外访问不到
	//p1.m_Password = 654321;//私有权限内容，在类外访问不到
	p1.func();//不可以通过public行为访问protected内容


	// struct和class区别
	C1 cc1;
	// cc1.m_A = 100; //戳啦
	C2 cc2;
	cc2.m_A = 100;


	// 成员属性设置为私有
	// 优点：
	// 1. 将所有成员属性设置为私有，可以自己控制读写权限
	// 2. 对于写权限，我们可以检测数据的有效性
	People p;
	p.setName("张三");
	cout << "姓名为：" << p.getName() << endl;
	cout << "年龄为：" << p.getAge() << endl;
	p.setLover("苍井");
	People2 p2;
	p2.setName("张三");
	cout << "姓名为：" << p2.getName() << endl;
	p2.setAge(10000);
	cout << "年龄为：" << p2.getAge() << endl;
	p2.setLover("苍井");


	// 圆和点的关系
	Circle C;
	Point Center;
	C.setR(10);
	Center.setX(10);
	Center.setY(0);
	C.setCenter(Center);

	Point P;
	P.setX(10);
	P.setY(10);
	
	isInCircle(C, P);

	system("pause");
	return 0;
}