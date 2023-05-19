#include<iostream>
using namespace std;

/*
C++����������������Ϊ��
		��װ
		�̳�
		��̬
*/
/*

/*
			��̬
*/

// ��̬��Ϊ����
//	��̬��̬ : �������غ�������������ھ�̬��̬�����ú�������
//	��̬��̬ : ��������麯��ʵ������ʱ��̬
// 
// ��̬��̬�Ͷ�̬��̬����:
//	��̬��̬�ĺ�����ַ��� - ����׶�ȷ��������ַ
//	��̬��̬�ĺ�����ַ��� - ���н׶�ȷ��������ַ

class Animal211
{
public:
	void speak()
	{
		cout << "������˵��" << endl;
	}
};
class Animal212
{
public:
	// �麯��
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
};

// è��
class Cat211 :public Animal211
{
public:
	// ��д
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};
class Cat212 :public Animal212
{
public:
	// ����Ӳ���virtual����ν
	// C++�涨����һ����Ա����������Ϊ�麯�������������е�ͬ���������Զ���Ϊ�麯����
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};
class Cat213 :public Animal212
{
public:
	// û�з�����д
};
// ����
class Dog211 :public Animal212
{
public:
	void speak()
	{
		cout << "С����˵��" << endl;
	}
};

// ִ��˵���ĺ���
// ��ַ��� - ����׶�ȷ��������ַ
// �����ִ����è˵������ô��������ĵ�ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а󶨣���ַ���
void doSpeak1(Animal211& animal) // Animal211& animal = cat; // ��������ָ��������󣬸���֮�䲻��Ҫǿ������ת��
{
	//�ھ������뿴��ߣ�ִ�п��ұ�
	animal.speak();
}
void doSpeak2(Animal212& animal) // Animal211& animal = cat; // ��������ָ��������󣬸���֮�䲻��Ҫǿ������ת��
{
	//�ھ������뿴��ߣ�ִ�п��ұ�
	animal.speak();
}

// ��̬��̬��������
// 1. �м̳й�ϵ
// 2. ����Ҫ��д������麯����ע�ⲻ�����أ�// ��д	��������ֵ����	������	�����б�	��ȫ��ͬ

// ��̬��̬ʹ��
// �����ָ��������ã�ִ���������

static void test01()
{
	cout << "-------------test01()-------------" << endl;
	Cat211 cat1;
	doSpeak1(cat1);
	Cat212 cat2;
	doSpeak2(cat2);
	Cat213 cat3;
	doSpeak2(cat3);
	Dog211 dog1;
	doSpeak2(dog1);
}



// ��̬ԭ������
static void test02()
{
	cout << "-------------test02()-------------" << endl;
	//	1
	cout << "sizeof(Animal211)" << sizeof(Animal211) << endl;
	//	x86 4	x64	8
	cout << "sizeof(Animal212)" << sizeof(Animal212) << endl;

	// Animal212���ڲ���һ��vfptr
	//	vfptr
	//	v - virtual
	//	f - function
	//  ptr - pointer
	//	�麯��(��)ָ�룬ָ��һ��vftable���麯����
	//	���ڲ���¼�麯����ַ��&Animal212::speak
	// 
	// ���û����д
	// Cat212���Animal212�е�ȫ���̳�����
	// Ҳ����һ��vfptrָ��һ��vftable������Ҳ��&Animal212::speak
	// 
	// ��������д������麯��
	// �����е��麯�����ڲ����滻��������麯����ַ
	// ������Ϊ��&Cat212::speak
	// �������麯��������û�䣩
	// 
	// �������ָ���������ָ���������ʱ�򣬷�����̬
	// 
	// û���麯���Ķ�����
	/*
	class Animal211 size(1) :
		+-- -
		+-- -
	*/
	// ���麯���Ķ�����
	/*
	class Animal212 size(4) :
		+-- -
		0 | {vfptr}
	+ -- -

		Animal212::$vftable@ :
		| &Animal212_meta
		| 0
		0 | &Animal212::speak
	*/
	// û����д��è��
	/*
	class Cat213    size(4) :
		+-- -
		0 | +-- - (base class Animal212)
		0      | | {vfptr}
	| +-- -
		+-- -

		Cat213::$vftable@:
	| &Cat213_meta
		| 0
		0 | &Animal212::speak�������Ƕ���ģ�
	*/
	// ������д��è��
	/*
	class Cat212    size(4) :
		+-- -
		0 | +-- - (base class Animal212)
		0      | | {vfptr}
	| +-- -
		+-- -

		Cat212::$vftable@:
	| &Cat212_meta
		| 0
		0 | &Cat212::speak��������è�ģ�

		Cat212::speak this adjustor : 0
	*/
}



