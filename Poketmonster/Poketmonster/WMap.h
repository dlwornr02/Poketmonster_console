#pragma once
#include<string>
class WMap
{
	WMap*up;
	WMap*down;
	WMap*right;
	WMap*left;
	int mapNum;
public:
	std::string wmap[21][20];
	WMap(std::string map[21][20]=0, int mN=0);
	void SetRelation(int i);
	WMap* GetUp()const;
	WMap* GetDown()const;
	WMap* GetRight()const;
	WMap* GetLeft()const;
	int MapNum()const;
};

