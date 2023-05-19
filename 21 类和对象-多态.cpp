#include<iostream>
using namespace std;

/*
C++面向对象的三大特性为：
		封装
		继承
		多态
*/
/*

/*
			多态
*/

// 多态分为两类
//	静态多态 : 函数重载和运算符重载属于静态多态，复用函数名。
//	动态多态 : 派生类和虚函数实现运行时多态
// 
// 静态多态和动态多态区别:
//	静态多态的函数地址早绑定 - 编译阶段确定函数地址
//	动态多态的函数地址晚绑定 - 运行阶段确定函数地址

class Animal211
{
public:
	void speak()
	{
		cout << "动物在说话" << endl;
	}
};
class Animal212
{
public:
	// 虚函数
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

// 猫类
class Cat211 :public Animal211
{
public:
	// 重写
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};
class Cat212 :public Animal212
{
public:
	// 这儿加不加virtual无所谓
	// C++规定，当一个成员函数被声明为虚函数后，其派生类中的同名函数都自动成为虚函数。
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};
class Cat213 :public Animal212
{
public:
	// 没有发生重写
};
// 狗类
class Dog211 :public Animal212
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};

// 执行说话的函数
// 地址早绑定 - 编译阶段确定函数地址
// 如果想执行让猫说话，那么这个函数的地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定
void doSpeak1(Animal211& animal) // Animal211& animal = cat; // 父类引用指向子类对象，父子之间不需要强制类型转换
{
	//口诀：编译看左边，执行看右边
	animal.speak();
}
void doSpeak2(Animal212& animal) // Animal211& animal = cat; // 父类引用指向子类对象，父子之间不需要强制类型转换
{
	//口诀：编译看左边，执行看右边
	animal.speak();
}

// 动态多态满足条件
// 1. 有继承关系
// 2. 子类要重写父类的虚函数（注意不是重载）// 重写	函数返回值类型	函数名	参数列表	完全相同

// 动态多态使用
// 父类的指针或者引用，执行子类对象

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



// 多态原理剖析
static void test02()
{
	cout << "-------------test02()-------------" << endl;
	//	1
	cout << "sizeof(Animal211)" << sizeof(Animal211) << endl;
	//	x86 4	x64	8
	cout << "sizeof(Animal212)" << sizeof(Animal212) << endl;

	// Animal212类内部有一个vfptr
	//	vfptr
	//	v - virtual
	//	f - function
	//  ptr - pointer
	//	虚函数(表)指针，指向一个vftable（虚函数表）
	//	表内部记录虚函数地址：&Animal212::speak
	// 
	// 如果没有重写
	// Cat212会把Animal212中的全部继承下来
	// 也会有一个vfptr指向一个vftable，里面也是&Animal212::speak
	// 
	// 当子类重写父类的虚函数
	// 子类中的虚函数表内部会替换成子类的虚函数地址
	// 即：换为了&Cat212::speak
	// （父类虚函数表里面没变）
	// 
	// 当父类的指针或者引用指向子类对象时候，发生多态
	// 
	// 没有虚函数的动物类
	/*
	class Animal211 size(1) :
		+-- -
		+-- -
	*/
	// 有虚函数的动物类
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
	// 没有重写的猫类
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
		0 | &Animal212::speak（发现是动物的）
	*/
	// 发生重写的猫类
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
		0 | &Cat212::speak（发现是猫的）

		Cat212::speak this adjustor : 0
	*/
}



// 多态的优点：
//	1. 代码组织结构清晰
//	2. 可读性强
//	3. 利于前期和后期的扩展以及维护



// 案例1 -- 计算器类

// 普通写法
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
		// 如果想扩展新的功能，需要修改源码
		// 在真实开发中，提倡开闭原则
		// 开闭原则:对扩展进行开发，对修改进行关闭
	}
	int m_Num1;
	int m_Num2;
};

// 多态写法

// 实现计算器抽象类
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
// 加法计算器
class AddCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};
// 减法计算器
class SubCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};
// 乘法计算器
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
	// 创建计算器对象
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

	// 多态使用条件
	// 父类指针或者引用指向子类对象
	// 当利用基类指针指向派生类对象，而派生类对象是使用new运算动态生成的，这是可能会产生不确定的后果     此时需要使用虚析构函数（还没学）
	// 加法运算
	AbstractCalculator* c1 = new AddCalculator;
	c1->m_Num1 = 2;
	c1->m_Num2 = 3;
	cout << c1->m_Num1 << " + " << c1->m_Num2 << " = " << c1->getResult() << endl;
	// 用完记得销毁
	delete c1;

	// 减法运算
	AbstractCalculator* c2 = new SubCalculator;
	c2->m_Num1 = 2;
	c2->m_Num2 = 3;
	cout << c2->m_Num1 << " - " << c2->m_Num2 << " = " << c2->getResult() << endl;
	// 用完记得销毁
	delete c2;

	// 乘法运算
	AbstractCalculator* c3 = new MulCalculator;
	c3->m_Num1 = 2;
	c3->m_Num2 = 3;
	cout << c3->m_Num1 << " * " << c3->m_Num2 << " = " << c3->getResult() << endl;
	// 用完记得销毁
	delete c3;
}



