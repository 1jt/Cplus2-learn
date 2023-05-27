#include<iostream>
using namespace std;
#include<string>

//	1. string基本概念
//	本质 :
//		·string是C++风格的字符串，而string本质上是一个类
//	string和char * 区别 :
//		·char * 是一个指针
//		·string是一个类，类内部封装了char * ，管理这个字符串，是一个char * 型的容器。
//	特点 :
//	 string 类内部封装了很多成员方法
//	 例如 : 查找find，拷贝copy，删除delete 替换replace，插入insert
//	 string管理char * 所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责



//	2. string构造函数
//	构造函数原型 :
//		·string();					//创建一个空的字符串 例如: string str;
//		·string(const char* s);	//使用字符串s初始化
//		·string(const string& str);//使用一个string对象初始化另一个string对象
//		·string(int n, char c);	//使用n个字符C初始化
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	string s1 = "ljtbbx";//默认构造
	cout << "s1=" << s1 << endl;
	const char* str = "hello world";
	string s2(str);
	cout << "s2=" << s2 << endl;
	string s3(s1);
	cout << "s3=" << s3 << endl;
	string s4(10, 'a');
	cout << "s4=" << s4 << endl;
}



//	3. string赋值操作
//	功能描述 :
//		·给string字符串进行赋值
//	赋值的函数原型 :
//		·string& operator=(const char* s);	//char*类型字符串 赋值给当前的字符串
//		·string& operator=(const string& s);	//把字符串s赋给当前的字符串
//		·string& operator=(char c);			//字符赋值给当前的字符串
//		·string& assign(const char* s);		//把字符串S赋给当前的字符串
//		·string& assign(const char* s, int n);	//把字符串s的前n个字符赋给当前的字符串
//		·string& assign(const string& s);		//把字符串s赋给当前字符串
//		·string& assign(int n, char c);		//用n个字符c赋给当前字符串
static void test02()
{
	cout << "-------------test02()-------------" << endl;
	// 1
	string s1 = "ljtbbx";
	cout << "s1=" << s1 << endl;
	// 2
	string s2 = s1;
	cout << "s2=" << s2 << endl;
	// 3
	string s3;
	s3 = 'a';
	cout << "s3=" << s3 << endl;
	// 4
	string s4;
	s4.assign("ljtbbx");
	cout << "s4=" << s4 << endl;
	// 5
	string s5;
	s5.assign("ljtbbx", 4);
	cout << "s5=" << s5 << endl;
	// 6
	string s6;
	s6.assign(s5);
	cout << "s6=" << s6 << endl;
	// 7
	string s7;
	s7.assign(10, 'w');
	cout << "s7=" << s7 << endl;
}



//	4. string字符串拼接
//	功能描述 :
//		·实现在字符串末尾拼接字符串
//	函数原型 :
//		·string& operator+=(const char* str);			//重载+=操作符
//		·string& operator+=(const char c);				//重载+=操作符
//		·string& operator+=(const string& str);		//重载+=操作符
//		·string& append(const char* s);				//把字符串S连接到当前字符串结尾
//		·string& append(const char* s, int n);			//把字符串s的前n个字符连接到当前字符串结尾
//		·string& append(const string& s);				//同operator+=(const string& str)
//		·string& append(const string& s，int pos，int n);//字符s中从pos开始的n个字符连接到字符串结尾
static void test03()
{
	cout << "-------------test03()-------------" << endl;
	string s1 = "ljt";
	s1 += "nb";
	cout << "s1=" << s1 << endl;
	string s2 = "bbx";
	s1 += s2;
	cout << "s1+=s2:" << s1 << endl;
	s1 += 'a';
	cout << "s1 += 'a':" << s1 << endl;
	s1.append("nb");
	cout << "s1.append(nb):" << s1 << endl;
	s1.append("bbx", 2);
	cout << "s1.append(bbx, 2):" << s1 << endl;
	s1.append(s2);
	cout << "s1.append(s2):" << s1 << endl;
	string s3;
	s3.append(s1, 5, 10);
	cout << "s3.append(s1, 5, 10):" << s3 << endl;
}


//	5 string查找和替换
//	功能描述 :
//		·查找:查找指定字符串是否存在
//		·替换 : 在指定的位置替换字符串
//	函数原型:
//		在函数声明或定义中，如果将const放在函数的参数列表后面，表示该函数不会修改任何成员变量的值。这种函数被称为常量成员函数。
//		·int find(const string & str, int pos = 0) const;		//查找str第一次出现位置,从pos开始查找（妹有就返回-1）
//		·int find(const char* s, int pos = 0) const;			//查找s第一次出现位置,从pos开始查找
//		·int find(const char* s, int pos, int n) const;		//从pos位置查找s的前n个字符第一次位置
//		·int find(const char c, int pos = 0) const;			//查找字符c第一次出现位置
//		·int rfind(const string& str, int pos = npos) const;	//查找str最后一次位置,从pos开始查找（从右往左）
//		·int rfind(const char* s, int pos = npos) const;		//查找s最后一次出现位置,从pos开始查找
//		·int rfind(const char* s, int pos, int n) const;		//从pos查找s的前n个字符最后一次位置
//		·int rfind(const char c, int pos = 0) const;			//查找字符c最后一次出现位置
//		·string& replace(int pos, int n, const string& str);	//替换从pos开始n个字符为字符串str（n为0就可以当插入使用了）
//		·string& replace(int pos, int n, const char* s);		//替换从pos开始的n个字符为字符串s



//	6. string字符串比较
//	功能描述:
//		·字符串之间的比较
// 比较方式:
//		·字符串比较是按字符的ASCII码进行对比
//	= 返回 0
//	> 返回 1
//	< 返回 - 1
//	函数原型:
//		·int compare(const string & s) const;	//与字符串s比较
//		·int compare(const char* s) const;		//与字符串s比较



//	7. string字符存取
//	string中单个字符存取方式有两种
//		·char& operator[](int n);	//通过[]方式取字符
//		·char& at(int n);			//通过at方法获取字符
static void test04()
{
	cout << "-------------test04()-------------" << endl;
	string s1 = "hello";
	cout << "s1=" << s1 << endl;
	// 通过[]方式取字符
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << "s1[i]" << s1[i] << endl;
	}
	// 通过at方法获取字符
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << "s1.at(i)" << s1.at(i) << endl;
	}
	// 修改单个字符
	s1[0] = 'x';
	cout << "s1=" << s1 << endl;
	s1.at(1) = 'x';
	cout << "s1=" << s1 << endl;
}



//	8. string插入和删除
//	功能描述:
//		·对string字符串进行插入和删除字符操作
//	函数原型:
//		·string & insert(int pos, const char* s);		//插入字符串
//		·string& insert(int pos, const string& str);	//插入字符串
//		·string& insert(int pes, int n, char c);		//在指定位置插入n个字符C
//		·string& erase(int pos, int n = npos);			//删除从Pos开始的n个字符



//	9. string子串
//	功能描述 :
//		·从字符串中获取想要的子串
//	函数原型 :
//		·string substr(int pos = 0, int n = npos) const; //返回由pos开始的n个字符组成的字符串



int main28()
{
	test01();
	test02();
	test03();
	test04();
	system("pause");
	return 0;
}