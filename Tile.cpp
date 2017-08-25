/*
 * Tile.cpp
 *
 *  Created on: Aug 24, 2017
 *      Author: mjd3
 */

#include "Tile.h"

Tile::Tile(int resource) {
	this->resource = resource;
}

Tile::~Tile() {}

void Tile::setNumber(int n) {
	this->number = n;
}

int Tile::getNumber() {
	return this->number;
}

int Tile::getResource() {
	return this->resource;
}