// ��̬���ŵ㣺
//	1. ������֯�ṹ����
//	2. �ɶ���ǿ
//	3. ����ǰ�ںͺ��ڵ���չ�Լ�ά��



// ����1 -- ��������

// ��ͨд��
class CalculatorPT
{
public:
	int getResult(string oper)
	{
		if (oper == "+")
		{
			return m_Num1 + m_Num2;
		}
		else if (oper == "-")
		{
			return m_Num1 - m_Num2;
		}
		else if (oper == "*")
		{
			return m_Num1 * m_Num2;
		}
		// �������չ�µĹ��ܣ���Ҫ�޸�Դ��
		// ����ʵ�����У��ᳫ����ԭ��
		// ����ԭ��:����չ���п��������޸Ľ��йر�
	}
	int m_Num1;
	int m_Num2;
};

// ��̬д��

// ʵ�ּ�����������
class AbstractCalculator
{
public:
	virtual int getResult()
	{
		return 0;
	}

	int m_Num1;
	int m_Num2;
};
// �ӷ�������
class AddCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};
// ����������
class SubCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};
// �˷�������
class MulCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};

static void test03()
{
	cout << "-------------test03()-------------" << endl;
	// ��������������
	CalculatorPT c1;
	c1.m_Num1 = 10;
	c1.m_Num2 = 10;
	cout << c1.m_Num1 << " + " << c1.m_Num2 << " = " << c1.getResult("+") << endl;
	cout << c1.m_Num1 << " - " << c1.m_Num2 << " = " << c1.getResult("-") << endl;
	cout << c1.m_Num1 << " * " << c1.m_Num2 << " = " << c1.getResult("*") << endl;
}
static void test04()
{
	cout << "-------------test03()-------------" << endl;

	// ��̬ʹ������
	// ����ָ���������ָ���������
	// �����û���ָ��ָ����������󣬶������������ʹ��new���㶯̬���ɵģ����ǿ��ܻ������ȷ���ĺ��     ��ʱ��Ҫʹ����������������ûѧ��
	// �ӷ�����
	AbstractCalculator* c1 = new AddCalculator;
	c1->m_Num1 = 2;
	c1->m_Num2 = 3;
	cout << c1->m_Num1 << " + " << c1->m_Num2 << " = " << c1->getResult() << endl;
	// ����ǵ�����
	delete c1;

	// ��������
	AbstractCalculator* c2 = new SubCalculator;
	c2->m_Num1 = 2;
	c2->m_Num2 = 3;
	cout << c2->m_Num1 << " - " << c2->m_Num2 << " = " << c2->getResult() << endl;
	// ����ǵ�����
	delete c2;

	// �˷�����
	AbstractCalculator* c3 = new MulCalculator;
	c3->m_Num1 = 2;
	c3->m_Num2 = 3;
	cout << c3->m_Num1 << " * " << c3->m_Num2 << " = " << c3->getResult() << endl;
	// ����ǵ�����
	delete c3;
}



// ������ͳ�����
//	�ڶ�̬�У�ͨ���������麯����ʵ���Ǻ�������ģ���Ҫ���ǵ���������д������
//
//	��˿��Խ��麯����Ϊ���麯��
//
//	���麯���﷨ : virtual ����ֵ���� ������(�����б�) = 0;
//
// ���������˴��麯���������Ҳ��Ϊ�����ࣨ�е���ӿڣ�
//
// �������ص�
//		�޷�ʵ��������
//		���������д�������еĴ��麯��������Ҳ���ڳ�����
class Base211
{
public:
	// ���麯��
	// ֻҪ��һ�����麯����������Ϊ������
	// 1. �޷�ʵ��������
	virtual void func() = 0;

};
class Son211 :public Base211
{
public:

};
class Son212 :public Base211
{
public:
	virtual void func() {};
};
class Son213 :public Base211
{
public:
	virtual void func() 
	{
		cout << "Son213��func()��������" << endl;
	};
};
static void test05()
{
	cout << "-------------test05()-------------" << endl;
	// 1. �޷�ʵ��������
	//Base211 b;
	//new Base211;

	// 2. ����������������д�������еĴ��麯��������Ҳ���ڳ�����
	//Son211 s;
	Son212 s2;// ����һ�����ûд��Ҳ�������Ͼ���д��
	Base211* base = new Son213;
	base->func();// ��̬����
}



