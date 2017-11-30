#include <conio.h>
#include<list>
#include <fstream>
#include <time.h>
#include<algorithm>
#include<map>
#include"WMap.h"
#include"User.h"
#include "Piece_of_Map.h"
#define RIGHT 77
#define LEFT 75
#define UP 72
#define DOWN 80
#define ENTER 13
#define SPACE 32
#define ESC 27
#define I 105
using namespace std;
void Load();
void Save();
void PrintMonster(string fileName);
void gotoxy(int x, int y);
void Menu();
void ApearMonster(int mapNum);
void Printmap(WMap&map);
int Move(int _x, int _y, WMap&map, int mapNum);
string GameStory(int& choose);
void ApearMonster(int mapNum);
void Fight();
void PrintMyMon(int hp, int exp, string monName);
void PrintEnemyMon(int hp, int exp, string monName);
void InitHMap();
void InitHMonster();
vector<Monster> Fire;
vector<Monster> Water;
vector<Monster> Earth;
vector<Monster> Electronic;
map<string, vector<Monster>> HMonster;
map<int, WMap> Hmap;

User user;
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
void main()
{
	InitHMap();
	InitHMonster();
re:
	system("cls");
	Menu();
	switch (_getch())
	{
	case '1':
		user.SelectMonster();
		break;
	case '2':
		Load();
		break;
	case '3':
		cout << "���α׷� ����." << endl;
		break;
	default:
		goto re;
	}
}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
class FindMonster
{
	string name;
public:
	FindMonster(string name) :name(name) {}
	bool operator()(const Monster&m1)
	{
		return (m1.GetName() == name);
	}
};
void WMap::SetRelation(int i)
{
	if (0 < (i - 1) && (i - 1) < 26)
		up = &Hmap[i - 1];
	if (0 < (i + 1) && (i + 1) < 26)
		down = &Hmap[i + 1];
	if (0 < (i + 5) && (i + 5) < 26)
		right = &Hmap[i + 5];
	if (0 < (i - 5) && (i - 5) < 26)
		left = &Hmap[i - 5];
}
void InitHMap()
{
	Hmap.insert(pair<int, WMap>(1, WMap(map11, 1)));
	Hmap.insert(pair<int, WMap>(2, WMap(map12, 3)));
	Hmap.insert(pair<int, WMap>(3, WMap(map13, 17)));
	Hmap.insert(pair<int, WMap>(4, WMap(map14, 9)));
	Hmap.insert(pair<int, WMap>(5, WMap(map15, 11)));
	Hmap.insert(pair<int, WMap>(6, WMap(map21, 2)));
	Hmap.insert(pair<int, WMap>(7, WMap(map22, 4)));
	Hmap.insert(pair<int, WMap>(8, WMap(map23, 18)));
	Hmap.insert(pair<int, WMap>(9, WMap(map24, 10)));
	Hmap.insert(pair<int, WMap>(10, WMap(map25, 12)));
	Hmap.insert(pair<int, WMap>(11, WMap(map31, 19)));
	Hmap.insert(pair<int, WMap>(12, WMap(map32, 20)));
	Hmap.insert(pair<int, WMap>(13, WMap(map33, 25)));
	Hmap.insert(pair<int, WMap>(14, WMap(map34, 23)));
	Hmap.insert(pair<int, WMap>(15, WMap(map35, 24)));
	Hmap.insert(pair<int, WMap>(16, WMap(map41, 5)));
	Hmap.insert(pair<int, WMap>(17, WMap(map42, 7)));
	Hmap.insert(pair<int, WMap>(18, WMap(map43, 21)));
	Hmap.insert(pair<int, WMap>(19, WMap(map44, 13)));
	Hmap.insert(pair<int, WMap>(20, WMap(map45, 15)));
	Hmap.insert(pair<int, WMap>(21, WMap(map51, 6)));
	Hmap.insert(pair<int, WMap>(22, WMap(map52, 8)));
	Hmap.insert(pair<int, WMap>(23, WMap(map53, 22)));
	Hmap.insert(pair<int, WMap>(24, WMap(map54, 14)));
	Hmap.insert(pair<int, WMap>(25, WMap(map55, 16)));

	for (int i = 0; i < 25; i++)
		Hmap[i + 1].SetRelation(i + 1);
}
void User::SetName(string pername)
{
	name = pername;
	system("cls");
	Printmap(Hmap[13]);
	Move(10, 10, Hmap[13], 25);
}
void User::SelectMonster()
{
	int choose;
	string name = GameStory(choose);
	vector<Monster>::iterator iter;
	if (choose == 1)
	{
		iter = find_if(HMonster["��"].begin(), HMonster["��"].end(), FindMonster("���α�"));
		SetMonster((*iter));
	}
	else if (choose == 2)
	{
		iter = find_if(HMonster["��"].begin(), HMonster["��"].end(), FindMonster("���̸�"));
		SetMonster((*iter));
	}
	else if (choose == 3)
	{
		iter = find_if(HMonster["��"].begin(), HMonster["��"].end(), FindMonster("�̻��ؾ�"));
		SetMonster((*iter));
	}
	SetName(name);

}
void InitHMonster() {
	HMonster["��"] = Fire;
	HMonster["��"] = Water;
	HMonster["��"] = Earth;
	HMonster["����"] = Electronic;

	HMonster["��"].push_back(Monster("���̸�", "��", 1, 80, "��", "����", "������", "ȭ�����", "���̸�.txt"));
	HMonster["��"].push_back(Monster("�Ҳɸ�", "��", 1, 80, "��", "������", "�Ҳɹ�ġ��", "�Ķ��Ҳ�", "�Ҳɸ�.txt"));
	HMonster["��"].push_back(Monster("������", "��", 2, 90, "��", "ȭǮ��", "���ǻ�����Ŭ", "����", "������.txt"));
	HMonster["��"].push_back(Monster("���׸���", "��", 2, 90, "��", "�Ҳ�Ƣ���", "��������", "ȭ��������", "���׸���.txt"));
	HMonster["��"].push_back(Monster("����Ÿ", "��", 3, 100, "��", "��������", "¤���", "�Ҳɼ���", "����Ÿ.txt"));
	HMonster["��"].push_back(Monster("��Ʈ��", "��", 7, 140, "��", "������", "�÷���", "��Ʈ�Ҳ�", "��Ʈ��.txt"));
	HMonster["��"].push_back(Monster("���ڸ�", "��", 10, 170, "��", "�÷������̺�", "��ǳ", "�Ҳ�ȸ����", "���ڸ�BOSS.txt"));

	HMonster["��"].push_back(Monster("���α�", "��", 1, 80, "��", "��ٶ��", "���������", "�����ĵ�", "���α�.txt"));
	HMonster["��"].push_back(Monster("�׾�ŷ", "��", 1, 70, "��", "Ƣ�������", "������", "�����Ű��", "�׾�ŷ.txt"));
	HMonster["��"].push_back(Monster("����", "��", 2, 90, "��", "���δ��", "����ź", "�ĵ�Ÿ��", "����.txt"));
	HMonster["��"].push_back(Monster("�����縮", "��", 2, 90, "��", "�ұݹ�", "��ǰ����", "������Ű�׽ý�", "�����縮.txt"));
	HMonster["��"].push_back(Monster("������", "��", 3, 100, "��", "°������", "������", "�õ���", "������.txt"));
	HMonster["��"].push_back(Monster("����Ĵ�", "��", 7, 140, "��", "�Ϳ���ô�ϱ�", "����ǥ�ٿ��", "����", "����Ĵ�.txt"));
	HMonster["��"].push_back(Monster("�źϿ�", "��", 10, 170, "��", "�׷ο���ġ", "������ĳ��", "���̵������", "�źϿ�BOSS.txt"));

	HMonster["����"].push_back(Monster("��ī��", "����", 1, 80, "��", "�����ġ��", "����ũ", "�鸸��Ʈ", "��ī��.txt"));
	HMonster["����"].push_back(Monster("�����", "����", 1, 80, "��", "�߱���", "�Ӹ��ڱ�", "������", "�����.txt"));
	HMonster["����"].push_back(Monster("����", "����", 1, 80, "��", "�ֱ�", "����ġ��", "���� ��ũ", "����.txt"));
	HMonster["����"].push_back(Monster("����", "����", 3, 100, "��", "���������", "�׸��ںн�", "�Ϸ�Ʈ����", "����.txt"));
	HMonster["����"].push_back(Monster("���ǽ��", "����", 4, 110, "��", "���¢��", "������ȭ", "��������", "���ǽ��.txt"));
	HMonster["����"].push_back(Monster("���", "����", 8, 150, "��", "�����ũ", "������", "������", "���.txt"));
	HMonster["����"].push_back(Monster("������", "����", 10, 170, "��", "���̾�����", "���ϵ庼Ʈ", "������ġ", "������BOSS.txt"));

	HMonster["��"].push_back(Monster("�̻��ؾ�", "��", 1, 80, "��", "��������", "���𳯸���", "����ä��", "�̻��ؾ�.txt"));
	HMonster["��"].push_back(Monster("ġ�ڸ�Ÿ", "��", 1, 80, "��", "�ķ�ġ��", "�����ٴ�����", "�����ø���", "ġ�ڸ�Ÿ.txt"));
	HMonster["��"].push_back(Monster("����", "��", 2, 90, "��", "�ٶ�����Ű��", "�ɾƴ��", "Į��������", "����.txt"));
	HMonster["��"].push_back(Monster("��������", "��", 3, 100, "��", "����������", "�볪����ġ", "��������", "��������.txt"));
	HMonster["��"].push_back(Monster("���丵", "��", 4, 110, "��", "���丮������", "����Ÿ��", "��������", "���丵.txt"));
	HMonster["��"].push_back(Monster("���ο�", "��", 8, 150, "��", "�ٴ���", "������ġ", "�ٴûձ�", "���ο�.txt"));
	HMonster["��"].push_back(Monster("�̻��ز�", "��", 10, 170, "��", "Ǯ����", "�Գ�������", "�ֶ��", "�̻��ز�BOSS.txt"));

	vector<Monster>::iterator fiter = Fire.begin();
	vector<Monster>::iterator witer = Water.begin();
	vector<Monster>::iterator eiter = Earth.begin();
	vector<Monster>::iterator eniter = Electronic.begin();
}

