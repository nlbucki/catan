/*
 * Node.h
 *
 *  Created on: Aug 24, 2017
 *  Author: mjd3
 */

#ifndef NODE_H_
#define NODE_H_

class Node {

	public:
		Node();
		virtual ~Node();
		bool hasCity();
		bool hasSettlement();
		bool isOwned();

		int playerID;
		bool settlement;
		bool city;
		int port;
};

#endif /* NODE_H_ */
