/*
 * Tile.h
 *
 *  Created on: Aug 24, 2017
 *  Author: mjd3
 */

#ifndef TILE_H_
#define TILE_H_

class Tile {
public:
	Tile(int resource);
	virtual ~Tile();
	void setNumber(int n);
	int getNumber();
	int getResource();

private:
	int number;
	int resource;
	// Node *nodes[6];
};

#endif /* TILE_H_ */
