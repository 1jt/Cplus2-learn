#include<iostream>
#include<string>

using namespace std;

/*
			���������
*/


// ���������������ͣ�������֪����ν������㣬�����Զ�������������أ�
// �����е���������½��ж��壬��������һ�ֹ��ܣ�����Ӧ��ͬ����������
// �������õĲ��ɸı�
// ��Ҫ�������������

// operator �� C++ ��һ���ؼ��֣�������������� =��һ��ʹ�ã���ʾһ����������غ�����
// �����ʱ�ɽ� operator �ʹ����ص���������壨�� operator=����Ϊһ����������

// ���ַ�ʽ��ͨ����Ա��������	ͨ��ȫ�ֺ�������



// �Ӻ����������
// ���ã�ʵ�������Զ�������������ӵ�����
// p1 operator+ p2
class Person191
{
public:
	// 1. ͨ����Ա��������
	Person191 operator+(Person191& p)
	{
		Person191 temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}
	int m_A;
	int m_B;
};
// 2. ͨ��ȫ�ֺ�������
//Person191 operator+(Person191& p1, Person191& p2)
//{
//	Person191 temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}

// ��������أ�Ҳ���Է�����������
Person191 operator+(Person191& p1, int num)
{
	Person191 temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}

static void test01()
{
	cout << "-------------test01()-------------" << endl;
	Person191 p1;
	p1.m_A = 10;
	p1.m_B = 11;
	Person191 p2;
	p2.m_A = 12;
	p2.m_B = 13;

	Person191 p3 = p1 + p2;
	cout << "p3.m_A:" << p3.m_A << endl;
	cout << "p3.m_B:" << p3.m_B << endl;
	// ��Ա�������ر��ʵ���
	//Person191 p3 = p1.operator+(p2);
	// ��Ա�������ر��ʵ���
	//Person191 p3 = operator+(p1, p2);

	// ��������أ�Ҳ���Է�����������
	p3 = p3 + 15;
	cout << "p3.m_A:" << p3.m_A << endl;
	cout << "p3.m_B:" << p3.m_B << endl;

}



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



// �������������
// ���ã�ͨ�����ص����������ʵ���Լ�����������
class MyInteger19
{
	friend ostream& operator<<(ostream& out, MyInteger19 myint);
public:
	MyInteger19()
	{
		m_Num = 0;
	}
	// ����ǰ��++�����
	MyInteger19& operator++()// ����Ҫ������
		// ����ֵ���������ͣ���Ϊ����ʽ���˼�룬����һֱ��һ�����ݽ��е���	e.g.:++(++a)	(���ֿ�������)
	{
		// �Ƚ���++����
		m_Num++;
		// �ٽ�������һ������
		return *this;
	}

	// ���غ���++�����
	// int����ռλ������������������ǰ�úͺ��õ���
	MyInteger19 operator++(int)
		// ����ֵ�������������ˣ�����Ϊ���ص�tempֻ��һ����ʱ������������ͱ��ͷŵ��ˣ������þͻ����
		// ���Բ�������ʽ�����Ŷ��ԭ����Ҳ�����ԣ�
	{
		// �ȼ�¼��ʱ���
		MyInteger19 temp = *this;
		// �ٵ���
		m_Num++;
		// ��󽫼�¼�������
		return temp;
	}

private:
	int m_Num;
};
// Ϊ�������������һ��
ostream& operator<<(ostream& out, MyInteger19 myint)
{
	cout << myint.m_Num << endl;
	return cout;
}
static void test03()
{
	cout << "-------------test03()-------------" << endl;
	MyInteger19 myint;
	cout << "myint.m_int:" << myint << endl;
	cout << "++myint:" << ++myint << endl;
	cout << "++(++myint):" << ++(++myint) << endl;
	cout << "myint++:" << myint++ << endl;
	cout << "m_int:" << myint << endl;
	//cout << "(myint++)++:" << (myint++)++ << endl;// ���õ�����������ʽ����(����ԭ����Ҳ������)
}



