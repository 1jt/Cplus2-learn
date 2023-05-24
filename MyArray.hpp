#pragma once
#include<iostream>
using namespace std;
// 自己通用的数组类

template<typename T>
class MyArray
{
public:
	// 有参构造 参数:容量
	MyArray(int capacity)
	{
		//cout << "MyArray的有参构造调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	// 拷贝构造
	// 加const防止不小心修改传进来的引用
	MyArray(const MyArray& arr)
	{
		//cout << "MyArray的拷贝构造调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		// this->pAddress = arr.pAddress;
		// 深拷贝
		this->pAddress = new T[arr.m_Capacity];
		// 将arr中的数据拷贝过来
		for (size_t i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	// operator= 防止浅拷贝问题
	MyArray& operator=(const MyArray& arr)
	{
		//cout << "MyArray的operator=调用" << endl;
		// 先判断堆区是否有数据，如果有先释放
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		// 深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		// 将arr中的数据拷贝过来
		for (size_t i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	// 尾插法
	void Push_Back(const T& val)
	{
		// 判断容量是否等于大小
		if (this->m_Capacity == this->m_Size)
		{
			cout << "满啦！！！！" << endl;
			return;
		}
		this->pAddress[this->m_Size] = val;// 在数组末尾插入数据
		this->m_Size++;// 更新数组大小
	}
	// 尾删法
	void Pop_Back()
	{
		// 让用户访问不到最后一个元素，即为尾删，逻辑删除
		if (this->m_Size == 0)
		{
			cout << "空啦！！！！" << endl;
			return;
		}
		this->m_Size--;// 更新数组大小
	}
	// 通过下标方式访问数组
	// 即，重载[]
	T& operator[](int index)
	{
		return this->pAddress[index];
	}
	// 返回数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}
	// 返回数组大小
	int getSize()
	{
		return this->m_Size;
	}
	


	// 析构函数
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			//cout << "MyArray的析构函数调用" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

private:
	T* pAddress;	// 指针指向堆区开辟的真实数组
	int m_Capacity;	// 数组容量
	int m_Size;	// 数组大小
};
