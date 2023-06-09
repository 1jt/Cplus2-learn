#include<iostream>
#include<algorithm>
#include<numeric>
#include<functional>
#include<vector>
using namespace std;


//	6. 常用集合算法
//	学习目标 :
//		·掌握常用的集合算法
//	算法简介 :
//		·set_intersection	// 求两个容器的交集
//		·set_union			// 求两个容器的并集
//		·set_difference	// 求两个容器的差集

class myPrint44
{
public:
	void operator()(int& val)
	{
		cout << val << " ";
	}
};
static void test01()
{
	cout << "-------------test01()-------------" << endl;

	vector<int>v1;
	for (size_t i = 0; i < 101; i++)
	{
		v1.push_back(i);
	}
	// 1.accumulate
	int total = accumulate(v1.begin(), v1.end(), 0);
	cout << "total=" << total << endl;
	total = accumulate(v1.begin(), v1.end(), 1000);
	cout << "total=" << total << endl;

	// 2.fill
	fill(v1.begin(), v1.end(), 100);
	for_each(v1.begin(), v1.end(), myPrint43());
	cout << endl;
}



int main()
{
	test01();
	system("pause");
	return 0;
}