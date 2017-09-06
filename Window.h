/*
 * Window.h
 *
 *  Created on: Aug 25, 2017
 *      Author: nlbucki
 *      Source-ish: https://wiki.qt.io/Qt_for_Beginners
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <QWidget>
#include <QPaintEvent>
#include <QPixmap>
#include <QPainter>
#include "Board.h"

class QPushButton;
class Window : public QWidget {
	Q_OBJECT
public:
	explicit Window(Board b);
private slots:
	void slotNextButtonClicked();
	void slotPrevButtonClicked();
private:
	const int gapSize = 15;
	const int tileWidth = 108;
	const int tileHeight = 126;
	QPushButton *button_next;
	QPushButton *button_prev;
	void paintEvent(QPaintEvent *e);
	QPixmap getTilePic(int resource);
	Board b;
};

#endif /* WINDOW_H_ */
