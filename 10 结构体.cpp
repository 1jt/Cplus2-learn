//#include<iostream>
//using namespace std;
//#include<string>
//
//// �ṹ�������û��Լ��Զ�����������ͣ������û��洢���õ���������
//// �﷨
//// struct �ṹ���� {�ṹ���Ա�б�};
//
//// ͨ���ṹ�崴������
//// 1. struct �ṹ���� ������
//// 2. struct �ṹ���� ������ = {��Ա1ֵ,��Ա2ֵ...}
//// 3. ����ṹ��ʱ˳�㴴������
//
//struct Student
//{
//	// ��Ա�б�
//	string name;
//	int age;
//	int score;
//}s3;
//struct Teacher
//{
//	int id;
//	string name;
//	int age;
//	Student stu;//������ѧ�������ȶ���ѧ���ṹ��
//};
//void print(Student s1);
//void print2(Student* s);
//
//int main()
//{
//	struct Student s1;
//	s1.name = "����";
//	s1.age = 18;
//	s1.score = 100;
//	cout << "������" << s1.name << " ���䣺" << s1.age << " ������" << s1.score << endl;
//	cout << "Studentռ���ڴ�ռ�Ϊ��" << sizeof(Student) << endl;
//	// 40+4+4
//	cout << "Studentռ���ڴ�ռ�Ϊ��" << sizeof(s1) << endl;
//	
//	Student s2 = {"����",19,80};// struct���Բ�Ҫ
//	cout << "������" << s2.name << " ���䣺" << s2.age << " ������" << s2.score << endl;
//
//	s3.name = "����";
//	s3.age = 20;
//	s3.score = 60;
//	cout << "������" << s3.name << " ���䣺" << s3.age << " ������" << s3.score << endl;
//
//
//	// �ṹ������
//	//����
//	Student arr[3]=
//	{
//		{"����",18,100},
//		{"����",19,80},
//		{"����",20,60}
//	};
//	// ��ֵ
//	arr[2].name = "����";
//	// ����
//	for (size_t i = 0; i < 3; i++)
//	{
//		cout << "������" << arr[i].name << " ���䣺" << arr[i].age << " ������" << arr[i].score << endl;
//	}
//
//	
//	// �ṹ��ָ��
//	// ͨ��ָ����ʽṹ���еĳ�Ա
//	// ���ò����� -> ����ͨ���ṹ��ָ����ʽṹ������
//	Student* p = &s1;
//	cout << "������" << p->name << endl;
//
//
//	// �ṹ��Ƕ�׽ṹ��
//	Teacher t;
//	t.age = 50;
//	t.id = 100000;
//	t.name = "����";
//	t.stu.age = 18;
//	t.stu.name = "С��";
//	t.stu.score = 100;
//
//	// �ṹ������������
//	// ֵ����
//	// ��ַ����
//	print(s1);
//	cout << "������������" << s1.name << "\t���䣺" << s1.age << "\t������" << s1.score << endl;
//	print2(&s1);
//	cout << "������������" << s1.name << "\t���䣺" << s1.age << "\t������" << s1.score << endl;
//
//
//	// �ṹ����constʹ�ó���
//	// ֵ���ݵĻ�̫���ڴ��ˣ���Ϊָ����Լ����ڴ�ռ䣬���Ҳ��Ḵ���µĸ�������
//	// ����const�Ժ�һ�����޸ĵĲ����ͻᱨ�����Է�ֹ���ǵ������
//
//	system("pause");
//	return 0;
//}
//
////ֵ����
//void print(Student s1) {
//	cout << "ֵ����" << endl;
//	s1.age = 66;
//	cout << "�Ӻ���������" << s1.name << "\t���䣺" << s1.age << "\t������" << s1.score << endl;
//}
//
////��ַ����
//void print2(Student* s) {
//	cout << "��ַ����" << endl;
//	s->age = 90;
//	cout << "�Ӻ���������" << s->name << "\t���䣺" << s->age << "\t������" << s->score << endl;
//}
