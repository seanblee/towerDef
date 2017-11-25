// WindowsProject2.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "WindowsProject2.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "screens.h"
#include "Player.h"

/*main.cpp
	initializes the universal GUI style, including loading the font from file
	initializes all the game screens as well as the window
	loads the sprite sheet from file


*/

int main(int argc, char** argv)
{
	//make player object
	string playerName = "George";

	int playerHP = 1;
	int playerCurrency = 200;
	Player *user= new Player (playerName,playerHP,playerCurrency);
	user->startHP = user->getHP();
	// make tower manager
	TowerManager *towerMan = new TowerManager();

	//declaring all of the GUIStyle elements
	sf::Font font;
	sf::Color bodycol(0, 0, 0);
	sf::Color bordercol(255, 255, 255);
	sf::Color textcol(255, 255, 255);

	if (!font.loadFromFile("8bit16.ttf")) {/*put in exception later*/ }

	//initialize GUIStyle
	GUIStyle style(font, 2.0, bodycol, bordercol, textcol);

	//load sprite sheet from file
	sf::Texture spriteSheet;
	if (!spriteSheet.loadFromFile("SpriteSheet.png")) {/*put in exception later*/ }


	//Applications variables
	std::vector<cScreen*> Screens;
	int screen = 0;

	//Window creation
	sf::RenderWindow window(sf::VideoMode(1000, 700), "Game Prototype");

	//Screens preparations
	
	WaveDescription *s1 = new WaveDescription(style);//wave description page
	BuySellPage s2(style, spriteSheet, towerMan, user); //where user buys, sells, and places towers
	WaveRunningPage s3(style, spriteSheet, user, towerMan); //wave runs
	WaveComplete *s4 = new WaveComplete(style, user);//wave complete page
	LevelComplete s5(style); //level complete
	WinnerPage s6(style, user); //winner page
	GameOverPage s7(style,user); //game over page
	MainMenu s0(style, towerMan, s1, s4, user); //main menu page

	//load all pages into vector
	Screens.push_back(&s0);
	Screens.push_back(&*(s1));
	Screens.push_back(&s2);
	Screens.push_back(&s3);
	Screens.push_back(&*(s4));
	Screens.push_back(&s5);
	Screens.push_back(&s6);
	Screens.push_back(&s7);



	//Main loop
	while (screen >= 0)
	{
		screen = Screens[screen]->Run(window);
	}

	return EXIT_SUCCESS;
}


