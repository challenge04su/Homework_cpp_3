#include <iostream>
#include <string>
#include "Item.h"
#include "Inventory.h"

using namespace std;

int main()
{
	int count;
	string name_;
	int price_;

	Inventory<Item> inventory(10);

	cout << "추가할 아이템 개수를 입력하세요. : ";
	cin >> count;
	cin.ignore();
	cout << endl;

	for (int i = 0; i < count; i++)
	{
		cout << "아이템 이름 : ";
		getline(cin, name_);
		cout << endl;

		cout << "아이템 가격 : ";
		cin >> price_;
		cin.ignore();
		cout << endl;

		Item item(name_, price_);
		inventory.AddItem(item);
	}
	cout << endl;
	inventory.PrintAllItems();

	return 0;
}