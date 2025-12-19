#include <iostream>
#include <string>

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

	string GetName() { return name_; }
	int GetPrice() { return price_; }

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
		pItems_ = new Item[capacity_];
		this->capacity_ = capacity_;
		size_ = 0;
	}
	~Inventory()
	{
		delete[] pItems_;
	}

	void AddItem(Item item)
	{
		if (size_ >= capacity_)
		{
			cout << "인벤토리가 꽉 찼습니다!" << endl;
			return;
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
};



int main()
{
	Item item("Hello Item", 1000);
	Inventory<Item> inventory;
	inventory.AddItem(item);
	inventory.AddItem(Item("Hello Item2", 1100));

	for (int i = 0; i < 10; i++)
	{
		inventory.AddItem(Item("Hello Item" + to_string(i), 100));
	}

	inventory.RemoveLastItem();
	inventory.PrintAllItems();
	return 0;
}