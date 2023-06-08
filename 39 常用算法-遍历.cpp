#include<iostream>
#include<algorithm>
#include<numeric>
#include<functional>
#include<vector>
using namespace std;


//	����:
//		���㷨��Ҫ����ͷ�ļ� <algorithm> <functional> <numeric>���
//		��<algorithm>������STLͷ�ļ�������һ������Χ�漰���Ƚϡ����������ҡ��������������ơ��޸ĵȵ�
//		��<numeric>�����С��ֻ��������������������м���ѧ�����ģ�庯��
//		��<functional>������һЩģ����, ����������������


//	1. ���ñ����㷨
//	ѧϰĿ�� :
//		�����ճ��õı����㷨
//	�㷨��� :
//		for_each	//��������
//		transform	//������������һ��������
//		find
// 1.for_each
//	��������
//		��ʵ�ֱ�������
//	����ԭ��
//		��for_each(iterator beg, iterator end, func);
//			�����㷨 ��������Ԫ��
//			beg ��ʼѡ����
//			end ����ѡ����
//			_func�������ߺ�������
void myPrint391(int& val)
{
	cout << val << " ";
}
class myPrint392
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
	vector<int> v1;
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(2);
	v1.push_back(5);
	v1.push_back(1);
	for_each(v1.begin(), v1.end(), myPrint391);//myPrint391��ʵ�Ǻ���ָ�룬����û��
	cout << endl;
	for_each(v1.begin(), v1.end(), myPrint392());
	cout << endl;
}
// 2.transform
//	�������� :
//		��������������һ��������
//	����ԭ�� :
//		��transform(iterator beg1, iterator end1, iterator beg2, func);
//			beg1 Դ������ʼѡ����
//			end1 Դ��������������
//			beg2 Ŀ��������ʼ������
//			_func�������ߺ�������
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
	vector<bool> v2;//��ͬ����֮��Ҳ���԰���
	v2.resize(v1.size());//���ȿ��٣���Ȼ���˲���
	transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


int main39()
{
	test01();
	test02();
	system("pause");
	return 0;
}