#pragma once
#include<iostream>
using namespace std;
// �Լ�ͨ�õ�������

template<typename T>
class MyArray
{
public:
	// �вι��� ����:����
	MyArray(int capacity)
	{
		//cout << "MyArray���вι������" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	// ��������
	// ��const��ֹ��С���޸Ĵ�����������
	MyArray(const MyArray& arr)
	{
		//cout << "MyArray�Ŀ����������" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		// this->pAddress = arr.pAddress;
		// ���
		this->pAddress = new T[arr.m_Capacity];
		// ��arr�е����ݿ�������
		for (size_t i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	// operator= ��ֹǳ��������
	MyArray& operator=(const MyArray& arr)
	{
		//cout << "MyArray��operator=����" << endl;
		// ���ж϶����Ƿ������ݣ���������ͷ�
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		// ���
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		// ��arr�е����ݿ�������
		for (size_t i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	// β�巨
	void Push_Back(const T& val)
	{
		// �ж������Ƿ���ڴ�С
		if (this->m_Capacity == this->m_Size)
		{
			cout << "������������" << endl;
			return;
		}
		this->pAddress[this->m_Size] = val;// ������ĩβ��������
		this->m_Size++;// ���������С
	}
	// βɾ��
	void Pop_Back()
	{
		// ���û����ʲ������һ��Ԫ�أ���Ϊβɾ���߼�ɾ��
		if (this->m_Size == 0)
		{
			cout << "������������" << endl;
			return;
		}
		this->m_Size--;// ���������С
	}
	// ͨ���±귽ʽ��������
	// ��������[]
	T& operator[](int index)
	{
		return this->pAddress[index];
	}
	// ������������
	int getCapacity()
	{
		return this->m_Capacity;
	}
	// ���������С
	int getSize()
	{
		return this->m_Size;
	}
	


	// ��������
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			//cout << "MyArray��������������" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

private:
	T* pAddress;	// ָ��ָ��������ٵ���ʵ����
	int m_Capacity;	// ��������
	int m_Size;	// �����С
};
