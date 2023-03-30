//#include<iostream>
//using namespace std;
//
//int main()
//{
//	// 顺序结构
//
//	// 选择结构
//	// if(条件){111}
//	// if(条件){111}else{222}
//	// if(条件){111}else if{222}else if{333}...else{***}
//
//	// 三目运算符
//	// 表达式1 ? 表达式2 : 表达式3 
//	/*int a = 10;
//	int b = 10;
//	int c = 0;
//	cout << (c = (a > b ? a : b)) << endl;*/
//	/*switch(表达式)
//		{
//		case 111:
//			 111; break;
//		case 222:
//			222; break;
//		case 333:
//			333; break;
//		case 444:
//			444; break;	
//		default:
//			555; break;
//		}*/
//	// 循环结构
//	/*while (true)
//	{
//
//	}*/
//	/*srand((unsigned int) time(NULL));
//	int num = rand() % 100 + 1;*/
//	//cout << num << endl;
//	/*int val;
//	
//	while (true)
//	{
//		cin >> val;
//		if (val > num)
//		{
//			cout << "猜测过大" << endl;
//		}
//		else if (val < num)
//		{
//			cout << "猜测过小" << endl;
//		}
//		else
//		{
//			cout << "恭喜你" << endl;
//			break;
//		}
//	}*/
//	/*do
//	{
//
//	} while (true);*/
//	/*for (size_t i = 0; i < length; i++)
//	{
//
//	}*/
//	/*size_t tmp;
//	for (size_t i = 0; i < 10000; i++)
//	{
//		if (i % 7 ==0)
//		{
//			cout << i << endl;
//			continue;
//		}
//		tmp = i;
//		do
//		{
//			if (tmp % 10 == 7)
//			{
//				cout << i << endl;
//				break;
//			}
//			tmp = tmp / 10;
//			
//		} while (tmp > 0);
//		
//	}*/
//	
//	// goto
//	// 如果标记的名称存在，执行到goto语句时，会跳转到标记的位置
//	// 听说别用
//
//	cout << "1" << endl;
//
//	goto FLAG;
//
//	cout << "2" << endl;
//	cout << "3" << endl;
//	cout << "4" << endl;
//
//	FLAG:	
//	cout << "5" << endl;
//
//	return 0;
//}