/*
 * Map.h
 *
 *  Created on: 26 Mar 2016
 *      Author: davide
 */

#ifndef SRC_MAP_H_
#define SRC_MAP_H_

#include "MovingAI.h"

class Map {
public:
	Map();
	virtual ~Map();


	// generic functions

	// set
	void setMapSeed(int s);

	// get
	int getMapSeed();


	//////////////////////////////

	// functions for binary maps
	bool generateBinaryMap();
	bool printMapPNG(string file);

	// set for binary maps
	void setBinarySize(int xS, int yS);

	// get for binary maps
	int getBinarySizeX();
	int getBinarySizeY();

	//////////////////////////////



	// debug functions
	void showBinaryMap();


	//////////////////////////////


private:
	int seed;				// seed for random map

	int binX, binY;		// sizes for the array for binary map
	int *binaryMap;


};

#endif /* SRC_MAP_H_ */
