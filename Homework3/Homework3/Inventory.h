#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Inventory
{
private:
	T* pItems_;
	int capacity_;
	int size_;

public:
	Inventory(int capacity) : capacity_(capacity), size_(0)
	{
		pItems_ = new T[capacity_];
		if (capacity_ < 1)
		{
			capacity_ = 1;
		}
	} 
	~Inventory()
	{
		delete[] pItems_;
		pItems_ = nullptr;
	}

	void AddItem(const T& item) 
	{ 
		if (size_ < capacity_) 
		{ 
			pItems_[size_] = item; 
			size_++; 
			return; 
		} 
		else 
		{ 
			cout << "인벤토리가 꽉 찼습니다!" << endl; 
		} 
	}
	void RemoveLastItem()
	{
		if (size_ < 1)
		{
			cout << "인벤토리가 비어있습니다." << endl;
			return;
		}
		else
		{
			size_--;
		}
	}
	int GetSize() const
	{
		return size_;
	}
	int GetCapacity() const
	{
		return capacity_;
	}
	
	void PrintAllItems() const
	{
		if (size_ < 1)
		{
			cout << "인벤토리가 비어있습니다." << endl;
			return;
		}
		else
		{
			for (int i = 0; i <= size_ - 1; i++)
			{
				pItems_[i].Print();
			}
		}	
	}
};