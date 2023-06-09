#include<iostream>
#include<algorithm>
#include<numeric>
#include<functional>
#include<vector>
using namespace std;


// 4.���ÿ������滻�㷨
//	ѧϰĿ�� :
//		�����ճ��õĿ������滻�㷨
//	�㷨���:
//		��copy		// ������ָ����Χ��Ԫ�ؿ�������һ������
//		��replace	//��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
//		��replace_if//������ָ����Χ����������Ԫ���滻Ϊ��Ԫ��
//		��swap		// ��������������Ԫ��


// 1.copy
//	�������� :
//		��������ָ����Χ��Ԫ�ؿ�������һ������
//	����ԭ�� :
//		��copy(iterator beg, iterator end, iterator dest);
//			��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
//			beg ��ʼ������
//			end ����ѡ����
//			dest Ŀ����ʼ������


// 2.replace
//	�������� :
//		����������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
//	����ԭ�� :
//		��replace(iterator beg, iteratorlend, oldvalue, newvalue);
//			�������ھ�Ԫ�� �滻����Ԫ��
//			beg ��ʼѡ����
//			end����ѡ����
//			oldvalue ��Ԫ��
//			newvalue ��Ԫ��


// 3.replace if
//	�������� :
//		��������������������Ԫ�أ��滻��ָ��Ԫ��
//	����ԭ�� :
//		��replace if (iterator beg, iterator end, _pred, newvalue);
//			�������滻Ԫ�أ������������滻��ָ��Ԫ��
//			beg ��ʼѡ����
//			end ����ѡ����
//			_pred ν��
//			newvalue �滻����Ԫ��


// 4.swap
//	�������� :
//		����������������Ԫ��
//	����ԭ�� :
//		��swap(container c1, container x2);
//			��������������Ԫ��
//			c1����1
//			c2����2

class LessFive
{
public:
	bool operator()(int val)
	{
		return val < 5;
	}
};

void myPrint42(int& val)
{
	cout << val << " ";
}
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	// ������һ�㲻��ֱ��=��
	vector<int>v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int>v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), myPrint42);
	cout << endl;

	// replace
	replace(v2.begin(), v2.end(), 6, 9);
	replace(v2.begin(), v2.end(), 7, 9);
	replace(v2.begin(), v2.end(), 8, 9);
	for_each(v2.begin(), v2.end(), myPrint42);
	cout << endl;

	// replace_if
	replace_if(v2.begin(), v2.end(), LessFive(), 8);
	for_each(v2.begin(), v2.end(), myPrint42);
	cout << endl;

	// swap
	swap(v1, v2);
	for_each(v1.begin(), v1.end(), myPrint42);
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint42);
	cout << endl;
}



int main()
{
	test01();
	system("pause");
	return 0;
}







