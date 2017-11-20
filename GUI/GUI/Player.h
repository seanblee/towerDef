#pragma once

#include "stdafx.h"
#include <string>

using namespace std;
class Player {
private:
	int HP;
	int money;
	string name;
public:
    int startHP =1;
	int HPstartLastWave = 0;
	int moneyStartLastWave = 0;
	Player(string, int, int);
	Player() {
		name = "null";
		money = 0;
		HP = 10000;
	}
	int getHP() const;
	int getMoney() const;
	string getName();
	void setHP(int);
	void setName(string name);
	void setMoney(int);
};