// 纯虚类和抽象类
//	在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
//
//	因此可以将虚函数改为纯虚函数
//
//	纯虚函数语法 : virtual 返回值类型 函数名(参数列表) = 0;
//
// 当类中有了纯虚函数，这个类也称为抽象类（有点像接口）
//
// 抽象类特点
//		无法实例化对象
//		子类必须重写抽象类中的纯虚函数，否则也属于抽象类
class Base211
{
public:
	// 纯虚函数
	// 只要有一个纯虚函数，这个类称为抽象类
	// 1. 无法实例化对象
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
		cout << "Son213的func()函数调用" << endl;
	};
};
static void test05()
{
	cout << "-------------test05()-------------" << endl;
	// 1. 无法实例化对象
	//Base211 b;
	//new Base211;

	// 2. 抽象类的子类必须重写抽象类中的纯虚函数，否则也属于抽象类
	//Son211 s;
	Son212 s2;// 就算一点代码没写，也不报错，毕竟重写了
	Base211* base = new Son213;
	base->func();// 多态调用
}



// 案例2 -- 制作饮品

// 煮水 -> 冲泡 -> 倒入杯中 -> 加入辅料
// 煮水 -> 冲泡咖啡 -> 倒入杯中 -> 加糖和牛奶
// 煮水 -> 冲泡茶叶 -> 倒入杯中 -> 加柠檬
// 
class AbstractDrinking
{
public:
	// 煮水
	virtual void Boil() = 0;

	// 冲泡
	virtual void Brew() = 0;

	// 倒入杯中
	virtual void PourInCup() = 0;

	// 加入辅料
	virtual void PutSomething() = 0;

	// 制作饮品
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

// 制作咖啡
class Coffee :public AbstractDrinking
{
public:
	// 煮水
	virtual void Boil()
	{
		cout << "煮农夫山泉" << endl;
	}

	// 冲泡
	virtual void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}

	// 倒入杯中
	virtual void PourInCup() 
	{
		cout << "倒入杯中" << endl;
	}

	// 加入辅料
	virtual void PutSomething()
	{
		cout << "加糖和牛奶" << endl;
	}
};

// 冲泡茶叶
class Tea :public AbstractDrinking
{
public:
	// 煮水
	virtual void Boil()
	{
		cout << "煮矿泉水" << endl;
	}

	// 冲泡
	virtual void Brew()
	{
		cout << "冲泡茶叶" << endl;
	}

	// 倒入杯中
	virtual void PourInCup()
	{
		cout << "倒入杯中" << endl;
	}

	// 加入辅料
	virtual void PutSomething()
	{
		cout << "加入枸杞" << endl;
	}
};
// 制作函数
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



// 虚析构和纯虚析构
//	多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码（只会调用自己的析构函数）
//	
//	解决方式 : 将父类中的析构函数改为虚析构或者纯虚析构
//
//	虚析构和纯虚析构共性 :
//		1. 可以解决父类指针释放子类对象.
//		2. 都需要有具体的函数实现
//	虚析构和纯虚析构区别 :
//		- 如果是纯虚析构，该类属于抽象类，无法实例化对象
//
//	虚析构语法 :
//	virtual ~类名(){}
//	纯虚析构语法 :
//	virtual ~类名() = 0;
//	类名::~类名(){}
class Animal213
{
public:
	Animal213()
	{
		cout << "Animal213构造函数调用" << endl;
	}
	// 纯虚函数
	virtual void speak() = 0;

	// Cat除了自己的析构还有继承的析构，用父类指针默认调父类的析构，所以父类得写为虚析构
	// 虚析构
	// 利用虚析构可以解决父亲指针释放子类对象时不干净的问题
	// 因为虚构函数变成子类的虚构函数之后，会指挥子类虚构
	/*virtual ~Animal213()
	{
		cout << "Animal213虚析构函数调用" << endl;
	}*/
	
	
	/*虚构父类就是调用父类的虚构函数，所以这里并不是一个虚析构可以同时调用父类和子类的析构函数;
	而是先调用子类的析构，再有子类的析构调用父类的析构（弹幕上抄的）*/
	
