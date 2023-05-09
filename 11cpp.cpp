#include<iostream>
using namespace std;

int main0()
{
	string s = "ljt";
	string seed = "ABCDE";
	for (size_t i = 0; i < 5; i++)
	cout << (s += seed[i]) <<endl;
	//随机数种子
	srand((unsigned int)time(NULL));
	int random = rand();
	while (1)
	{

		srand((unsigned int)time(NULL));
		random = rand();
		cout << random << "\r";	
	}
	


	system("pause");
	return 0;
}