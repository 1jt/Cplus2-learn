#include<iostream>
using namespace std;

// ���ã������������
// �﷨���������� &���� = ԭ��
// �������ڲ���*��ָ�룩

int main()
{
	int a = 10;
	cout << "�޸�ǰ��" << a << endl;
	int& b = a;
	b = 20;
	cout << "�޸ĺ�" << a << endl;

	// ע������
	// 1. ���ñ����ʼ��
	// 2. �����ڳ�ʼ���󣬲����Ըı�

	system("pause");
	return 0;
}