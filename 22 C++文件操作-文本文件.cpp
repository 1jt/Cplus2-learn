#include<iostream>
using namespace std;
#include<fstream>
#include<string>

//程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放
//通过文件可以将数据持久化C++中对文件操作需要包含头文件 <fstream>
// 
//文件类型分为两种:
//	1. 文本文件文件以文本的ASCII码形式存储在计算机中
//	2. 二进制文件 文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂它们
//
// 操作文件的三大类 :
//	1. ofstream : 写操作	从控制台输出（out）到文件
//	2. ifstream : 读操作	从文件输入（in）入到控制台
//	3. fstream : 读写操作

// 补充一个，若用之前开发人员命令提示工具，会在当前文件夹下生成单个文件的obj和exe文件



// 文件打开方式
//		打开方式				解释
//		ios::in					为读文件而打开文件
//		ios::out				为写文件而打开文件
//		ios::ate				初始位置 : 文件尾
//		ios.:app				追加方式写文件
//		ios::trunc				如果文件存在先删除，再创建
//		ios. : binary			进制方式
// 
//	注意: 文件打开方式可以配合使用，利用|操作符
//	例如: 用二进制方式写文件ios::binary | ios::out
//



// 写文件
//写文件步骤如下:
//	1. 包含头文件
//	 #include <fstream>
//	2. 创建流对象
//	 ofstream ofs;
//	3. 打开文件
//	 ofs.open("文件路径", 打开方式)	;
//	4. 写数据
//	 ofs << "写入的数据"
//	5. 关闭文件
//	 ofs.close()

static	void test01()
{
	cout << "-------------test01()-------------" << endl;

	//	1. 包含头文件 fstream
	
	//	2. 创建流对象
	ofstream ofs;

	//	3. 指定打开方式打开文件
	ofs.open("test221.txt", ios::out);

	//	4. 写内容
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;

	//	5. 关闭文件
	ofs.close();
}



// 读文件
// 读文件与写文件步骤相似，但是读取方式相对于比较多
//
// 读文件步骤如下
//	1. 包含头文件
//	 #include <fstream>
//	2. 创建流对象
//	 ifstream ifs;
//	3. 打开文件并判断文件是否打开成功
//	 ifs.open(”文件路径”, 打开方式);
//	4. 读数据
//	 四种方式读取
//	5. 关闭文件
//	 ifs.close();
static	void test02()
{
	cout << "-------------test02()-------------" << endl;
	//	1. 包含头文件 fstream

	//	2. 创建流对象
	ifstream ifs;

	//	3. 打开文件并判断文件是否打开成功
	ifs.open("test221.txt", ios::in);
	if (ifs.is_open())
	{
		cout << "文件打开成功" << endl;
	}
	//	4. 读数据

	// 第一种
	/*cout << "first" << endl;
	char buf1[1024] = { 0 };
	while (ifs >> buf1)
	{
		cout << buf1 << endl;
	}*/

	// 第二种
	/*cout << "second" << endl;
	char buf2[1024] = { 0 };
	while (ifs.getline(buf2,sizeof(buf2)))
	{
		cout << buf2 << endl;
	}*/

	// 第三种
	//cout << "third" << endl;
	//string buf3;
	//while (getline(ifs, buf3))	//getline()全局函数
	//{
	//	cout << buf3 << endl;
	//}

	// 第四种
	cout << "fourth" << endl;
	char c;
	while ((c = ifs.get())!= EOF)	//EOF = end of file
		//	这儿括号不可以打错，不然会输出小格子 
	{
		cout << c;
	}


	//	5. 关闭文件
	ifs.close();
}




int main22()
{
	test02();
	system("pause");
	return 0;
}