#include<iostream>
using namespace std;

// operator �� C++ ��һ���ؼ��֣�������������� =��һ��ʹ�ã���ʾһ����������غ�����
// �����ʱ�ɽ� operator �ʹ����ص���������壨�� operator=����Ϊһ����������




// �������������
// ���ã���������Զ������������

class Person192
{
	// �����Ԫ��������˽�б���
	friend ostream& operator<<(ostream& out, Person192& p);
public:

	Person192(int a,int b)
	{
		m_A = a;
		m_B = b;
	}

	// ���ó�Ա�������أ����������		p.operator<<(cout)	�򻯰汾 p << cout
	// cout������һ������
	// cout�����������ostream��������ȫ��ֻ����һ�������Ե������õķ�ʽ����ȥ
	// ͨ���������ó�Ա��������<<���������Ϊ�޷�ʵ��cout�����
	void operator<<(ostream& cout)
	{
		cout << "���ó�Ա�����������������" << m_A << endl;
		cout << "���ó�Ա�����������������" << m_B << endl;
	}

private:
	int m_A;
	int m_B;
};

// ����ֻ������ȫ�ֺ����������������
// cout�����������ostream��������ȫ��ֻ����һ�������Ե������õķ�ʽ����ȥ
ostream& operator<<(ostream& out, Person192& p)// ����	operator<<(cout, p)	��	cout << p
{
	// ���ñ��ʾ�����������������д��out����cout����ν���ȼ۵ģ������м��õ�out�������õ�cout������ȫ��ֻ��һ����
	out << "����ȫ�ֺ����������������" << p.m_A << endl;
	out << "����ȫ�ֺ����������������" << p.m_B << endl;

	return cout;
}

static void test02()
{
	cout << "-------------test02()-------------" << endl;
	Person192 p(10, 20);

	//cout << p << endl;// E0349	û������Щ������ƥ��� "<<" �����	
	p << cout;// ��Ա�������أ��޷�ʵ��cout�����

	cout << p ;// ȫ�ֺ�������
	//cout << p << endl;//�ᱨ����Ϊ�Ƿ���ֵ������void����ʵ�ֵ�����ʽ���˼��
	cout << p << endl; // ����ֵ��Ϊostream&�ͺ���

}



int main()
{
	test02();
	system("pause");
	return 0;
}