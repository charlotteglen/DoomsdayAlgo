//
// Created by Charlotte Glen on 2023-07-02.
//
#include "Player.h"
Player::Player(std::string name) {
	Name = name;
	Points = 0;
	Lives = 3;
}
void Player::setName(std::string name) {
	Name = name;
}
std::string Player::getName() {
	return Name;
}
void Player::setPoints(int points) {
	Points = points;
}
void Player::increasePoints() {
	Points++;
}
int Player::getPoints() {
	return Points;
}
void Player::setLives(int lives) {
	Lives = lives;
}
void Player::decreaseLives() {
	Lives--;
}
int Player::getLives() const {
	return Lives;
}
void Player::setHighScore(int highscore) {
	highScore = highscore;
}
int Player::getHighScore() const {
	return highScore;
}
void Player::setPrevPoints(int prevpoints) {
	prevPoints = prevpoints;
}
int Player::getPrevPoints() {
	return prevPoints;
}