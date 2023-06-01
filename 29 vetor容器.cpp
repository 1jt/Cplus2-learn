#include<iostream>
using namespace std;
#include<vector>

//	1. vector��������
//	���� :
//		��vector���ݽṹ������ǳ����ƣ�Ҳ��Ϊ��������
//	vector����ͨ�������� :
//		����֮ͬ�����������Ǿ�̬�ռ䣬��vector���Զ�̬��չ
//	��̬��չ :
//		����������ԭ�ռ�֮�������¿ռ䣬�����Ҹ�����ڴ�ռ䣬Ȼ��ԭ���ݿ����¿ռ䣬�ͷ�ԭ�ռ�(�׳ơ���ҡ�)
//			���õ�������v.begin()	��һ��Ԫ��				v.end()	   ���һ��Ԫ�صĺ�һλ
//						v.rend()	��һ��Ԫ��ǰһ��λ��	v.rbegin() ���һ��Ԫ��
//		��vertor�����ĵ�������֧��������ʵĵ�����



//	2. vector���캯��
//	�������� :
//		������vector����
//	����ԭ�� :
//		vector<T> v; I				//����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
//		vector(v.begin()��v.end());	//��v[begin0,end0)�����е�Ԫ�ؿ���������.
//		vector(n, elem);			//���캯����n��elem����������
//		vector(const vector& vec);	//�������캯��

//��ӡ�����ӿ�
void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	// 1
	vector<int> v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	// 2
	vector<int> v2(v1.begin() + 1, v1.end());//����ҿ�
	printVector(v2);
	// 3	n��elem��ʽ����
	vector<int> v3(10, 100);
	printVector(v3);
	// 4	����
	vector<int> v4(v3);
	printVector(v4);
}



//	3.  vector��ֵ����
//	��������:
//		`��vector�������и�ֵ
//	����ԭ�� :
//		vector& operator=(const vector& vec);	//���صȺŲ�����
//		assign(beg, end);						//��[beg, end)�����е����ݿ�����ֵ������
//		assign(n, elem);						//��n��elem������ֵ������
static void test02()
{
	cout << "-------------test02()-------------" << endl;
	vector<int> v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	vector<int> v2;
	// 1
	v2 = v1;
	printVector(v2);
	// 2
	vector<int> v3;
	v3.assign(v1.begin() + 1, v1.end() + 1);//����ҿ��������
	printVector(v3);
	// 3
	vector<int> v4;
	v4.assign(10, 100);
	printVector(v4);
}



//	4. vector�����ʹ�С
//	�������� :
//		����vector�����������ʹ�С����
//	����ԭ�� :
//		empy();					//�ж������Ƿ�Ϊ��
//		capacity();				//����������
//		size();					//����������Ԫ�صĸ���
//		resize(int num);		//����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ��
//								//���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
//		resize(int num, elem);	//����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ��
								//���������̣����β�����������ȵ�Ԫ�ر�ɾ��
static void test03()
{
	cout << "-------------test03()-------------" << endl;
	vector<int> v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	vector<int> v2;
	if (!v1.empty())
	{
		cout << "v1��Ϊ��" << endl;
		cout << "v1������Ϊ" << v1.capacity() << endl;// ���ܻ�Ԥ��Щλ��
		cout << "v1�Ĵ�СΪ" << v1.size() << endl;
	}
	// ����ָ����С
	v1.resize(15, 100);
	printVector(v1);
	v1.resize(5);
	printVector(v1);
}



//	5. vector�����ɾ��
//	�������� :
//		����vector�������в��롢ɾ������
//	����ԭ�� :
//		push_back(ele);										//β������Ԫ��ele
//		pop_back();											//ɾ�����һ��Ԫ��
//		insert(const_iterator pos, ele);					//ѡ����ָ��λ��pos����Ԫ��ele
//		insert(const_iterator pos��int count, ele);			//ѡ����ָ��λ��pos����count��Ԫ��ele
//		erase(const_iterator pos);							//ɾ��������ָ���Ԫ��
//		erase(const_iterator start�� const iterator end);	//ɾ��ѡ������start��end֮���Ԫ��
//		clear();											//ɾ������������Ԫ��
static void test04()
{
	cout << "-------------test04()-------------" << endl;
	vector<int> v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	v1.pop_back();
	printVector(v1);
	v1.insert(v1.begin(), 100);
	printVector(v1);
	v1.insert(v1.begin(), 2, 200);
	printVector(v1);
	v1.erase(v1.begin());
	printVector(v1);
	v1.erase(v1.begin() + 1, v1.end() - 1);
	printVector(v1);
	v1.clear();
	printVector(v1);
}



