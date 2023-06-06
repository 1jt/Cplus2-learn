#include<iostream>
using namespace std;
#include<map>

//	1. map��������
//	��� :
//		��map������Ԫ�ض���pair
//		��pair�е�һ��Ԫ��Ϊkey(��ֵ)�����������ã��ڶ���Ԫ��Ϊvalue(ʵֵ)
//		������Ԫ�ض������Ԫ�صļ�ֵ�Զ�����
//	���� :
//		��map / multimap���ڹ���ʽ�������ײ�ṹ���ö�����ʵ��
// �ŵ� :
//		�����Ը���keyֵ�����ҵ�valueֵ
// map��multimap���� :
//		��map���������������ظ�keyֵԪ��
//		��multimap�������������ظ�keyֵԪ��



//	2. map����͸�ֵ
//	��������
//			����map�������й���͸�ֵ������
//	����ԭ�� :
//	����:
//		map<T1�� T2> mp;	//mapĬ�Ϲ��캯��
//		map(const map& mp);	//�������캯��
//	��ֵ:
//		map& operator=(const map& mp);//���صȺŲ�����



//	3. map��С�ͽ���
//	�������� :
//		��ͳ��map������С�Լ�����map����
//	����ԭ�� :
//	size();		//����������Ԫ�ص���Ŀ
//	empty();	//�ж������Ƿ�Ϊ��
//	swap(st);	//����������������



//	4. map�����ɾ��
//	�������� :
//		��map�������в������ݺ�ɾ������
//	����ԭ�� :
//		insert(elem);	//�������в���Ԫ��
//		clear();		//�������Ԫ��
//		erase(pos);		//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
//		erase(beg��end);//ɾ������[beg,end)������Ԫ�أ�������һ��Ԫ�صĵ�����
//		erase(key);		//ɾ��������ֵΪkey��Ԫ�ء�
void printMap(const map<int, int>& m)
{
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << (*it).first << "\t" << it->second << endl;
	}
}
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	map<int, int>m2;
	m2[4] = 40;
	m2.insert(pair<int, int>(5, 50));
	m2.insert(pair<int, int>(6, 60));
	m2.insert(pair<int, int>(7, 70));
	cout << m2[8] << endl;//�����Ų�����ȥ��ֵ
	cout << "-------------m-------------" << endl;
	printMap(m);
	cout << "-------------m2-------------" << endl;
	printMap(m2);
	m.swap(m2);
	cout << "-------------m-------------" << endl;
	printMap(m);
	cout << "-------------m2-------------" << endl;
	printMap(m2);
}



//	5. map���Һ�ͳ��
//	�������� :
//		����map�������в��������Լ�ͳ������
//	����ԭ�� :
//		find(key);	//����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ�����;�������ڣ�����map.end():
//		count(key);	//ͳ��key��Ԫ�ظ���



//	6. map��������
//	ѧϰĿ�� :
//		��map����Ĭ���������Ϊ ����keyֵ���� ��С��������������θı��������
//	��Ҫ������ :
//		�����÷º��������Ըı��������
class myCompare35//����ù��캯���������أ���
{
public:
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};
static void test02()
{
	cout << "-------------test02()-------------" << endl;
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	map<int, int,myCompare35>m2;
	// �޸Ĺ���Ҫ�ڴ���֮ǰ�ƶ�����
	m2[4] = 40;
	m2.insert(pair<int, int>(5, 50));
	m2.insert(pair<int, int>(6, 60));
	m2.insert(pair<int, int>(7, 70));
	for (map<int, int, myCompare35>::const_iterator it = m2.begin(); it != m2.end(); it++)
	{
		cout << (*it).first << "\t" << it->second << endl;
	}

}



int main35()
{
	test01();
	test02();
	system("pause");
	return 0;
}