#pragma once
#include <string>
#include "Monster.h"
#include "Role.h"
using namespace std;
class Battle
{
public:
	Battle();
	int startBattle(Role *role, int randNumber);
	int CreateMonster();
	~Battle();

private:

};
