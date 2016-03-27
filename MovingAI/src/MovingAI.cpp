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
	testMap->setMapSeed(0);
	testMap->setBinarySize(300, 300);
	testMap->generateBinaryMap();
	testMap->printMapPNG("/Users/davide/Desktop/test.png");




	//testMap->showBinaryMap();

	cout << "\n\n";
	cout << "MovingAI ended" << endl;
	return 0;
}
