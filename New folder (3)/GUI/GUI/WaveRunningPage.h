#pragma once
#include <iostream>
#include <string>
#include "cScreen.h"
#include "stdafx.h"
#include "Hostile.h"
#include "HostileManager.h"
#include "BuySellPage.h"
#include "WindowsProject2.h"
#include "Player.h"
#include "Wave.h"
#include <SFML/Graphics.hpp>
#include <typeinfo>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

/* WaveRunningPage.h
	implementation of game screen where the wave runs
		-hostiles generated, towers shoot projectiles and hostiles

	to do: projectile animations, hostile animation
	make spawnHostile(Hostile h),moveHostile,checkHostileEndOfPath, removeHostile, checkHostileMove 
					work with real hostile class, hostile textures, randomly pick which square at beginning
																		to spawn hostile better

	
*/


class WaveRunningPage : public cScreen
{
	sf::Texture spriteSheet;
	bool switchPage = false;// true if time to go to next page
	int nextPageInt=0;// holds integer that will be returned to go next selected page
	vector<int> beginningTiles;
    vector<Hostile> hostilesOnScreen;//holds all hostiles currently on screen
	int intMap[20][16];// to hold map, need in multiple functions
	int timeToSpawnHost = 0;
	int numWave = 0;//keeps track of what wave we are on
	int numHostilesLeftToSpawn;

	Player *user;
	TowerManager *towerMan;
	HostileManager *hostMan;


public:
	void resetScreen() {
		numWave = 0;
	}
	WaveRunningPage(GUIStyle& style, sf::Texture Sheet, Player*& p, TowerManager*& tempMan, HostileManager*& tempHost) : cScreen(style) { 
		spriteSheet = Sheet; 
		user = p; 
		towerMan = tempMan;
		hostMan = tempHost;
	}
	
	virtual int Run(sf::RenderWindow &window);
	
	void spawnHostile(Hostile h);
	
	int moveHostile(Hostile h,int x, int y);//returns -1 if move illegal and doesn't move, 0 if not
	bool checkHostileEndOfPath(Hostile h);

	
	void removeHostile(Hostile h);
	bool checkHostileMove(Hostile h, int x, int y);
	
};

int WaveRunningPage::Run(sf::RenderWindow &window)
{
	numWave++;
	Wave wave(numWave);

	numHostilesLeftToSpawn=wave.getHostileAmount();

	sf::Clock clock; // starts the clock
	user->HPstartLastWave = user->getHP();
	user->moneyStartLastWave = user->getMoney();


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
	//remove all hostiles still on screen from last wave
	hostilesOnScreen.clear();
	Hostile h(1);
	spawnHostile(h);
	hostMan->spawn(h);
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
			
			


			//TEMPORARY
			if (event.type == sf::Event::KeyPressed)
			{

				//this is temporary, wait for projectile stuff
				if (event.key.code == sf::Keyboard::C) {
					hostMan->totalHostilesEliminated++;
					hostMan->hostileKilledLastWave++;
					hostMan->killHost(hostilesOnScreen[0]);
					removeHostile(hostilesOnScreen[0]);
				}
				//END TEMPORARY STUFF
			}
		}

		sf::Time elapsed1 = clock.getElapsedTime();
				if (elapsed1.asSeconds()>=1&&numHostilesLeftToSpawn>0) {
					Hostile h(1);
					spawnHostile(h);
					hostMan->spawn(h);
					clock.restart();
				}


				window.clear();




				window.draw(easyPath.pathImage);

				//set HP and money text to HP and money of player
				overlays.setHP(user->getHP());
				overlays.setMoney(user->getMoney());

				//draw overlays
				window.draw(overlays.backing);
				window.draw(overlays.getHP());
				window.draw(overlays.getMoney());
				window.draw(overlays.getMessage());


				towerMan->drawTowers(window);


				for (int col = 0; col < hostilesOnScreen.size(); col++) {
					int x = hostilesOnScreen[col].getNextPos()[0];
					int y = hostilesOnScreen[col].getNextPos()[1];
					hostilesOnScreen[col].sprite.setPosition(x, y);
					hostilesOnScreen[col].setPosition();
						window.draw(hostilesOnScreen[col].sprite);		
				}
				for (int col = 0; col < hostilesOnScreen.size(); col++) {
					if (checkHostileEndOfPath(hostilesOnScreen[col])) {
						hostMan->killHost(hostilesOnScreen[col]);
						removeHostile(hostilesOnScreen[col]);
						break;
					}
				}


				//time to switch the page?
				if (user->getHP() <= 0) {// go to gameOverPage
					switchPage = true;
					nextPageInt = 7;
				}

				if (hostMan->isEveryoneDead()&& user->getHP() >0) {//go to waveComplete page
					switchPage = true;
					nextPageInt = 4;
				}

				if (switchPage) {//go to next page
					return nextPageInt;
				}

				window.display();
			

		
		
		}

	}
	