void PrintMyMon(Monster& mymon, int&selectSkill)
{
a:
	system("cls");
	ifstream fin;
	char line[200];

	fin.open(mymon.GetFilename());

	if (fin.is_open())
	{
		while (fin.getline(line, sizeof(line)))
		{
			cout << line << endl;
		}
	}
	cout << "LV." << mymon.GetLevel() << endl;
	cout << "HP:" << Bar[(mymon.GetHP() / 10)] << endl << endl;
	cout << "EXP:" << Bar[mymon.GetExp() / 10] << endl;
	for (int i = 0; i < 5; i++)
	{
		gotoxy(45, 5 + i);
		cout << (i + 1) << '.' << mymon.GetSkill()[i] << endl;
	}
	gotoxy(45, 10);
	cout << "��ų���� :";
	selectSkill = ((_getch()) - '0');
	if ((selectSkill <= 0) || (6 <= selectSkill && selectSkill != 57))
	{
		fin.close();
		goto a;
	}
	fin.close();
}
void PrintEnemyMon(Monster& enemymon, int&selectSkill)
{
	srand((unsigned)time(NULL));
	system("cls");
	ifstream fin;
	char line[200];

	fin.open(enemymon.GetFilename());
	if (fin.is_open())
	{
		while (fin.getline(line, sizeof(line)))
		{
			int i = 0;
			cout << line << endl;
			i++;
		}
	}
	cout << "LV." << enemymon.GetLevel() << endl;
	cout << "HP:" << Bar[(enemymon.GetHP() / 10)] << endl << endl;
	fin.close();
	selectSkill = (rand() % 3 + 1);
	Sleep(1000);
}
void Fight(string enemyname, string montype)
{
	static int mymonNumber = 1;
	int selectSkill1, selectSkill2;
	string enemymontype;
	int mymonsterNum = user.GetInven().GetMonsterlist().size();
	Monster mymon = user.GetInven().UserMonster(mymonNumber - 1);
	vector<Monster>::iterator iter = find_if(HMonster[montype].begin(), HMonster[montype].end(), FindMonster(enemyname));
	Monster enemymon = *(iter);
	while (0 < enemymon.GetHP())
	{
		int die_monsterNum = 0;
		die_monsterNum = 0;
		for (int i = 0; i < mymonsterNum; i++)
		{
			if (user.GetInven().UserMonster(i).GetHP() <= 0)
			{
				die_monsterNum++;
			}
		}
		if (mymon.GetHP() <= 0 && die_monsterNum < mymonsterNum)
		{
		reselect:
			system("cls");
			user.GetInven().UserMonster(mymonNumber - 1).SetHP(0);
			user.GetInven().InventoryInfo();
			cout << "���ϸ��� �����ϼ��� : ";
			cin >> mymonNumber;
			if (cin.fail())
			{
				cin.clear();
				char c;
				cin >> c;
				goto reselect2;
			}
			else if (mymonNumber <= mymonsterNum)
				mymon = user.GetInven().UserMonster(mymonNumber - 1);
			else
				goto reselect;
		}
		else if (mymon.GetHP() <= 0 && die_monsterNum == mymonsterNum)
		{
			system("cls");
			user.GetInven().UserMonster(mymonNumber - 1).SetHP(0);
			cout << "���������� ���Ͱ� �����ϴ�." << endl << "���ϸ��Ϳ��� ġ���������." << endl;
			Sleep(1000);
			break;
		}
	b:
		PrintMyMon(mymon, selectSkill1);
		if (selectSkill1 == 4)
		{
			if (enemymon.GetHP() <= 20)
			{
				if (user.GetInven().Size() < 6)
				{
					user.GetInven().AddMonster(enemymon);
					mymonsterNum++;
					system("cls");
					cout << enemymon.GetName() << "��/�� ��ȹ�ϼ˽��ϴ�." << endl;
					Sleep(1000);
					break;
				}
				else
				{
					system("cls");
					cout << "�賶�� ���������ϴ�." << endl;
					goto b;
				}
			}
			else if (20 < enemymon.GetHP())
			{
				system("cls");
				cout << "���Ͱ� ���� �����մϴ�!!!!" << endl;
				Sleep(1000);
				goto b;
			}
		}
		else if (selectSkill1 == 5)
		{
			system("cls");
			cout << "�ʹ����...��������...�Ф�" << endl;
			Sleep(1000);
			break;
		}
		else if (0 < selectSkill1 && selectSkill1 < 4)
		{
			PrintEnemyMon(enemymon, selectSkill2);
			mymon.Attack(enemymon, selectSkill1);

			PrintEnemyMon(enemymon, selectSkill2);
			enemymon.Attack(mymon, selectSkill2);
			user.GetInven().UserMonster(mymonNumber - 1).SetHP(mymon.GetHP());
		}
		else if (selectSkill1 == 57)
		{
		reselect2:
			system("cls");
			user.GetInven().InventoryInfo();
			cout << "���ϸ��� �����ϼ��� : ";
			cin >> mymonNumber;
			if (cin.fail())
			{
				cin.clear();
				char c;
				cin >> c;
				goto reselect2;
			}
			else if (mymonNumber <= mymonsterNum) {
				mymon = user.GetInven().UserMonster(mymonNumber - 1);
				goto b;
			}
			else
				goto reselect2;
		}
	}
	if (mymon.GetHP() > 0 && selectSkill1 != 4 && selectSkill1 != 5)
	{
		user.GetInven().UserMonster(mymonNumber - 1).SetExp(((enemymon.GetLevel()) * 20) / mymon.GetLevel());
	}

	if (mymon.GetExp() >= 100)
	{
		user.GetInven().UserMonster(mymonNumber - 1).SetExp(-100);
		user.GetInven().UserMonster(mymonNumber - 1).SetLevel(mymon.GetLevel() + 1);
	}


}


