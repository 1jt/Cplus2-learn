#include<iostream>
using namespace std;
#include"Circle.h"
#include"Point.h"

/*
C++����������������Ϊ��
		��װ
		�̳�
		��̬
*/
/*
C++��Ϊ���������Ϊ���󣬶������������Ժ���Ϊ

������ͬ���ʵĶ������ǿ��Գ���Ϊ ��
*/

/*
			��װ

��װ�����壺
1. �����Ժ���Ϊ��Ϊһ�����壬���������е�����
2. �����Ժ���Ϊ����Ȩ�޿���
*/
// 1. ��������ʱ�����Ժ���Ϊд��һ�𣬱�������
// �﷨��class ����{����Ȩ�ޣ�����/��Ϊ};
// 
// ���һ��Բ�࣬��Բ���ܳ�
// 2 * PI * �뾶
// Բ����
const double PI = 3.1415926;

class CirclE
{
	//����Ȩ��
	// public	 ����Ȩ��	���ڿ��Է��ʣ�������Է���
	// protected ����Ȩ��	���ڿ��Է��ʣ����ⲻ���Է��� ����Ҳ���Է��ʸ����еı�������
	// private	 ˽��Ȩ��	���ڿ��Է��ʣ����ⲻ���Է��� ���Ӳ����Է��ʸ����еı�������

public://����Ȩ��

	//���е����Ժ���Ϊ������ͳһ��Ϊ ��Ա
	// ����		��Ա���� ��Ա����
	// ��Ϊ		��Ա���� ��Ա����
	//����
	int m_r;

	//��Ϊ
	//��ȡԲ���ܳ�
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
		cout << "������" << m_Name << "\tѧ�ţ�" << m_Id << endl;
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

// Ȩ��
class Person
{
public:// ����Ȩ��
	string m_Name;

protected:// ����Ȩ��
	string m_Car;

private:// ˽��Ȩ��
	int m_Password;

public:
	void func()
	{
		m_Name = "����";
		cout << m_Name << endl;
		//m_Car = "������";
		//cout << m_Car << endl;//������ͨ��public��Ϊ����protected����
		m_Password = 123456;
		cout << m_Password << endl;
	}
};


// struct��class����
// Ψһ�������� Ĭ�ϵķ���Ȩ�޲�ͬ
// structĬ��Ȩ��Ϊ����public
// class Ĭ��Ȩ��Ϊ˽��private
class C1
{
	int m_A; //Ĭ��Ȩ�� ˽��
};
struct C2
{
	int  m_A; //Ĭ��Ȩ�� ����
};


// ��Ա��������Ϊ˽��
// �ŵ㣺
// 1. �����г�Ա��������Ϊ˽�У������Լ����ƶ�дȨ��
// 2. ����дȨ�ޣ����ǿ��Լ�����ݵ���Ч��
class People//���Դ�ļ���ע�⣬�������ܺ�����Դ�ļ���������ͬŶ��
{
public:
	//��������
	void setName(string name)
	{
		m_Name = name;
	}
	//��ȡ����
	string getName()
	{
		return m_Name;
	}
	//��ȡ���� ֻ��
	int getAge()
	{
		m_Age = 0;//����ʼ����������
		return m_Age;
	}
	//�������� ֻд
	void setLover(string lover)
	{
		m_Lover = lover;
	}

private:
	string m_Name;// �ɶ���д
	int m_Age;// ֻ��
	string m_Lover;// ֻд
};
// 2. ����дȨ�ޣ����ǿ��Լ�����ݵ���Ч��
class People2
{
public:
	//��������
	void setName(string name)
	{m_Name = name;}
	//��ȡ����
	string getName()
	{return m_Name;}
	//��ȡ���� �ɶ���д ������޸ģ�����ķ�Χ������0 ~ 150֮��
	int getAge()
	{
		return m_Age;
	}
	//��������
	void setAge(int Age)
	{
		if (Age < 0 || Age>150)
		{
			m_Age = 0;//�����������
			cout << "�������������" << endl;
			return;
		}
		m_Age = Age;
	}
	//�������� ֻд
	void setLover(string lover)
	{m_Lover = lover;}
private:
	string m_Name;// �ɶ���д
	int m_Age;// �ɶ���д
	string m_Lover;// ֻд
};



// ���Բ�Ĺ�ϵ����
// Բ�ϣ�Բ�⣬Բ��

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

////Բ��
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
//	// �����п�������һ������Ϊ�����еĳ�Ա
//	Point m_Center;//Բ��
//};
// �жϹ�ϵ
void isInCircle(Circle &c,Point &p)
{
	int distance =
		(c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	int rDistance = c.getR() * c.getR();
	if (distance==rDistance)
	{
		cout << "����Բ��" << endl;
	}
	else if(distance > rDistance)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
	}
}


int main14()
{
	//ʵ������ͨ��һ���࣬����һ������
	CirclE c1;
	c1.m_r = 10;
	cout << "Բ���ܳ�Ϊ��" << c1.calcuateZC() << endl;

	Student s1;
	s1.m_Name = "����";
	s1.m_Id = 1;
	s1.showStudent();
	Student s2;
	s2.setName("����");
	s2.setId(2);
	s2.showStudent();

	Person p1;
	p1.m_Name = "����";
	//p1.m_Car = "����";//����Ȩ�����ݣ���������ʲ���
	//p1.m_Password = 654321;//˽��Ȩ�����ݣ���������ʲ���
	p1.func();//������ͨ��public��Ϊ����protected����


	// struct��class����
	C1 cc1;
	// cc1.m_A = 100; //����
	C2 cc2;
	cc2.m_A = 100;


	// ��Ա��������Ϊ˽��
	// �ŵ㣺
	// 1. �����г�Ա��������Ϊ˽�У������Լ����ƶ�дȨ��
	// 2. ����дȨ�ޣ����ǿ��Լ�����ݵ���Ч��
	People p;
	p.setName("����");
	cout << "����Ϊ��" << p.getName() << endl;
	cout << "����Ϊ��" << p.getAge() << endl;
	p.setLover("�Ծ�");
	People2 p2;
	p2.setName("����");
	cout << "����Ϊ��" << p2.getName() << endl;
	p2.setAge(10000);
	cout << "����Ϊ��" << p2.getAge() << endl;
	p2.setLover("�Ծ�");


	// Բ�͵�Ĺ�ϵ
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