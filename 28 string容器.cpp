#include<iostream>
using namespace std;
#include<string>

//	1. string��������
//	���� :
//		��string��C++�����ַ�������string��������һ����
//	string��char * ���� :
//		��char * ��һ��ָ��
//		��string��һ���࣬���ڲ���װ��char * ����������ַ�������һ��char * �͵�������
//	�ص� :
//	 string ���ڲ���װ�˺ܶ��Ա����
//	 ���� : ����find������copy��ɾ��delete �滻replace������insert
//	 string����char * ��������ڴ棬���õ��ĸ���Խ���ȡֵԽ��ȣ������ڲ����и���



//	2. string���캯��
//	���캯��ԭ�� :
//		��string();					//����һ���յ��ַ��� ����: string str;
//		��string(const char* s);	//ʹ���ַ���s��ʼ��
//		��string(const string& str);//ʹ��һ��string�����ʼ����һ��string����
//		��string(int n, char c);	//ʹ��n���ַ�C��ʼ��
static void test01()
{
	cout << "-------------test01()-------------" << endl;
	string s1 = "ljtbbx";//Ĭ�Ϲ���
	cout << "s1=" << s1 << endl;
	const char* str = "hello world";
	string s2(str);
	cout << "s2=" << s2 << endl;
	string s3(s1);
	cout << "s3=" << s3 << endl;
	string s4(10, 'a');
	cout << "s4=" << s4 << endl;
}



//	3. string��ֵ����
//	�������� :
//		����string�ַ������и�ֵ
//	��ֵ�ĺ���ԭ�� :
//		��string& operator=(const char* s);	//char*�����ַ��� ��ֵ����ǰ���ַ���
//		��string& operator=(const string& s);	//���ַ���s������ǰ���ַ���
//		��string& operator=(char c);			//�ַ���ֵ����ǰ���ַ���
//		��string& assign(const char* s);		//���ַ���S������ǰ���ַ���
//		��string& assign(const char* s, int n);	//���ַ���s��ǰn���ַ�������ǰ���ַ���
//		��string& assign(const string& s);		//���ַ���s������ǰ�ַ���
//		��string& assign(int n, char c);		//��n���ַ�c������ǰ�ַ���
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



//	4. string�ַ���ƴ��
//	�������� :
//		��ʵ�����ַ���ĩβƴ���ַ���
//	����ԭ�� :
//		��string& operator+=(const char* str);			//����+=������
//		��string& operator+=(const char c);				//����+=������
//		��string& operator+=(const string& str);		//����+=������
//		��string& append(const char* s);				//���ַ���S���ӵ���ǰ�ַ�����β
//		��string& append(const char* s, int n);			//���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
//		��string& append(const string& s);				//ͬoperator+=(const string& str)
//		��string& append(const string& s��int pos��int n);//�ַ�s�д�pos��ʼ��n���ַ����ӵ��ַ�����β
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


//	5 string���Һ��滻
//	�������� :
//		������:����ָ���ַ����Ƿ����
//		���滻 : ��ָ����λ���滻�ַ���
//	����ԭ��:
//		�ں������������У������const���ں����Ĳ����б���棬��ʾ�ú��������޸��κγ�Ա������ֵ�����ֺ�������Ϊ������Ա������
//		��int find(const string & str, int pos = 0) const;		//����str��һ�γ���λ��,��pos��ʼ���ң����оͷ���-1��
//		��int find(const char* s, int pos = 0) const;			//����s��һ�γ���λ��,��pos��ʼ����
//		��int find(const char* s, int pos, int n) const;		//��posλ�ò���s��ǰn���ַ���һ��λ��
//		��int find(const char c, int pos = 0) const;			//�����ַ�c��һ�γ���λ��
//		��int rfind(const string& str, int pos = npos) const;	//����str���һ��λ��,��pos��ʼ���ң���������
//		��int rfind(const char* s, int pos = npos) const;		//����s���һ�γ���λ��,��pos��ʼ����
//		��int rfind(const char* s, int pos, int n) const;		//��pos����s��ǰn���ַ����һ��λ��
//		��int rfind(const char c, int pos = 0) const;			//�����ַ�c���һ�γ���λ��
//		��string& replace(int pos, int n, const string& str);	//�滻��pos��ʼn���ַ�Ϊ�ַ���str��nΪ0�Ϳ��Ե�����ʹ���ˣ�
//		��string& replace(int pos, int n, const char* s);		//�滻��pos��ʼ��n���ַ�Ϊ�ַ���s



//	6. string�ַ����Ƚ�
//	��������:
//		���ַ���֮��ıȽ�
// �ȽϷ�ʽ:
//		���ַ����Ƚ��ǰ��ַ���ASCII����жԱ�
//	= ���� 0
//	> ���� 1
//	< ���� - 1
//	����ԭ��:
//		��int compare(const string & s) const;	//���ַ���s�Ƚ�
//		��int compare(const char* s) const;		//���ַ���s�Ƚ�



//	7. string�ַ���ȡ
//	string�е����ַ���ȡ��ʽ������
//		��char& operator[](int n);	//ͨ��[]��ʽȡ�ַ�
//		��char& at(int n);			//ͨ��at������ȡ�ַ�
static void test04()
{
	cout << "-------------test04()-------------" << endl;
	string s1 = "hello";
	cout << "s1=" << s1 << endl;
	// ͨ��[]��ʽȡ�ַ�
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << "s1[i]" << s1[i] << endl;
	}
	// ͨ��at������ȡ�ַ�
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << "s1.at(i)" << s1.at(i) << endl;
	}
	// �޸ĵ����ַ�
	s1[0] = 'x';
	cout << "s1=" << s1 << endl;
	s1.at(1) = 'x';
	cout << "s1=" << s1 << endl;
}



//	8. string�����ɾ��
//	��������:
//		����string�ַ������в����ɾ���ַ�����
//	����ԭ��:
//		��string & insert(int pos, const char* s);		//�����ַ���
//		��string& insert(int pos, const string& str);	//�����ַ���
//		��string& insert(int pes, int n, char c);		//��ָ��λ�ò���n���ַ�C
//		��string& erase(int pos, int n = npos);			//ɾ����Pos��ʼ��n���ַ�



//	9. string�Ӵ�
//	�������� :
//		�����ַ����л�ȡ��Ҫ���Ӵ�
//	����ԭ�� :
//		��string substr(int pos = 0, int n = npos) const; //������pos��ʼ��n���ַ���ɵ��ַ���



int main28()
{
	test01();
	test02();
	test03();
	test04();
	system("pause");
	return 0;
}