/*
 * Board.cpp
 *
 *  Created on: Aug 25, 2017
 *      Author: mjd3
 */

#include "Board.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <map>

// static const int node_numbers[18][2] = {{3, 5}, {2, 4}, {1, 3}, {2, 2}, {3, 1}, 
										// {5, 1}, {7, 1}, {8, 2}, {9, 3}, {8, 4},
										// {7, 5}, {5, 5}, {4, 4}, {3, 3}, {4, 2}, 
										// {6, 2}, {7, 3}, {6, 4}, {5, 3}};

// static const std::map<int, std::map<int, int>> ports_map = {
// 	{ 0, { { 4, 3 }, { 5, 3 }, { 7, 6 }, { 8, 6 }, } },
// 	{ 1, { { 1, 5 }, { 2, 5 }, { 9, 1 }, } },
// 	{ 2, { { 0, 6 }, { 9, 1 }, } },
// 	{ 3, { { 0, 6 }, { 9, 4 }, } },
// 	{ 4, { { 1, 2 }, { 2, 2 }, { 9, 4 }, } },
// 	{ 5, { { 4, 6 }, { 5, 6 }, { 7, 6 }, { 8, 6 }, } },
// };

static const int tile_numbers[18] = {5, 2, 6, 3, 8, 10, 9, 12, 11, 4, 8, 10, 9, 4, 5, 6, 3, 11};

static const int node_numbers[19][6] = {{0, 1, 2, 31, 30, 29}, {2, 3, 4, 33, 32, 31}, 
									 {4, 5, 6, 7, 34, 33}, {7, 8, 9, 36, 35, 34}, 
									 {9, 10, 11, 12, 37, 36}, {12, 13, 14, 39, 38, 37}, 
									 {14, 15, 16, 17, 40, 39}, {17, 18, 19, 42, 41, 40}, 
									 {19, 20, 21, 22, 43, 42}, {22, 23, 24, 45, 44, 43}, 
									 {24, 25, 26, 27, 46, 45}, {27, 28, 29, 30, 47, 46}, 
									 {30, 31, 32, 49, 48, 47}, {32, 33, 34, 35, 50, 49}, 
									 {35, 36, 37, 38, 51, 50}, {38, 39, 40, 41, 52, 51}, 
									 {41, 42, 43, 44, 53, 52}, {44, 45, 46, 47, 48, 53}, 
									 {48, 49, 50, 51, 52, 53}};


static const std::map<int, int> ports_map = {
	{ 18, 1 }, { 19, 1 },
    { 2, 2 }, { 3, 2 },
    { 12, 3 }, { 13, 3 },
    { 22, 4 }, { 23, 4 },
    { 8, 5 }, { 9, 5 },
    { 5, 6 }, { 6, 6 }, { 15, 6 }, { 16, 6 }, { 25, 6 }, {26, 6 }, { 28, 6 }, { 29, 6 },
};

Board::Board() {
	
	// Initialization of all the tiles to start (only happens once per board)
	tiles.push_back(new Tile(0));
	for (int i = 0; i < NUMBER_OF_TILES-1; i++) {
		tiles.push_back(new Tile((i % 5) + 1));
	}

	// Create all of the nodes and assign the ports
	for (int i = 0; i < NUMBER_OF_NODES; i++) {
		nodes.push_back(new Node(i));
		if (ports_map.count(i) > 0)
			nodes[i]->port = ports_map.at(i);
	}

	// Initialize connection matrix
	connections.resize(NUMBER_OF_NODES, std::vector<int>(NUMBER_OF_NODES, -1));
}

Board::~Board() {}

