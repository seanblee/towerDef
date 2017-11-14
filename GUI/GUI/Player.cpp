#include "stdafx.h"
#include <string>
#include "Player.h"
Player::Player(string tempName, int tempHP, int tempMoney) {
	name = tempName;
	HP = tempHP;
	money = tempMoney;
}
int Player::getHP() const {
	return HP;
}
void Player::setHP(int tempHP) {
	HP = tempHP;
}
void Player::setName(string tempName) {
	name = tempName;
}
string Player::getName() {
	return name;
}
int Player::getMoney() const {
	return money;
}
void Player::setMoney(int tempMoney) {
	money = tempMoney;
}