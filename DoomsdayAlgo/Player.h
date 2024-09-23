#pragma once
#pragma once

#ifndef DOOMSDAY3_0_PLAYER_H
#define DOOMSDAY3_0_PLAYER_H
#include <string>

class Player {
private:
	std::string Name;
	int Points;
	int prevPoints;
	int highScore;
	int Lives;
public:
	Player(std::string name);
	void setName(std::string name);
	std::string getName();
	void increasePoints();
	void setPoints(int points);
	int getPoints();
	void setLives(int lives);
	void decreaseLives();
	int getLives() const;
	void setHighScore(int highscore);
	int getHighScore() const;
	void setPrevPoints(int prevpoints);
	int getPrevPoints();
};

#endif //DOOMSDAY3_0_PLAYER_H