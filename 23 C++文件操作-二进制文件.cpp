#include<iostream>
using namespace std;
#include<fstream>
#include<string>

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

// 文本方式和二进制方式并没有本质上的区别，只是对于换行符的处理不同。
// 在 UNIX / Linux 平台中，用文本方式或二进制方式打开文件没有任何区别，因为文本文件以 \n（ASCII 码为 0x0a）作为换行符号。
//
// 但在 Windows 平台上，文本文件以连在一起的 \r\n 作为换行符号。
// 如果以文本方式打开文件，当读取文件时，程序会将文件中所有的 \r\n 转换成一个字符 \n。
// 也就是说，如果文本文件中有连续的两个字符是 \r\n，则程序会丢弃前面的 \r，只读入 \n。
//
// 同样当写入文件时，程序会将 \n 转换成 \r\n 写入。也就是说，如果要写入的内容中有字符 \n，则在写入该字符前，程序会自动先写入一个 \r。
//
// 因此在 Windows 平台上，如果用文本方式打开二进制文件进行读写，读写的内容就可能和文件的内容有出入。
//
// 总的来说，Linux 平台使用哪种打开方式都行；Windows 平台上最好用 “ios::in | ios::out” 等打开文本文件，用 “ios::binary” 打开二进制文件。
// 但无论哪种平台，用二进制方式打开文件总是最保险的
//

// 二进制文件比文本文件的好处是占用内存空间小，且便于检索。
// 比如要存放结构体或者类时，文本文件存储的只是单纯的文本，不但浪费空间而且效率低下。
// 因为在结构体或者类中每个对象的占用字节数不同，即使文本文件按照某个值排好序，只能从文件头向文件尾搜索，没有什么其他好办法。
//
// 但是用二进制来存储，每个结构体或者类占用的字节数都是相同的，直接将该对象写入文件，称作“记录”，每个对象对应一条记录，
// 按照某个值排序之后可以用比如二分搜索等算法进行检索，这样就快了很多。
//
// 读写二进制文件不能用类似于cin cout之类的流数据读取方法，这时需要调用fstream和ofstream的成员函数write向文件中写入数据，
// fstream和ifstream的成员函数read从文件中读取数据。
//

// 写文件
// 
// 二进制方式写文件主要利用流对象调用成员函数write
// 参数原型：
// ostream& write(const char* buffer,int len);
// 字符指针buffer指向内存中一段存储空间，len是读写的字节数

// 可以操作自定义数据类型
class Person231
{
public:
	char m_Name[64];
	int m_Age;
};


static	void test01()
{
	cout << "-------------test01()-------------" << endl;

	//	1. 包含头文件 fstream

	//	2. 创建流对象
	ofstream ofs;
	//ofstream ofs("test231.txt", ios::out | ios::binary);
	// 可以用构造函数直接创建
	
	//	3. 指定打开方式打开文件
	ofs.open("test231.txt", ios::out | ios::binary);

	//	4. 写内容
	Person231 p = { "张三",18 };
	ofs.write((const char*)&p, sizeof(Person231));// 就是把Persona231的对象写进文件里
	//由于 C++ 不支持指向字节的指针，因此 write 函数原型将指定缓冲区的地址是指向 char 的指针


	//	5. 关闭文件
	ofs.close();
}



// 读文件
// 二进制方式写文件主要利用流对象调用成员函数read
// 参数原型：
// istream& read(char* buffer,int len);
// 字符指针buffer指向内存中一段存储空间，len是读写的字节数
static	void test02()
{
	cout << "-------------test02()-------------" << endl;
	//	1. 包含头文件 fstream

	//	2. 创建流对象
	ifstream ifs;

	//	3. 打开文件并判断文件是否打开成功
	ifs.open("test231.txt", ios::in | ios::binary);
	if (ifs.is_open())
	{
		cout << "文件打开成功" << endl;
	}
	//	4. 读数据
	Person231 p;
	ifs.read((char*) & p, sizeof(Person231));
	cout << "姓名：" << p.m_Name << endl;
	cout << "年龄：" << p.m_Age << endl;


	//	5. 关闭文件
	ifs.close();
}




int main23()
{
	test02();
	system("pause");
	return 0;
}