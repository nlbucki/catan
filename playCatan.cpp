/*
 * playCatan.cpp
 *
 *  Created on: Aug 23, 2017
 *      Author: nlbucki, mjd3
 */

#include <stdio.h>
#include <stdlib.h>
#include <QApplication>
#include "Board.h"
#include "Window.h"

// #include "Player.h"

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

int dispGame(int argc, char **argv, Board b) {
	QApplication app(argc, argv);

	Window window(b);
	window.show();

	return app.exec();
}


int main(int argc, char **argv) {

	Board *b = new Board();
	b->newGame();
	dispGame(argc, argv, *b);
	return 0;
	printf("\n");
	printf("%d\n", b->placeSettlement(3, 1));
	printf("%d\n", b->placeRoad(3, 4, 1));
	b->printConnections();

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
