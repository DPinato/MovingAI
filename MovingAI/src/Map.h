/*
 * Map.h
 *
 *  Created on: 26 Mar 2016
 *      Author: davide
 */

#ifndef SRC_MAP_H_
#define SRC_MAP_H_

class Map {
public:
	Map();
	virtual ~Map();


	// functions
	bool generateBinaryMap();
	bool generateBinaryMap(int xSize = this->binX, int ySize = this->binY);


	// set
	void setBinarySize(int xS, int yS);

	// get
	int getBinarySizeX();
	int getBinarySizeY();


private:
	int binX, binY;		// sizes for the array for binary map


};

#endif /* SRC_MAP_H_ */
