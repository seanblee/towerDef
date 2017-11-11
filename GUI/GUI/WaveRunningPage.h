#pragma once
#pragma once
#include <iostream>
#include <string>
#include "cScreen.h"
#include "stdafx.h"
#include "fakeHostile.h"//tempHostileClass //#include "Hostile.h"
#include "BuySellPage.h"
#include "WindowsProject2.h"
#include <SFML/Graphics.hpp>
#include <typeinfo>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

/* WaveRunningPage.h
	implementation of game screen where the wave runs
		-hostiles generated, towers shoot projectiles and hostiles

	to do: projectile animations, hostile animation, logic for going to either WaveComplete, LevelComplete, WinnerPage or GameOverScreen
	(or would the logic come from GameLogic???-this is how code works for now), pass in towers from towerManager, 
	make spawnHostile(Hostile h),moveHostile,checkHostileEndOfPath, removeHostile, checkHostileMove work with real hostile class

	
*/


class WaveRunningPage : public cScreen
{
	sf::Texture spriteSheet;
	bool switchPage = false;// true if time to go to next page
	int nextPageInt=0;// holds integer that will be returned to go next selected page
	int getIntForPage(cScreen& screen);//given screen object gets return int value for its class
	vector<int> beginningTiles;
	vector<Hostile> hostilesOnScreen;//holds all hostiles currently on screen
	int intMap[20][16];// to hold map, need in multiple functions
public:
	WaveRunningPage(GUIStyle& style, sf::Texture Sheet) : cScreen(style) { spriteSheet = Sheet; }
	void goToNextPage(cScreen& screen);// sets switchPage to true, nextPageInt to correct integer, will now 
									//switch to correct page
	virtual int Run(sf::RenderWindow &window);
	
	void spawnHostile(Hostile h);
	int moveHostile(Hostile h,int x, int y);//returns -1 if move illegal and doesn't move, 0 if not
	bool checkHostileEndOfPath(Hostile h);
	void removeHostile(Hostile h);
	bool checkHostileMove(Hostile h, int x, int y);
	
};



int WaveRunningPage::Run(sf::RenderWindow &window)
{
	Hostile h;
	h.type = 3;


	//initialize GUI style
	GUIStyle style(getStyle());

	//set path background and overlays
	string easyPathMap("path1.jpg");
	path easyPath(easyPathMap, 10, 7);
	pathOverlays overlays;
	overlays.setStyle(style);
	buySell buySellOverlay(3, spriteSheet, style);

	//becomes true when time to go to nextPage
	switchPage = false;
	hostilesOnScreen.clear();
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			//if they click the x in top corner close window
			if (event.type == sf::Event::Closed) {
				window.close();
				return -1;
			}
			//time to switch the page
			if (switchPage) {
				return nextPageInt;
			}


			//TEMPORARY
			if (event.type == sf::Event::KeyPressed)
			{

				//temporary for testing, next goToNextPage call will come from gameLogic(I think)
				if (event.key.code == sf::Keyboard::Return)
				{
					WaveComplete w(style);
					goToNextPage(w);
				}

				//this is temporary, outside code will call spawnHostile, moveHostile, and removeHostile
				if (event.key.code == sf::Keyboard::A)
				{
					spawnHostile(h);
				}
				if (event.key.code == sf::Keyboard::B)
				{
					
					if (hostilesOnScreen.size() != 0) {
						int good = moveHostile(hostilesOnScreen[0], hostilesOnScreen[0].sprite.getPosition().x + 5,
							hostilesOnScreen[0].sprite.getPosition().y);
						if (good != 0) {
							good = moveHostile(hostilesOnScreen[0], hostilesOnScreen[0].sprite.getPosition().x,
								hostilesOnScreen[0].sprite.getPosition().y - 5);
							if (good != 0) {
								good = 0;
								while (good == 0) {
									good = moveHostile(hostilesOnScreen[0], hostilesOnScreen[0].sprite.getPosition().x,
										hostilesOnScreen[0].sprite.getPosition().y + 5);

								}
							}
						}
						if(checkHostileEndOfPath(hostilesOnScreen[0])) {
							removeHostile(hostilesOnScreen[0]);
						}
					}
				}
				if (event.key.code == sf::Keyboard::C) {
					removeHostile(hostilesOnScreen[0]);
				}
				//END TEMPORARY STUFF
			}

			

		
			
		
			window.clear();
			window.draw(easyPath.pathImage);
			window.draw(overlays.backing);
			window.draw(overlays.getHP());
			window.draw(overlays.getMoney());
			window.draw(overlays.getMessage());

			//draw all hostiles to screen
			for (int col = 0; col < hostilesOnScreen.size(); col++) {
				window.draw(hostilesOnScreen[col].sprite);
			}
			window.display();
		}

	}
}

