#include "Inventory.h"
using namespace std;
Inventory::Inventory()
{
	key = false;
}
void Inventory::SetKey(bool get)
{
	key = get;
}
bool Inventory::GetKey()
{
	return key;
}
void Inventory::SetSize(int size)
{
	mv.reserve(size);
}
void Inventory::InventoryInfo()
{
	vector<Monster>::iterator iter = mv.begin();
	int i = 1;
	for (; iter != mv.end(); iter++, i++)
	{
		cout << i << "." << endl;
		(*iter).ShowInfor();
		cout << endl;
	}
	if (key == true)
		cout << "키:보유중" << endl;
	else if (key == false)
		cout << "키:없음" << endl;
}
void Inventory::AddMonster(Monster m)
{
	mv.push_back(m);
}
vector<Monster> Inventory::GetMonsterlist()
{
	return mv;
}
vector<Monster>::iterator Inventory::Getsiter()
{
	return mv.begin();
}
Monster& Inventory::UserMonster(int i)
{
	return mv[i];
}
int Inventory::Size()const
{
	return mv.size();
}

