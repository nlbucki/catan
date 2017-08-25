/*
 * Tile.h
 *
 *  Created on: Aug 24, 2017
 *  Author: mjd3
 */

#ifndef TILE_H_
#define TILE_H_

#include "Node.h"
#include <vector>
#include <stdio.h>

class Tile {

	public:
		Tile(int resource);
		virtual ~Tile();

		void printNodes();

		int number;
		int resource;
		std::vector<Node*> nodes;
};

#endif /* TILE_H_ */