//ALL OF THESE ASSUMES START PATH ON LEFT END ON RIGHT AND IS NOT FULLY TESTED

//adds a hostile to the beginning of the path
// assumes start is on left side
void WaveRunningPage::spawnHostile(Hostile h) {
	//make hostile texture, I don't know how we are managing this 
	//temporary

	h.sprite.setTexture(spriteSheet);
	h.sprite.setTextureRect(sf::IntRect(25 * h.type, 0, 25, 25));
	//find beginning of path
	int beginningColumn = 0;
	int squareWidth = 50;

	fstream mapFile;
	mapFile.open("Intmap.txt");


	while (mapFile.is_open()) {
		for (int row = 0; row < 16; row++) {
			for (int col = 0; col < 20; col++) {
				mapFile >> intMap[col][row];
				if (intMap[0][row] == -1) {
					beginningTiles.push_back(row);
				}
			}
		}
		mapFile.close();
	}

	//randomly pick which square at beginning of path to use
	srand(time(NULL));
	int beginning = rand() % beginningTiles.size();
	h.X = -35;
	h.Y = (beginningTiles[beginning])*squareWidth + 5;
	h.sprite.setPosition(-35, (beginningTiles[beginning])*squareWidth + 5);
	h.sprite.scale(1.5f, 1.5f);
	h.sprite.setColor((sf::Color(255, 0, 0)));
	//add hostile to vector of those to draw
	hostilesOnScreen.push_back(h);
	h.idNum = hostilesOnScreen.size() - 1;

}
//check if hostile is going to move off the path
bool WaveRunningPage::checkHostileMove(Hostile h, int x, int y) {
	//pixel x and y to quadrant

	//will move left or up off path?
	int quadX = (x / 50);
	int quadY = (y / 50);

	if (h.X <= x) {//move right off path?
		quadX = ((x + 36) / 50);
	}
	if (h.Y <= y) {//move down off path?
		quadY = ((y + 36) / 50);
	}

	if (y<-50) {//off edge screen, going backwards, assuming start left side
		return false;
	}

	if (quadY < 0)// at start will be
		quadY = 0;

	if (quadX >= 20 && h.X <= x) {//assumes end on right side, at quadX=20 at end of path want to move off screen
		return true;
	}

	if ((intMap[quadX][quadY] != -1)) {//not on path
		return false;
	}
	return true;
}

//moves hostile if it can move without going off path, if can move returns 0, else returns -1
int WaveRunningPage::moveHostile(Hostile h, int x, int y) {
	if (checkHostileMove(h, x, y)) {
		h.sprite.setPosition(x, y);
		h.X = x;
		h.Y = y;
		hostilesOnScreen[h.idNum] = (h);
		return 0;
	}
	return -1;
}

//remove hostile given, used when hostile at end of path
void WaveRunningPage::removeHostile(Hostile h) {

	swap(hostilesOnScreen[h.idNum], hostilesOnScreen[hostilesOnScreen.size()-1]);
	int temp=hostilesOnScreen[hostilesOnScreen.size() - 1].idNum;
	hostilesOnScreen[hostilesOnScreen.size() - 1].idNum = hostilesOnScreen[h.idNum].idNum;
	hostilesOnScreen[h.idNum].idNum = temp;

	hostilesOnScreen.erase(hostilesOnScreen.end()-1);
}

//returns true if hostile at end of path else returns false
bool WaveRunningPage::checkHostileEndOfPath(Hostile h) {
	if (h.sprite.getPosition().x >= 990) {//if end on right this would mean the hostile is moving off screen at end of path
											//and needs to be removed
		return true;
	}
	return false;

}



//function to be called by gameLogic when time to switch page, gives page want to switch to
void WaveRunningPage::goToNextPage(cScreen& screen) {
	switchPage = true;
	nextPageInt = getIntForPage(screen);

}
//takes in screen, and returns the integer for its corresponding place in the vector
int WaveRunningPage::getIntForPage(cScreen& screen) {
	if (typeid(screen).name() == typeid(MainMenu).name()) {
		return 0;
	}
	if (typeid(screen).name() == typeid(WaveDescription).name()) {
		return 1;
	}
	if (typeid(screen).name() == typeid(BuySellPage).name()) {
		return 2;
	}
	if (typeid(screen).name() == typeid(WaveRunningPage).name()) {
		return 3;
	}
	if (typeid(screen).name() == typeid(WaveComplete).name()) {
		return 4;
	}
	if (typeid(screen).name() == typeid(LevelComplete).name()) {
		return 5;
	}
	if (typeid(screen).name() == typeid(WinnerPage).name()) {
		return 6;
	}
	if (typeid(screen).name() == typeid(GameOverPage).name()) {
		return 7;
	}

}