void Board::newGame() {

	// Randomize the tile order
	std::srand(std::time(0));
	std::random_shuffle(tiles.begin(),tiles.end());

	// Clear tile/node associations
	for (int i = 0; i < NUMBER_OF_NODES; i++)
		nodes[i]->parents.clear();

	// Assign nodes and tiles to each other
	int j = 0;
	for (int i = 0; i < NUMBER_OF_TILES; i++) {
		std::vector<Node*> tile_nodes;

		for (int k = 0; k < 6; k++) {
			tile_nodes.push_back(nodes[node_numbers[i][k]]);
			nodes[node_numbers[i][k]]->parents.push_back(tiles[i]);
		}
		tiles[i]->nodes = tile_nodes;
		
		// Assign dice numbers to tiles (unless desert tile)
		if (tiles[i]->resource > 0) {
			tiles[i]->number = tile_numbers[j];
			j++;
		}
		else
			tiles[i]->number = 0;

		#ifdef DEBUG_ON
		// Print out tile info (for debugging)
		printf("Tile Number: %d, Resource: %d, Number: %d, Nodes: ", i, tiles[i]->resource, tiles[i]->number);
		tiles[i]->printNodes();
		printf("\n");
		#endif
	}

	#ifdef DEBUG_ON
	// Print out node info (for debugging)
	for (int i = 0; i < NUMBER_OF_NODES; i++) {
		nodes[i]->print();
	}
	#endif

	// Reset connections matrix
	for (int i = 0; i < NUMBER_OF_TILES; i++) {
		int x = tiles[i]->nodes.front()->index;
		int y = tiles[i]->nodes.back()->index;
		connections[x][y] = connections[y][x] = 0;
		for (int j = 0; j < tiles[i]->nodes.size()-1; j++) {
			x = tiles[i]->nodes[j]->index;
			y = tiles[i]->nodes[j+1]->index;
			connections[x][y] = connections[y][x] = 0;
		}
	}

	#ifdef DEBUG_ON
	printConnections();
	#endif
	firstTurn = true;
}

bool Board::placeSettlement(int node, int player) {
	
	if (nodes[node]->hasSettlement()) {
		#ifdef DEBUG_ON
		printf("Settlement already taken by player %d\n", nodes[node]->settlement);
		#endif
		return false;
	}

	for (int i = 0; i < NUMBER_OF_NODES; i++) {
		if (connections[node][i] >= 0 && nodes[node]->settlement) {
			#ifdef DEBUG_ON
			printf("Invalid Settlement location - too close to another settlement\n");
			#endif
			return false;
		}
	}

	// TODO CHECK RESOURCES
	if (firstTurn || playerPresent(node, player)) {
		nodes[node]->settlement = player;
		return true;
	}

	#ifdef DEBUG_ON
	printf("Invalid Settlement location\n");
	#endif
	return false;
}

bool Board::placeRoad(int start, int end, int player) {
	
	if (connections[start][end] < 0) {
		#ifdef DEBUG_ON
		printf("Road location invalid\n");
		#endif
		return false;
	}

	if (connections[start][end] > 0) {
		#ifdef DEBUG_ON
		printf("Road location already taken by player %d\n", connections[start][end]);
		#endif
		return false;
	}

	// if (nodes[start]->settlement == player || nodes[end]->settlement == player) {
	// 		connections[start][end] = connections[end][start] = player;
	// 		return true;
	// 	}

	// 	#ifdef DEBUG_ON
	// 	printf("Road location invalid\n");
	// 	#endif
	// 	return false;
	// }

	// // TODO RESOURCE CHECK
	// else {
	// 	if (playerPresent(start) || playerPresent(end)) {
	// 		connections[start][end] = connections[end][start] = player;
	// 	}
	// }
}

bool Board::playerPresent(int node, int player) {
	for (int i = 0; i < NUMBER_OF_NODES; i++) {
			if (connections[node][i] == player)
				return true;
	}
	return false;
}

void Board::printConnections() {
	for (int i = 0; i < NUMBER_OF_NODES; i++) {
		for (int j = 0; j < NUMBER_OF_NODES; j++) {
			printf("%d ", connections[i][j]);
		}
		printf("\n");
	}
}

int Board::getVictoryPoints() {

}
