//#include<iostream>
//using namespace std;
//
//int main()
//{
//	// 一块连续的内存空间
//	// 
//	// 定义方法
//	// 数组类型 数组名[ 数组长度 ]
//	// 数组类型 数组名[ 数组长度 ] = { 值1, 值2, ...}
//	// 如果没有全填完，会用0填补
//	// 数组类型 数组名[ ] = { 值1, 值2, ...}
//
//	// 数组名
//	// 统计整个数组在内存中的长度
//	//int arr[5] = {1, 2, 3, 4 ,5}; 
//	//cout << "数组大小：" << sizeof(arr) << endl;
//	//cout << "元素大小：" << sizeof(arr[0]) << endl;
//
//	//// 获取数组在内存中的首地址
//	//cout << "数组首地址：" << arr << endl;
//	//cout << "数组首地址：" << &arr[0] << endl;
//	//cout << "数组首地址(十进制)：" << unsigned int(arr) << endl;
//	//cout << "数组第二个地址(十进制)：" << unsigned int(&arr[1]) << endl;
//
//	// 数组名是常量，不可以赋值
//	// arr = 100; 是错误的
//
//	// 二维数组
//	// 数组类型 数组名[ 行数 ][ 列数 ]
//	// 数组类型 数组名[ 行数 ][ 列数 ] = { {数据1，数据2} , {数据3，数据4} , ...}
//	// 数组类型 数组名[ 行数 ][ 列数 ] = { 数据1，数据2 ,数据3，数据4, ...}
//	// 数组类型 数组名[  ][ 列数 ] = { 数据1，数据2 ,数据3，数据4, ...}
//	// 数组名
//	int arr[][3] =
//	{
//		{1, 2, 3},
//		{4, 5, 6}
//	};
//	// 统计整个数组在内存中的长度
//	cout << "数组大小：" << sizeof(arr) << endl;
//	cout << "数组第一行大小：" << sizeof(arr[0]) << endl;
//	cout << "数组第一个元素大小：" << sizeof(arr[0][0]) << endl;
//
//	// 获取数组在内存中的首地址
//	cout << "数组首地址：" << arr << endl;
//	cout << "数组首地址(十进制)：" << unsigned int(arr) << endl;
//	cout << "数组第一行地址：" << arr[0] << endl;
//	cout << "数组第二行地址：" << arr[1] << endl;
//	cout << "数组第一个元素地址：" << &arr[0][0] << endl;
//
//	
//
//	system("pause");
//	return 0;
//}