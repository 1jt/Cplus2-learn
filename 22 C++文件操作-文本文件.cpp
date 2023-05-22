#include<iostream>
using namespace std;
#include<fstream>
#include<string>

//��������ʱ���������ݶ�������ʱ���ݣ�����һ�����н������ᱻ�ͷ�
//ͨ���ļ����Խ����ݳ־û�C++�ж��ļ�������Ҫ����ͷ�ļ� <fstream>
// 
//�ļ����ͷ�Ϊ����:
//	1. �ı��ļ��ļ����ı���ASCII����ʽ�洢�ڼ������
//	2. �������ļ� �ļ����ı��Ķ�������ʽ�洢�ڼ�����У��û�һ�㲻��ֱ�Ӷ�������
//
// �����ļ��������� :
//	1. ofstream : д����	�ӿ���̨�����out�����ļ�
//	2. ifstream : ������	���ļ����루in���뵽����̨
//	3. fstream : ��д����

// ����һ��������֮ǰ������Ա������ʾ���ߣ����ڵ�ǰ�ļ��������ɵ����ļ���obj��exe�ļ�



// �ļ��򿪷�ʽ
//		�򿪷�ʽ				����
//		ios::in					Ϊ���ļ������ļ�
//		ios::out				Ϊд�ļ������ļ�
//		ios::ate				��ʼλ�� : �ļ�β
//		ios.:app				׷�ӷ�ʽд�ļ�
//		ios::trunc				����ļ�������ɾ�����ٴ���
//		ios. : binary			���Ʒ�ʽ
// 
//	ע��: �ļ��򿪷�ʽ�������ʹ�ã�����|������
//	����: �ö����Ʒ�ʽд�ļ�ios::binary | ios::out
//



// д�ļ�
//д�ļ���������:
//	1. ����ͷ�ļ�
//	 #include <fstream>
//	2. ����������
//	 ofstream ofs;
//	3. ���ļ�
//	 ofs.open("�ļ�·��", �򿪷�ʽ)	;
//	4. д����
//	 ofs << "д�������"
//	5. �ر��ļ�
//	 ofs.close()

static	void test01()
{
	cout << "-------------test01()-------------" << endl;

	//	1. ����ͷ�ļ� fstream
	
	//	2. ����������
	ofstream ofs;

	//	3. ָ���򿪷�ʽ���ļ�
	ofs.open("test221.txt", ios::out);

	//	4. д����
	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺18" << endl;

	//	5. �ر��ļ�
	ofs.close();
}



// ���ļ�
// ���ļ���д�ļ��������ƣ����Ƕ�ȡ��ʽ����ڱȽ϶�
//
// ���ļ���������
//	1. ����ͷ�ļ�
//	 #include <fstream>
//	2. ����������
//	 ifstream ifs;
//	3. ���ļ����ж��ļ��Ƿ�򿪳ɹ�
//	 ifs.open(���ļ�·����, �򿪷�ʽ);
//	4. ������
//	 ���ַ�ʽ��ȡ
//	5. �ر��ļ�
//	 ifs.close();
static	void test02()
{
	cout << "-------------test02()-------------" << endl;
	//	1. ����ͷ�ļ� fstream

	//	2. ����������
	ifstream ifs;

	//	3. ���ļ����ж��ļ��Ƿ�򿪳ɹ�
	ifs.open("test221.txt", ios::in);
	if (ifs.is_open())
	{
		cout << "�ļ��򿪳ɹ�" << endl;
	}
	//	4. ������

	// ��һ��
	/*cout << "first" << endl;
	char buf1[1024] = { 0 };
	while (ifs >> buf1)
	{
		cout << buf1 << endl;
	}*/

	// �ڶ���
	/*cout << "second" << endl;
	char buf2[1024] = { 0 };
	while (ifs.getline(buf2,sizeof(buf2)))
	{
		cout << buf2 << endl;
	}*/

	// ������
	//cout << "third" << endl;
	//string buf3;
	//while (getline(ifs, buf3))	//getline()ȫ�ֺ���
	//{
	//	cout << buf3 << endl;
	//}

	// ������
	cout << "fourth" << endl;
	char c;
	while ((c = ifs.get())!= EOF)	//EOF = end of file
		//	������Ų����Դ����Ȼ�����С���� 
	{
		cout << c;
	}


	//	5. �ر��ļ�
	ifs.close();
}




int main22()
{
	test02();
	system("pause");
	return 0;
}