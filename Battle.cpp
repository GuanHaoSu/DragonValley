#include "Battle.h"
#include "Monster.h"
#include "Role.h"
#include <iostream> 
#include<windows.h>
#include <time.h>
Battle::Battle()
{
	srand(time(NULL));
}

int Battle::startBattle(Role *role, int randNumber) {
	int battleResult;

	MonsterFactory *monster = new MonsterFactory(randNumber);
	bool ifMonsterCreate = true;

	if (ifMonsterCreate) {
		
		int roleATK = role->getAtk();
		int roleHealth = role->getHealth();
		int MonsterATK = monster->getAtk();
		int MonsterHealth = monster->getHealth();
		string MonsterType = monster->getMonsterType();

		while (roleHealth>0&&MonsterHealth>0)
		{

			if (roleHealth > 0 && MonsterHealth != 0) {
				MonsterHealth = MonsterHealth - roleATK;
				cout << "You are attacking " << MonsterType << ", " << MonsterType << "'s health is:" << MonsterHealth << endl;
			
				if (MonsterHealth <= 0) {
					cout << "You defeat the " << MonsterType << endl;
				}
				Sleep(100);
			}

			if (MonsterHealth > 0&& roleHealth!=0)
			{
				roleHealth = roleHealth - MonsterATK;
				cout << MonsterType << " are attacking you. Your health is" << roleHealth << endl;
		
				if (roleHealth <= 0)
				{
					cout << MonsterType << " defeat you, you lose your life " << endl;
				}
				Sleep(100);

			}


		}

		if(roleHealth>0)
		{ 
			role->setHealth(roleHealth);
			role->LevelCalculator(monster->getExperience());
			monster->CreateItems(role);
			battleResult = 1;
		}
		else if (roleHealth<=0)
		{
			role->setHealth(roleHealth);
			battleResult = 0;
			cout <<"Game Over!!!"<< endl;
		}
	
	}
	else {
		cout << "No monster here." << endl;
	}
	return battleResult;
}

int Battle::CreateMonster() {
	
	int randNumber = rand() % 5 + 1;	
	return randNumber;
}

Battle::~Battle()
{

}
