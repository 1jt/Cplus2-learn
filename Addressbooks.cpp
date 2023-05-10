#include <iostream>
#include <windows.h>
#include <conio.h> 
#include <string>
#include <time.h>
#include <regex>
constexpr auto MAX = 10;

using namespace std;

// ��ϵ�˽ṹ��
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};
// ͨѶ¼�ṹ��
struct Addressbooks
{
	// ͨѶ¼�б������ϵ������
	Person personArray[MAX];
	// ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_Size = 0;
};

// �˵�
void showMenu();
// 1.�����ϵ��
void addPerson(Addressbooks* abs);
// 2.��ʾ��ϵ��
void showPerson(Addressbooks* abs);
// 3. ɾ����ϵ��
int isExit(Addressbooks* abs,string name);//�����ϵ���Ƿ���ڣ�������ڣ����ؾ���λ�ã������ڷ���-1
void deletePerson(Addressbooks* abs);
// 4. ������ϵ��
void findPerson(Addressbooks* abs);
// 5. �޸���ϵ��
void modifyPerson(Addressbooks* abs);
// 6. �����ϵ��
void cleanPerson(Addressbooks* abs);

string NAME()
{
	srand((unsigned int)time(0));//�����������
	//�ټ���-����
	const char* NA1[444] = { "��", "Ǯ", "��", "��", "��", "��", "֣", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ʩ", "��", "��", "��", "��", "��", "��", "κ", "��", "��", "��", "л", "��", "��", "��", "ˮ", "�", "��", "��", "��", "��", "��", "��", "��", "��", "��", "³", "Τ", "��", "��", "��", "��", "��", "��", "��", "��", "Ԭ", "��", "ۺ", "��", "ʷ", "��", "��", "��", "�", "Ѧ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ʱ", "��", "Ƥ", "��", "��", "��", "��", "��", "Ԫ", "��", "��", "��", "ƽ", "��", "��", "��", "��", "��", "Ҧ", "��", "տ", "��", "��", "ë", "��", "��", "��", "��", "��", "�", "��", "��", "��", "��", "̸", "��", "é", "��", "��", "��", "��", "��", "��", "ף", "��", "��", "��", "��", "��", "��", "ϯ", "��", "��", "ǿ", "��", "·", "¦", "Σ", "��", "ͯ", "��", "��", "÷", "ʢ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "֧", "��", "��", "��", "¬", "Ī", "��", "��", "��", "��", "��", "��", "Ӧ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ʯ", "��", "��", "ť", "��", "��", "��", "��", "��", "��", "½", "��", "��", "��", "��", "�", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ɽ", "��", "��", "��", "�", "��", "ȫ", "ۭ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ղ", "��", "��", "Ҷ", "��", "˾", "��", "۬", "��", "��", "��", "ӡ", "��", "��", "��", "��", "ۢ", "��", "��", "��", "��", "��", "��", "׿", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "˫", "��", "ݷ", "��", "��", "̷", "��", "��", "��", "��", "��", "��", "��", "Ƚ", "��", "۪", "Ӻ", "��", "�", "ɣ", "��", "�", "ţ", "��", "ͨ", "��", "��", "��", "��", "ۣ", "��", "��", "ũ", "��", "��", "ׯ", "��", "��", "��", "��", "��", "Ľ", "��", "��", "ϰ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "»", "��", "��", "Ź", "�", "��", "��", "ε", "Խ", "��", "¡", "ʦ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ɳ", "ؿ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "Ȩ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "۳", "Ϳ", "��", "��", "��", "��", "˧", "��", "��", "��", "��", "��", "��", "��", "Ĳ", "��", "٦", "��", "��", "ī", "��", "��", "��", "��", "��", "��", "١", "��", "��" };

	//�ټ���-����
	const char* NA2[59] = { "��ٹ", "˾��", "�Ϲ�", "ŷ��", "�ĺ�", "���", "����", "����", "����", "�ʸ�", "ξ��", "����", "�̨", "��ұ", "����", "���", "����", "����", "̫��", "����", "����", "����", "��ԯ", "���", "����", "����", "����", "Ľ��", "����", "����", "˾ͽ", "˾��", "����", "˾��", "�ӳ�", "���", "��ľ", "����", "����", "���", "����", "����", "����", "�ذ�", "�й�", "�׸�", "����", "����", "����", "����", "����", "����", "΢��", "����", "����", "����", "����", "�Ϲ�", "����" };

	//���Գ�����
	const char* ME1m[140] = { "ΰ", "��", "��", "��", "��", "��", "ǿ", "��", "ƽ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "־", "��", "��", "��", "��", "ɽ", "��", "��", "��", "��", "��", "��", "��", "Ԫ", "ȫ", "��", "ʤ", "ѧ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "˳", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ï", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "׳", "��", "˼", "Ⱥ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ԣ", "��", "��", "��", "��", "��", "��", "��", "ǫ", "��", "��", "��", "֮", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ά", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ʿ", "��", "��", "��", "��", "��", "��", "��", "��", "ʱ", "̩", "ʢ" };
	const char* ME2m[140] = { "ΰ", "��", "��", "��", "��", "��", "ǿ", "��", "ƽ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "־", "��", "��", "��", "��", "ɽ", "��", "��", "��", "��", "��", "��", "��", "Ԫ", "ȫ", "��", "ʤ", "ѧ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "˳", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ï", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "׳", "��", "˼", "Ⱥ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ԣ", "��", "��", "��", "��", "��", "��", "��", "ǫ", "��", "��", "��", "֮", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ά", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ʿ", "��", "��", "��", "��", "��", "��", "��", "��", "ʱ", "̩", "ʢ" };


	//Ů�Գ�����
	const char* ME1f[165] = { "��", "��", "Ӣ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "֥", "��", "Ƽ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "÷", "��", "��", "��", "��", "��", "��", "ѩ", "��", "��", "��", "ϼ", "��", "��", "ݺ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "�", "Ҷ", "�", "�", "�", "��", "��", "��", "��", "��", "ɺ", "ɯ", "��", "��", "��", "ٻ", "��", "�", "��", "�", "�", "ӱ", "¶", "��", "��", "�", "��", "��", "��", "��", "��", "��", "��", "ü", "��", "��", "��", "ޱ", "ݼ", "��", "�", "Է", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ܿ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "Ӱ", "��", "֦", "˼", "��", "��", "Ʈ", "��", "�", "��", "��", "��", "��", "��", "ɺ", "ɯ", "��", "��", "��", "ٻ", "��", "��", "��", "��", "Է", "�", "ܰ", "�", "��", "��", "��", "԰", "��", "ӽ", "��", "��", "��", "��", "ع", "��", "��", "��", "ˬ", "��", "��", "��", "ϣ" };
	const char* ME2f[165] = { "��", "��", "Ӣ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "֥", "��", "Ƽ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "÷", "��", "��", "��", "��", "��", "��", "ѩ", "��", "��", "��", "ϼ", "��", "��", "ݺ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "�", "Ҷ", "�", "�", "�", "��", "��", "��", "��", "��", "ɺ", "ɯ", "��", "��", "��", "ٻ", "��", "�", "��", "�", "�", "ӱ", "¶", "��", "��", "�", "��", "��", "��", "��", "��", "��", "��", "ü", "��", "��", "��", "ޱ", "ݼ", "��", "�", "Է", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ܿ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "Ӱ", "��", "֦", "˼", "��", "��", "Ʈ", "��", "�", "��", "��", "��", "��", "��", "ɺ", "ɯ", "��", "��", "��", "ٻ", "��", "��", "��", "��", "Է", "�", "ܰ", "�", "��", "��", "��", "԰", "��", "ӽ", "��", "��", "��", "��", "ع", "��", "��", "��", "ˬ", "��", "��", "��", "ϣ" };
	//cout << rand() << endl;
	int NA1Roll = rand() % 444;//����
	int NA2Roll = rand() % 59;//����
	int ME1mRoll = rand() % 140;//����
	int ME2mRoll = rand() % 140;//����
	int ME1fRoll = rand() % 165;//Ů��
	int ME2fRoll = rand() % 165;//Ů��
	string name;
	switch (rand()%8)
	{
	case 0:
		

		//���յ�����
		//printf("���յ�����:%s%s\n", NA1[NA1Roll], ME1m[ME1mRoll]);
		return string(NA1[NA1Roll]) + string(ME1m[ME1mRoll]);
	case 1:
		NA1Roll = rand() % 444;//����
		ME1fRoll = rand() % 140;//����
		//���յ���Ů
		//printf("���յ���Ů:%s%s\n", NA1[NA1Roll], ME1f[ME1fRoll]);
		return name = string(NA1[NA1Roll]) + string(ME1f[ME1fRoll]);
	case 2:
		NA1Roll = rand() % 444;//����
		ME1mRoll = rand() % 140;//����
		ME2mRoll = rand() % 140;//����
		//����˫����
		//printf("����˫����:%s%s%s\n", NA1[NA1Roll], ME1m[ME1mRoll], ME1m[ME2mRoll]);
		return string(NA1[NA1Roll]) + string(ME1m[ME1mRoll]) + string(ME1m[ME2mRoll]);
	case 3:
		NA1Roll = rand() % 444;//����
		ME1fRoll = rand() % 165;//Ů��
		ME2fRoll = rand() % 165;//Ů��
		//����˫��Ů
		//printf("����˫��Ů:%s%s%s\n", NA1[NA1Roll], ME1f[ME1fRoll], ME1f[ME2fRoll]);
		return string(NA1[NA1Roll]) + string(ME1f[ME1fRoll]) + string(ME1f[ME2fRoll]);
	case 4:
		NA2Roll = rand() % 59;//����
		ME1mRoll = rand() % 140;//����
		//���յ�����
		//printf("���յ�����:%s%s\n", NA2[NA2Roll], ME1m[ME1mRoll]);
		return string(NA2[NA2Roll]) + string(ME1m[ME1mRoll]);
	case 5:
		NA2Roll = rand() % 59;//����
		ME1fRoll = rand() % 165;//Ů��
		//���յ���Ů
		//printf("���յ���Ů:%s%s\n", NA2[NA2Roll], ME1f[ME1fRoll]);
		return string(NA2[NA2Roll]) + string(ME1f[ME1fRoll]);
	case 6:
		NA2Roll = rand() % 59;//����
		ME1mRoll = rand() % 140;//����
		ME2mRoll = rand() % 140;//����
		//����˫����
		//printf("����˫����:%s%s%s\n", NA2[NA2Roll], ME1m[ME1mRoll], ME2m[ME2mRoll]);
		return string(NA2[NA2Roll]) + string(ME1m[ME1mRoll]) + string(ME2m[ME2mRoll]);
	case 7:
		NA2Roll = rand() % 59;//����
		ME1fRoll = rand() % 165;//Ů��
		ME2fRoll = rand() % 165;//Ů��
		//����˫��Ů
		//printf("����˫��Ů:%s%s%s\n", NA2[NA2Roll], ME1f[ME1fRoll], ME2f[ME2fRoll]);
		return string(NA2[NA2Roll]) + string(ME1f[ME1fRoll]) + string(ME2f[ME2fRoll]);

	default:
		break;
	}

}
bool IsRegexInput(string str1)          // ʹ��������ʽ����ƥ�䣬
{
	bool flag;
	flag = true;
	regex r("\\d+");
	while (!(flag = regex_match(str1, r)))
	{
		return flag;
	}
	return flag;
}

int main0()
{   
	// ����ͨѶ¼
	Addressbooks abs;
	abs.m_Size = 0;

	int select = 0;
	while (true)
	{
		showMenu();

		//cin >> select;
		string str;
		cout << "input a int:" << endl;
		cin >> str;
		/*������һ��int��������cin����ʱ������������һ���ַ����ᷢ������4�������
			1.n��ֵ���0
			2.��ƥ������뱻������������
			3.cin�����һ�������Ǳ����ã���cin.fail()����true
			4.��cin�ķ������÷���false����(cin >> n)���ص���false*/
		//if (cin.fail() == true)
		//{
		//	cout << "����Ĳ�������\n";
		//	cin.clear();  //��ձ��
		//	cin.get();  //������һ����������Ļس�
		//	continue;
		//}
		
		while (!IsRegexInput(str))   // �ж�����������Ƿ�Ϊ����
		{
			cout << "�������ݸ�ʽ�������������֣�\n";
			cin >> str;
		}
		select = atoi(str.c_str());     //����û�����⣬�����ַ���ת��Ϊ����


		switch (select)
		{
		case 1://1.�����ϵ��
			addPerson(&abs);// ��ַ����
			break;
		case 2://2.��ʾ��ϵ��	
			showPerson(&abs);
			break;
		case 3://3.ɾ����ϵ��	
			deletePerson(&abs);
			break;
		case 4://4.������ϵ��
			findPerson(&abs);
			break;
		case 5://5.�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://6.�����ϵ��
			cleanPerson(&abs);
			break;
		case 0://0.�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������ȷָ���" << endl;
			break;
		}
	}
	
	/*start:
		cout << "�Ƿ�ʼ�������? Y/N \n" << endl;
			char choose = _getch();
			switch (choose)
			{
			case 'Y':
			case 'y':
			NAME();	
			goto start;
			case 'N':
			case 'n':
				break;
			default:
				cout << "�������,����������\n" << endl;
				goto start;
			}  
	*/
}
// �˵�
void showMenu()
{
	cout << "**********************" << endl;
	cout << "*****1.�����ϵ��*****" << endl;
	cout << "*****2.��ʾ��ϵ��*****" << endl;
	cout << "*****3.ɾ����ϵ��*****" << endl;
	cout << "*****4.������ϵ��*****" << endl;
	cout << "*****5.�޸���ϵ��*****" << endl;
	cout << "*****6.�����ϵ��*****" << endl;
	cout << "*****0.�˳�ͨѶ¼*****" << endl;
	cout << "**********************" << endl;
};
// 1.�����ϵ��
void addPerson(Addressbooks *abs)
{
	// ͨѶ¼�Ƿ�����
	if (abs->m_Size==MAX)
	{
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else
	{
		// ��Ӿ�����ϵ��
		// ����
		string name;
		cout << "������������" << endl;
		cin >> name;
		if (name == "y")
		{
			name = NAME();
			cout << "���ѡ���������" << name << endl;
		}
		abs->personArray[abs->m_Size].m_Name = name;
		// �Ա�
		cout << "�������Ա�" << endl;
		cout << "1--�У�" << endl;
		cout << "2--Ů��" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		// ����
		cout << "���������䣺" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age >= 0 && age <= 120)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "������������������" << endl;
		}
		//��ϵ�绰
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//��ͥסַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		//����ͨѶ¼����
		abs->m_Size++;

		cout << "��ӳɹ�" << endl;
		system("pause"); 

		system("cls");
	}
};

// 2.��ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (size_t i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��":"Ů" )<< "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");

	system("cls");
}

// 3. ɾ����ϵ��
int isExit(Addressbooks* abs, string name)//�����ϵ���Ƿ���ڣ�������ڣ����ؾ���λ�ã������ڷ���-1
{
	for (size_t i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
			return i;
	}
	return -1;
}
void deletePerson(Addressbooks* abs)
{
		cout << "������ɾ����ϵ������" << endl;
		string name;
		cin >> name;
		int ret = isExit(abs, name);
		if (ret == -1) {
			cout << "���޴���" << endl;
		}
		else
		{
			for (size_t i = ret; i < abs->m_Size; i++)
			{
				//����ǰ��
				abs->personArray[i] = abs->personArray[i + 1];
			}
			abs->m_Size--;
			cout << "ɾ���ɹ�" << endl;
		}
		system("pause");

		system("cls");
}

// 4. ������ϵ��
void findPerson(Addressbooks* abs)
{
	cout << "�����������ϵ������" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret == -1) {
		cout << "���޴���" << endl;
	}
	else
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_Addr << endl;
	}
	system("pause");
	system("cls");
}

// 5. �޸���ϵ��
void modifyPerson(Addressbooks* abs)
{
	cout << "������Ҫ�޸���ϵ�˵�����" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret == -1) {
		cout << "���޴���" << endl;
	}
	else
	{
		// ����
		cout << "������������" << endl;
		cin >> name;
		if (name == "y")
		{
			name = NAME();
			cout << "���ѡ���������" << name << endl;
		}
		abs->personArray[ret].m_Name = name;
		// �Ա�
		cout << "�������Ա�" << endl;
		cout << "1--�У�" << endl;
		cout << "2--Ů��" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		// ����
		cout << "���������䣺" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age >= 0 && age <= 120)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "������������������" << endl;
		}
		//��ϵ�绰
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//��ͥסַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
	}
	system("pause");
	system("cls");
}

// 6. �����ϵ��
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "�߼�������" << endl;
	system("pause");
	system("cls");
}