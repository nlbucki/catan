/*
 * playCatan.cpp
 *
 *  Created on: Aug 23, 2017
 *      Author: nlbucki
 */

#include <stdio.h>
#include <stdlib.h>

#include "Player.h"
#include "Board.h"

#define NUMBER_OF_TILES 19
static const int tile_numbers[18] = {5, 2, 6, 3, 8, 10, 9, 12, 11, 4, 8, 10, 9, 4, 5, 6, 3, 11}; 

struct participant {
	Player player;
	int victories = 0;
};

void playGame(participant p[4]) {
	// Takes in 4 participants and adds one to "victories" of the winning player
	int numTurns = 0;
	while(numTurns < 1000){

	}

}

void getVictoryPoints()

int main() {
		
	std::vector<Tile*> tiles;
	tiles.push_back(new Tile(0));
	for (int i = 0; i < NUMBER_OF_TILES-1; i++)
		tiles.push_back(new Tile((i % 5) + 1));
	std::random_shuffle(tiles.begin(),tiles.end());
	int j = 0;
	for (int i = 0; i < NUMBER_OF_TILES, i++) {
		if (tiles[i]->resource > 0) {
			tiles[i]->setNumber(tile_numbers[j]);
			j++;
		}
		printf("Tile Number: %d, Resource: %d, Number: %d", i, tiles[i]->getResource(), tiles[i]->getNumber());
	}	

	delete tiles;



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
