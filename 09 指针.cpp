//#include<iostream>
//using namespace std;
//void swap01(int num1, int num2);
//void swap01(int *p1, int *p2);
//
//int main()
//{
//	// 定义指针
//	int a = 10;
//	// 指针定义的语法：数据类型 * 指针变量名
//	int * p;
//
//	// 可以通过解引用的方式来找到指针指向的内存
//	// 即指针前加 * 
//	p = &a;
//	cout << "a的地址为：" << &a << endl;
//	cout << "指针p为：" << p << endl;
//	cout << "指针p指向的内存为：" << *p << endl;
//
//	// 所占内存空间
//	cout << "指针占用内存空间为：" << sizeof(p) << endl;
//	cout << "指针占用内存空间为：" << sizeof(float *) << endl;
//	cout << "指针占用内存空间为：" << sizeof(double *) << endl;
//	cout << "指针占用内存空间为：" << sizeof(char *) << endl;
//	// 32位4字节，64位8字节
//	cout << "指针指向占用内存空间为：" << sizeof(*p) << endl;
//
//	// 空指针
//	// 内存中编号为0的空间
//	// 用途：初始化指针变量
//	// 空指针指向的内存是不可以访问的
//	int* pp = NULL;
//	cout << "指针pp为：" << pp << endl;
//	//*pp = 100;
//	// 0 ~ 255之间的内存编号是系统占用的，不可以访问
//	
//
//	// 野指针
//	// 指针变量指向非法的内存空间
//	int * ppp = (int *)0x1100;
//	// 访问野指针会报错
//	// cout  << *ppp << endl;
//	// 空指针和野指针都不是我们申请的空间，因此不要访问
//
//	// const 修饰指针有三种情况：
//	// 1. const 修饰指针 --常量指针
//	// 2. const 修饰常量 --指针常量
//	// 3. const 既修饰指针，又修饰常量
//	// 1. 
//	int aa = 10;
//	int bb = 10;
//	const int* pa = &aa;
//	cout << "指针pa的内存为(aa)：" << pa << endl;
//	// 指针指向可以改，指针指向的值不可以改
//	// *pa = 20; 会报错误
//	pa = &bb;
//	cout << "指针pa的内存为(bb)：" << pa << endl;
//
//	// 2. 
//	int* const pb = &a;
//	// 指针的指向不可以改，指针指向的值可以改
//	*pb = 20;
//	// pb = &bb; 会报错误
//
//	// 3.
//	const int* const pc = &aa;
//	// 指针的指向和指针指向的值都不可以改
//	// *pc = 20;
//	// pc = &bb; 都会报错误
//	// 在谁前面谁不能改
//
//
//	// 指针和数组
//	// 利用指针访问数组中元素
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	cout << "第一个元素为：" << arr[0] << endl;
//
//	p = arr;// arr就是数组首地址
//	cout << "利用指针访问第一个元素" << *p << endl;
//	p++;
//	cout << "利用指针访问第二个元素" << *p << endl;
//	cout << "利用指针遍历数组" << endl;
//	int* p2 = arr;
//
//	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		cout << *p2 << endl;
//		p2++;
//	}
//
//	// 指针和函数
//	// 1. 值传递
//	a = 10;
//	int b = 20;
//	swap01(a, b);
//	cout << a << endl;
//	cout << b << endl;
//
//
//	// 2. 地址传递
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