// ����2 -- ������Ʒ

// ��ˮ -> ���� -> ���뱭�� -> ���븨��
// ��ˮ -> ���ݿ��� -> ���뱭�� -> ���Ǻ�ţ��
// ��ˮ -> ���ݲ�Ҷ -> ���뱭�� -> ������
// 
class AbstractDrinking
{
public:
	// ��ˮ
	virtual void Boil() = 0;

	// ����
	virtual void Brew() = 0;

	// ���뱭��
	virtual void PourInCup() = 0;

	// ���븨��
	virtual void PutSomething() = 0;

	// ������Ʒ
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

// ��������
class Coffee :public AbstractDrinking
{
public:
	// ��ˮ
	virtual void Boil()
	{
		cout << "��ũ��ɽȪ" << endl;
	}

	// ����
	virtual void Brew()
	{
		cout << "���ݿ���" << endl;
	}

	// ���뱭��
	virtual void PourInCup() 
	{
		cout << "���뱭��" << endl;
	}

	// ���븨��
	virtual void PutSomething()
	{
		cout << "���Ǻ�ţ��" << endl;
	}
};

// ���ݲ�Ҷ
class Tea :public AbstractDrinking
{
public:
	// ��ˮ
	virtual void Boil()
	{
		cout << "���Ȫˮ" << endl;
	}

	// ����
	virtual void Brew()
	{
		cout << "���ݲ�Ҷ" << endl;
	}

	// ���뱭��
	virtual void PourInCup()
	{
		cout << "���뱭��" << endl;
	}

	// ���븨��
	virtual void PutSomething()
	{
		cout << "�������" << endl;
	}
};
// ��������
void doWork(AbstractDrinking *abs)// AbstractDrinking *abs = new Coffee/Tea
{
	abs->makeDrink();
	delete abs;
}
static void test06()
{
	cout << "-------------test06()-------------" << endl;
	doWork(new Coffee);
	doWork(new Tea);
}



// �������ʹ�������
//	��̬ʹ��ʱ����������������Կ��ٵ���������ô����ָ�����ͷ�ʱ�޷����õ�������������루ֻ������Լ�������������
//	
//	�����ʽ : �������е�����������Ϊ���������ߴ�������
//
//	�������ʹ����������� :
//		1. ���Խ������ָ���ͷ��������.
//		2. ����Ҫ�о���ĺ���ʵ��
//	�������ʹ����������� :
//		- ����Ǵ����������������ڳ����࣬�޷�ʵ��������
//
//	�������﷨ :
//	virtual ~����(){}
//	���������﷨ :
//	virtual ~����() = 0;
//	����::~����(){}
class Animal213
{
public:
	Animal213()
	{
		cout << "Animal213���캯������" << endl;
	}
	// ���麯��
	virtual void speak() = 0;

	// Cat�����Լ����������м̳е��������ø���ָ��Ĭ�ϵ���������������Ը����дΪ������
	// ������
	// �������������Խ������ָ���ͷ��������ʱ���ɾ�������
	// ��Ϊ�鹹�������������鹹����֮�󣬻�ָ�������鹹
	/*virtual ~Animal213()
	{
		cout << "Animal213��������������" << endl;
	}*/
	
	
	/*�鹹������ǵ��ø�����鹹�������������ﲢ����һ������������ͬʱ���ø�����������������;
	�����ȵ������������������������������ø������������Ļ�ϳ��ģ�*/
	
	// ��������
	// �ʹ��麯��һ����������������ҲҪ�У���Ȼ���Ǻðְ�
	// �޷��������ⲿ������ӽ׶γ����ˣ�
	// Ҳ����˵����ʹ������������ʱ�������������������������������������˵���
	// ���Դ�������Ҳ��Ҫ����ʵ��
	// �﷨ǿ�ƴ����������������к���ʵ��, ��Ϊ��ʱ����Ҳ��һЩ���ݿ����ڶ���������˵���׵��������뱻���ã����鲻ʵ�ֵĻ��᲻֪����ô������
	// ��Ҫʹ�ô��麯������Ҫ�ͷŸ����ڶ����е����ݣ�����Ҫʹ�����ڴ��麯������������дʵ�ֵ�д��
	virtual ~Animal213() = 0;

