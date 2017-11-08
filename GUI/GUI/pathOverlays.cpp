

#include "stdafx.h"
#include <string>

#include <SFML/Graphics.hpp>

using namespace std;

/*pathOverlays.cpp
	implementation of pathOverlays.h
*/

pathOverlays::pathOverlays() {

	//note: styles not set here, only default info for each of the things
	
	//temp rectangle shape that is set to backing
	sf::RectangleShape rekt(sf::Vector2f(250, 175));
	rekt.setPosition(750, 0);
	backing = rekt;

	//HP
	playerHP.setString("HP: 0");
	playerHP.setPosition(770, 20);

	//Money
	playerMoney.setString("$: 0");
	playerMoney.setPosition(770, 50);

	//Big message
	statusMessage.setString("Starting Game...");
	statusMessage.setPosition(770, 85);

	//small message
	optionsMessage.setString(" ");
	optionsMessage.setPosition(770, 115);
	

}

//constructor to initialize with desired strings if u wanted idk why i wrote this i never use it
pathOverlays::pathOverlays(string& HP, string& money, string& message) {
	
	//temp rectangle shape that is set to backing
	sf::RectangleShape rekt(sf::Vector2f(250, 175));
	rekt.setPosition(750, 0);
	backing = rekt;

	HP = "HP: " + HP;
	playerHP.setString(HP);
	money = "$: " + money;
	playerMoney.setString(money);
	statusMessage.setString(message);
}


//set style for each attribute stored in pathOverlays class
void pathOverlays::setStyle(GUIStyle& style) {
	style.setStyle(backing);

	style.setStyle(playerHP, 19);
	style.setStyle(playerMoney, 19);

	style.setStyle(statusMessage, 19);
	style.setStyle(optionsMessage, 16);
}

//functions to set values

//pass in int, this converts it to a string for you
void pathOverlays::setHP(int HP) {
	string HPStr = to_string(HP);
	HPStr = "HP: " + HPStr;
	playerHP.setString(HPStr);
}

//pass in int, this converts it to a string for you
void pathOverlays::setMoney(int money) {
	string moneyStr = to_string(money);
	moneyStr = "$: " + moneyStr;
	playerMoney.setString(moneyStr);
}

//big message
void pathOverlays::setMessage(string& message) {
	statusMessage.setString(message);
}

//small message
void pathOverlays::setOptions(string& message) {
	optionsMessage.setString(message);
}

//accessors for drawing the window
//can't get the individual HP, money values from here

sf::Text pathOverlays::getHP() {
	return (playerHP);
}
sf::Text pathOverlays::getMoney() {
	return (playerMoney);
}
sf::Text pathOverlays::getMessage() {
	return (statusMessage);
}
sf::Text pathOverlays::getOptions() {
	return (optionsMessage);
}