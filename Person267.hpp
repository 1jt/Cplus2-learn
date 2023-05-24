#pragma once
#include<iostream>
using namespace std;

template<class T1, class T2>
class Person267
{
public:
	Person267(T1 name, T2 age);
	void showPerson();

	T1 m_Name;
	T2 m_Age;
};
#include"Person267.h"

// 构造函数的类外实现
template<class T1, class T2>
Person267<T1, T2>::Person267(T1 name, T2 age)
//第一组T1, T2是为了告诉编译器现在是模板的类外实现
{
	m_Name = name;
	m_Age = age;
}
// 成员函数的类外实现
template<class T1, class T2>
void Person267<T1, T2>::showPerson()
{
	cout << "name:" << m_Name << endl;
	cout << "age:" << m_Age << endl;
}