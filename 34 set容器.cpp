#include<iostream>
#include<set>
using namespace std;

//	1. set��������
//	��� :
//		������Ԫ�ض����ڲ���ʱ�Զ�������
//	���� :
//		��set / multiset���ڹ���ʽ�������ײ�ṹ���ö�����ʵ��
//	set��multiset����
//		��set���������������ظ���Ԫ��
//		��multiset�������������ظ���Ԫ��
 
 

//	2. set����͸�ֵ
//	�������� : 
//		������set�����Լ���ֵ
//	����:
//		set<T> st;			//Ĭ�Ϲ��캯��:
//		set(const set& st);	//�������캯��
//	��ֵ:
//		set& operator=(const set& st);	//���صȺŲ�����
void printSet(const set<int> &st)
{
	for (set<int>::const_iterator it = st.begin(); it != st.end(); it++)
	{
		cout << (*it) << " ";
	}
	cout << endl;
}
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	set<int>s1;
	// ��������ֻ��insert�ķ�ʽ
	s1.insert(50);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	s1.insert(10);
	s1.insert(10);// �Զ�����+�޷������ظ���(���˰ײ�)
	printSet(s1);
	set<int>s2(s1);
	printSet(s2);
}



//	3. set��С�ͽ���
//	�������� :
//		��ͳ��set������С�Լ�����set����
//	����ԭ�� :
//		size();		//����������Ԫ�ص���Ŀ
//		empty();	//�ж������Ƿ�Ϊ��
//		swap(st);	//����������������



//	4. set�����ɾ��
//	�������� :
//		��set�������в������ݺ�ɾ������
//	����ԭ��
//		insert(elem);	//�������в���Ԫ��
//		clear();		//�������Ԫ��
//		erase(pos);		//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�����
//		erase(beg,end);	//ɾ������[beg,end)������Ԫ�أ�������һ��Ԫ�صĵ�����
//		erase(elem);	//ɾ��������ֵΪelem��Ԫ��



//	5. set���Һ�ͳ��
//	�������� :
//		����set������в��������Լ�ͳ������
//	����ԭ�� :
//		find(key);	//����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ�����;�������ڣ�����set.end():
//		count(key);	//ͳ��key��Ԫ�ظ���



//	6. set��multiset����
//	ѧϰĿ�� :
//		������set��multiset������
//	���� :
//		��set�����Բ����ظ����ݣ���multiset����
//		��set�������ݵ�ͬʱ�᷵�ز���������ʾ�����Ƿ�ɹ�multiset���������ݣ���˿��Բ����ظ�����
void printMultiSet(const multiset<int>& st)
{
	for (multiset<int>::const_iterator it = st.begin(); it != st.end(); it++)
	{
		cout << (*it) << " ";
	}
	cout << endl;
}
static void test02()
{
	cout << "-------------test02()-------------" << endl;
	set<int>s1;
	// ��������ֻ��insert�ķ�ʽ
	pair<set<int>::iterator, bool> ret = s1.insert(10);
	if (ret.second)
	{
		cout << "��һ�β���ɹ�" << endl;
	}
	else
	{
		cout << "��һ�β����ʧ��" << endl;
	}
	ret = s1.insert(10);
	if (ret.second)
	{
		cout << "�ڶ��β���ɹ�" << endl;
	}
	else
	{
		cout << "�ڶ��β���ʧ��" << endl;
	}
	printSet(s1);

	multiset<int>s2;
	s2.insert(10);
	s2.insert(10);
	printMultiSet(s2);
}



//	7. pair���鴴��
//	�������� :
//		���ɶԳ��ֵ����ݣ����ö�����Է�����������
//	���ִ�����ʽ :
//		pair<type, type> p(value1, value2);
//		pair<type, type> p = make_pair(value1, value2);
static void test03()
{
	cout << "-------------test03()-------------" << endl;
	// 1
	pair<string, int>p1("Tom", 20);
	cout << "������" << p1.first << "\t���䣺" << p1.second << endl;
	// 2 
	pair<string, int>p2 = make_pair("Jerry", 30);
	cout << "������" << p2.first << "\t���䣺" << p2.second << endl;
}



//	8. set�������� I
//	ѧϰĿ�� :
//		��set����Ĭ���������Ϊ��С����������θı��������
// ��Ҫ������:
//		�����÷º��������Ըı��������
class myCompare34//����ù��캯���������أ���
{
public:
	//vs2019�����أ����ǵüӸ�const   ��bool  operator()(int x, int y) const
	//�����޸������ڵ���ĳ�Ա�Ĳ������ǲ�����ģ���Ϊ�����˶�thisָ���const���ã���
	bool operator()(int v1, int v2) const//����Ļ� ���ڷº��������һ��const
	{
		//cout << "ljt" << endl;
		//�º��������������ͣ�������operator()�������һ��������
		//�����������ֵ��Ҳ����˵���������ʱ�����������������ṩ��������������ǰ��
		return v1 > v2;
	}
};
// 1. set����������������
static void test04()
{
	cout << "-------------test04()-------------" << endl;
	set<int>s1;
	s1.insert(50);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	s1.insert(10);
	printSet(s1);

	// �޸Ĺ���Ҫ�ڴ���֮ǰ�ƶ�����
	set<int,myCompare34>s2;//��дΪset<����>��������������һ�����ͣ����ܷź��������º�����������һ�����ͣ���
	//�º����������࣬���ǹ�����ȴ�Ƿ���
	//����ù��캯����������()
	s2.insert(50);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);
	s2.insert(10);
	for (set<int, myCompare34>::const_iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << (*it) << " ";
	}
	cout << endl;
}

// 2. set�����Զ�����������
class Person341
{
public:
	Person341(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	string m_Name;
	int m_Age;
};
class myCompare342
{
public:
	bool operator()(const Person341& p1, const Person341& p2) const
	{
		// �������䣬����
		return p1.m_Age > p2.m_Age;
	}
};
static void test05()
{
	cout << "-------------test05()-------------" << endl;
	// �Զ����������ͣ�����ָ���������
	set<Person341,myCompare342>s1;
	Person341 p1("����", 35);
	Person341 p2("�ܲ�", 45);
	Person341 p3("��Ȩ", 15);
	Person341 p4("����", 25);
	Person341 p5("�ŷ�", 33);
	Person341 p6("����", 34);
	//���û���������Ҳ�Ͳ�֪����ô����
	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);
	s1.insert(p5);
	s1.insert(p6);
	//���û���������Ҳ���޷�����
	for (set<Person341, myCompare342>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << "������" << (*it).m_Name << "\t���䣺" << it->m_Age << endl;
	}
	cout << endl;
	

}
int main34()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	system("pause");
	return 0;
}