//	6. vector���ݴ�ȡ
//	�������� :
//		����vector�е����ݵĴ�ȡ����
//	����ԭ�� :
//		at(int idx);	//��������idx��ָ������
//		operator[];		//��������idx��ָ������
//		front();		//���������е�һ������Ԫ��
//		back();			//�������������һ������Ԫ��
static void test05()
{
	cout << "-------------test05()-------------" << endl;
	vector<int> v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << "v1[i]:" << v1[i] << endl;
	}
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << "v1[i] = " << v1.at(i) << endl;
	}
	cout << "v1.front() = " << v1.front() << endl;
	cout << "v1.back() = " << v1.back() << endl;
}



//	7. vector��������
//	�������� :
//		��ʵ������������Ԫ�ؽ��л���
//	����ԭ�� :
//		swap(vec);		// ��vec�뱾���Ԫ�ػ���
static void test06()
{
	cout << "-------------test06()-------------" << endl;
	vector<int> v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	vector<int> v3(10, 100);
	printVector(v3);
	// 1
	v1.swap(v3);
	printVector(v1);
	printVector(v3);
	// 2
	swap(v1, v3);
	printVector(v1);
	printVector(v3);
}
// ʵ����;
// ����swap���������ڴ�ռ�
static void test07()
{
	cout << "-------------test07()-------------" << endl;
	vector<int> v1;
	for (size_t i = 0; i < 100000; i++)
	{
		v1.push_back(i);
	}
	cout << "v1������Ϊ" << v1.capacity() << endl;// ������չ��13����
	cout << "v1�Ĵ�СΪ" << v1.size() << endl;

	v1.resize(3);
	cout << "v1������Ϊ" << v1.capacity() << endl;// ������Ȼ��13��
	cout << "v1�Ĵ�СΪ" << v1.size() << endl;

	//����swap�����ڴ�ռ�
	vector<int>(v1).swap(v1);//vector<int>(v1)����������
	//vector<int>(v);�ᱻϵͳĬ��Ϊ��������
	cout << "v1������Ϊ" << v1.capacity() << endl;
	cout << "v1�Ĵ�СΪ" << v1.size() << endl;
}



//	8. vectorԤ���ռ�
//	�������� :
//		������vector�ڶ�̬��չ����ʱ����չ����
//	����ԭ�� :
//		reserve(int len);	//����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�
static void test08()
{
	cout << "-------------test08()-------------" << endl;
	vector<int> v1;
	int num = 0;//ͳ�ƿ��ٴ���
	int* p = NULL;
	for (size_t i = 0; i < 100000; i++)
	{
		v1.push_back(i);
		if (p != &v1[0])
		{
			p = &v1[0];
			num++;
		}
	}
	cout << "v1������Ϊ" << v1.capacity() << endl;// ������չ��13����
	cout << "v1�Ĵ�СΪ" << v1.size() << endl;
	cout << "num = " << num << endl;// ������30��
	// ����reserveԤ���ռ�
	vector<int> v2;
	v2.reserve(100000);
	num = 0;//ͳ�ƿ��ٴ���
	p = NULL;
	for (size_t i = 0; i < 100000; i++)
	{
		v2.push_back(i);
		if (p != &v2[0])
		{
			p = &v2[0];
			num++;
		}
	}
	cout << "v2������Ϊ" << v2.capacity() << endl;// ��������100000
	cout << "v2�Ĵ�СΪ" << v2.size() << endl;
	cout << "num = " << num << endl;//�ͷ���һ��
	
}


int main29()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	system("pause");
	return 0;
}