
#include "stdafx.h"

#include <SFML/Graphics.hpp>

using namespace std;


path::path(string& filename, int width, int height) {
	map.loadFromFile(filename);
	position loc;
	pathImage.setTexture(map);
	
	tileWidth = width;
	tileHeight = height;

	string msg("Map Image");

	initEntity(loc, 1000, 700, msg);

}
