#include<iostream>
using namespace std;

int main()
{
	string s = "ljt";
	string seed = "ABCDE";
	for (size_t i = 0; i < 5; i++)
	cout << (s += seed[i]) <<endl;
	/*
	C++������ִ��ʱ����
	*/
	


	system("pause");
	return 0;
}