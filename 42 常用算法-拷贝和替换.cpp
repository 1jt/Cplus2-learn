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


void myPrint42(int& val)
{
	cout << val << " ";
}
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	//����������������
	vector<int>v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int>v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), myPrint42);
}



int main()
{
	test01();
	system("pause");
	return 0;
}