//ALL OF THESE ASSUMES START PATH ON LEFT END ON RIGHT AND IS NOT FULLY TESTED

//adds a hostile to the beginning of the path
// assumes start is on left side
void WaveRunningPage::spawnHostile(Hostile h) {

	//make hostile texture, I don't know how we are managing this 
	//temporary
	numHostilesLeftToSpawn--;
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
	h.startPos = 1;
	h.sprite.setPosition(-35, (beginningTiles[beginning])*squareWidth + 5);
	h.setPosition();
	h.sprite.scale(1.5f, 1.5f);
	h.sprite.setColor((sf::Color(255, 0, 0)));
	//add hostile to vector of those to draw
	hostilesOnScreen.push_back(h);
	h.idNum = hostilesOnScreen.size() - 1;
	
	h.setPosition();
}

//check if hostile is going to move off the path
bool WaveRunningPage::checkHostileMove(Hostile h, int x, int y) {
	//pixel x and y to quadrant

	//will move left or up off path?
	int quadX = (x / 50);
	int quadY = (y / 50);

	if (h.sprite.getPosition().x <= x) {//move right off path?
		quadX = ((x + 36) / 50);
	}
	if (h.sprite.getPosition().y <= y) {//move down off path?
		quadY = ((y + 36) / 50);
	}

	if (y<-50) {//off edge screen, going backwards, assuming start left side
		return false;
	}

	if (quadY < 0)// at start will be
		quadY = 0;

	if (quadX >= 20 && h.sprite.getPosition().x <= x) {//assumes end on right side, at quadX=20 at end of path want to move off screen
		return true;
	}

	if ((intMap[quadX][quadY] != -1)) {//not on path
		return false;
	}
	return true;
}


//moves hostile if it can move without going off path, if can move returns 0, else returns -1
int WaveRunningPage::moveHostile(Hostile h, int x, int y) {
	//if (checkHostileMove(h, x, y)) {
		h.sprite.setPosition(x, y);
		h.setPosition();

		hostilesOnScreen[h.idNum] = (h);
		return 0;
	//}
	return -1;
}

//remove hostile given, used when hostile at end of path
void WaveRunningPage::removeHostile(Hostile h) {

	//swap(hostilesOnScreen[h.idNum], hostilesOnScreen[hostilesOnScreen.size()-1]);
	//int temp=hostilesOnScreen[hostilesOnScreen.size() - 1].idNum;
	//hostilesOnScreen[hostilesOnScreen.size() - 1].idNum = hostilesOnScreen[h.idNum].idNum;
	//hostilesOnScreen[h.idNum].idNum = temp;
	int temp = h.idNum;
	hostilesOnScreen.erase(hostilesOnScreen.begin()+temp);
	user->setMoney(user->getMoney() + 10);//money increase whenenemy killed
}


//returns true if hostile at end of path else returns false
bool WaveRunningPage::checkHostileEndOfPath(Hostile h) {
	if (h.sprite.getPosition().x >= 1000) {//if end on right this would mean the hostile is moving off screen at end of path
		user->setHP(user->getHP()-1);	//and needs to be removed
		user->setMoney(user->getMoney() - 10);//money goes down then back up to starting point if enemy makes it through
		//j.incNumEscaped()
		return true;
	}
	
	
	return false;
} 
