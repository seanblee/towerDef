#pragma once

#include "stdafx.h"

#include <SFML/Graphics.hpp>


using namespace std;

class position {
	int x;
	int y;
public:
	position();
	position(int,int);
	void setLocation(int, int);	//sets location 
	int getX();
	int getY();
};

class GUIStyle {
public:
	sf::Color bodyCol;
	sf::Color borderCol;
	sf::Color textCol;
	sf::Font font;

	float borderSize;

	GUIStyle();

	GUIStyle(sf::Font font, float borderSize,
		sf::Color bodyCol, sf::Color borderCol, sf::Color textCol);

	void setStyle(sf::Text&, int);
	void setStyle(sf::RectangleShape&);

};






