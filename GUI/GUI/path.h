#pragma once

#include "stdafx.h"
#include "GUI.h"

#include <SFML/Graphics.hpp>

using namespace std;


class path {
	sf::Texture map;
	int tileWidth; //how many tiles there are in path horizontally
	int tileHeight; //how many tiles there are in path vertically
	
public:
	path(string&, int, int);

	sf::Sprite pathImage;
	int getWidth();
	int getHeight();

};