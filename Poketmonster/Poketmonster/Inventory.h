#pragma once
#include"Monster.h"
#include<vector>
class Inventory
{
	std::vector<Monster> mv;
	bool key;
public:
	Inventory();
	void SetKey(bool get);
	bool GetKey();
	void SetSize(int size);
	void InventoryInfo();
	void AddMonster(Monster m);
	std::vector<Monster> GetMonsterlist();
	std::vector<Monster>::iterator Getsiter();
	Monster& UserMonster(int i);
	int Size()const;
};

