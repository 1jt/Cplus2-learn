#include<iostream>
using namespace std;
#include <iomanip> // ����С��λ��

// �������ͱ�̵Ĵ��ţ�����STL����


// ģ��ĸ���
// ģ����ǽ���ͨ�õ�ģ�ߣ������߸�����
// 1. ģ�岻��ֱ��ʹ�ã���ֻ��һ�����
// 2. ģ�岢������



//	C++��һ�ֱ��˼���Ϊ]���ͱ�̣���Ҫ���õļ�������ģ��
//	C++�ṩ����ģ�����:����ģ�����ģ��
// 
// 
//����ģ��
// ����ģ������ :
//	����һ��ͨ�ú������亯������ֵ���ͺ��β����Ϳ��Բ������ƶ�����һ����������������������Ͳ�����
//
// �﷨ :
//	template<typename T>
//	������������
//
// ���� :
//	template --- ��������ģ��
//	typename --- ���������ķ�����һ���������ͣ�������class����
//		T	 --- ͨ�õ��������ͣ����ƿ����滻��ͨ��Ϊ��д��ĸ



// �����������ͺ���
void swapInt25(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
// �������������ͺ���
void swapDouble25(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}
// ����ģ��
template<typename T> // ����һ��ģ�壬���߱�������������н����ŵ�T��Ҫ����T��һ��ͨ�õ���������
// typename�����滻Ϊclass
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
// ����ģ��ע������
//	1. �Զ������Ƶ��������Ƶ���һ�µ���������T���ſ���ʹ��
//	2. ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
template<class T>
void func()
{
	cout << "func�ĵ���" << endl;
}



static	void test01()
{
	cout << "-------------test01()-------------" << endl;
	int a = 10;
	int b = 20;
	swapInt25(a, b);
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;

	// ���ú���ģ�彻��
	// ���ַ�ʽʹ�ú���ģ��
	// 1. �Զ������Ƶ�
	mySwap(a, b);
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	// 2. ��ʾָ������
	mySwap<int>(a, b);
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;

	double c = 3.1415926;
	double d = 2.7187845;
	swapDouble25(c, d);
	cout << setiosflags(ios::fixed);
	cout << setprecision(7) << "c:" << c << endl;
	cout << setprecision(7) << "d:" << d << endl;
	mySwap(c, d);
	cout << setprecision(7) << "c:" << c << endl;
	cout << setprecision(7) << "d:" << d << endl;
	mySwap<double>(c, d);
	cout << setprecision(7) << "c:" << c << endl;
	cout << setprecision(7) << "d:" << d << endl;

	//	1. �Զ������Ƶ��������Ƶ���һ�µ���������T���ſ���ʹ��
	//mySwap(a, c);// ����
	
	//	2. ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
	//func();// ����
	func<int>();
}



// ���� -- ��������
// ʵ��ͨ�ö������������ĺ���
//	1. ���ú���ģ���װһ������ĺ��������ԶԲ�ͬ�������������������
//	2. �������Ӵ�С�������㷨Ϊѡ������
//	3. �ֱ�����char�����int������в���

// �����㷨
template<class T>
void mySort(T arr[],int len)
{
	for (size_t i = 0; i < len; i++)
	{
		int max = i;//�϶����ֵ���±�
		for(int j =i+1;j<len;j++)
		{
			//�϶����ֵ�ȱ���������ֵҪС��˵��j�±��Ԫ�ز������������ֵ
			if (arr[max]<arr[j])
			{
				max = j;
			}
		}
		if (max!=i)
		{
			// ����max��i
			mySwap(arr[max], arr[i]);
		}
	}
}
/// �ṩ��ӡ����ģ��
template<class T>
void printArray(T arr[], int len)
{
	for (size_t i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

static	void test02()
{
	cout << "-------------test02()-------------" << endl;
	char charArr[] = "abskicgwifgiugfc";
	mySort(charArr, sizeof(charArr) / sizeof(char));
	printArray(charArr, sizeof(charArr) / sizeof(char));

	int intArr[] = { 1654,46,4164,6516,6846,646,164,64,4648,76,136,4 };
	mySort(intArr, sizeof(intArr) / sizeof(int));
	printArray(intArr, sizeof(intArr) / sizeof(int));
}



// ��ͨ�����뺯��ģ�������
//	1. ��ͨ��������ʱ���Է����Զ�����ת��(��ʽ����ת��)
//	2. ����ģ�����ʱ����������Զ������Ƶ������ᷢ����ʽ����ת��
//	3. ���������ʾָ�����͵ķ�ʽ�����Է�����ʽ����ת��
// ����ʹ����ʾָ�����͵ķ�ʽ�����ú���ģ�壬��Ϊ�����Լ�ȷ��ͨ������T
int myAdd251(int a, int b)
{
	return a + b;
}
template<class T>
T myAdd252(T a, T b)
{
	return a + b;
}
static	void test03()
{
	cout << "-------------test03()-------------" << endl;
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << "a+b=" << myAdd251(a, b) << endl;
	//	1. ��ͨ��������ʱ���Է����Զ�����ת��(��ʽ����ת��)
	cout << "a+c=" << myAdd251(a, c) << endl;

	//	2. ����ģ�����ʱ����������Զ������Ƶ������ᷢ����ʽ����ת��
	cout << "myAdd252(a, b):" << myAdd252(a, b) << endl;
	//cout << "myAdd252(a, c):" << myAdd252(a, c) << endl;

	//	3. ���������ʾָ�����͵ķ�ʽ�����Է�����ʽ����ת��
	cout << "myAdd252<int>(a, c):" << myAdd252<int>(a, c) << endl;
	// ���������á��ҵ���⣺����ʵ��Ϊconst T* temp = &����������տ�ʼ������T��int�������ָ��������Ͷ����ˣ�����ָ��char
}



// ��ͨ�����뺯��ģ����ù���
//	���ù�������:
//		1. �������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
//		2. ����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
//		3. ����ģ��Ҳ���Է�������
//		4. �������ģ����Բ������õ�ƥ��, ���ȵ��ú���ģ��
// ��Ȼ�ṩ�˺���ģ�壬��þͲ�Ҫ�ṩ��ͨ�������������׳��ֶ�����
void myPrint251(int a, int b)
{
	cout << "���õ���ͨ����" << endl;
}
template<class T>
void myPrint251(T a, T b)
{
	cout << "���õĺ���ģ��" << endl;
}
//	3. ����ģ��Ҳ���Է�������
template<class T>
void myPrint251(T a, T b, T c)
{
	cout << "���õ����غ���ģ��" << endl;
}
static void test04()
{
	cout << "-------------test04()-------------" << endl;
	int a = 10;
	int b = 20;
	//	1. �������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
	myPrint251(a, b);

	//	2. ����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
	myPrint251<>(a, b);

	//	3. ����ģ��Ҳ���Է�������
	myPrint251<>(a, b, 100);

	//	4. �������ģ����Բ������õ�ƥ��, ���ȵ��ú���ģ��
	char c1 = 'a';
	char c2 = 'b';
	myPrint251(c1, c2);
}



// ģ��ľ�����
// ģ�岢�������ܵ�
// �������Ĳ������Զ�����������ͣ���θ�ֵ����αȽϣ�
// C++Ϊ�˽���������⣬�ṩģ������أ�����Ϊ��Щ�ض��������ṩ���廯��ģ��
// ���þ��廯��ģ�壬���Խ���Զ������͵�ͨ�û�
// ѧϰģ�岢����Ϊ��дģ�壬������STL���ܹ�����ϵͳ�ṩ��ģ��

// �Ա����������Ƿ���Ⱥ���
class Person251
{
public:
	Person251(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};
template<class T>
bool myCompare251(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// ���þ��廯Person�İ汾ʵ�ִ��룬���廯����ʹ��
template<> bool myCompare251(Person251& p1, Person251& p2)
{
	if ((p1.name == p2.name) && (p1.age == p2.age))
	{
		return true;
	}
	else
	{
		return false;
	}
}
static void test05()
{
	cout << "-------------test05()-------------" << endl;

	int a = 10;
	int b = 20;
	bool ret1 = myCompare251(a, b);
	if (ret1)
	{
		cout << "a==b" << endl;
	}
	else
	{
		cout << "a!=b" << endl;
	}
	Person251 p1("Tom", 10);
	Person251 p2("Tom", 11);
	bool ret2 = myCompare251(p1, p2);
	if (ret2)
	{
		cout << "p1==p2" << endl;
	}
	else
	{
		cout << "p1!=p2" << endl;
	}

}
int main25()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	system("pause");
	return 0;
}