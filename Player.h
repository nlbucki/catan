/*
 * player.h
 *
 *  Created on: Aug 23, 2017
 *      Author: nlbucki
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

class Player {
public:
	std::string name;
	virtual ~Player();
	Player();
};

#endif /* PLAYER_H_ */
