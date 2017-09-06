/*
 * Window.cpp
 *
 *  Created on: Aug 25, 2017
 *      Author: nlbucki
 */

#include <qobjectdefs.h>
#include <qpainter.h>
#include <qpixmap.h>
#include <qpushbutton.h>
#include <Window.h>
#include <vector>

Window::Window(Board b){
	setFixedSize(800,640);

	// Set up navigation buttons
	button_next = new QPushButton("Next", this);
	button_prev = new QPushButton("Previous", this);
	button_next->setGeometry(710, 600, 80, 30);
	button_prev->setGeometry(620, 600, 80, 30);
	connect(button_next, SIGNAL (clicked(bool)), this, SLOT (slotNextButtonClicked()));
	connect(button_prev, SIGNAL (clicked(bool)), this, SLOT (slotPrevButtonClicked()));

	this->b = b;
}

void Window::slotNextButtonClicked(){

}

void Window::slotPrevButtonClicked(){

}

void Window::paintEvent(QPaintEvent *e){
	QPainter painter(this);
	std::vector<Tile*> tiles = b.getTiles();
	QPixmap tilePic;
	int i = 0;

	// Plot top 3 tiles
	for (int k=1; k<4; k++) {
		int r = tiles[i++]->resource;
		tilePic = getTilePic(r);
		painter.drawPixmap(gapSize + (gapSize + tileWidth)*k, gapSize, tilePic);
	}
	// Second 4 tiles
	for (int k=0; k<4; k++){
		int r = tiles[i++]->resource;
		tilePic = getTilePic(r);
		painter.drawPixmap(gapSize + tileWidth/2 + (gapSize + tileWidth)*k, tileHeight, tilePic);
	}
	// Middle 5 tiles
	for (int k=0; k<5; k++) {
		int r = tiles[i++]->resource;
		tilePic = getTilePic(r);
		painter.drawPixmap(gapSize + (gapSize + tileWidth)*k, tileHeight*2, tilePic);
	}
}

QPixmap Window::getTilePic(int resource){
	QPixmap sheep("./img/sheep.png");
	QPixmap wheat("./img/wheat.png");
	QPixmap wood("./img/wood.png");
	QPixmap stone("./img/stone.png");
	QPixmap brick("./img/brick.png");
	switch(resource){
		case 0:
			//desert
			return sheep;
		case 1:
			return sheep;
		case 2:
			return wheat;
		case 3:
			return wood;
		case 4:
			return stone;
		case 5:
			return brick;
	}
}
