#pragma once


#include "stdafx.h"

#include <SFML/Graphics.hpp>

/*cScreen.h
	game screen's parent class, stores a GUIStyle
	there used to be a moveSprite function in here, moved to cursor.h


	*******implementation code in GUI.cpp******************

	to do: put implementation code in separate .cpp file maybe

*/

class cScreen
{
	GUIStyle style; //stores the GUI's style attributes

	

public:
	//constructors
	cScreen();
	cScreen(GUIStyle&); //can pass in a universal GUI style

	//run the window; function where implementation of game screen is done
	virtual int Run(sf::RenderWindow &App) =0;

	//get the GUI style
	GUIStyle getStyle();
};
