#include<iostream>
using namespace std;


//	1. �����������
//	����:
//		�����غ������ò��������࣬����󳣳�Ϊ��������
//		����������ʹ�����ص�()ʱ����Ϊ���ƺ������ã�Ҳ�зº���.
//	���� :
//		����������(�º���)��һ���࣬����һ������



//	2. ��������ʹ��
//	�ص� :
//		������������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
//		���������󳬳���ͨ�����ĸ����������������Լ���״̬
//		���������������Ϊ��������

//	1. ����������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
class MyAdd361
{
public:
	int operator()(int v1,int v2)
	{
		return v1 + v2;
	}
};
//	2. �������󳬳���ͨ�����ĸ����������������Լ���״̬
class MyPrint361
{
public:
	MyPrint361()
	{
		this->count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		this->count++;
	}
	int count;// �ڲ�״̬��¼�����ִ���
};
//	3. �������������Ϊ��������
void doPrint(MyPrint361& mp, string test)
{
	mp(test);
}

static void test01()
{
	cout << "-------------test01()-------------" << endl;
	MyAdd361 myadd;
	cout << myadd(10, 10) << endl;
	MyPrint361 myprint;
	myprint("ljt");
	myprint("ljt");
	myprint("ljt");
	myprint("ljt");
	cout << "���ô�����" << myprint.count << endl;
	doPrint(myprint, "hello world");
}

int main36()
{
	test01();
	system("pause");
	return 0;
}