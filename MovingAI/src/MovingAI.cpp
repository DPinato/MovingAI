//============================================================================
// Name        : MovingAI.cpp
// Author      : D
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "MovingAI.h"

int main(int argc, char *argv[]) {

	cout << "MovingAI started" << endl;


	// make a map
	Map *testMap = new Map();
	testMap->setMapSeed(123);
	testMap->setBinarySize(6, 7);
	testMap->generateBinaryMap();
	testMap->printMapPNG("/Users/davide/Desktop/test.png");



	cout << "\n";
	testMap->showBinaryMap();
	cout << "\n";
	testMap->showBinaryPixMap();

	cout << "\n\n";
	cout << "MovingAI ended" << endl;
	return 0;
}
