//============================================================================
// Name        : Lab5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <cstdlib> // for testing
#include <string>
#include "ZDatabase.h"
using namespace std;

int main() {
	//string g = "zipcodes.txt"; The full file – after you have everything
	// working
	string h = "C:/Users/physi/workspace/CISC220CODE/Lab5/src/ziptestfile.txt"; // for testing purposes
	cout <<"BINARY SEARCH TREE:" << endl<<"__________________________" <<endl;
	ZDatabase *zdb = new ZDatabase(h,false);
	cout <<endl<<"AVL TREE:" << endl<<"__________________________" <<endl;
	//ZDatabase *zdb2 = new ZDatabase(h,true);


	return 0;
}
