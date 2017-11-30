#pragma once
#include "Inventory.h"
#include<string>
class User //  사용자 클래스
{
	typedef struct Position
	{
		int x, y, mapNumber;
	}Position;
	Position position;
	std::string name;
	Inventory inven;
public:
	Inventory& GetInven();
	void UpdatePosition(int x, int y, int mapNumber);
	Position GetPosition()const;
	std::string GetName() const;
	void SetName(std::string pername);
	void SetMonster(Monster mon);
	void SelectMonster();

};
