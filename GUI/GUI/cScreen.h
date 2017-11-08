#pragma once


#include "stdafx.h"

#include <SFML/Graphics.hpp>



class cScreen
{
	GUIStyle style; 

public:

	cScreen();
	cScreen(GUIStyle&);
	virtual int Run(sf::RenderWindow &App) =0;
	GUIStyle getStyle();
	

};