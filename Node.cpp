/*
 * Node.cpp
 *
 *  Created on: Aug 24, 2017
 *      Author: mjd3
 */

#include "Node.h"
#include "Tile.h"

Node::Node(int index) {
	this->index = index;
	this->settlement = 0;
	this->city = false;
	this->port = 0;
}

Node::~Node() {}

bool Node::hasSettlement() {
	return (this->settlement > 0);
}

bool Node::hasCity() {
	return this->city;
}

void Node::print() {
	printf("i: %d, settlement: %d, port: %d, resources: ", this->index, this->settlement, this->port);
	for (int i = 0; i <  parents.size(); i++) 
		printf("%d ", parents[i]->resource);
	printf("\n");
}
