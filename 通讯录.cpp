#include <iostream>
#include <windows.h>
#include <conio.h> 
#include <string>
#include <time.h>

using namespace std;
// �˵�
void showMenu()
{
	cout << "**********************" << endl;
	cout << "*****1.������ϵ��*****" << endl;
	cout << "*****2.��ʾ��ϵ��*****" << endl;
	cout << "*****3.ɾ����ϵ��*****" << endl;
	cout << "*****4.������ϵ��*****" << endl;
	cout << "*****5.�޸���ϵ��*****" << endl;
	cout << "*****6.�����ϵ��*****" << endl;
	cout << "*****0.�˳�ͨѶ¼*****" << endl;
	cout << "**********************" << endl;

};


void NAME()
{
	srand(time(0));//�����������
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
	cout << rand() << endl;
	int NA1Roll = rand() % 444;//����
	int NA2Roll = rand() % 59;//����
	int ME1mRoll = rand() % 140;//����
	int ME2mRoll = rand() % 140;//����
	int ME1fRoll = rand() % 165;//Ů��
	int ME2fRoll = rand() % 165;//Ů��

	//���յ�����
	printf("���յ�����:%s%s\n", NA1[NA1Roll], ME1m[ME1mRoll]);

	NA1Roll = rand() % 444;//����
	ME1mRoll = rand() % 140;//����
	//���յ���Ů
	printf("���յ���Ů:%s%s\n", NA1[NA1Roll], ME1f[ME1fRoll]);

	NA1Roll = rand() % 444;//����
	ME1mRoll = rand() % 140;//����
	ME2mRoll = rand() % 140;//����
	//����˫����
	printf("����˫����:%s%s%s\n", NA1[NA1Roll], ME1m[ME1mRoll], ME1m[ME2mRoll]);

	NA1Roll = rand() % 444;//����
	ME1fRoll = rand() % 165;//Ů��
	ME2fRoll = rand() % 165;//Ů��
	//����˫��Ů
	printf("����˫��Ů:%s%s%s\n", NA1[NA1Roll], ME1f[ME1fRoll], ME1f[ME2fRoll]);

	NA2Roll = rand() % 59;//����
	ME1mRoll = rand() % 140;//����
	//���յ�����
	printf("���յ�����:%s%s\n", NA2[NA2Roll], ME1m[ME1mRoll]);

	NA2Roll = rand() % 59;//����
	ME1fRoll = rand() % 165;//Ů��
	//���յ���Ů
	printf("���յ���Ů:%s%s\n", NA2[NA2Roll], ME1f[ME1fRoll]);

	NA2Roll = rand() % 59;//����
	ME1mRoll = rand() % 140;//����
	ME2mRoll = rand() % 140;//����
	//����˫����
	printf("����˫����:%s%s%s\n", NA2[NA2Roll], ME1m[ME1mRoll], ME2m[ME2mRoll]);

	NA2Roll = rand() % 59;//����
	ME1fRoll = rand() % 165;//Ů��
	ME2fRoll = rand() % 165;//Ů��
	//����˫��Ů
	printf("����˫��Ů:%s%s%s\n", NA2[NA2Roll], ME1f[ME1fRoll], ME2f[ME2fRoll]);

	cout << "\n" << endl;

}
int main()
{   
	int select = 0;
	while (true)
	{
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1://1.������ϵ��
			break;
		case 2://2.��ʾ��ϵ��		
			break;
		case 3://3.ɾ����ϵ��		
			break;
		case 4://4.������ϵ��
			break;
		case 5://5.�޸���ϵ��
			break;
		case 6://6.�����ϵ��
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
