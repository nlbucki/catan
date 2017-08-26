/*
 * Node.h
 *
 *  Created on: Aug 24, 2017
 *  Author: mjd3
 */

#ifndef NODE_H_
#define NODE_H_

#include <stdio.h>
#include <vector>

class Tile;

class Node {

	public:
		Node(int index);
		virtual ~Node();
		bool hasCity();
		bool hasSettlement();
		void print();

		int index;
		bool settlement;
		bool city;
		int port;
		std::vector<Tile*> parents;
};

#endif /* NODE_H_ */
