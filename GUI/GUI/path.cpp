
#include "stdafx.h"

#include <SFML/Graphics.hpp>

using namespace std;


path::path(string& filename, int width, int height) {
	map.loadFromFile(filename);
	pathImage.setTexture(map);
	
	tileWidth = width;
	tileHeight = height;
}