	// 纯虚析构
	// 和纯虚函数一样，父类有了子类也要有，不然不是好爸爸
	// 无法解析的外部命令（链接阶段出错了）
	// 也就是说，在使用虚析构函数时，父类的析构函数和子类的析构函数都存在了调用
	// 所以纯虚析构也需要代码实现
	// 语法强制纯虚析构函数必须有函数实现, 因为有时父类也有一些数据开辟在堆区（或者说父亲的析构必须被调用，纯虚不实现的话会不知道怎么析构）
	// 既要使用纯虚函数，又要释放父类在堆区中的数据，就需要使用类内纯虚函数声明，类外写实现的写法
	virtual ~Animal213() = 0;

	// 虚析构和纯虚析构有一个就行了
	// 有了纯虚析构以后，这个类也属于抽象类，无法实例化对象
	// 如果没有合适的函数变为纯虚函数，就把析构函数变为纯虚函数
};

Animal213::~Animal213()
{
	cout << "Animal213纯虚析构函数调用" << endl;
}

class Cat214 :public Animal213
{
public:
	Cat214(string name)
	{
		cout << "Cat214构造函数调用" << endl;
		m_Name = new string(name);
	}
	// 重写
	virtual void speak()
	{
		cout << *m_Name << "小猫214在说话" << endl;
	}
	string *m_Name;

	~Cat214()
	{
		if (m_Name != NULL)	// 如果父类没有虚析构，那这行不会被执行到
		// 父类指针在析构时不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄露
		{
			cout << "Cat214析构函数调用" << endl;
			delete m_Name; // 通俗：delete掉的是指针指向的堆区内存。指针自己没被delete。
			// delete会把指针指向的内存权限释放，让这块内存可以被其他进程使用
			m_Name = NULL;// 避免乱指
		}
	}

};
static void test07()
{
	cout << "-------------test07()-------------" << endl;
	Animal213* animal = new Cat214("Tom");
	animal->speak();
	// 父类指针在析构时不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄露
	// Cat除了自己的析构还有继承的析构，用父类指针默认调父类的析构，所以父类得写为虚析构
	delete animal;
}
// 1. 虚析构或纯虚析构就是用来解决通过父类指针释放子类对象
// 2. 如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
// 3. 拥有纯虚析构函数的类也属于抽象类



// 案例3 -- 电脑组装
// 
// 需求分析
// 电脑主要组成部件为 CPU(用于计算)  显卡(用于显示) ，内存条(用于存储)
// 将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，例如lntel厂商和Lenovo厂商
// 创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
// 测试时组装一台不同的电脑进行工作


// 抽象不同零件类
// 抽象CPU类
class Cpu
{
public:
	// 抽象的计算函数
	virtual void calculate() = 0;
};

// 抽象显卡类
class VideoCard
{
public:
	// 抽象的显示函数
	virtual void display() = 0;
};

// 抽象内存条类
class Memory
{
public:
	// 抽象的存储函数
	virtual void storage() = 0;
};

// 电脑类
class Computer
{
public:
	Computer(Cpu* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	//提供工作的函数
	void work()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	// 提供析构函数,释放三个电脑的零件
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

	Cpu* m_cpu; // CPU的零件指针
	VideoCard* m_vc; // 显卡的零件指针
	Memory* m_mem; // C内存条的零件指针
};

// 具体厂商
// Intel厂商
class IntelCPU :public Cpu
{
public:
	virtual void calculate()
	{
		cout << "Intel的CPU开始计算!!" << endl;
	}
};
class IntelVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Intel的VideoCard开始显示!!" << endl;
	}
};
class IntelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel的Memory开始存储!!" << endl;
	}
};
// Lenovo厂商
class LenovoCPU :public Cpu
{
public:
	virtual void calculate()
	{
		cout << "Lenovo的CPU开始计算!!" << endl;
	}
};
class LenovoVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Lenovo的VideoCard开始显示!!" << endl;
	}
};
class LenovoMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo的Memory开始存储!!" << endl;
	}
};


static void test08()
{
	cout << "-------------test08()-------------" << endl;
	// 第一台电脑零件
	Cpu* intelCpu = new IntelCPU;
	VideoCard* intelCard = new IntelVideoCard;
	Memory* intelMem = new IntelMemory;

	// 创建第一台电脑
	Computer* computer1 = new Computer(intelCpu, intelCard, intelMem);
	computer1->work();
	delete computer1;
	// 如果不写析构函数,电脑没了,但是零件还在

	// 第二台电脑组装
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;

	// 第三台电脑组装
	Computer* computer3 = new Computer(new IntelCPU, new LenovoVideoCard, new LenovoMemory);
	computer3->work();
	delete computer3;
	// 不用虚析构！！！不用，子类没有new空间
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