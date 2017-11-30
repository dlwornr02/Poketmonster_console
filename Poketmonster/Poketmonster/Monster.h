#pragma once
#include<string>
#include<vector>
#include<iostream>
#include <windows.h>
class Monster
{
	std::string name; // 몬스터이름
	std::string type; //속성
	int level; // 몬스터 레벨
	int HP; // 몬스터 체력
	int Exp;
	std::vector<std::string> skill;
	std::string filename;
	std::string strong;
public:
	Monster(std::string name = "", std::string type = "", int level = 0, int hp = 0, std::string strong = "", std::string skill1 = "", std::string skill2 = "", std::string skill3 = "", std::string filename = "");
	std::vector<std::string> GetSkill()const;
	void SetHP(int hp);
	void Hurting(int damage);
	void Attack(Monster& enemy, int skillNum);
	void SetLevel(int level);
	int GetExp()const;
	void SetExp(int exp);
	int GetHP()const;
	std::string GetType()const;
	int GetLevel()const;
	std::string GetName()const;
	std::string GetSkillName(int i);
	int GetDamage(int i);
	std::string GetFilename()const;
	std::string GetStrong()const;
	void SetName(std::string _name);
	void ShowInfor();
};