//	��ֵ���������
//	c++���������ٸ�һ�������4������
//		1.Ĭ�Ϲ��캯��(�޲Σ�������Ϊ��)
//		2.Ĭ����������(�޲Σ�������Ϊ��)
//		3.Ĭ�Ͽ������캯���������Խ���ֵ����
//		4.��ֵ����� operator=, �����Խ���ֵ����
// 
//	�������������ָ�����������ֵ����ʱҲ�������ǳ��������
class Person193
{
public:
	Person193(int age)
	{
		m_Age = new int(age);
	}
	~Person193()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}

	// ����	��ֵ�����
	Person193& operator=(Person193 &p)
	{
		// �������ṩ����ǳ����
		// m_Age = p.m_Age;

		// Ӧ�����ж��Ƿ��������ڶ�������������ͷŸɾ���Ȼ�������
		if (m_Age!=NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		// ���
		m_Age = new int(*p.m_Age);

		// Ҳ����ֱ��
		//*m_Age = *p.m_Age;
		// ֱ�ӸĶ������ݣ���������û����

		// ���ض�������
		return *this;
	}

	int* m_Age;
};
static void test04()
{
	cout << "-------------test04()-------------" << endl;
	Person193 p1(18);
	cout << "p1������Ϊ:" << *p1.m_Age << endl;
	Person193 p2(20);
	cout << "p2������Ϊ:" << *p2.m_Age << endl;

	p1 = p2;// ��������صĻ�������һ����򵥵���ֵ���������ֱ���ͷŵĻ�������ǳ�����������ظ��ͷţ�
	cout << "p1������Ϊ:" << *p1.m_Age << endl;
	cout << "p2������Ϊ:" << *p2.m_Age << endl;

	int a = 10;
	int b = 20;
	int c = 30;
	c = b = a;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;//������10����a��

	Person193 p3(30);
	*p1.m_Age = 18;
	p3 = p2 = p1;
	cout << "p1������Ϊ:" << *p1.m_Age << endl;
	cout << "p2������Ϊ:" << *p2.m_Age << endl;
	cout << "p3������Ϊ:" << *p3.m_Age << endl;
}



// ��ϵ���������
// ���ã�ʵ�������Զ����������ͱȽϵ�����
class Person194
{
public:
	Person194(string m_Name,int m_Age)
	{
		this->m_Name = m_Name;
		this->m_Age = m_Age;
	}
	
	//	���� == ��
	bool operator==(Person194& p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return  true;
		}
		else
			return false;
	}
	//	���� != ��
	bool operator!=(Person194& p)
	{
		if (this->m_Name != p.m_Name || this->m_Age != p.m_Age)
		{
			return  true;
		}
		else
			return false;
	}


	string m_Name;
	int m_Age;
};
static void test05()
{
	cout << "-------------test05()-------------" << endl;
	Person194 p1("ljt", 22);
	Person194 p2("ljtt", 22);
	if (p1 == p2)
	{
		cout << "p1��p2����ȵ�" << endl;
	}
	else
	{
		cout << "p1��p2�ǲ���ȵ�" << endl;
	}
	if (p1 != p2)
	{
		cout << "p1��p2�ǲ���ȵ�" << endl;
	}
	else
	{
		cout << "p1��p2����ȵ�" << endl;
	}
}



// �����������������
//	�������������()Ҳ��������
//	�������غ�ʹ�õķ�ʽ�ǳ������ĵ��ã���˳�Ϊ�º���
//	�º���û�й̶�д�����ǳ����

//	��ӡ�����
class MyPrint19
{
public:
	// ���غ������������
	void operator()(string test)
	{
		cout << "testΪ��" << test << endl;
	}
};
//	�º���û�й̶�д�����ǳ����
//	�ӷ���
class MyAdd19
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};

static void test06()
{
	cout << "-------------test06()-------------" << endl;
	MyPrint19 myprint;
	myprint("hello world");// ����ʹ�������ǳ������ں������ã���˳�Ϊ�º���
	MyAdd19 myadd;
	int ret = myadd(100, 101);
	cout << "ret=" << ret << endl;

	// ������������
	cout << MyAdd19()(102, 103) << endl;
}


int main19()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	system("pause");
	return 0;
}