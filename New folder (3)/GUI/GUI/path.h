#pragma once

#include "stdafx.h"
#include "GUI.h"

#include <SFML/Graphics.hpp>

using namespace std;

/*path.h
	class for storing the background image of the path
	also has the tile width and tile height of path, but this'll eventually be in wave

*/

class path {
	
	sf::Texture map; //actual image
	int tileWidth; //how many tiles there are in path horizontally
	int tileHeight; //how many tiles there are in path vertically
	
public:
	//constructor; gets texture from specified file name, stores tileWidth and tileHeight
	path(string&, int w, int h);

	//drawable sprite of the path
	sf::Sprite pathImage;

	//accessors to get tileWidth and tileHeight; should be in wave instead
	int getWidth();
	int getHeight();

};