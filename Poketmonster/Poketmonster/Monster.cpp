#include "Monster.h"
using namespace std;
Monster::Monster(string name, string type, int level, int hp, string strong, string skill1, string skill2, string skill3, string filename) :name(name), type(type), level(level), HP(hp), strong(strong), filename(filename)
{
	skill.push_back(skill1);
	skill.push_back(skill2);
	skill.push_back(skill3);
	skill.push_back("포획하기!");
	skill.push_back("도망가기!");

	Exp = 0;
}
vector<string> Monster::GetSkill()const
{
	return skill;
}
void Monster::SetHP(int hp)
{
	HP = hp;
}
void Monster::Hurting(int damage)
{
	HP -= damage;
}
void Monster::Attack(Monster& enemy, int skillNum)
{
	int power;
	if (skillNum < 4 && 0 < HP)
	{
		power = this->GetDamage(skillNum);
		enemy.Hurting(power);
		system("cls");
		cout << name << "!!!  " << GetSkillName(skillNum) << "!!!" << endl;
		Sleep(1000);
	}
}
void Monster::SetLevel(int level)
{
	this->level = level;
	HP = 80 + (this->level - 1) * 10;
}
int Monster::GetExp()const
{
	return Exp;
}
void Monster::SetExp(int exp)
{
	Exp += exp;
}
int Monster::GetHP()const
{
	return HP;
}
string Monster::GetType()const
{
	return type;
}
int Monster::GetLevel()const
{
	return level;
}
string Monster::GetName()const
{
	return name;
}
string Monster::GetSkillName(int i)
{
	return skill[i - 1];

}
int Monster::GetDamage(int i)
{
	return i * (level * 5);
}
string Monster::GetFilename()const
{
	return filename;
}
string Monster::GetStrong()const
{
	return strong;
}
void Monster::SetName(string _name)
{
	name = _name;
}
void Monster::ShowInfor()
{
	cout << "포켓몬: " << name << endl;
	cout << "속성: " << type << endl;
	cout << "level: " << level << endl;
	cout << "체력: " << HP << endl;

}
