#include<iostream>
using namespace std;
#include<string>

/*
			C++����ģ�ͺ�thisָ��
*/



//���ڵ�  ��Ա����  ��  ��Ա����  �ֿ��洢
//��C++�У�ֻ�зǾ�̬��Ա������������Ķ�����
class Person171
{

};
static void test01()
{
	cout << "-------------test01()-------------" << endl;

	Person171 p;
	// �ն���ռ���ڴ�ռ�Ϊ��1
	// C++���������ÿ���ն���Ҳ����һ���ֽڿռ䣬��Ϊ�����ֿն���ռ�ڴ��λ��
	// ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
	cout << "size of p =:" << sizeof(p) << endl;
	cout << "address of p =:" << &p << endl;
}

class Person172
{
	int m_A;// �Ǿ�̬��Ա����	������Ķ����ϵ�

	static int m_B;// ��̬��Ա����	�������������

	void func() {};// �Ǿ�̬��Ա����	������������ϣ�������Ҳֻ��һ�ݣ�

	static void func2() {};// ��̬��Ա����	�������������
};
int Person172::m_B = 100;

static void test02()
{
	cout << "-------------test02()-------------" << endl;

	Person172 p;
	// ռ���ڴ�ռ�Ϊ��4
	// ��m_A
	cout << "size of p =:" << sizeof(p) << endl;
	cout << "address of p =:" << &p << endl;//��test01һ����ַ��C++���ڴ���ĺܿ�
}



// thisָ�����;
// thisָ�����
// ��C++�г�Ա�����ͳ�Ա�����Ƿֿ��洢��
// ÿһ���Ǿ�̬��Ա����ֻ�ᵮ��һ�ݺ���ʵ����Ҳ����˵���ͬ���͵Ķ���Ṳ��һ�����
// ��ô������: ��һ���������������Ǹ���������Լ����� ?
// 
// C++ͨ���ṩ����Ķ���ָ�룬thisָ�룬����������⡣thisָ��ָ�򱻵��õĳ�Ա���������Ķ���˭����thisָ˭��
// thisָ��������ÿһ���Ǿ�̬��Ա�����ڵ�һ��ָ��
// thisָ�벻��Ҫ���壬ֱ��ʹ�ü���
// 
// thisָ�����; :
// ���βκͳ�Ա����ͬ��ʱ������thisָ��������
// ����ķǾ�̬��Ա�����з��ض�������ʹ��return * this
class Person173
{
public:
	Person173(int age)
	{
		age = age;//������Ϊ������age��ͬһ��
	}
	int age;// ������û�������ֵ
};
class Person174
{
public:
	Person174(int age)
	{
		// thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
		this->age = age;
	}
	// �������&�����ǵ��ÿ���������
	// �������&��ÿ�ζ��᷵��һ���µĶ��󣬶�p2�ĸı佫ֻ�����ڵ�һ��
	Person174& PersonAddAge(Person174 &p)// ����ָ�����ڴ棬�������þ��ǿ����ˣ�������ָ����һ���ڴ�
	{
		this->age += p.age;// ���˵�������Լ�������

		return *this;//   thisָ��p2����*thisָ��ľ���p2���������
	}

	int age;
};
// 1. ������Ƴ�ͻ
static void test03()
{
	cout << "-------------test03()-------------" << endl;

	Person173 p1(18);
	cout << "p1������Ϊ:" << p1.age << endl;
	Person174 p2(18);
	cout << "p2������Ϊ:" << p2.age << endl;

}
// 2. ���ض�������this
static void test04()
{
	cout << "-------------test04()-------------" << endl;

	Person174 p1(10);
	Person174 p2(18);
	p2.PersonAddAge(p1);
	cout << "p2����p1������Ϊ:" << p2.age << endl;

	// ��ʽ���˼��
	// ��string + stringҲ��������
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
	// �������&��ÿ�ζ��᷵��һ���µĶ��󣬶�p2�ĸı佫ֻ�����ڵ�һ��
	cout << "p2�ټ���p1����p1����p1����p1������Ϊ:" << p2.age << endl;
}



