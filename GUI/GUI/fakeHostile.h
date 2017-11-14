#pragma once
#include "stdafx.h"
#include <string>

//temporary class until get real hostile class, then replace
using namespace std;
class Hostile{
public:
	std::string name;
	int speed;
	int HP;
	bool allHostileDead() {
		return numHostLeft <= 0;
	}
	Hostile() {

	}
	Hostile(int type) {
		speed = 1;
		HP = 1;
		name = "Hostile Type "+std::to_string(type);
	}
	int numHostLeft = 2;

	int type;
	int X;
	int Y;

	//these to are needed, for WaveRunningPage, want in real hostile class if possible
	sf::Sprite sprite;
	int idNum;







};