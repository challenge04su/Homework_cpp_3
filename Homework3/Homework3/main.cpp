#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Item
{
public:
	Item()
	{
		name_ = "";
		price_ = 0;
	}
	Item(string name, int price)
	{
		name_ = name;
		price_ = price;
	}
	~Item() {}

	string GetName() const { return name_; }
	int GetPrice() const { return price_; }

private:
	string name_;
	int price_;
};

template <typename T>
class Inventory
{
private:
	T* pItems_;
	int capacity_;
	int size_;

public:
	Inventory(int capacity_ = 10)
	{
		pItems_ = new T[capacity_];
		this->capacity_ = capacity_;
		size_ = 0;
	}
	Inventory(const Inventory<T>& other)
	{
		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T[capacity_];
		
		for (int i = 0; i < size_; ++i) 
		{
			pItems_[i] = other.pItems_[i];
		}
		cout << "인벤토리 복사 완료" << endl;
	}
	~Inventory()
	{
		delete[] pItems_;
	}
	int GetCapacity() const { return capacity_; }
	void AddItem(Item item)
	{
		if (size_ >= capacity_)
		{
			Resize(capacity_ * 2);
		}
		pItems_[size_++] = item;

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
	void PrintAllItems()
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
				cout << "Name : " << pItems_[i].GetName() << ", Price : " << pItems_[i].GetPrice() << endl;
			}
		}
	}
	void Assign(const Inventory<T>& other)
	{

	}
	void Resize(int newCapacity)
	{
		if(newCapacity < size_)
			size_ = newCapacity;

		T* newItems = new T[newCapacity];

		for (int i = 0; i < size_; ++i)
			newItems[i] = pItems_[i];

		delete[] pItems_;
		pItems_ = newItems;
		capacity_ = newCapacity;
	}
	
	void SortItems()
	{
		sort(pItems_, pItems_ + size_, [](const Item& a, const Item& b)
			{ return a.GetPrice() < b.GetPrice(); }
			);
	}
};



int main()
{
	Inventory<Item>* itemInventory = new Inventory<Item>();
	for (int i = 0; i < 11; ++i)
	{
		itemInventory->AddItem(Item("Item" + to_string(i), i * 100));
	}

	itemInventory->PrintAllItems();
	cout << "ItemCapacity : " << itemInventory->GetCapacity() << endl;

	itemInventory->Resize(25);
	for (int i = 0; i < 14; ++i)
	{
		itemInventory->AddItem(Item("Item" +to_string(i), i * 100));
	}

	itemInventory->PrintAllItems();
	cout << "ItemCapacity : " << itemInventory->GetCapacity() << endl;

	itemInventory->SortItems();
	itemInventory->PrintAllItems();

	Inventory<Item>* itemInventory2 = new Inventory<Item>(*itemInventory);
	itemInventory2->PrintAllItems();

	delete itemInventory;
	delete itemInventory2;
	return 0;
}