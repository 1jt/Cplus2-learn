#include<iostream>
using namespace std;
// ��һ�ֽ����ʽ��ֱ�Ӱ���Դ�ļ�
//#include"Person267.cpp"

// �ڶ��ֽ����ʽ����.h��.cpp�е�����д��һ�𣬽���׺��Ϊ.hpp��һ����֪������ģ�壩
#include"Person267.hpp"
#include"MyArray.hpp"

//��ģ��

// ��ģ������ :
//	����һ��ͨ���࣬���еĳ�Ա���������Ϳ��Բ������ƶ�������һ�����������������
//
// �﷨ :
//	template<typename T>
//	��
//
// ���� :
//	template --- ��������ģ��
//	typename --- ���������ķ�����һ���������ͣ�������class����
//		T	 --- ͨ�õ��������ͣ����ƿ����滻��ͨ��Ϊ��д��ĸ

template<class NameType,class AgeType>
class Person261
{
public:
	Person261(NameType name, AgeType age)
	{
		m_Name = name;
		m_Age = age;
	}
	void showPerson()
	{
		cout << "name:" << m_Name << endl;
		cout << "age:" << m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;

};
static	void test01()
{
	cout << "-------------test01()-------------" << endl;
	Person261<string, int> p1("�����", 99);
	p1.showPerson();
}



// ��ģ���뺯��ģ������
//	��ģ���뺯��ģ��������Ҫ������
//		1. ��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
//		2. ��ģ����ģ������б��п�����Ĭ�ϲ���
template<class NameType, class AgeType = int>
class Person262
{
public:
	Person262(NameType name, AgeType age)
	{
		m_Name = name;
		m_Age = age;
	}
	void showPerson()
	{
		cout << "name:" << m_Name << endl;
		cout << "age:" << m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};
static	void test02()
{
	cout << "-------------test02()-------------" << endl;

	//	1. ��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
	//Person262 p1("�����", 99); // ����
	Person262<string, int> p1("�����", 1000);// ֻ������ʾָ������
	p1.showPerson();

	//	2. ��ģ����ģ������б��п�����Ĭ�ϲ���
	Person262<string> p2("��˽�", 999);// ֻ������ʾָ������
	p2.showPerson();
}



// ��ģ���г�Ա��������ʱ��

// ��ģ���г�Ա��������ͨ���г�Ա��������ʱ�����������
//	1. ��ͨ���еĳ�Ա����һ��ʼ�Ϳ��Դ���
//	2. ��ģ���еĳ�Ա�����ڵ���ʱ�Ŵ���
// �ڵ��ý׶βŴ�����Ϊ�˱�֤ģ���ͨ����
class Person263
{
public:
	void showPerson1()
	{
		cout << "Person263 show"<< endl;
	}
};
class Person264
{
public:
	void showPerson2()
	{
		cout << "Person264 show" << endl;
	}
};
template<class T>
class MyClass261
{
public:
	T obj;

	// ��ģ���еĳ�Ա����
	// ֻҪ�����þͲ��ᴴ��
	void func1()
	{
		obj.showPerson1();
	}
	void func2()
	{
		obj.showPerson2();
	}
};
static	void test03()
{
	cout << "-------------test03()-------------" << endl;
	MyClass261<Person263>m1;
	m1.func1();
	//m1.func2();// ����
	MyClass261<Person264>m2;
	m2.func2();
}



// ��ģ���������������

// ѧϰĿ��:
// ����ģ��ʵ�������Ķ����������εķ�ʽ

// �������ִ��뷽ʽ
//	1. ָ�����������	--- ֱ����ʾ�������������
//	2. ����ģ�廯		--- �������еĲ�����Ϊģ����д���
//	3. ������ģ�廯		--- ������������� ģ�廯���д���
// ��һ�����
// �����е�����ģ�������ģ��
template<class T1,class T2>
class Person265
{
public:
	Person265(T1 name, T2 age)
	{
		m_Name = name;
		m_Age = age;
	}
	void showPerson()
	{
		cout << "name:" << m_Name << endl;
		cout << "age:" << m_Age << endl;
	}
	T1 m_Name;
	T2 m_Age;
};
//	1. ָ�����������	--- ֱ����ʾ�������������
void printPerson265(Person265<string, int>& p)
{
	p.showPerson();
}
//	2. ����ģ�廯		--- �������еĲ�����Ϊģ����д���
template<class T1, class T2>
void printPerson265_2(Person265<T1, T2>& p)
{
	p.showPerson();
	cout << "T1������Ϊ:" << typeid(T1).name() << endl;
	cout << "T2������Ϊ:" << typeid(T2).name() << endl;
}
//	3. ������ģ�廯		--- ������������� ģ�廯���д���
template<class T>
void printPerson265_3(T &p)
{
	p.showPerson();
	cout << "T������Ϊ:" << typeid(T).name() << endl;
}
static	void test04()
{
	cout << "-------------test04()-------------" << endl;
	Person265<string, int> p1("�����", 100);
	printPerson265(p1);

	//	2. ����ģ�廯		--- �������еĲ�����Ϊģ����д���
	Person265<string, int> p2("��˽�", 99);
	printPerson265_2(p2);

	//	3. ������ģ�廯		--- ������������� ģ�廯���д���
	Person265<string, int> p3("��ɮ", 18);
	printPerson265_3(p3);
}



// ��ģ����̳�

// ����ģ�������̳�ʱ����Ҫע��һ�¼���:
//	1. ������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ����������T������
//  2. �����ָ�����������޷�����������ڴ�
//	3. ��������ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��
template<class T>
class Base261
{
	T m;
};
//	1. ������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ����������T������
//  2. �����ָ�����������޷�����������ڴ�
//class Son261 :public Base261// ���󣬱���֪�������е�T���ͣ����ܼ̳и�����
class Son261 :public Base261<int> 
{

};
//	3. ��������ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��
template<class T1,class T2>
class Son262 :public Base261<T2>
{
public:
	Son262()
	{
		cout << "T1������Ϊ:" << typeid(T1).name() << endl;
		cout << "T2������Ϊ:" << typeid(T2).name() << endl;
	}
	T1 obj;
};
static void test05()
{
	cout << "-------------test05()-------------" << endl;
	Son261 s1;
	Son262<int, char>s2;
}


// ��ģ���Ա��������ʵ��
// 
// ��ģ���г�Ա��������ʵ��ʱ����Ҫ����ģ������б�
template<class T1, class T2>
class Person266
{
public:
	Person266(T1 name, T2 age);
	void showPerson();
	
