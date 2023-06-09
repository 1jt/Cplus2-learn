#include<iostream>
#include<algorithm>
#include<numeric>
#include<functional>
#include<vector>
using namespace std;


//	6. ���ü����㷨
//	ѧϰĿ�� :
//		�����ճ��õļ����㷨
//	�㷨��� :
//		��set_intersection	// �����������Ľ���
//		��set_union			// �����������Ĳ���
//		��set_difference	// �����������Ĳ


// 1.set_intersection
//	�������� :
//		�������������Ľ���
//	����ԭ�� :
//		��set_intersection(iterator begl, iterator end1, iterator beg2, iterator end2, iterator dest);
//			���������ϵĽ���
//			ע��:�������ϱ�������������
//			beg1 ����1��ʼѡ����
//			end1 ����1����������
//			beg2 ����2��ʼѡ����
//			end2 ����2����������
//			dest Ŀ��������ʼѡ����


// 2.set union
//	�������� :
//		�����������ϵĲ���
//	����ԭ��
//		��set union(iterator begl, iterator end1, iterator beg2, iterator end2, iterator dest);
//			���������ϵĲ���
//			ע��:�������ϱ�������������
//			beg1 ����1��ʼ������
//			end1 ����1����ѡ����
//			beg2 ����2��ʼ������
//			end2 ����2����������
//			dest Ŀ��������ʼѡ����


// 3.set difference
//	�������� :
//		�����������ϵĲ!
//	����ԭ�� :
//		��set difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
//			���������ϵĲ
//			ע��:�������ϱ�������������
//			beg1 ����1��ʼ������
//			end1 ����1����������
//			beg2 ����2��ʼ������
//			end2 ����2����������
//			dest Ŀ��������ʼѡ����

class myPrint44
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
	vector<int>v2;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	};
	//v1.push_back(3);
	//v2.push_back(3);//����������

	// ����
	// ��������
	cout << "��ʼ����" << endl;
	for_each(v1.begin(), v1.end(), myPrint44());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint44());
	cout << endl;
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v2.begin());
	cout << "���������v2��" << endl;
	for_each(v1.begin(), v1.end(), myPrint44());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint44());// ���ֻ��ǵ����µ�����
	cout << endl;
	cout << "���������vTarget��" << endl;
	vector<int>vTarget1;
	vTarget1.resize(min(v1.size(), v2.size()));//ȡС���Ǹ�
	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget1.begin());
	// ��Ȼ�����û�õ�0
	//cout << (*itEnd) << endl;
	for_each(vTarget1.begin(), itEnd, myPrint44());
	cout << endl;

	// ����
	cout << "���������vTarget��" << endl;
	vTarget1.resize(v1.size() + v2.size());
	itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget1.begin());
	for_each(vTarget1.begin(), itEnd, myPrint44());
	cout << endl;

	// �
	cout << "v1��v2�Ĳ��" << endl;
	vTarget1.resize(max(v1.size(), v2.size()));
	itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget1.begin());
	for_each(vTarget1.begin(), itEnd, myPrint44());
	cout << endl;
	cout << "v2��v1�Ĳ��" << endl;
	vTarget1.resize(max(v1.size(), v2.size()));
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget1.begin());
	for_each(vTarget1.begin(), itEnd, myPrint44());
	cout << endl;
}



int main44()
{
	test01();
	system("pause");
	return 0;
}