#include<iostream>
#include<algorithm>
#include<numeric>
#include<functional>
#include<vector>
using namespace std;

//	3. 常用排序算法
//	学习目标 :
//		·掌握常用的排序算法
//	算法简介:
//		·sort				//对容器内元素进行排排序
//		·random shufflel	//洗牌 指定范围内的元素随机调整次序
//		·merge				//容器元素合并，并存储到另一容器中
//		·reverse			//反转指定范围的元素



// 1.sort
//	功能描述 :
//		·对容器内元素进行排序
//	函数原型 :
//		·sort(iterator peg, iterator end, _Pred);
//			 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
//			beg 开始选代器
//			end 结束选代器
//			_Pred 谓词


// 2.random_shuffle
//	功能描述 :
//		·洗牌 指定范围内的元素随机调整次序
//	函数原型 :
//		·random_shuffle(iterator beg, iterator end);
//			指定范围内的元素随机调整次序
//			beg 开始选代器
//			end 结束选代器


// 3.merge
//	功能描述 :
//		·两个容器元素合并，并存储到另一容器中
//	函数原型 :
//		·merge(iterator begl, iterator end1, iterator beg2, iterator end2, iterator dest);
//			容器元素合并，并存储到另一容器中
//			注意: 两个容器必须是有序的
//			beg1容器1开始迭代器
//			end1容器1结束迭代器
//			beg2容器2开始迭代器
//			end2容器2结束迭代器
//			dest 目标容器开始选代器


// 4.reverse
//	功能描述 :
//		·将容器内元素进行反转
//	函数原型 :
//		·reverse(iterator beg, iterator end);
//			反转指定范围的元素
//			beg 开始选代器
//			end 结束选代器


void myPrint41(int& val)
{
	cout << val << " ";
}
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	//查找内置数据类型
	vector<int>v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	v.push_back(10);
	v.push_back(40);
	// 用sort排序（升序）
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint41);
	cout << endl;

	// 改变为降序
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), myPrint41);
	cout << endl;

	// 洗牌
	srand((unsigned int)time(NULL));//随机种子
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint41);
	cout << endl;

	//合并
	vector<int>v1;
	vector<int>v2;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
		//可以观察一下如果排序规则不一样会如何
		//v2.push_back(10-i);
	}
	//可以观察一下如果排序规则不一样会如何
	/*for_each(v1.begin(), v1.end(), myPrint41);
	cout << endl; 
	for_each(v2.begin(), v2.end(), myPrint41);
	cout << endl;*/
	vector<int>vTarget;
	vTarget.resize(v1.size() + v2.size());//预留空间
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), myPrint41);
	cout << endl;

	// 反转
	reverse(vTarget.begin(), vTarget.end());
	for_each(vTarget.begin(), vTarget.end(), myPrint41);
	cout << endl;
}





int main41()
{
	test01();
	system("pause");
	return 0;
}