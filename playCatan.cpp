/*
 * playCatan.cpp
 *
 *  Created on: Aug 23, 2017
 *      Author: nlbucki
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>

// #include "Player.h"
#include "Tile.h"

#define NUMBER_OF_TILES 19
#define NUMBER_OF_NODES 54

static const int tile_numbers[18] = {5, 2, 6, 3, 8, 10, 9, 12, 11, 4, 8, 10, 9, 4, 5, 6, 3, 11}; 
static const int node_numbers[19][6] = {{0, 1, 2, 31, 30, 29}, {2, 3, 4, 33, 32, 31}, {4, 5, 6, 7, 34, 33}, {7, 8, 9, 36, 35, 34}, {9, 10, 11, 12, 37, 36},
										{12, 13, 14, 39, 38, 37}, {14, 15, 16, 17, 40, 39}, {17, 18, 19, 42, 41, 40}, {19, 20, 21, 22, 43, 42}, 
										{22, 23, 24, 45, 44, 43}, {24, 25, 26, 27, 46, 45}, {27, 28, 29, 30, 47, 46}, {30, 31, 32, 49, 48, 47}, 
										{32, 33, 34, 35, 50, 49}, {35, 36, 37, 38, 51, 50}, {38, 39, 40, 41, 52, 51}, {41, 42, 43, 44, 53, 52},
										{44, 45, 46, 47, 48, 53}, {48, 49, 50, 51, 52, 53}};

static const std::map<int, int> ports_map = {
												{ 18, 1 }, { 19, 1 },
											    { 2, 2 }, { 3, 2 },
											    { 12, 3 }, { 13, 3 },
											    { 22, 4 }, { 23, 4 },
											    { 8, 5 }, { 9, 5 },
											    { 5, 6 }, { 6, 6 }, { 15, 6 }, { 16, 6 }, { 25, 6 }, {26, 6 }, { 28, 6 }, { 29, 6 },
										    };

// struct participant {
// 	Player player;
// 	int victories = 0;
// };

// void playGame(participant p[4]) {
// 	// Takes in 4 participants and adds one to "victories" of the winning player
// 	int numTurns = 0;
// 	while(numTurns < 1000){

// 	}

// }

// void getVictoryPoints()


int main() {
		
	std::vector<Tile*> tiles;
	std::vector<Node*> nodes;

	for (int i = 0; i < NUMBER_OF_NODES; i++) {
		nodes.push_back(new Node());
		if (ports_map.count(i) > 0)
			nodes[i]->port = ports_map.at(i);
	}

	tiles.push_back(new Tile(0));
	for (int i = 0; i < NUMBER_OF_TILES-1; i++) {
		tiles.push_back(new Tile((i % 5) + 1));
	}

	std::random_shuffle(tiles.begin(),tiles.end());
	int j = 0;
	for (int i = 0; i < NUMBER_OF_TILES; i++) {
		std::vector<Node*> tile_nodes;
		for (int k = 0; k < 6; k++)
			tile_nodes.push_back(nodes[node_numbers[i][k]]);
		tiles[i]->nodes = tile_nodes;
		if (tiles[i]->resource > 0) {
			tiles[i]->number = tile_numbers[j];
			j++;
		}
		else
			tiles[i]->number = 0;
		printf("Tile Number: %d, Resource: %d, Number: %d, Nodes: ", i, tiles[i]->resource, tiles[i]->number);
		tiles[i]->printNodes();
		printf("\n");
	}


	std::random_shuffle(tiles.begin(),tiles.end());
	j = 0;
	for (int i = 0; i < NUMBER_OF_TILES; i++) {
		std::vector<Node*> tile_nodes;
		for (int k = 0; k < 6; k++)
			tile_nodes.push_back(nodes[node_numbers[i][k]]);
		tiles[i]->nodes = tile_nodes;
		if (tiles[i]->resource > 0) {
			tiles[i]->number = tile_numbers[j];
			j++;
		}
		else
			tiles[i]->number = 0;
		printf("Tile Number: %d, Resource: %d, Number: %d, Nodes: ", i, tiles[i]->resource, tiles[i]->number);
		tiles[i]->printNodes();
		printf("\n");
	}
	// int t = 0;
	// for (int i = 0; i < NUMBER_OF_NODES; i++) {
	// 	if (i < 30) {
	// 		if (i % 5 == 2 || i % 5 == 4) {
	// 			tiles[t++]->addNode(i);
	// 			tiles[t]->addNode(i);
	// 		}
	// 		else if (t % 2) {
	// 			tiles[t]->addNode(i++);
	// 			tiles[t]->addNode(i);
	// 		}
	// 		else 
	// 			tiles[t]->addNode(i);
	// 	}
	// 	else 
	// }



	// Initialize players (change to actual player classes)
	// participant p[4];
	// p[1].player = Player();
	// p[2].player = Player();
	// p[3].player = Player();
	// p[4].player = Player();

	// // Play a bunch of games
	// for(int i=0; i<100; i++){
	// 	playGame(p);
	// }

	// Display win counts
	// for(int i=0; i<4; i++){
	// 	printf("%s: %d\n", p[i].player.name, p[i].victories);
	// }

}
