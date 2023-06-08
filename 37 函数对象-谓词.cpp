#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//	1. ν�ʸ���
//	���� :
//		������bool���͵ķº�����Ϊν��
//		�����operator()����һ����������ô����һԪν��
//		�����operator()����������������ô������Ԫν��

//	һԪν��
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

// ��Ԫν��
class MyCompare37
{
public:
	bool operator()(int val,int val2)
	{
		return val > val2;
	}
};

static void test01()
{
	cout << "-------------test01()-------------" << endl;
	vector<int>v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//	һԪν��
	// ������������û�д���5������
	// predicate(Pred) ��ν��
	//GreaterFive()����������������
	/*	��������루find_ifԴ�룩�У����Կ��� "_First" ��һ����������ԭ����������

		��������������ʽ���� C++ �У�������ͨ��������ָ��ķ�ʽ���������Ա������������ڱ���������Ԫ�ص�ָ�롣
		����������У�"_First" ��ʾ�����еĵ�һ��Ԫ�أ�����������ʽ�ǳ����ϵ������������淶��

		�����������͵Ķ��壺����������У�����ǩ���е� "_InIt" ��ʾ�����������input iterator����
		����һ�ֵ��������ͣ����ڱ��������е�Ԫ�أ�����ֻ����ǰ�ƶ������ܽ���������ʡ�
		��ˣ�����������У�"_First" ��һ�����������������ָ�������㷨����ʼλ�á�

		�������������Կ��� "_First" ��һ������������������һ����������������ڱ��������е�Ԫ�ء�*/
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());//return _First ���ص���һ��������
	if (it == v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ�����5������Ϊ��"<<*it << endl;
	}

	//��Ԫν��
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	// ʹ�ú������󣬸ı��㷨���ԣ���Ϊ�������Ӵ�С
	sort(v.begin(), v.end(),MyCompare37());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


int main37()
{
	test01();
	system("pause");
	return 0;
}