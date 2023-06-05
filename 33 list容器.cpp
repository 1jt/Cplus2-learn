#include<iostream>
using namespace std;
#include<list>
#include<algorithm>


//	1. list��������
//	���� : 
//		�����ݽ�����ʽ�洢
//	����(list)��һ������洢��Ԫ�Ϸ������Ĵ洢�ṹ������Ԫ�ص��߼�˳����ͨ�������е�ָ������ʵ�ֵ�
//	�������� : ������һϵ�н�����
//	������� : һ���Ǵ洢����Ԫ�ص���������һ���Ǵ洢��һ������ַ��ָ����
//	STL�е�������һ��˫��ѭ������

//	��������Ĵ洢��ʽ�������������ڴ�ռ䣬�������list�еĵ�����ֻ֧��ǰ�ƺͺ��ƣ�����˫�������

//	list���ŵ� :
//		�����ö�̬�洢���䣬��������ڴ��˷Ѻ����
//		������ִ�в����ɾ������ʮ�ַ��㣬�޸�ָ�뼴�ɣ�����Ҫ�ƶ�����Ԫ��list��ȱ�� :
//	list��ȱ��:
//		�����������ǿռ�(ָ����)�� ʱ��(����)����ķѽϴ�
// 
//	List��һ����Ҫ�����ʣ����������ɾ���������������ԭ��list��������ʧЧ������vector�ǲ�������.

//	�ܽ�: STL��List��vector���������ʹ�õ�������������ȱ��

void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << endl;
	}
}


//	2. list���캯��
//	�������� :
//		������list����
//	����ԭ�� :
//		list<T> list;			//list���ò���ģ����ʵ��,�����Ĭ�Ϲ�����ʽ
//		list(beg; end);			//���캯����[beg,end)�����е�Ԫ�ؿ���������
//		list(n, elem);			//���캯����n��elem����������
//		list(const list& lst);	//�������캯��



//	3. list ��ֵ�ͽ���
//	�������� :
//		����list�������и�ֵ���Լ�����list����
//	����ԭ��:
//		assign(beg, end);	//��[beg,end)�����е����ݿ�����ֵ������
//		assign(n, elem);	//��n��elem������ֵ������
//		list& operator=(const list& lst);//���صȺŲ�����
//		swap(lst);			//��lst�뱾���Ԫ�ػ���



//	4. list ��С����
//	�������� :
//		����list�����Ĵ�С���в���
//	����ԭ�� :
//		size();				//����������Ԫ�صĸ���
//		empty();			//�ж������Ƿ�Ϊ��
//		resize(num);		//����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ��
							//���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
//		resize(num, elem);	//����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ��
							//���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��



//	5. list �����ɾ��
//	�������� :
//		����list�����������ݵĲ����ɾ��
//	����ԭ�� :
//		push_back(elem);		//������β������һ��Ԫ��
//		pop_back();				//ɾ�����������һ��Ԫ�ء�
//		push_front(elem);		//��������ͷ����һ��Ԫ��
//		pop_front():			//���ݿ�ͷ�Ƴ���һ��Ԫ��
//		insert(pos,elem);		//��posλ�ò�elemԪ�صĿ��������������ݵ�λ��
//		insert(pos,n,elem);		//��posλ�ò���n��elem���ݣ��޷���ֵ
//		insert(pos, beg,end);	//��posλ�ò���[beg,end)��������ݣ��޷���ֵ.
//		clear();				//�Ƴ���������������
//		erase(beg, end);		//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ��
//		erase(pos);				//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
//		remove(elem);			//ɾ��������������elemֵƥ���Ԫ��



//	6. list ���ݴ�ȡ
//	�������� :
//		����list���������ݽ��д�ȡ
//	����ԭ�� :
//		front();//���ص�һ��Ԫ��
//		back();	//�������һ��Ԫ��
//	list���������������������Ե��ڴ棬���Բ�����[]����
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	//L1[0];//û��[]���ֲ���
	//	list���������������������Ե��ڴ棬���Բ�����[]����
	cout << "��һ��Ԫ��Ϊ��" << L1.front() << endl;
	cout << "���һ��Ԫ��Ϊ��" << L1.back() << endl;

	// ��֤�������ǲ�֧��������ʵ�
	auto it = L1.begin();
	it++;//֧��˫��
	//it + 1;//���ϲ��У���֧��������ʣ��ж������˫���С���ɣ�
	cout << "it++ = " << *it << endl;
}



//	7. list ��ת������
//	�������� :
//		���������е�Ԫ�ط�ת���Լ��������е����ݽ�������
//	����ԭ�� :
//		reverse();	//��ת����
//		sort();		//��������
bool myCompare33(int v1,int v2)// �ص�����
{
	// ����	����	��һ����>�ڶ�����
	return v1 > v2;
}
static void test02()
{
	cout << "-------------test02()-------------" << endl;
	list<int>L1;
	L1.push_back(80);
	L1.push_back(50);
	L1.push_back(30);
	L1.push_back(70);
	L1.push_back(20);
	L1.push_back(90);
	L1.push_back(60);
	L1.push_back(10);
	cout << "��תǰ" << endl;
	printList(L1);
	cout << "��ת��" << endl;
	L1.reverse();
	printList(L1);
	cout << "�����" << endl;
	// ���в�֧��������ʵ�������������ʹ�ñ�׼�㷨
	// ��֧��������ʵ��������������ڲ����ṩһЩ��Ӧ�㷨
	//sort(L1.begin(), L1.end());//��������
	L1.sort();//Ĭ������(�������������ѡ���㷨)
	printList(L1);
	cout << "�������" << endl;
	//ctrl+shift+�ո�=�鿴������Ϣ
	// ���غ�����Ҫ�ṩһ���������߷º�����ȥ��19��
	L1.sort(myCompare33);
	printList(L1);
}



// ������
// ������������Person�Զ����������ͽ�������Person����������������������
// ���򣺰��������������(����)�����������ͬ������߽�������(����)
class Person331
{
public:
	Person331(string name, int age, int height)
	{
		m_Name = name;
		m_Age = age;
		m_Height = height;
	}

	string m_Name;
	int m_Age;
	int m_Height;
};
// ָ���������
bool myCompare332(Person331 &p1, Person331& p2)// �ص�����
{
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;
	}
	return p1.m_Age < p2.m_Age;
}


static void test03()
{
	cout << "-------------test03()-------------" << endl;
	list<Person331>L1;
	Person331 p1("����", 35, 175);
	Person331 p2("�ܲ�", 45, 180);
	Person331 p3("��Ȩ", 40, 170);
	Person331 p4("����", 25, 190);
	Person331 p5("�ŷ�", 35, 160);
	Person331 p6("����", 35, 200);
	L1.push_back(p1);
	L1.push_back(p2);
	L1.push_back(p3);
	L1.push_back(p4);
	L1.push_back(p5);
	L1.push_back(p6);
	for (list<Person331>::iterator it = L1.begin(); it != L1.end(); it++)
	{
		cout << "������" << (*it).m_Name << "\t���䣺" << it->m_Age << "\t��ߣ�" << (*it).m_Height << endl;
	}
	//����
	cout << "------------------------------" << endl;
	cout << "�����" << endl;
	L1.sort(myCompare332);
	for (list<Person331>::iterator it = L1.begin(); it != L1.end(); it++)
	{
		cout << "������" << (*it).m_Name << "\t���䣺" << it->m_Age << "\t��ߣ�" << (*it).m_Height << endl;
	}
}







int main33()
{
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}