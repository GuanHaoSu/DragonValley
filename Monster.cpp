#include "Monster.h"
#include "Role.h"
#include <iostream> 
#include <string>
#include<windows.h>
#include <time.h>
string Monster::getMonster(){
	return MonsterType;
}
void Monster::setMonsterType(string type) {
	MonsterType = type;
}
void Monster::setHealth(int h) {
	health = h;
}
void Monster::setAtk(int a) {
	atk = a;
}

string Monster::getMonsterType() {
	return MonsterType;
}

int Monster::getHealth() {
	return health;
}

int Monster::getAtk() {
	return atk;
}

int Monster::getExperience() {
	return experience;
}

Monster::Monster()
{

}

Monster::~Monster()
{
}

Spider::Spider(int h, int a)
{
	health = h;
	atk = a;
	MonsterType = "Spider";
	experience = 20;

}

Spider::~Spider()
{
}

Bat::Bat(int h, int a)
{
	health = h;
	atk = a;
	MonsterType = "Bat";
	experience = 20;

}

Bat::~Bat()
{
}

Giant::Giant(int h, int a)
{
	health = h;
	atk = a;
	MonsterType = "Giant";
	experience = 40;

}

Giant::~Giant()
{
}

Dragon::Dragon(int h, int a)
{
	health = h; 
	atk = a;
	MonsterType = "Dragon";
	experience = 40;

}

Dragon::~Dragon()
{
}


MonsterFactory::MonsterFactory(int randNumber)
{
	srand(time(NULL));
	switch (randNumber) {
		case 1:
			CreateSpider();
			break;
		case 2:
			CreateBat();
			break;
		case 3:
			CreateGiant();
			break;
		case 7:
			CreateDragon();
			break;
	}
	
}

MonsterFactory::~MonsterFactory()
{
}

void MonsterFactory::CreateSpider()
{
	Spider *spider = new Spider(100, 2);
	health = spider->getHealth();
	atk = spider->getAtk();
	experience = spider->getExperience();
	MonsterType = spider->getMonsterType();
}

void MonsterFactory::CreateBat()
{
	Bat *bat = new Bat(90, 1);
	health = bat->getHealth();
	atk = bat->getAtk();
	experience = bat->getExperience();
	MonsterType = bat->getMonsterType();
}
void MonsterFactory::CreateGiant()
{
	Giant *giant = new Giant(120, 5);
	health = giant->getHealth();
	atk = giant->getAtk();
	experience = giant->getExperience();
	MonsterType = giant->getMonsterType();
}
void MonsterFactory::CreateDragon()
{
	Dragon *dragon = new Dragon(352, 50);
	health = dragon->getHealth();
	atk = dragon->getAtk();
	experience = dragon->getExperience();
	MonsterType = dragon->getMonsterType();
}
void MonsterFactory::CreateItems(Role *role)
{
	int randNumber = rand() % 5 + 1;
	switch (randNumber) {
	case 1:
		role->addItem("healherb", 1);
		cout << "you get a healherb"<<endl ;
		break;
	case 2:
		role->addItem("powerherb", 1);
		cout << "you get a powerherb" << endl;
		break;
	case 3:
		role->addItem("experienceherb", 1);
		cout << "you get a experienceherb" << endl;
		break;

	}
}
string MonsterFactory::getMonsterType() {
	return MonsterType;
}

int MonsterFactory::getHealth() {
	return health;
}

int MonsterFactory::getAtk() {
	return atk;
}

int MonsterFactory::getExperience() {
	return experience;
}

