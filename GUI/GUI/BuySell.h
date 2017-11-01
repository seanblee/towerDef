#pragma once

#include "stdafx.h"
#include <SFML/Graphics.hpp>

using namespace std;


class buySell : public GUIEntity {
private:
	int numTowers;
	vector<sf::Sprite> towers;
	vector<sf::RectangleShape> borders;
	vector<sf::Text> towerNums;

public:
	buySell();
	buySell(int, sf::Texture&, GUIStyle&);


	sf::Sprite getTower(int);
	sf::RectangleShape getBorder(int);
	sf::Text getText(int);


};
