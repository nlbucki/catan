/*
 * Tile.cpp
 *
 *  Created on: Aug 24, 2017
 *      Author: mjd3
 */

#include "Tile.h"
#include "Node.h"

Tile::Tile(int resource) {
	this->resource = resource;
}

Tile::~Tile() {}

void Tile::printNodes() {
	for (int i = 0; i < this->nodes.size(); i++){
		printf("%d ", this->nodes[i]->port);
	}
}