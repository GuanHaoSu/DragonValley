#pragma once
#include <string>
#include <map>
#include <vector>
#include "Monster.h"
using namespace std;

class Role
{

	string name;
	int PositionX=0;
	int PositionY=0;
	int RowLength=5;
	int ColumnLength=5;

	int DragonPosistionX;
	int DragonPosistionY;

	int Heath=100;
	int Level= 1;
	int Experince = 0;
	int Atk = 10;
	//string Map[4][5] = { {"You","_","_","_","_"},{ "_","_","_","_","_" },{ "_","_","_","_","_" },{ "_","_","_","_","Dragon" } };
	string **Map;
	map<string, int> ItemBox;
public:
	Role(string PlayerName);
	~Role();
	string getName();
	int getPositionX();
	int getPositionY();
	int getMapRow();
	int getMapColumn();
	void CreateMap();
	void CreateDragonPosition();
	int getDragonPosistionX();
	int getDragonPosistionY();
	void getMap();
	void goNorth();
	void goSouth();
	void goEast();
	void goWest();

	void getRoleInfo();
	void setHealth(int h);
	void setAtk(int a);
	void setExperince(int e);
	void setLevel(int l);
	int getHealth();
	int getAtk();
	int getExperince();
	int getLevel();
	void LevelCalculator(int ExperienceGet);

	void addItem(string key,int value);
	void getItemBox();
	void useItem(int i);
};