// ��ָ����ʳ�Ա����
// C++�п�ָ��Ҳ�ǿ��Ե��ó�Ա�����ģ�����ҲҪע����û���õ�thisָ��
// ����õ�thisָ�룬��Ҫ�����жϱ�֤����Ľ�׳��
class Person175
{
public:
	void showClassName()
	{
		cout << "this is Person175 class" << endl;
	}
	void showClassAge()
	{
		// ��������Ͳ�����ˣ�������ߴ��뽡׳��
		/*if (this == NULL)
		{
			cout << "this is NULL pointer" << endl;
			return;
		}*/
		cout << "age=" << this->age << endl;
	}
	int age;

	void showStaticAge()
	{
		cout << "s_age=" << s_age << endl;
	}
	static int s_age;
};
int Person175::s_age = 105;

static void test05()
{
	cout << "-------------test05()-------------" << endl;

	Person175* p = NULL;
	p->showClassName();//����û��

	//p->showClassAge();//������ˣ���Ϊһ����ָ��û��ʵ�壬�������age���϶�����
	// ����Ů���Ѷ�û�У���ô����Ů���ѵ�����
	p->showStaticAge();// ��̬�Ϳ��Է���
}



// const���γ�Ա����
//	������:
//		��Ա�������const�����ǳ�Ϊ�������Ϊ������
//		�������ڲ������޸ĳ�Ա����
//		��Ա��������ʱ�ӹؼ���mutable���ɱ�� �ױ�ģ����ڳ���������Ȼ�����޸�
// 
//	������ :
//		��������ǰ��const�Ƹö���Ϊ������
//		������ֻ�ܵ��ó�����

//	������
class Person176
{
public:

	// thisָ��ı��ʣ���ָ�볣����ָ���ָ���ǲ������޸ĵģ�����
	// Person176* const this;
	// �������thisָ��ָ���ֵҲ�������޸�,����
	// const Person176* const this;// ָ�볣���ӳ���ָ�� = һ��Ҳ�䲻��
	// �ڳ�Ա���������const�����ε���this��ָ����thisָ��ָ���ֵҲ�������޸�
	void showPerson() const//const����д�ں��棬��Ȼ�Ͳ��ǳ������ˣ�д��ǰ��ͳ������η���ֵ�����ˣ�
	{
		//m_A = 100;//����������޸���Ŷ
		this->m_B = 100;//����������޸���Ŷ
		cout << "m_B=" << this->m_B << endl;

		//this = NULL;// this��ָ��Ҳ�������޸�Ŷ
	}
	void func() 
	{
		m_A = 100;
	};//�� ������

	int m_A;
	mutable int m_B;// �����������ʹ�ڳ������У�Ҳ�����޸����ֵ���ӹؼ���mutable

	// ����������޸ľ�̬������ֵ
	static int s_A;
};
int Person176::s_A= 105;
static void test06()
{
	cout << "-------------test06()-------------" << endl;

	Person176 p;
	p.showPerson();
}

//	������ 
static void test07()
{
	cout << "-------------test07()-------------" << endl;

	const Person176 p;//����ǰ��const����Ϊ������
	//p.m_A = 100;//������������޸�
	p.m_B = 100;// m_B�Ƚ����⣬��������Ҳ���޸�
	// ������ֻ�ܵ��ó�����
	p.showPerson();
	//p.func();//����������Ա���������ݵ������޶���
	// �����Ե�����ͨ��Ա��������Ϊ��ͨ��Ա���������޸�����
	// func()��������޸ı�����Ҫ���ܵ��������Ϳ��Բ����޸��ˣ�����m_A�������Աز����Ե���
	
	
	// ����������޸ľ�̬������ֵ
	cout << "p.s_A =" << p.s_A << endl;
	p.s_A = 106;
	cout << "p.s_A =" << p.s_A << endl;
}



int main17()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();

	system("pause");
	return 0;
}
