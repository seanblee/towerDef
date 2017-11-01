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

    int borderSize;

	GUIStyle();

	GUIStyle(sf::Font font, int borderSize,
		sf::Color bodyCol, sf::Color borderCol, sf::Color textCol);
	
};

class GUIEntity {
private: 
	position location; //location on screen in pixels
	sf::Text message; //what pops up when loading it (theoretically)(like "loading: *message*")
	//size of entity - width and height in pixels
	int w; 
	int h;

public:

	GUIEntity();
	GUIEntity(int&, int&);
	GUIEntity(position&, int&, int&);

	void initEntity(position&, int, int,  string&);
	
	

	void moveSprite(sf::Sprite&);
	
};


