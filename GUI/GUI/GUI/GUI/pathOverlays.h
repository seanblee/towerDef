#pragma once

#include "stdafx.h"

#include <SFML/Graphics.hpp>

using namespace std;

/*pathOverlays.h
	class that stores the info box in the upper right corner of the game screen;
	used in BuySellPage.h and WaveRunning.h

	to do: allow it to change size maybe? 
	so it isn't blocking the way if player wants to put something in upper right corner

*/


class pathOverlays {
	
	//all the text attributes that get drawn

	sf::Text playerHP;
	sf::Text playerMoney;

	//these 2 used to be the same, but then I wanted to make the options a smaller font
	sf::Text statusMessage; //like "Select a tower"
	sf::Text optionsMessage; //like "[enter] Select"

public:
	//constructors
	pathOverlays();
	pathOverlays(string&, string&, string&);

	//the border for the window
	sf::RectangleShape backing;

	//set the style to match the universal GUI style
	void setStyle(GUIStyle&);

	//set functions for HP, money, and messages
	void setHP(int);
	void setMoney(int);
	void setMessage(string&);
	void setOptions(string&);

	//accessors for drawing them in the window
	sf::Text getHP();
	sf::Text getMoney();
	sf::Text getMessage();
	sf::Text getOptions();
	
};
