#pragma once
#include <string>
class Role;
#include "Role.h"
using namespace std;
class Monster
{	

public:
	Monster();
	string MonsterType;
	int health;
	int atk;
	int experience;
	~Monster();
	string getMonster();
	void setMonsterType(string type);
	void setHealth(int h);
	void setAtk(int a);
	string getMonsterType();
	int getHealth();
	int getAtk();
	int getExperience();
private:
	
};

class MonsterFactory
{
	int health;
	int atk;
	int experience;
public:
	MonsterFactory(int randNumber);
	string MonsterType;
	void CreateItems(Role *role);
	void CreateSpider();
	void CreateBat();
	void CreateGiant();
	void CreateDragon();
	string getMonsterType();
	int getHealth();
	int getAtk();
	int getExperience();
	~MonsterFactory();
private:
};

class Spider :public Monster
{

public:
	Spider(int health, int atk);
	~Spider();
private:

};

class Bat :public Monster
{

public:
	Bat(int health, int atk);
	~Bat();
private:

};

class Giant :public Monster
{

public:
	Giant(int health, int atk);
	~Giant();
private:

};

class Dragon :public Monster
{

public:
	Dragon(int health, int atk);
	~Dragon();
private:

};


