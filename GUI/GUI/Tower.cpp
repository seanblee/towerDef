#pragma once
#include "Tower.h"
#include <SFML/Graphics.hpp>
#include "stdafx.h"
#include <fstream>
#include "BuySell.h"

Tower::Tower(int type, buySell overlay) {
	towerType = type;
	switch (type) {
	case 1: towerImage = overlay.getTower(1);
		case 2: towerImage = overlay.getTower(2);
		case 3: towerImage = overlay.getTower(3);
	}
	fstream towerStat;
	towerStat.open("statSheet.txt");
}