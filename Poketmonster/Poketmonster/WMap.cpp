#include "WMap.h"
using namespace std;
WMap::WMap(string map[21][20], int mN):mapNum(mN)
{
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 20; j++)
			wmap[i][j] = map[i][j];
	up = NULL;
	down = NULL;
	right = NULL;
	left = NULL;
}
WMap* WMap::GetUp()const
{
	return up;
}
WMap* WMap::GetDown()const
{
	return down;
}
WMap* WMap::GetRight()const
{
	return right;
}
WMap* WMap::GetLeft()const
{
	return left;
}
int WMap::MapNum()const
{
	return mapNum;
}


