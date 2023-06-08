#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;


//	1. �ڽ���������
//	�������:
//		��vSTL�ڽ���һЩ��������
//	����:
//		�������º���
//		����ϵ�º���
//		���߼��º���
//	�÷� :
//		����Щ�º����������Ķ����÷���һ�㺯����ȫ��ͬ
//		��ʹ���ڽ�����������Ҫ����ͷ�ļ� #include<functional>



//	2. �����º���
//	�������� :
//		��ʵ����������
//		������negate��һԪ���㣬�������Ƕ�Ԫ����
//	�º���ԭ��
//		template<class T> T plus<T>			//�ӷ��º���
//		template<class T> T minus<T>		//�����º���
//		template<class T> T multiplies<T>	//�˷��º���
//		template<class T> T divides<T>		//�����º���
//		template<class T> T modulus<T>		//ȡģ�º���
//		template<class T> T negate<T>		//ȡ���º���
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	//��������negate<>���Ǹ�����ִ�зº������࣬
	//�������ֻ��ִ����ĺ������봴��һ�����ʵ�������󣬿��Բ��ô������n
	negate<int>n;
	cout << n(50) << endl;
	plus<int>n2;//ֻ��һ��int��Ĭ����ӵ���ͬ�����ݽṹ
	cout << n2(50, 60) << endl;
}



//	3. ��ϵ�º���
//	�������� :
//		��ʵ�ֹ�ϵ�Ա�
//	�º���ԭ�� :
//		template<class T> bool equal to<T>		//����
//		template<class T> bool not equal to<T>	//������
//		template<class T> bool greater<T>		//����
//		template<class T> bool greater equal<T>	//���ڵ���
//		template<class T> bool less<T>			//С��
//		template<class T> bool less equal<T>	//С�ڵ���
static void test02()
{
	cout << "-------------test02()-------------" << endl;
	vector<int> v1;
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(2);
	v1.push_back(5);
	v1.push_back(1);
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	sort(v1.begin(), v1.end(), greater<int>());
	//˵���ˣ��ڽ��º������Ǹ��������������õġ�ν���Ǹ��Զ��������õġ�
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}



//	4. �߼��º���
//	��������:
//		��ʵ���߼�����
//	����ԭ�� :
//		template<class T> bool logical_and <T>	//�߼���
//		template<class T> bool logical_or <T>	//�߼���
//		template<class T> bool logical_not<T>	//�߼���
//	�����ò���
static void test03()
{
	cout << "-------------test03()-------------" << endl;
	vector<bool> v1;
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(2);
	for (vector<bool>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	// �����߼��ǽ��������˵�����v2�У���ִ��ȡ������
	vector<bool> v2;
	v2.resize(v1.size());//���ȿ��٣���Ȼ���˲���
	transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


int main38()
{
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}