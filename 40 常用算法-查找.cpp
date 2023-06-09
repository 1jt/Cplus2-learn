#include<iostream>
#include<algorithm>
#include<numeric>
#include<functional>
#include<vector>
using namespace std;


//	2. ���ò����㷨
//	ѧϰĿ�� :
//		�����ճ��õĲ����㷨
//	�㷨��� :
//		find			//����Ԫ��
//		find_if			//����������Ԫ��
//		adjacent_find	//���������ظ�Ԫ��
//		binary_search	//���ֲ��ҷ�
//		count			//ͳ��Ԫ�ظ���
//		count_if		//������ͳ��Ԫ�ظ���



// 1.find
//	��������:
//		������ָ��Ԫ�أ��ҵ�����ָ��Ԫ�صĵ��������Ҳ������ؽ���������end()
//	����ԭ�� :
//		��find(iterator beg, iterator end, value);
//			��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
//			beg ��ʼѡ����
//			end ����ѡ����
//			value ���ҵ�Ԫ��
class Person401
{
public:
	Person401(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	bool operator==(const Person401& p)
	{
		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name)
		{
			return true;
		}
		return false;
	}
	string m_Name;
	int m_Age;
};
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	//����������������
	vector<int>v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���" << *it << endl;
	}

	//�����Զ�����������
	vector<Person401>v2;
	Person401 p1("����", 35);
	Person401 p2("�ܲ�", 45);
	Person401 p3("��Ȩ", 15);
	Person401 p4("����", 25);
	Person401 p5("�ŷ�", 33);
	Person401 p6("����", 34);
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);
	v2.push_back(p5);
	v2.push_back(p6);
	vector<Person401>::iterator it2 = find(v2.begin(), v2.end(), p2);//��Ҫ���أ���Ȼ��֪��==��ô����
	if (it2 == v2.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���" << it2->m_Name << endl;
	}
}



// 2.find_if
//	��������:
//		������������Ԫ��
//	����ԭ�� :
//		��find_if(iterator beg, iterator end, _Pred);
//			��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
//			beg��ʼѡ����
//			end ����ѡ����
//			_Pred ��������ν�� (����bool���͵ķº���)
class GreaterFive40
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
class Greater20
{
public:
	bool operator()(Person401 &p)
	{
		return p.m_Age > 20;
	}
};
static void test02()
{
	cout << "-------------test02()-------------" << endl;
	//����������������
	vector<int>v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive40());
	if (it == v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ�����5������Ϊ��" << *it << endl;
	}

	//�����Զ�����������
	vector<Person401>v2;
	Person401 p1("����", 35);
	Person401 p2("�ܲ�", 45);
	Person401 p3("��Ȩ", 15);
	Person401 p4("����", 25);
	Person401 p5("�ŷ�", 33);
	Person401 p6("����", 34);
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);
	v2.push_back(p5);
	v2.push_back(p6);
	vector<Person401>::iterator it2 = find_if(v2.begin(), v2.end(), Greater20());
	if (it2 == v2.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��������20���ˣ�" << it2->m_Name << endl;
	}
}



// 3.adjacent find
//	��������
//		�����������ظ�Ԫ��
//	����ԭ�� :
//		��adjacent find(iterator beg, iterator end);
//			���������ظ�Ԫ��,��������Ԫ�صĵ�һ��λ�õĵ�����
//			beg ��ʼѡ����
//			end ����ѡ����
static void test03()
{
	cout << "-------------test03()-------------" << endl;
	//����������������
	vector<int>v;
	v.push_back(0);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);
	v.push_back(3);//���ҵ����
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ�������Ϊ��" << *it << endl;
	}
}



// 4.binary_search
//	�������� :
//		������ָ��Ԫ���Ƿ����
//	����ԭ�� :
//		��bool binary_search(iterator beg, iterator end, value);
//			����ָ����Ԫ�أ��鵽 ����true ����false
//			ע��: �����������в�����
//			beg ��ʼѡ����
//			end ����ѡ����
//			value ���ҵ�Ԫ��
static void test04()
{
	cout << "-------------test04()-------------" << endl;
	//����������������
	vector<int>v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	// ������������������򣬽��δ֪
	bool it = binary_search(v.begin(), v.end(), 6);
	if (it == false)
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ�" << endl;
	}
}



// 5.count
//	�������� :
//		��ͳ��Ԫ�ظ���
//	����ԭ�� :
//		��count(iterator beg, iterator end, value);
//			ͳ��Ԫ�س��ִ���
//			beg ��ʼѡ����
//			end ����ѡ����
//			value ͳ�Ƶ�Ԫ��
class Person402
{
public:
	Person402(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	bool operator==(const Person402& p)
	{
		if (this->m_Age == p.m_Age)
		{
			return true;
		}
		return false;
	}
	string m_Name;
	int m_Age;
};
static void test05()
{
	cout << "-------------test05()-------------" << endl;
	//����������������
	vector<int>v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	v.push_back(5);
	v.push_back(5);

	int num = count(v.begin(), v.end(), 5);
	cout << "5�ĸ���Ϊ��" << num << endl;

	//�����Զ�����������
	vector<Person402>v2;
	Person402 p1("����", 35);
	Person402 p2("�ܲ�", 45);
	Person402 p3("��Ȩ", 15);
	Person402 p4("����", 25);
	Person402 p5("�ŷ�", 35);
	Person402 p6("����", 35);
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);
	v2.push_back(p5);
	v2.push_back(p6);
	v2.push_back(p6);
	v2.push_back(p6);
	int num2 = count(v2.begin(), v2.end(), p1);
	cout << "������һ�����������У�" << num2 << endl;
}



// 6.count if
//	��������:
//		��������ͳ��Ԫ�ظ�������ԭ��
//		��count if (iterator beg, iterator end, Pred);
//			������ͳ��Ԫ�س��ִ���
//			beg ��ʼѡ����
//			end ����ѡ����
//	_Pred ν��




int main40()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	system("pause");
	return 0;
}