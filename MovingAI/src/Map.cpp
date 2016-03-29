/*
 * Map.cpp
 *
 *  Created on: 26 Mar 2016
 *      Author: davide
 */

#include "Map.h"

Map::Map() {
	// TODO Auto-generated constructor stub
	binX = -1;
	binY = -1;
	srand(0);

}

Map::~Map() {
	// TODO Auto-generated destructor stub
}

bool Map::generateBinaryMap() {
	// generate an array with 0 and 1, representing a high or low terrain
	cout << "Generating binary map" << endl;

	// check size
	if (!(binX > 0 && binY > 0)) {
		cout << "\tBad size for binary map" << endl;
		return false;
	}

	cout << "\tSizes binX: " << binX << "\tbinY: " << binY << endl;
	cout << (binX*binY) / 8.0 << "\tBytes" << endl;
	cout << (int)ceil((binX*binY) / 8.0) << "\tBytes (ceil)" << endl;

	binaryMap = new (nothrow) int [binX*binY];
	binaryPixMap = new (nothrow) uint8_t [(int)ceil((binX*binY) / 8.0)];
	if (binaryMap == nullptr || binaryPixMap == nullptr) {
		cout << "Could not allocate memory for binaryMap" << endl;
		return false;
	}


	// generate random binary map
	for (int iX = 0; iX < binX; iX++) {
		for (int iY = 0; iY < binY; iY++) {
			binaryMap[iX*binY + iY] = rand()%2;
		}
	}



	// fill binaryPixMap
	for (int i = 0; i < (int)ceil((binX*binY) / 8.0); i++) {
		//cout << i;
		binaryPixMap[i] = 0x00;		// initialise value

		int diff = binY*binX - i*8;		// see if a full Byte still needs to put in binaryPixMap
		if (diff < 8) {
			//cout << "\tPART";
			for (int j = 0; j < diff; j++) {
				//cout << "\t" << hex << ((binaryMap[i*8 + j] & 0x1) << (7- j));
				binaryPixMap[i] += ((binaryMap[i*8 + j] & 0x1) << (7 - j));		// get the single bit value, shift it to the left accordingly
			}

		} else {
			// do the full Byte
			//cout << "\tFULL";
			for (int j = 0; j < 8; j++) {
				//cout << "\t" << hex << ((binaryMap[i*8 + j] & 0x1) << (7- j));
				binaryPixMap[i] += ((binaryMap[i*8 + j] & 0x1) << (7- j));		// get the single bit value, shift it to the left accordingly
			}

		}
		//cout << "\n";
	}



	// everything went fine
	return true;

}

void Map::setBinarySize(int xS, int yS) {
	binX = xS;
	binY = yS;
}

int Map::getBinarySizeX() {
	return binX;
}

void Map::setMapSeed(int s) {
	seed = s;
	srand(seed);
}

int Map::getMapSeed() {
	return seed;
}

int Map::getBinarySizeY() {
	return binX;
}

bool Map::printMapPNG(string file) {
	// generate a PNG image file of the binary map in file

	ofstream write(file.c_str(), ios::binary);


	if (write.is_open()) {
		char head[12] = {0x89, 0x50, 0x4E, 0x47,
									0x0D, 0x0A, 0x1A, 0x0A,
									0x00, 0x00, 0x00, 0x0D};
		write.write(head, 12);


		// IHDR chunk
		char headIHDR[4] = {0x49, 0x48, 0x44, 0x52}	;		// IHDR
		char headIHDR1[4] = {((binX>>24) & 0xFF), ((binX>>16) & 0xFF), ((binX>>8) & 0xFF), (binX & 0xFF)};	// width
		char headIHDR2[4] = {((binY>>24) & 0xFF), ((binY>>16) & 0xFF), ((binY>>8) & 0xFF), (binY & 0xFF)};	// height
		write.write(headIHDR, 4);
		write.write(headIHDR1, 4);
		write.write(headIHDR2, 4);

		char headIHDR3 = 0x01;	// bit depth, 1
		char headIHDR4 = 0x00;	// colour type, greyscale
		char headIHDR5 = 0x00;	// compression method, default
		char headIHDR6 = 0x00;	// filter method, default 0
		char headIHDR7 = 0x00;	// interlace method, no interlace
		write.write(&headIHDR3, 1);
		write.write(&headIHDR4, 1);
		write.write(&headIHDR5, 1);
		write.write(&headIHDR6, 1);
		write.write(&headIHDR7, 1);


		// PLTE chunk, not here because colour type 0

		// IDAT chunk, image data
		char headIDAT[4] = {0x49, 0x44, 0x41, 0x54};
		write.write(headIDAT, 4);

		// put the image pixels here
		//char pix[8] = {0xFF, 0xFF, 0xFF, 0xFF,
		//						0xFF, 0xFF, 0xFF, 0xFF};
		//write.write(pix, 8);




//		write << 0x49444154;	// IDAT

		// IEND chunk
		char headIEND[4] = {0x49, 0x45, 0x4E, 0x44};
		//char crc = {0xAE, 0x42, 0x60, 0x82};
		write.write(headIEND, 4);



		write.close();

	} else {
		cout << "Could not open file to output binary map" << endl;
		return false;
	}

	return true;

}

void Map::showBinaryMap() {
	for (int i = 0; i < binX*binY; i++) {
		if (i%8 == 0) { cout << "\n"; }
		cout << hex << binaryMap[i] << "\t";
	}

}

void Map::showBinaryPixMap() {
	for (int i = 0; i < (int)ceil((binX*binY) / 8.0); i++) {
		if (i%8 == 0) { cout << "\n"; }
		cout << hex << (int)binaryPixMap[i] << "\t";
	}

}