void PrintMonster(string fileName, string montype)
{
	if (rand() % 6 == 0 && fileName != "��Ű.txt")
	{
		system("cls");
		cout << "���ϸ� ����!!!!" << endl;
		ifstream fin;
		char line[200];

		fin.open(fileName);

		if (fin.is_open())
		{
			while (fin.getline(line, sizeof(line)))
			{
				cout << line << endl;
			}
		}
		fin.close();
		Sleep(1000);
		//twinkletwinkle();
		fileName.pop_back();
		fileName.pop_back();
		fileName.pop_back();
		fileName.pop_back();
		Fight(fileName, montype);

	}
	else if (fileName == "��Ű.txt")
	{
		system("cls");
		cout << "�����������ϸ��͢�������" << endl;
		cout << "---���ϸ� ġ����---" << endl;
		ifstream fin;
		char line[200];

		fin.open(fileName);

		if (fin.is_open())
		{
			while (fin.getline(line, sizeof(line)))
			{
				cout << line << endl;
			}
		}
		fin.close();
		Sleep(1000);
	}
}
void ApearMonster(int mapNum)
{
	srand((unsigned int)time(NULL));
	int singletype = rand() % 6;
	int doubletype = rand() % 12;
	string doubletypeMonster[12];
	string montype;

	if (1 <= mapNum && mapNum <= 4)
	{
		PrintMonster(HMonster["��"][singletype].GetFilename(), "��");
	}
	else if (5 <= mapNum && mapNum <= 8)
	{
		PrintMonster(HMonster["��"][singletype].GetFilename(), "��");
	}
	else if (9 <= mapNum && mapNum <= 12)
	{
		PrintMonster(HMonster["��"][singletype].GetFilename(), "��");
	}
	else if (13 <= mapNum && mapNum <= 16)
	{
		PrintMonster(HMonster["����"][singletype].GetFilename(), "����");
	}
	else if (17 <= mapNum && mapNum <= 18)
	{
		for (int i = 0; i < 6; i++) {
			doubletypeMonster[i] = HMonster["��"][i].GetFilename();
			doubletypeMonster[i + 6] = HMonster["��"][i].GetFilename();
		}
		if (0 <= doubletype && doubletype <= 5)
		{
			montype = "��";
		}
		else
		{
			montype = "��";
		}
		PrintMonster(doubletypeMonster[doubletype], montype);
	}
	else if (19 <= mapNum && mapNum <= 20)
	{
		for (int i = 0; i < 6; i++) {
			doubletypeMonster[i] = HMonster["��"][i].GetFilename();
			doubletypeMonster[i + 6] = HMonster["��"][i].GetFilename();
		}
		if (0 <= doubletype && doubletype <= 5)
		{
			montype = "��";
		}
		else
		{
			montype = "��";
		}
		PrintMonster(doubletypeMonster[doubletype], montype);
	}
	else if (21 <= mapNum && mapNum <= 22)
	{
		for (int i = 0; i < 6; i++) {
			doubletypeMonster[i] = HMonster["��"][i].GetFilename();
			doubletypeMonster[i + 6] = HMonster["����"][i].GetFilename();
		}
		if (0 <= doubletype && doubletype <= 5)
		{
			montype = "��";
		}
		else
		{
			montype = "����";
		}
		PrintMonster(doubletypeMonster[doubletype], montype);
	}
	else if (23 <= mapNum && mapNum <= 24)
	{
		for (int i = 0; i < 6; i++)
		{
			doubletypeMonster[i] = HMonster["��"][i].GetFilename();
			doubletypeMonster[i + 6] = HMonster["����"][i].GetFilename();
		}
		if (0 <= doubletype && doubletype <= 5)
		{
			montype = "��";
		}
		else
		{
			montype = "����";
		}
		PrintMonster(doubletypeMonster[doubletype], montype);
	}
	else if (mapNum == 25)
	{
		return;
	}
}
void gotoxy(int x, int y)
{
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}
void Menu()
{
	cout << "1. ���ο� ���ӽ���" << endl;
	cout << "2. �ҷ�����" << endl;
	cout << "3. ���α׷� ����" << endl;
}

