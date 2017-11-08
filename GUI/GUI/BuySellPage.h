#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "cScreen.h"
#include "stdafx.h"
#include "WindowsProject2.h"
#include <SFML/Graphics.hpp>

using namespace std;

class BuySellPage : public cScreen
{
	sf::Texture spriteSheet;
	int tower; //tower number; 0 is nothing, a blank cursor
	int state; //0 = selection, 1 = buy,  2 = sell

public:
	BuySellPage(GUIStyle& style, sf::Texture sheet) : cScreen(style), spriteSheet(sheet) { }
	virtual int Run(sf::RenderWindow &window);

	int getTowerNum();
	int getState();
	void setTowerNum(int);
	void setState(int);
};


