#pragma once
#include "stdafx.h"
#include <string>

//temporary class until get real hostile class, then replace
using namespace std;
class Hostile{
public:
	int type;
	int X;
	int Y;

	//these to are needed, for WaveRunningPage, want in real hostile class if possible
	sf::Sprite sprite;
	int idNum;




};