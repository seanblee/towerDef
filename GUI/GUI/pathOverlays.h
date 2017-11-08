#pragma once

#include "stdafx.h"

#include <SFML/Graphics.hpp>

using namespace std;


class pathOverlays {
	
	sf::Text playerHP;
	sf::Text playerMoney;
	sf::Text statusMessage;
	sf::Text optionsMessage;

public:
	pathOverlays();
	pathOverlays(string&, string&, string&);

	sf::RectangleShape backing;

	void setStyle(GUIStyle&);

	void setHP(int);
	void setMoney(int);
	void setMessage(string&);
	void setOptions(string&);

	sf::Text getHP();
	sf::Text getMoney();
	sf::Text getMessage();
	sf::Text getOptions();
	
};
