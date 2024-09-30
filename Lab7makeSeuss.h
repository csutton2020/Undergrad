/*
 * makeSeuss.h
 *
 *  Created on: May 22, 2017
 *      Author: physi
 */

#ifndef MAKESEUSS_H_
#define MAKESEUSS_H_

#include "hashMap.h"
#include <iostream>
using namespace std;

class makeSeuss {
	hashMap *ht;
	string fn; //// file name for input (“DrSeuss.txt”)
	string newfile; // name of output file

public:
	makeSeuss();
	makeSeuss(string file, string newf);
	void readFile();
	void writeFile();

};

#endif /* MAKESEUSS_H_ */
