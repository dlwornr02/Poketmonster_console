#include "User.h"
using namespace std;
Inventory& User::GetInven()
{
	return inven;
}
void User::UpdatePosition(int x, int y, int mapNumber)
{
	position.x = x;
	position.y = y;
	position.mapNumber = mapNumber;
}
User::Position User::GetPosition()const
{
	return position;
}
string User::GetName() const
{
	return name;
}
/*void User::SetName(string pername)
{
	name = pername;
	system("cls");
	Printmap(Hmap[13]);
	Move(10, 10, Hmap[13], 25);
}*/
void User::SetMonster(Monster mon)
{
	mon.SetLevel(5);
	inven.AddMonster(mon);
}
/*void User::SelectMonster()
{
	int choose;
	string name = GameStory(choose);
	vector<Monster>::iterator iter;
	if (choose == 1)
	{
		iter = find_if(HMonster["¹°"].begin(), HMonster["¹°"].end(), FindMonster("²¿ºÎ±â"));
		SetMonster((*iter));
	}
	else if (choose == 2)
	{
		iter = find_if(HMonster["ºÒ"].begin(), HMonster["ºÒ"].end(), FindMonster("ÆÄÀÌ¸®"));
		SetMonster((*iter));
	}
	else if (choose == 3)
	{
		iter = find_if(HMonster["¶¥"].begin(), HMonster["¶¥"].end(), FindMonster("ÀÌ»óÇØ¾¾"));
		SetMonster((*iter));
	}
	SetName(name);

}*/
