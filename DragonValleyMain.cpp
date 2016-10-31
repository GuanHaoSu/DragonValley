#include <iostream> 
using namespace std;
#include "Role.h"
#include "Monster.h"
#include "Battle.h"
int main() {
	Battle *battle = new Battle();

	
	string playerName;
	cout << "Wellcome to Dragon Valley" << endl;
	cout <<"Please name your knight:" <<endl ;
	cin >> playerName;
	Role *role = new Role(playerName);

	string name = role->getName();
	int MonsterNumber;


	role->CreateMap();
    cout << "Hello " << name <<"! I am elf, I will help you when you adventure in Dragon Valley"<<endl;
	cout << "Dragon is habit in ("<< role->getDragonPosistionX() <<"(Column),"<< role->getDragonPosistionY() <<"(Row)), you have to defeat the dargon to win your thesaurus." << endl;
	cout << "You can move your position by using command as follow, Move to east: Enter 'E' Move to west: Enter 'W' Move to north: Enter 'N' Move to south: Enter 'S'" << endl;
	cout << "You can use command 'M' open the Map to check your position" << endl;
	string Command;
	
	do {
		cin >> Command;
		if (Command=="E") {
			role->goEast();
			if (role->getPositionX() == role->getDragonPosistionX() &&role->getPositionY() == role->getDragonPosistionY())
			{
				cout << "You encounter a dragon, do you want to fight?" << endl;
				cin >> Command;
				if (Command == "Y") {
					int BattleResult = battle->startBattle(role, 7);
					cout << "HP remain: " << role->getHealth() << endl;
					cout << "Experince: " << role->getExperince() << endl;
					if (BattleResult == 0) {
						cout << "Game Over" << endl;
						Command = "exit";
					}
					else if(BattleResult == 1)
					{
						cout << "Congratulation! You win your thesaurus!!! " << endl;
						Command = "exit";
					}
				}
				else if (Command == "N") {
					role->CreateDragonPosition();
					cout << "Dragon is move to (" << role->getDragonPosistionX() << "," << role->getDragonPosistionY() << ")" << endl;
				}
			}
			else
			{		
					MonsterNumber = battle->CreateMonster();
			
					if(MonsterNumber <=3)
					{ 
						cout << "You encounter a monster, do you want to fight?" <<endl;
						cin >> Command;
						if (Command =="Y") {
							int BattleResult=	battle->startBattle(role, MonsterNumber);
							cout << "HP remain: " << role->getHealth() << endl;
							cout << "Experince: " << role->getExperince() << endl;
							if (BattleResult == 0) {
								cout << "Game Over" << endl;
								Command = "exit";
							}
						}
						else if (Command == "N") {
							cout << "Move to next direction." << endl;
						}
					}
					else 
					{
						cout << "Nothing happen in here." << endl;
					}
			}
		}
		else if (Command == "S")
		{
			role->goSouth();
			if (role->getPositionX() == role->getDragonPosistionX() && role->getPositionY() == role->getDragonPosistionY())
			{
				cout << "You encounter a dragon, do you want to fight?" << endl;
				cin >> Command;
				if (Command == "Y") {
					int BattleResult = battle->startBattle(role, 7);
					cout << "HP remain: " << role->getHealth() << endl;
					cout << "Experince: " << role->getExperince() << endl;
					if (BattleResult == 0) {
						cout << "Game Over" << endl;
						Command = "exit";
					}
					else if (BattleResult == 1)
					{
						cout << "Congratulation! You win your thesaurus!!! " << endl;
						Command = "exit";
					}
				}
				else if (Command == "N") {
					role->CreateDragonPosition();
					cout << "Dragon is move to (" << role->getDragonPosistionX() << "," << role->getDragonPosistionY() << ")" << endl;
				}
			}
			else
			{
				MonsterNumber = battle->CreateMonster();
				if (MonsterNumber <= 3)
				{
					cout << "You encounter a monster, do you want to fight?" << endl;
					cin >> Command;
					if (Command == "Y") {
						int BattleResult = battle->startBattle(role, MonsterNumber);
						cout << "HP remain: " << role->getHealth() << endl;
						cout << "Experince: " << role->getExperince() << endl;
						if (BattleResult == 0) {
							cout << "Game Over" << endl;
							Command = "exit";
						}
					}
					else if (Command == "N") {
						cout << "Move to next direction." << endl;
					}
				}
				else
				{
					cout << "Nothing happen in here." << endl;
				}
			}
		}
		else if (Command == "N")
		{
			role->goNorth();
			if (role->getPositionX() == role->getDragonPosistionX() && role->getPositionY() == role->getDragonPosistionY())
			{
				cout << "You encounter a dragon, do you want to fight?" << endl;
				cin >> Command;
				if (Command == "Y") {
					int BattleResult = battle->startBattle(role, 7);
					cout << "HP remain: " << role->getHealth() << endl;
					cout << "Experince: " << role->getExperince() << endl;
					if (BattleResult == 0) {
						cout << "Game Over" << endl;
						Command = "exit";
					}
					else if (BattleResult == 1)
					{
						cout << "Congratulation! You win your thesaurus!!! " << endl;
						Command = "exit";
					}
				}
				else if (Command == "N") {
					role->CreateDragonPosition();
					cout << "Dragon is move to (" << role->getDragonPosistionX() << "," << role->getDragonPosistionY() << ")" << endl;
				}
			}
			else
			{
				MonsterNumber = battle->CreateMonster();
				if (MonsterNumber <= 3)
				{
					cout << "You encounter a monster, do you want to fight?" << endl;
					cin >> Command;
					if (Command == "Y") {
						int BattleResult = battle->startBattle(role, MonsterNumber);
						cout << "HP remain: " << role->getHealth() << endl;
						cout << "Experince: " << role->getExperince() << endl;
						if (BattleResult == 0) {
							cout << "Game Over" << endl;
							Command = "exit";
						}
					}
					else if (Command == "N") {
						cout << "Move to next direction." << endl;
					}
				}
				else
				{
					cout << "Nothing happen in here." << endl;
				}
			}
		}
		else if (Command == "W")
		{
			role->goWest();
			if (role->getPositionX() == role->getDragonPosistionX() && role->getPositionY() == role->getDragonPosistionY())
			{
				cout << "You encounter a dragon, do you want to fight?" << endl;
				cin >> Command;
				if (Command == "Y") {
					int BattleResult = battle->startBattle(role, 7);
					cout << "HP remain: " << role->getHealth() << endl;
					cout << "Experince: " << role->getExperince() << endl;
					if (BattleResult == 0) {
						cout << "Game Over" << endl;
						Command = "exit";
					}
					else if (BattleResult == 1)
					{
						cout << "Congratulation! You win your thesaurus!!! " << endl;
						Command = "exit";
					}
				}
				else if (Command == "N") {
					role->CreateDragonPosition();
					cout << "Dragon is move to (" << role->getDragonPosistionX() << "," << role->getDragonPosistionY() << ")" << endl;
				}
			}
			else
			{
				MonsterNumber = battle->CreateMonster();
				if (MonsterNumber <= 3)
				{
					cout << "You encounter a monster, do you want to fight?" << endl;
					cin >> Command;
					if (Command == "Y") {
						int BattleResult = battle->startBattle(role, MonsterNumber);
						cout << "HP remain: " << role->getHealth() << endl;
						cout << "Experince: " << role->getExperince() << endl;
						if (BattleResult == 0) {
							cout << "Game Over" << endl;
							Command = "exit";
						}
					}
					else if (Command == "N") {
						cout << "Move to next direction." << endl;
					}
				}
				else
				{
					cout << "Nothing happen in here." << endl;
				}
			}
		}
		else if (Command == "M")
		{
			role->getMap();
		}
		else if (Command == "T")
		{
			role->getItemBox();
		}
		else if (Command == "I")
		{
			role->getRoleInfo();
		}
	} while (Command != "exit");

	system("PAUSE");
	return 0;

}