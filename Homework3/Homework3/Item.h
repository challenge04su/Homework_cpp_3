#pragma once
#include <iostream>
#include <string>

using namespace std;

class Item
{
private:
	string name_;
	int price_;

public:
	Item() : name_(" "), price_(0) {}
	Item(const string& name, int price) : name_(name), price_(price) {}

	const string& GetName() const;
	int GetPrice() const;
	void Clear()
	{
		name_ = "";
		price_ = 0;
	}
	void Print() const
	{
		cout << "[ 이름: " << name_ << ", 가격: " << price_ << " ]" << endl;
	}
};
