#include<iostream>
#include<algorithm>
#include<numeric>
#include<functional>
#include<vector>
using namespace std;

//	3. ���������㷨
//	ѧϰĿ�� :
//		�����ճ��õ������㷨
//	�㷨���:
//		��sort				//��������Ԫ�ؽ���������
//		��random shufflel	//ϴ�� ָ����Χ�ڵ�Ԫ�������������
//		��merge				//����Ԫ�غϲ������洢����һ������
//		��reverse			//��תָ����Χ��Ԫ��



// 1.sort
//	�������� :
//		����������Ԫ�ؽ�������
//	����ԭ�� :
//		��sort(iterator peg, iterator end, _Pred);
//			 ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
//			beg ��ʼѡ����
//			end ����ѡ����
//			_Pred ν��


// 2.random_shuffle
//	�������� :
//		��ϴ�� ָ����Χ�ڵ�Ԫ�������������
//	����ԭ�� :
//		��random_shuffle(iterator beg, iterator end);
//			ָ����Χ�ڵ�Ԫ�������������
//			beg ��ʼѡ����
//			end ����ѡ����


// 3.merge
//	�������� :
//		����������Ԫ�غϲ������洢����һ������
//	����ԭ�� :
//		��merge(iterator begl, iterator end1, iterator beg2, iterator end2, iterator dest);
//			����Ԫ�غϲ������洢����һ������
//			ע��: �������������������
//			beg1����1��ʼ������
//			end1����1����������
//			beg2����2��ʼ������
//			end2����2����������
//			dest Ŀ��������ʼѡ����


// 4.reverse
//	�������� :
//		����������Ԫ�ؽ��з�ת
//	����ԭ�� :
//		��reverse(iterator beg, iterator end);
//			��תָ����Χ��Ԫ��
//			beg ��ʼѡ����
//			end ����ѡ����


void myPrint41(int& val)
{
	cout << val << " ";
}
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	//����������������
	vector<int>v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	v.push_back(10);
	v.push_back(40);
	// ��sort��������
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint41);
	cout << endl;

	// �ı�Ϊ����
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), myPrint41);
	cout << endl;

	// ϴ��
	srand((unsigned int)time(NULL));//�������
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint41);
	cout << endl;

	//�ϲ�
	vector<int>v1;
	vector<int>v2;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
		//���Թ۲�һ������������һ�������
		//v2.push_back(10-i);
	}
	//���Թ۲�һ������������һ�������
	/*for_each(v1.begin(), v1.end(), myPrint41);
	cout << endl; 
	for_each(v2.begin(), v2.end(), myPrint41);
	cout << endl;*/
	vector<int>vTarget;
	vTarget.resize(v1.size() + v2.size());//Ԥ���ռ�
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), myPrint41);
	cout << endl;

	// ��ת
	reverse(vTarget.begin(), vTarget.end());
	for_each(vTarget.begin(), vTarget.end(), myPrint41);
	cout << endl;
}





int main41()
{
	test01();
	system("pause");
	return 0;
}