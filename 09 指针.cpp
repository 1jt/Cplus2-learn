//#include<iostream>
//using namespace std;
//void swap01(int num1, int num2);
//void swap01(int *p1, int *p2);
//
//int main()
//{
//	// ����ָ��
//	int a = 10;
//	// ָ�붨����﷨���������� * ָ�������
//	int * p;
//
//	// ����ͨ�������õķ�ʽ���ҵ�ָ��ָ����ڴ�
//	// ��ָ��ǰ�� * 
//	p = &a;
//	cout << "a�ĵ�ַΪ��" << &a << endl;
//	cout << "ָ��pΪ��" << p << endl;
//	cout << "ָ��pָ����ڴ�Ϊ��" << *p << endl;
//
//	// ��ռ�ڴ�ռ�
//	cout << "ָ��ռ���ڴ�ռ�Ϊ��" << sizeof(p) << endl;
//	cout << "ָ��ռ���ڴ�ռ�Ϊ��" << sizeof(float *) << endl;
//	cout << "ָ��ռ���ڴ�ռ�Ϊ��" << sizeof(double *) << endl;
//	cout << "ָ��ռ���ڴ�ռ�Ϊ��" << sizeof(char *) << endl;
//	// 32λ4�ֽڣ�64λ8�ֽ�
//	cout << "ָ��ָ��ռ���ڴ�ռ�Ϊ��" << sizeof(*p) << endl;
//
//	// ��ָ��
//	// �ڴ��б��Ϊ0�Ŀռ�
//	// ��;����ʼ��ָ�����
//	// ��ָ��ָ����ڴ��ǲ����Է��ʵ�
//	int* pp = NULL;
//	cout << "ָ��ppΪ��" << pp << endl;
//	//*pp = 100;
//	// 0 ~ 255֮����ڴ�����ϵͳռ�õģ������Է���
//	
//
//	// Ұָ��
//	// ָ�����ָ��Ƿ����ڴ�ռ�
//	int * ppp = (int *)0x1100;
//	// ����Ұָ��ᱨ��
//	// cout  << *ppp << endl;
//	// ��ָ���Ұָ�붼������������Ŀռ䣬��˲�Ҫ����
//
//	// const ����ָ�������������
//	// 1. const ����ָ�� --����ָ��
//	// 2. const ���γ��� --ָ�볣��
//	// 3. const ������ָ�룬�����γ���
//	// 1. 
//	int aa = 10;
//	int bb = 10;
//	const int* pa = &aa;
//	cout << "ָ��pa���ڴ�Ϊ(aa)��" << pa << endl;
//	// ָ��ָ����Ըģ�ָ��ָ���ֵ�����Ը�
//	// *pa = 20; �ᱨ����
//	pa = &bb;
//	cout << "ָ��pa���ڴ�Ϊ(bb)��" << pa << endl;
//
//	// 2. 
//	int* const pb = &a;
//	// ָ���ָ�򲻿��Ըģ�ָ��ָ���ֵ���Ը�
//	*pb = 20;
//	// pb = &bb; �ᱨ����
//
//	// 3.
//	const int* const pc = &aa;
//	// ָ���ָ���ָ��ָ���ֵ�������Ը�
//	// *pc = 20;
//	// pc = &bb; ���ᱨ����
//	// ��˭ǰ��˭���ܸ�
//
//
//	// ָ�������
//	// ����ָ�����������Ԫ��
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	cout << "��һ��Ԫ��Ϊ��" << arr[0] << endl;
//
//	p = arr;// arr���������׵�ַ
//	cout << "����ָ����ʵ�һ��Ԫ��" << *p << endl;
//	p++;
//	cout << "����ָ����ʵڶ���Ԫ��" << *p << endl;
//	cout << "����ָ���������" << endl;
//	int* p2 = arr;
//
//	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		cout << *p2 << endl;
//		p2++;
//	}
//
//	// ָ��ͺ���
//	// 1. ֵ����
//	a = 10;
//	int b = 20;
//	swap01(a, b);
//	cout << a << endl;
//	cout << b << endl;
//
//
//	// 2. ��ַ����
//	swap01(&a, &b);
//	cout << a << endl;
//	cout << b << endl;
//
//	system("pause");
//
//	
//	return 0;
//}
//void swap01(int num1, int num2)
//{
//	cout << "before swap" << endl;
//	cout << "num1 = " << num1 << endl;
//	cout << "num2 = " << num2 << endl;
//
//	int tmp = num1;
//	num1 = num2;
//	num2 = tmp;
//
//	cout << "after swap" << endl;
//	cout << "num1 = " << num1 << endl;
//	cout << "num2 = " << num2 << endl;
//}
//void swap01(int* p1, int* p2)
//{
//	int temp = *p1;
//	*p1 = *p2;
//	*p2 = temp;
//}
//
