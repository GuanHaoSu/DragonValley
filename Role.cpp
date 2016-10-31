#include "Role.h"
#include <iostream> 
#include <string>
#include<windows.h>
#include <time.h>
Role::Role(string PlayerName)
{
	srand(time(NULL));
	name = PlayerName;
}
string Role::getName() {
	return name;
}

void Role::CreateMap() {
	CreateDragonPosition();
	Map = new string*[RowLength];
	for (int i = 0; i < RowLength; i++)
	{
		Map[i] = new string[ColumnLength];
		for (int j = 0; j < ColumnLength;j++) {
			if(i==0&&j==0)
			{ 
				Map[i][j]="You";
			}
			else if (i+1==RowLength&&j+1== ColumnLength) {
				Map[i][j] = "^";
			}
			else {
				Map[i][j] = "^";
			}
		}
	}
}
void Role::CreateDragonPosition()
{
	int r=RowLength - 1;
	int c=ColumnLength -1;
	DragonPosistionY = rand() % r + 1;
	DragonPosistionX = rand() % c + 1;

}
int Role::getDragonPosistionX()
{
	return DragonPosistionX;
}
int Role::getDragonPosistionY()
{
	return DragonPosistionY;
}
void Role::getMap() {
	int RowLength = getMapRow();
	int ColumnLength = getMapColumn();
	for (int i = 0; i < RowLength; i++)
	{
		for (int j = 0; j < ColumnLength; j++)
		{
		
			cout<<Map[i][j]<<" ";
			if (j == ColumnLength - 1)
			{
				cout << endl;
				cout << endl;
			}
		}
	}
}
int Role::getPositionX() {
	return PositionX;
}

int Role::getPositionY() {
	return PositionY;
}
int Role::getMapRow() {
	//int RowLength = sizeof(Map) / sizeof(*Map);
	return RowLength;
}

int Role::getMapColumn() {
	//int ColumnLength = sizeof(*Map) / sizeof(*Map[0]);
	return ColumnLength;
}

void Role::goEast() {
	int MapX = getMapColumn();
	if (PositionX + 1 > MapX-1)
	{

		cout << "You are out of valley, choose other directions" << endl;
	}
	else {
		Map[PositionY][PositionX] = "^";
		PositionX = PositionX + 1;
		Map[PositionY][PositionX] = "You";
	}
}

void Role::goSouth() {
	int MapY = getMapRow();
	if (PositionY + 1 > MapY-1)
	{
		cout << "You are out of valley, choose other directions" << endl;
	}
	else {
		Map[PositionY][PositionX] = "^";
		PositionY = PositionY + 1;
		Map[PositionY][PositionX] = "You";
	}
}

void Role::goNorth() {
	int MapY = getMapRow();
	if (PositionY - 1 < 0)
	{
		cout << "You are out of valley, choose other directions" << endl;
	}
	else {
		Map[PositionY][PositionX] = "^";
		PositionY = PositionY - 1;
		Map[PositionY][PositionX] = "You";
	}
}

void Role::goWest() {
	int MapX = getMapColumn();
	if (PositionX - 1 < 0)
	{
		cout << "You are out of valley, choose other directions" << endl;
	}
	else {
		Map[PositionY][PositionX] = "^";
		PositionX = PositionX - 1;
		Map[PositionY][PositionX] = "You";
	}
}

void Role::getRoleInfo()
{
	cout << "level: " << getLevel()<< endl;
	cout << "hp: " << getHealth() << endl;
	cout << "exp: " <<getExperince() << endl;
	cout << "atk: " << getAtk() << endl;
}

void Role::setHealth(int h) {
	Heath = h;
}
void Role::setExperince(int e) {
	Experince = e;
}
void Role::setAtk(int a) {
	Atk = a;
}
void Role::setLevel(int l) {
	Level = l;
}

int Role::getHealth() {
	return	Heath;
}
int Role::getExperince() {
	return Experince;
}
int Role::getAtk() {
	return	Atk;
}
int Role::getLevel() {
	return	Level;
}

void Role::LevelCalculator(int ExperienceGet) {
	Experince = Experince + ExperienceGet;
	if (Experince>=(50*Level)) {
		Level = Level+1;
		Atk = Atk+(Level* 5);
		cout << "Your level up! Level: "<< Level << " Atk increase to "<< Atk << endl;
	}
}

void Role::addItem(string key,int value)
{
	
	map<string, int>::iterator itr = ItemBox.find(key);
	if (itr != ItemBox.end())
	{
		int value = itr->second;
		itr->second = value + 1;
	}
	else {
		ItemBox.insert(pair<string, int>(key, value));
	}

}

void Role::getItemBox()
{
	map<string, int>::iterator itr;
	int i = 0;
	int no;
	if (!ItemBox.empty())
	{
		for (itr = ItemBox.begin(); itr != ItemBox.end(); ++itr)
		{
			i++;
			cout << "(" << i << ") " << itr->first << ": " << itr->second << endl;
		}
		cout << "Please enter the Item number to use" << endl;
		cin >> no;
		useItem(no);
	}
	else {
		cout << "You don't have any item" << endl;
	}

}

void Role::useItem(int no)
{
	//map<string, int>::iterator itr;
	int i = 0;
	string item;
	if(ItemBox.size()>1)
	{ 
		for (auto itr = ItemBox.begin(); itr != ItemBox.end(); ++itr)
		{
			i++;
			if (no==i) {
				item = itr->first;
				int value = itr->second;
				value = value - 1;
				itr->second = value;
				if (value == 0) {
					ItemBox.erase(itr++);
				}
			}

		
		}
	}
	else if (ItemBox.size()==1) {
		if (no==1) {
			auto itr = ItemBox.begin();
			item = itr->first;
			ItemBox =  map<string, int>();
		}
	}
	if (item=="healherb") {
		Heath = Heath + 20;
		cout <<"you use the healherb, health point plus 20" << endl;
	}
	else if (item == "powerherb") {
		Atk = Atk + 2;
		cout << "you use the powerherb, atk point plus 2" << endl;
	}
	else if (item == "experienceherb") {
		LevelCalculator(30);
		cout << "you use the experienceherb, experince plus 30" << endl;
	}
	else {
		cout << "you don't have this item." << endl;
	}
	
}

Role::~Role() {
	delete[] Map;
}