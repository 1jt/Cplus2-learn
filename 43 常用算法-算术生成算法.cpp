#include<iostream>
#include<algorithm>
#include<numeric>
#include<functional>
#include<vector>
using namespace std;


//	5. �������������㷨
//	ѧϰĿ�� :
//		�����ճ��õ����������㷨
//	ע��:
//		�����������㷨����С���㷨��ʹ��ʱ���ϵ�ͷ�ļ�Ϊ #include <numeric>
//	�㷨��� :
//		��accumulate// ��������Ԫ���ۼ��ܺ�
//		��fill		// �����������Ԫ��


// 1.accumulate
//	�������� :
//		������������ ����Ԫ���ۼ��ܺ�
//	����ԭ�� :
//		��accumulate(iterator beg, iterator end, value);
//			��������Ԫ���ۼ��ܺ�
//			beg ��ʼѡ����
//			end ����ѡ����
//			value ��ʼֵ


// 2.fill
//	�������� :
//		�������������ָ����Ԫ��
//	����ԭ�� :
//		��fill(iterator beg, iteraton, end, value);
//			�����������Ԫ��
//			beg ��ʼѡ����
//			end ����ѡ����
//			value ����ֵ


class myPrint43
{
public:
	void operator()(int& val)
	{
		cout << val << " ";
	}
};
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	
	vector<int>v1;
	for (size_t i = 0; i < 101; i++)
	{
		v1.push_back(i);
	}
	// 1.accumulate
	int total = accumulate(v1.begin(), v1.end(), 0);
	cout << "total=" << total << endl;
	total = accumulate(v1.begin(), v1.end(), 1000);
	cout << "total=" << total << endl;

	// 2.fill
	fill(v1.begin(), v1.end(), 100);
	for_each(v1.begin(), v1.end(), myPrint43());
	cout << endl;
}



int main43()
{
	test01();
	system("pause");
	return 0;
}