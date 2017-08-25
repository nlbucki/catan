/*
 * Node.cpp
 *
 *  Created on: Aug 24, 2017
 *      Author: mjd3
 */

#include "Node.h"

Node::Node() {
	this->playerID = 0;
	this->settlement = false;
	this->city = false;
	this->port = 0;
}

Node::~Node() {}

bool Node::isOwned() {
	return (this->playerID != 0);
}

bool Node::hasSettlement() {
	return this->settlement;
}

bool Node::hasCity() {
	return this->city;
}
