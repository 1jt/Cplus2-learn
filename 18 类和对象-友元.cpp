#include<iostream>
using namespace std;

/*
			��Ԫ
*/


// ��������ļ��п���(Public)�����������(Private)
// �����������Ŀ��˶����Խ�ȥ���������������˽�еģ�Ҳ����˵ֻ�����ܽ�ȥ
// �����أ���Ҳ����������ĺù��ۺû��ѽ�ȥ��
// 
// �ڳ������Щ˽������ Ҳ�������������һЩ������������з��ʣ�����Ҫ�õ���Ԫ�ļ���
// 
// ��Ԫ��Ŀ�ľ�����һ������������ ������һ������˽�г�Ա
//
// ��Ԫ�Ĺؼ���Ϊ friend
//
// ��Ԫ������ʵ��
//		ȫ�ֺ�������Ԫ
//		������Ԫ
//		��Ա��������Ԫ



// ȫ�ֺ�����Ԫ
class Building
{
	//goodGayȫ�ֺ�����Building�ĺ����ѣ����Է���Building��˽�г�Ա
	friend void goodGay(Building* building);

	//goodGay2�Ǳ���ĺ����ѣ����Է���Building��˽�г�Ա
	friend class goodGay2;

	// ���߱�������goodGay3���µ�visit��Ա������Ϊ����ĺ����ѣ����Է���˽�г�Ա
	//friend void goodGay3::visit();
	// Building������������ΪGoodgay������õ���Building���ͺ�Goodgay���ԭ����Building���л�����friend��Goodgay�еĳ�Ա��������
public:
	Building()//һ������������������ʵ��
	{
		m_SittingRoom = "����";
		m_BedRoom = "����";
	}

	string m_SittingRoom; //����

private:
	string m_BedRoom; //����
};
// ȫ�ֺ���
void goodGay(Building *building)
{
	cout << "�û��ѵ�ȫ�ֺ��� ���ڷ��ʣ�" << building->m_SittingRoom << endl;//��������������

	cout << "�û��ѵ�ȫ�ֺ��� ���ڷ��ʣ�" << building->m_BedRoom << endl;//friend����˽�г�Ա
}
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	Building building;
	goodGay(&building);
}



// ������Ԫ
class goodGay2
{
public:
	goodGay2();//һ������������������ʵ��
	void visit();//�ιۺ��� ����Building�е�����

	Building* building;

private:

};
goodGay2::goodGay2()
{
	// �������������
	building = new Building;
}
void goodGay2::visit()
{
	cout << "�û���2���ڷ��ʣ�" << building->m_SittingRoom << endl;

	cout << "�û���2���ڷ��ʣ�" << building->m_BedRoom << endl;
}
static void test02()
{
	cout << "-------------test02()-------------" << endl;
	goodGay2 gg;
	gg.visit();
}



// ��Ա��������Ԫ
// Building2������������ΪGoodgay3������õ�
class Building2;													//1
class goodGay3
{
public:
	goodGay3();
	void visit();// ��visit�������Է���Building�е�˽�г�Ա
	void visit2();// ��visit2���� �� ���Է���Building�е�˽�г�Ա

	Building2* building;											//2

private:

};

// Building2���ͺ�Goodgay3���ԭ����Building���л�����friend��Goodgay3�еĳ�Ա��������
class Building2
{
	// ���߱�������goodGay3���µ�visit��Ա������Ϊ����ĺ����ѣ����Է���˽�г�Ա
	friend void goodGay3::visit();									//3
public:
	Building2()//һ������������������ʵ��
	{
		m_SittingRoom = "����";
		m_BedRoom = "����";
	}

	string m_SittingRoom; //����

private:
	string m_BedRoom; //����
};

// ������Building2����֮��д���캯������Ȼ��֪����ô�����Building2����Ϊ�᲻֪�����壬˳����ĺ���Ҫ��
goodGay3::goodGay3()
{
	// �������������
	building = new Building2;										//4
}
void goodGay3::visit()
{
	cout << "visit�������ڷ��ʣ�" << building->m_SittingRoom << endl;
	cout << "visit�������ڷ��ʣ�" << building->m_BedRoom << endl;
}
void goodGay3::visit2()
{
	cout << "visit2�������ڷ��ʣ�" << building->m_SittingRoom << endl;
	//cout << "visit2�������ڷ��ʣ�" << building->m_BedRoom << endl; // ���Ǻ����Ѳ����Է���
}




static void test03()
{
	cout << "-------------test03()-------------" << endl;
	goodGay3 gg;
	gg.visit();
	gg.visit2();
}


int main18()
{
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}