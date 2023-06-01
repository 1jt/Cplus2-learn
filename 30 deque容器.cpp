#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>

//	1. deque������������
//	���� :
//		��˫�����飬���Զ�ͷ�˽��в���ɾ������
//	deque��vector���� :
//		��vector����ͷ���Ĳ���ɾ��Ч�ʵͣ�������Խ��Ч��Խ��
//		��deque��Զ��ԣ���ͷ���Ĳ���ɾ���ٶȻر�vector��
//		��vector����Ԫ��ʱ���ٶȻ��deque��, ��������ڲ�ʵ���й�
//	deque�ڲ�����ԭ��:
//		deque�ڲ��и��п�����ά��ÿ�λ������е����ݣ��������д����ʵ����
//		�п���ά������ÿ���������ĵ�ַ��ʹ��ʹ��dequeʱ��һƬ�������ڴ�ռ�
//	vertor�����ĵ�������֧��������ʵĵ�����


//	2. deque���캯��
//	��������
//		��deque��������
//	����ԭ�� :
//		deque <T> deqT;			//Ĭ�Ϲ�����ʽ
//		deque(beg, end);		//���캯����[beg,end)�����е�Ԫ�ؿ���������
//		deque(n, elem);			//���캯����n��elem����������
//		deque(const deque& deg);//�������캯��

//��ӡ�����ӿ�
void printDeque(const deque<int>& d)//��const�޶�ֻ������iteratorҲ�����Ϊconst_iterator
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)//ͻȻ����deque<int>::const_iterator��λautoҲ����
	{
		// *it = 100;//�����е����ݲ������޸�
		cout << *it << " ";
	}
	cout << endl;
}
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	// 1
	deque<int> d1;
	for (size_t i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	// 2
	deque<int> d2(d1.begin() + 1, d1.end());//����ҿ�
	printDeque(d2);
	// 3	n��elem��ʽ����
	deque<int> d3(10, 100);
	printDeque(d3);
	// 4	����
	deque<int> d4(d3);
	printDeque(d4);
}



//	3. deque��ֵ����
//	�������� :
//		����deque�������и�ֵ
//	����ԭ�� :
//		deque & operator=(const deque & deq);	//���صȺŲ�����
//		assign(beg�� end);						//��[beg,end)�����е����ݿ�����ֵ������
//		assign(n, elem);						//��n��elem������ֵ������



//	4. deque��С����
//	�������� :
//		����deque�����Ĵ�С���в���
//	����ԭ�� :
//		��deque.empty();			//�ж������Ƿ�Ϊ��
//		��deque.size();				//����������Ԫ�صĸ���
//		��deque.resize(num);		//����ָ�������ĳ���Ϊnum,�������䳤������Ĭ��ֵ�����λ��
									//���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
//		��deque.resize(num, elem);	//����ָ�������ĳ���Ϊnum,�������䳤������elemֵ�����λ��
									//���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
//	ע��dequeû�������ĸ���



//	5. deque �����ɾ��
//	�������� :
//		����deque�����в����ɾ������
//	����ԭ�� :
//	���˲������:
//		push back(elem);	//������β�����һ������
//		push front(elem);	//����ͷ������һ������
//		pop_back();			//ɾ���������һ������
//		pop_front();		//ɾ��������һ������
//	ָ��λ�ò���:
//		insert(pos, elem);		//��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ��
//		insert(pos, n, elem);	//��posλ�ò���n��elem���ݣ��޷���ֵ
//		insert(pos, beg, end);	//��posλ�ò���[beg,end)��������ݣ��޷���ֵ
//		clear();				//�����������������
//		erase(beg, end);		//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ��
//		erase(pos);				//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�



//	6. deque ���ݴ�ȡ
//	�������� :
//		����deque �е����ݵĴ�ȡ����
//	����ԭ�� :
//		at(int idx);//��������idx��ָ������
//		operator[];	//��������idx��ָ������
//		front();	//���������е�һ������Ԫ��
//		back();		//�������������һ������Ԫ��



//	7. deque ����
//	�������� :
//		�������㷨ʵ�ֶ�deque������������
//	�㷨 :
//		sort(iterator beg��iterator end);	//��beg��end������Ԫ�ؽ�������
static void test02()
{
	cout << "-------------test02()-------------" << endl;
	// 1
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(60);
	d1.push_front(50);
	d1.push_front(40);
	printDeque(d1);
	//Ҫ��#include<algorithm>
	//����֧��������ʵĵ�����������������������sort�㷨ֱ�Ӷ����������
	// ����vetcor����Ҳ����
	sort(d1.begin(), d1.end());//Ĭ������
	printDeque(d1);
}



int main30()
{
	test01();
	test02();
	system("pause");
	return 0;
}