void Printmap(WMap&map)
{
	system("cls");
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
			cout << map.wmap[i][j];
		cout << endl;
	}
	cout << map.wmap[20][0] << endl;
	cout << "Esc�� ������ ����&����" << endl;
}
int Move(int _x, int _y, WMap&map, int mapNum)
{
	int x = _x, x2 = _y * 2;
	int y = _y, y2 = _x;
	int run = 1;
	gotoxy(x2, y2);
	//user.UpdatePosition(x2, y2, map.MapNum());
	while (run)
	{
		switch (_getch())
		{
		case ESC:
		{
			Save();
			system("cls");
			cout << "����� ���ϸ���� ���ʸ����� ���������ϴ�." << endl;
			Sleep(2000);
			return 0;
		}
		case I:
		{
			system("cls");
			user.GetInven().InventoryInfo();
			Sleep(1000);
			Printmap(map);
		}
		case RIGHT:

			if (y < 19 && map.wmap[x][y + 1] == "��")
			{
				
				y++, x2 += 2;
				map.wmap[x][y - 1] = "��";
				map.wmap[x][y] = "��";
				Printmap(map);
				ApearMonster(map.MapNum());
				gotoxy(x2, y2);
				system("cls");
				Printmap(map);
			}
			else if (y == 19 && map.GetRight() != NULL)
			{
				system("cls");
				map.wmap[x][y] = "��";
				map.GetRight()->wmap[x][0] = "��";
				Printmap(*(map.GetRight()));
				run = Move(x, 0, *(map.GetRight()), map.MapNum());
				return 0;
			}
			break;
		case LEFT:
			if (0 < y && map.wmap[x][y - 1] == "��")
			{

				y--, x2 -= 2;

				map.wmap[x][y + 1] = "��";
				map.wmap[x][y] = "��";
				gotoxy(x2, y2);
				Printmap(map);
				ApearMonster(map.MapNum());
				system("cls");
				Printmap(map);
			}
			else if (y == 0 && map.GetLeft() != NULL)
			{
				system("cls");
				map.wmap[x][y] = "��";
				map.GetLeft()->wmap[x][19] = "��";
				Printmap(*(map.GetLeft()));
				run = Move(x, 19, *(map.GetLeft()), map.MapNum());
				return 0;
			}
			break;
		case UP:
			if ((0 < x && map.wmap[x - 1][y] == "��"))
			{
				--x, y2--;

				map.wmap[x + 1][y] = "��";
				map.wmap[x][y] = "��";
				gotoxy(x2, y2);
				Printmap(map);
				ApearMonster(map.MapNum());
				system("cls");
				Printmap(map);
			}
			else if (x == 0 && map.GetUp() != NULL)
			{
				system("cls");
				map.wmap[x][y] = "��";
				map.GetUp()->wmap[19][y] = "��";
				Printmap(*(map.GetUp()));
				run = Move(19, y, *(map.GetUp()), map.MapNum());
				return 0;
			}
			break;
		case DOWN:
			if (x < 19 && map.wmap[x + 1][y] == "��")
			{
				x++, y2++;
				map.wmap[x - 1][y] = "��";
				map.wmap[x][y] = "��";
				gotoxy(x2, y2);
				Printmap(map);
				ApearMonster(map.MapNum());
				system("cls");
				Printmap(map);
			}
			else if (x == 19 && map.GetDown() != NULL)
			{
				system("cls");
				map.wmap[x][y] = "��";
				map.GetDown()->wmap[0][y] = "��";
				Printmap(*(map.GetDown()));
				run = Move(0, y, *(map.GetDown()), map.MapNum());
				return 0;
			}
			break;
		case SPACE:
			if (map.wmap[x + 1][y] == "��" || map.wmap[x - 1][y] == "��" || map.wmap[x][y + 1] == "��" || map.wmap[x][y - 1] == "��")
			{
				int size = user.GetInven().Size();
				for (int i = 0; i < size; i++)
				{
					Monster& usermonster = user.GetInven().UserMonster(i);
					usermonster.SetHP(80 + (((usermonster).GetLevel()) - 1) * 10);
				}
				PrintMonster("��Ű.txt", "ġ��");
				Sleep(1000);
				system("cls");
				Printmap(map);
			}
			else if (map.wmap[x + 1][y] == "��" || map.wmap[x - 1][y] == "��" || map.wmap[x][y + 1] == "��" || map.wmap[x][y - 1] == "��")
			{
				if (1 <= mapNum && mapNum <= 4)
				{
					system("cls");
					cout << "??? : ������ ������ ȭ���� �Ҹ��� ������߰ڱ���" << endl;
					Sleep(1000);
					Fight("���ڸ�", "��");
					Printmap(map);
				}
				else if (5 <= mapNum && mapNum <= 8)
				{
					system("cls");
					cout << "??? : ��� �����?" << endl;
					Sleep(1000);
					Fight("�źϿ�", "��");
					Printmap(map);
				}
				else if (9 <= mapNum && mapNum <= 12)
				{
					system("cls");
					cout << "??? : �� �ɰ��� �˷����� ��������" << endl;
					Sleep(1000);
					Fight("�̻��ز�", "��");
					Printmap(map);
				}
				else if (13 <= mapNum && mapNum <= 16)
				{
					system("cls");
					cout << "??? :  Electric E-E-E-Electric E-E-E-Electric Shoc" << endl << "�� �� �������� ���� Ÿ�� �귯 �ٳ� �� �� ���� �� �� �ƽ��ƽ� ��" << endl;
					Sleep(1000);
					Fight("������", "����");
					Printmap(map);
				}
			}
			else if (map.wmap[x + 1][y] == "��" || map.wmap[x - 1][y] == "��" || map.wmap[x][y + 1] == "��" || map.wmap[x][y - 1] == "��")
			{
				if (user.GetInven().GetKey() == true)
				{
					system("cls");
					cout << "�̹� ���踦 �������ֽ��ϴ�." << endl;
				}
				else
				{
					user.GetInven().SetKey(true);
					system("cls");
					cout << "���踦 �����!! ������� ���̴� �����ϱ� ���� ���ƴٳຸ��!" << endl;
				}
				Sleep(1000);
				Printmap(map);

			}
			else if (map.wmap[x + 1][y] == "��" || map.wmap[x - 1][y] == "��" || map.wmap[x][y + 1] == "��" || map.wmap[x][y - 1] == "��")
			{
				system("cls");
				if (user.GetInven().GetKey() == true)
				{
					if (map.wmap[x + 1][y] == "��")
						map.wmap[x + 1][y] = "��";
					else if (map.wmap[x - 1][y] == "��")
						map.wmap[x - 1][y] = "��";
					else if (map.wmap[x][y + 1] == "��")
						map.wmap[x][y + 1] = "��";
					else if (map.wmap[x][y - 1] == "��")
						map.wmap[x][y - 1] = "��";
					cout << "���� ���ȴ�!!!�ȿ� ����������..." << endl;
					Sleep(1000);
					Printmap(map);
				}
				else
				{
					system("cls");
					cout << "KEY�� �����ϴ٤��� Ű�� ��������." << endl;
					Sleep(1000);
					Printmap(map);
				}
				Printmap(map);
			}
			break;
		}
	}
	return 0;
}
string GameStory(int& choose)
{
	system("cls");
	cout << "���ϸ󼼰迡 ���Ű� ȯ���մϴ�!!!" << endl;
	Sleep(1000);
	system("cls");
	cout << "�̸� �Է��ϼ���." << endl;
	string name;
	cin >> name;
	system("cls");
	cout << "���ڻ� : " << name << "��! ���ϸ� �������� ���� �ְ� ���ϴܴ�. �׷��� �� ���� ���߰ڴ�??" << endl;
	Sleep(1000);
	cout << name << " : ��! �ڻ��.. �������ֽ� ���� ���������� �� ���ϸ󸶽��Ͱ� �Ǿ߰ڽ��ϴ�!" << endl;
	Sleep(1000);
Rechoose:
	system("cls");
	cout << "���ڻ� : �׷�! �׷��� �ʸ� ���� ���ϸ��� �غ��ߴܴ�. �ʰ� ���ϴ� ���ϸ��� ����!" << endl;
	cout << "1. ������  2. ���̸�  3. �̻��ؾ�" << endl;
	cin >> choose;
	if (cin.fail())
	{
		cin.clear();
		char c;
		cin >> c;
		goto Rechoose;
	}
	system("cls");
	switch (choose)
	{
	case 1:
		cout << choose << ". ������ ����!!" << endl;
		break;
	case 2:
		cout << choose << ". ���̸� ����!!" << endl;
		break;
	case 3:
		cout << choose << ". �̻��ؾ� ����!!" << endl;
		break;
	default:
		goto Rechoose;
	}

	return name;
}
void Save()
{
	ofstream fout("User.txt");

	fout << user.GetName() << " ";
	fout << user.GetInven().Size() << " ";
	for (int i = 0; i < user.GetInven().Size(); ++i)
	{
		fout << user.GetInven().UserMonster(i).GetName() << " ";
		fout << user.GetInven().UserMonster(i).GetType() << " ";
		fout << user.GetInven().UserMonster(i).GetLevel() << " ";
		fout << user.GetInven().UserMonster(i).GetHP() << " ";
		fout << user.GetInven().UserMonster(i).GetStrong() << " ";
		fout << user.GetInven().UserMonster(i).GetSkillName(1) << " ";
		fout << user.GetInven().UserMonster(i).GetSkillName(2) << " ";
		fout << user.GetInven().UserMonster(i).GetSkillName(3) << " ";
		fout << user.GetInven().UserMonster(i).GetFilename() << " ";
		fout << user.GetInven().UserMonster(i).GetExp() << " ";
	}
	/*fout<<user.GetPosition().x<<" ";
	fout<<user.GetPosition().y<<" ";
	fout<<user.GetPosition().mapNumber<<" ";*/

	fout.close();
}
void Load()
{
	ifstream fin;
	string name;
	/*int x;
	int y;
	int mapNumber;*/
	int size;
	string monname;
	string type;
	int level;
	int HP;
	string strong;
	string skillName1;
	string skillName2;
	string skillName3;
	string filename;
	int exp;

	fin.open("User.txt");
	if (fin)
	{
		fin >> name;
		fin >> size;

		for (int i = 0; i < size; i++)
		{
			fin >> monname;
			fin >> type;
			fin >> level;
			fin >> HP;
			fin >> strong;
			fin >> skillName1;
			fin >> skillName2;
			fin >> skillName3;
			fin >> filename;
			fin >> exp;
			user.GetInven().AddMonster(Monster(monname, type, level, HP, strong, skillName1, skillName2, skillName3, filename));
			user.GetInven().UserMonster(i).SetExp(exp);
		}
		/*fin>> x;
		fin>> y;
		fin>> mapNumber;
		*/
		fin.close();
		user.SetName(name);
	}
	else
	{
		system("cls");
		cout << "����� �����Ͱ� �����ϴ�." << endl;
		Sleep(1000);
		user.SelectMonster();
	}
}