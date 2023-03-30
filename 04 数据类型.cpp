//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	// 浮点型
//	// 默认输出一个小鼠，6位有效数字
//	float f1 = 3.1415926f;
//	double d1 = 3.1415926;
//	cout << "float占用内存空间为：" << sizeof(f1) << endl;
//	cout << "double占用内存空间为：" << sizeof(d1) << endl;
//
//	// 科学计数法
//	float f2 = 3e2; //3*10^2
//
//	float f3 = 3e-2; // 3 * 0.1 ^2
//
//	cout << "f2 = " << f2 << endl;
//	cout << "f3 = " << f3 << endl;
//
//	// 字符型
//	char ch = 'a';
//	cout << "char占用内存空间为：" << sizeof(ch) << endl;
//	// 不能用双引号
//	// ASCII
//	cout << int(ch) << endl;
//
//	// 转义字符
//	// \a 警告 
//	// \n
//	cout << "Hello world\n";
//	// \\反斜杠
//	cout << "Hello world\\" << endl;
//	// \t
//	cout << "aaa\tHello world" << endl;
//	cout << "aa\tHello world" << endl;
//	cout << "aaaa\tHello world" << endl;
//
//	// 字符串型
//	// C
//	char str[] = "Hello world";
//	cout << str << endl;
//
//	// C++ 
//	// 要有#include<string>
//	string str2 = "Hello world";
//	cout << str2 << endl;
//
//	// 布尔类型
//	bool flag1 = true;
//	bool flag2 = false;
//
//	cout << flag1 << endl;
//	cout << flag2 << endl;
//	cout << "bool占用内存空间为：" << sizeof(flag1) << endl;
//
//	// 数据输入
//	int input;
//	cout << "请输入整型变量" << endl;
//	cin >> input;
//	cout << input << endl;
//
//	float inputf;
//	cout << "请输入浮点型型变量" << endl;
//	cin >> inputf;
//	cout << inputf << endl;
//
//	char inputc;
//	cout << "请输入字符型变量" << endl;
//	cin >> inputc;
//	cout << inputc << endl;
//
//	string inputs;
//	cout << "请输入字符串型变量" << endl;
//	cin >> inputs;
//	cout << inputs << endl;
//
//	bool inputb;// 非0全真
//	cout << "请输入布尔型变量" << endl;
//	cin >> inputb;
//	cout << inputb << endl;
//
//
//	system("pause");
//	return 0;
//}