	// �������ʹ���������һ��������
	// ���˴��������Ժ������Ҳ���ڳ����࣬�޷�ʵ��������
	// ���û�к��ʵĺ�����Ϊ���麯�����Ͱ�����������Ϊ���麯��
};

Animal213::~Animal213()
{
	cout << "Animal213����������������" << endl;
}

class Cat214 :public Animal213
{
public:
	Cat214(string name)
	{
		cout << "Cat214���캯������" << endl;
		m_Name = new string(name);
	}
	// ��д
	virtual void speak()
	{
		cout << *m_Name << "Сè214��˵��" << endl;
	}
	string *m_Name;

	~Cat214()
	{
		if (m_Name != NULL)	// �������û���������������в��ᱻִ�е�
		// ����ָ��������ʱ�����������������������������������ж������ԣ������ڴ�й¶
		{
			cout << "Cat214������������" << endl;
			delete m_Name; // ͨ�ף�delete������ָ��ָ��Ķ����ڴ档ָ���Լ�û��delete��
			// delete���ָ��ָ����ڴ�Ȩ���ͷţ�������ڴ���Ա���������ʹ��
			m_Name = NULL;// ������ָ
		}
	}

};
static void test07()
{
	cout << "-------------test07()-------------" << endl;
	Animal213* animal = new Cat214("Tom");
	animal->speak();
	// ����ָ��������ʱ�����������������������������������ж������ԣ������ڴ�й¶
	// Cat�����Լ����������м̳е��������ø���ָ��Ĭ�ϵ���������������Ը����дΪ������
	delete animal;
}
// 1. �������������������������ͨ������ָ���ͷ��������
// 2. ���������û�ж������ݣ����Բ�дΪ��������������
// 3. ӵ�д���������������Ҳ���ڳ�����



// ����3 -- ������װ
// 
// �������
// ������Ҫ��ɲ���Ϊ CPU(���ڼ���)  �Կ�(������ʾ) ���ڴ���(���ڴ洢)
// ��ÿ�������װ��������࣬�����ṩ��ͬ�ĳ���������ͬ�����������lntel���̺�Lenovo����
// �����������ṩ�õ��Թ����ĺ��������ҵ���ÿ����������Ľӿ�
// ����ʱ��װһ̨��ͬ�ĵ��Խ��й���


// ����ͬ�����
// ����CPU��
class Cpu
{
public:
	// ����ļ��㺯��
	virtual void calculate() = 0;
};

// �����Կ���
class VideoCard
{
public:
	// �������ʾ����
	virtual void display() = 0;
};

// �����ڴ�����
class Memory
{
public:
	// ����Ĵ洢����
	virtual void storage() = 0;
};

// ������
class Computer
{
public:
	Computer(Cpu* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	//�ṩ�����ĺ���
	void work()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	// �ṩ��������,�ͷ��������Ե����
	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu; 
			m_cpu = NULL;
		}
		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}
private:

	Cpu* m_cpu; // CPU�����ָ��
	VideoCard* m_vc; // �Կ������ָ��
	Memory* m_mem; // C�ڴ��������ָ��
};

// ���峧��
// Intel����
class IntelCPU :public Cpu
{
public:
	virtual void calculate()
	{
		cout << "Intel��CPU��ʼ����!!" << endl;
	}
};
class IntelVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Intel��VideoCard��ʼ��ʾ!!" << endl;
	}
};
class IntelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel��Memory��ʼ�洢!!" << endl;
	}
};
// Lenovo����
class LenovoCPU :public Cpu
{
public:
	virtual void calculate()
	{
		cout << "Lenovo��CPU��ʼ����!!" << endl;
	}
};
class LenovoVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Lenovo��VideoCard��ʼ��ʾ!!" << endl;
	}
};
class LenovoMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo��Memory��ʼ�洢!!" << endl;
	}
};


static void test08()
{
	cout << "-------------test08()-------------" << endl;
	// ��һ̨�������
	Cpu* intelCpu = new IntelCPU;
	VideoCard* intelCard = new IntelVideoCard;
	Memory* intelMem = new IntelMemory;

	// ������һ̨����
	Computer* computer1 = new Computer(intelCpu, intelCard, intelMem);
	computer1->work();
	delete computer1;
	// �����д��������,����û��,�����������

	// �ڶ�̨������װ
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;

	// ����̨������װ
	Computer* computer3 = new Computer(new IntelCPU, new LenovoVideoCard, new LenovoMemory);
	computer3->work();
	delete computer3;
	// �������������������ã�����û��new�ռ�
}

int main21()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	system("pause");
	return 0;
}