	T1 m_Name;
	T2 m_Age;
};

// ���캯��������ʵ��
template<class T1, class T2>
Person266<T1, T2>::Person266(T1 name, T2 age)
//��һ��T1, T2��Ϊ�˸��߱�����������ģ�������ʵ��
{
	m_Name = name;
	m_Age = age;
}
// ��Ա����������ʵ��
template<class T1, class T2>
void Person266<T1, T2>::showPerson()
{
	cout << "name:" << m_Name << endl;
	cout << "age:" << m_Age << endl;
}
static void test06()
{
	cout << "-------------test06()-------------" << endl;
	Person266<string, int>p1("Tom", 10);
	p1.showPerson();
}



// ��ģ����ļ���д

// ѧϰĿ��:
// ��������ģ���Ա�������ļ���д�����������Լ������ʽ

// ���� :
// ����ģ���г�Ա��������ʱ�����ڵ��ý׶Σ����·��ļ���дʱ���Ӳ���
// ���:
//	�����ʽ1: ֱ�Ӱ���.cppԴ�ļ�
//	�����ʽ2 : ��������ʵ��д��ͬһ���ļ��У������ĺ�׺��Ϊ.hpp��hpp��Լ�������ƣ�������ǿ��

//template<class T1, class T2>
//class Person267
//{
//public:
//	Person267(T1 name, T2 age);
//	void showPerson();
//
//	T1 m_Name;
//	T2 m_Age;
//};

//// ���캯��������ʵ��
//template<class T1, class T2>
//Person267<T1, T2>::Person267(T1 name, T2 age)
////��һ��T1, T2��Ϊ�˸��߱�����������ģ�������ʵ��
//{
//	m_Name = name;
//	m_Age = age;
//}
//// ��Ա����������ʵ��
//template<class T1, class T2>
//void Person267<T1, T2>::showPerson()
//{
//	cout << "name:" << m_Name << endl;
//	cout << "age:" << m_Age << endl;
//}
static void test07()
{
	cout << "-------------test07()-------------" << endl;

	// ��һ�ֽ����ʽ��ֱ�Ӱ���Դ�ļ�
	//#include"Person267.h"�������Ϊ��ģ���еĳ�Ա����һ��ʼ���ᴴ����������Person267.hʱ������������Թ�����Person267()��showPerson()����
	//��Person267.cpp�ļ�������Ҳû���������Ի���������ⲿ�����������
	//#include"Person267.cpp"//ͷ�ļ�����������Ͳ��ᱨ����ΪPerson267.cpp��Ҳ#include"Person267.h"���൱�ڱ��������������е����ݣ�������Ȼ�ɹ�

	// �ڶ��ֽ����ʽ����.h��.cpp�е�����д��һ�𣬽���׺��Ϊ.hpp��һ����֪������ģ�壩

	Person267<string, int>p1("Jerry", 101);
	p1.showPerson();
}



// ��ģ������Ԫ

// ѧϰĿ��:
// ��������ģ�������Ԫ���������ں�����ʵ��
// 
//	1. ȫ�ֺ�������ʵ�� - ֱ��������������Ԫ����
//	2. ȫ�ֺ�������ʵ�� - ��Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���
//�ܽ᣺˭����ʵ�ִ���˭��


// ͨ��ȫ�ֺ��� ��ӡPerson����Ϣ

//	2. ȫ�ֺ�������ʵ�� - ��Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���
// ��ȫ�֣����Բ�ҪϹ��������

template<class T1, class T2>// Person268�Ǹ���ģ��
class Person268;// �����ú���֪��Person268�Ĵ���
template<class T1, class T2>
void printPerson268_2(Person268<T1, T2> &p)// �����ú���֪��Person268�Ĵ���
{
	cout << "����ʵ��" << endl;
	cout << "name:" << p.m_Name << endl;
	cout << "age:" << p.m_Age << endl;
}

template<class T1, class T2>
class Person268
{
	//	1. ȫ�ֺ�������ʵ�� - ֱ��������������Ԫ����
	friend void printPerson268(Person268<T1,T2> &p)
	{
		cout << "����ʵ��" << endl;
		cout << "name:" << p.m_Name << endl;
		cout << "age:" << p.m_Age << endl;
	}
	//	2. ȫ�ֺ�������ʵ�� - ��Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ��ڣ�����д�����棩
	// �ӿ�ģ������б�����Ҫ�����˼����Ǹ�ģ�壩
	friend void printPerson268_2<>(Person268<T1, T2> &p);

public:
	Person268(T1 name, T2 age)
	{
		m_Name = name;
		m_Age = age;
	}
private:
	T1 m_Name;
	T2 m_Age;
};
static void test08()
{
	cout << "-------------test08()-------------" << endl;
	//	1. ȫ�ֺ�������ʵ�� - ֱ��������������Ԫ����
	Person268<string, int>p1("LJT", 22);
	printPerson268(p1);

	//	2. ȫ�ֺ�������ʵ�� - ��Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���
	Person268<string, int>p2("BBX", 18);
	printPerson268_2(p2);
}



// ��ģ�尸�� - �������װ

// ��������: ʵ��һ��ͨ�õ������࣬Ҫ������:
//	�����Զ��������������Լ��Զ����������͵����ݽ��д洢
//	���������е����ݴ洢������
//	�����캯���п��Դ������������
//	���ṩ��Ӧ�Ŀ������캯���Լ�operator = ��ֹǳ��������
//	���ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
//	������ͨ���±�ķ�ʽ���������е�Ԫ��
//	�����Ի�ȡ�����е�ǰԪ�ظ��������������

void printArray(MyArray<int>& arr)
{
	for (size_t i = 0; i < arr.getSize(); i++)
	{
		cout << "arr[i]" << arr[i] << endl;
	}
}
class Person269
{
public:
	Person269() {};
	Person269(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	string m_Name;
	int m_Age;
};
void printPerson269(MyArray<Person269>& arr)
{
	for (size_t i = 0; i < arr.getSize(); i++)
	{
		cout << "������" << arr[i].m_Name << endl;
		cout << "���䣺" << arr[i].m_Age << endl;
	}
}

static void test09()
{
	cout << "-------------test09()-------------" << endl;
	MyArray<int> arr1(5);
	for (size_t i = 0; i < 5; i++)
	{
		arr1.Push_Back(i);
	}
	cout << "arr1�Ĵ�ӡ���Ϊ��" << endl;
	printArray(arr1);
	arr1.Pop_Back();
	cout << "arr1βɾ��" << endl;
	cout << "arr1.getSize():" << arr1.getSize() << endl;
	cout << "arr1.getCapacity():" << arr1.getCapacity() << endl;

	MyArray<int>arr2(arr1);
	cout << "arr2�Ĵ�ӡ���Ϊ��" << endl;
	printArray(arr2);

	MyArray<Person269>arr3(10);
	Person269 p1("�����", 999);
	Person269 p2("����", 20);
	Person269 p3("槼�", 18);
	Person269 p4("����", 25);
	Person269 p5("������", 27);
	// �����ݲ���������
	arr3.Push_Back(p1);
	arr3.Push_Back(p2);
	arr3.Push_Back(p3);
	arr3.Push_Back(p4);
	arr3.Push_Back(p5);

	// ��ӡ����
	printPerson269(arr3);
	arr3.Pop_Back();
	cout << "arr3βɾ��" << endl;
	cout << "arr3.getSize():" << arr3.getSize() << endl;
	cout << "arr3.getCapacity():" << arr3.getCapacity() << endl;

	MyArray<Person269>arr4(arr3);
	cout << "arr4�Ĵ�ӡ���Ϊ��" << endl;
	printPerson269(arr4);


}



int main26()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	test09();
	system("pause");
	return 0;
}