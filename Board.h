/*
 * Board.h
 *
 *  Created on: Aug 23, 2017
 *      Author: nlbucki
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "Tile.h"
#include "Node.h"
#include <vector>

#define DEBUG_ON true

#define NUMBER_OF_TILES 19
#define NUMBER_OF_NODES 54

class Board {

	public:
		Board();
		virtual ~Board();
		void newGame();
		int rollDice();
		bool placeSettlement(int node, int player);
		bool placeRoad(int start, int end, int player);
		void printConnections();
		int getVictoryPoints();

	private:

		bool playerPresent(int node, int player);
		

		bool firstTurn;
		std::vector<Tile*> tiles;
		std::vector<Node*> nodes;
		std::vector<std::vector<int>> connections; 

};

#endif /* BOARD_H_ */
