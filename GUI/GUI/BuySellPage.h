#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "cScreen.h"
#include "stdafx.h"
#include "WindowsProject2.h"
#include <SFML/Graphics.hpp>

using namespace std;
#include "TowerManager.h"
#include "Player.h"

/*BuySellPage.h: 
	header class for the GUI screen where player can buy, sell, and place towers
	
	to do: sell features
*/

class BuySellPage : public cScreen
{
	sf::Texture spriteSheet; //spriteSheet.png
	int tower; //tower number; 0 is nothing, a blank cursor
	int state; //0 = selection, 1 = buy,  2 = sell
	TowerManager *BuySellManager;
	Player *user;

public:
	BuySellPage(GUIStyle& style, sf::Texture sheet, TowerManager*& tempMan, Player*& p) : cScreen(style), spriteSheet(sheet) { 
		BuySellManager = tempMan; 
		user = p;
	}
	virtual int Run(sf::RenderWindow &window);

	int getTowerNum(); //get the currently selected tower number
	int getState(); //get the state
	void setTowerNum(int); //set the tower number
	void setState(int); //set current state
};


