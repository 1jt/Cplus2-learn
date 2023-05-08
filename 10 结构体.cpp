//#include<iostream>
//using namespace std;
//#include<string>
//
//// 结构体属于用户自己自定义的数据类型，允许用户存储不用的数据类型
//// 语法
//// struct 结构体名 {结构体成员列表};
//
//// 通过结构体创建变量
//// 1. struct 结构体名 变量名
//// 2. struct 结构体名 变量名 = {成员1值,成员2值...}
//// 3. 定义结构体时顺便创建变量
//
//struct Student
//{
//	// 成员列表
//	string name;
//	int age;
//	int score;
//}s3;
//struct Teacher
//{
//	int id;
//	string name;
//	int age;
//	Student stu;//辅导的学术，得先定义学生结构体
//};
//void print(Student s1);
//void print2(Student* s);
//
//int main()
//{
//	struct Student s1;
//	s1.name = "张三";
//	s1.age = 18;
//	s1.score = 100;
//	cout << "姓名：" << s1.name << " 年龄：" << s1.age << " 姓名：" << s1.score << endl;
//	cout << "Student占用内存空间为：" << sizeof(Student) << endl;
//	// 40+4+4
//	cout << "Student占用内存空间为：" << sizeof(s1) << endl;
//	
//	Student s2 = {"李四",19,80};// struct可以不要
//	cout << "姓名：" << s2.name << " 年龄：" << s2.age << " 姓名：" << s2.score << endl;
//
//	s3.name = "王五";
//	s3.age = 20;
//	s3.score = 60;
//	cout << "姓名：" << s3.name << " 年龄：" << s3.age << " 姓名：" << s3.score << endl;
//
//
//	// 结构体数组
//	//创建
//	Student arr[3]=
//	{
//		{"张三",18,100},
//		{"李四",19,80},
//		{"王五",20,60}
//	};
//	// 赋值
//	arr[2].name = "赵六";
//	// 遍历
//	for (size_t i = 0; i < 3; i++)
//	{
//		cout << "姓名：" << arr[i].name << " 年龄：" << arr[i].age << " 姓名：" << arr[i].score << endl;
//	}
//
//	
//	// 结构体指针
//	// 通过指针访问结构体中的成员
//	// 利用操作符 -> 可以通过结构体指针访问结构体属性
//	Student* p = &s1;
//	cout << "姓名：" << p->name << endl;
//
//
//	// 结构体嵌套结构体
//	Teacher t;
//	t.age = 50;
//	t.id = 100000;
//	t.name = "老王";
//	t.stu.age = 18;
//	t.stu.name = "小王";
//	t.stu.score = 100;
//
//	// 结构体做函数参数
//	// 值传递
//	// 地址传递
//	print(s1);
//	cout << "主函数姓名：" << s1.name << "\t年龄：" << s1.age << "\t分数：" << s1.score << endl;
//	print2(&s1);
//	cout << "主函数姓名：" << s1.name << "\t年龄：" << s1.age << "\t分数：" << s1.score << endl;
//
//
//	// 结构体中const使用场景
//	// 值传递的话太费内村了，改为指针可以减少内存空间，而且不会复制新的副本出来
//	// 加入const以后，一旦有修改的操作就会报错，可以防止我们的误操作
//
//	system("pause");
//	return 0;
//}
//
////值传递
//void print(Student s1) {
//	cout << "值传递" << endl;
//	s1.age = 66;
//	cout << "子函数姓名：" << s1.name << "\t年龄：" << s1.age << "\t分数：" << s1.score << endl;
//}
//
////地址传递
//void print2(Student* s) {
//	cout << "地址传递" << endl;
//	s->age = 90;
//	cout << "子函数姓名：" << s->name << "\t年龄：" << s->age << "\t分数：" << s->score << endl;
//}
