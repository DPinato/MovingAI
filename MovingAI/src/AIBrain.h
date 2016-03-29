/*
 * AIBrain.h
 *
 *  Created on: 26 Mar 2016
 *      Author: davide
 */

#ifndef SRC_AIBRAIN_H_
#define SRC_AIBRAIN_H_

#include "MovingAI.h"

class AIBrain {
public:
	AIBrain();
	virtual ~AIBrain();


	// functions

	// set

	// get
	int getXPos();
	int getYPos();



private:
	int xPos, yPos;	// current x and y position in the map


};

#endif /* SRC_AIBRAIN_H_ */
