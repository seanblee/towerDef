#pragma once

#include "stdafx.h"

#include <SFML/Graphics.hpp>

using namespace std;


class pathOverlays {
	
	sf::Text playerHP;
	sf::Text playerMoney;
	sf::Text statusMessage;

public:
	pathOverlays();
	pathOverlays(string&, string&, string&);

	sf::RectangleShape backing;
	
	void setStyle(GUIStyle&);

	void updateHP(string&);
	void updateMoney(string&);
	void updateMessage(string&);

	sf::Text getHP();
	sf::Text getMoney();
	sf::Text getMessage();
	
};
