#pragma once
#include "Tower.h"
#include <SFML/Graphics.hpp>
#include "stdafx.h"
#include <fstream>
#include "Cursor.h"

using namespace std;

Tower::Tower(int type, cursor cur) {
	towerImage = cur.getImage();
}