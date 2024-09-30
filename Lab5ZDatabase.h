/*
 * Olivia liepa
 * chris sutton
 * cisc220 032L
 */

#ifndef ZDATABASE_H_
#define ZDATABASE_H_

#include "Z_Obj.h"
#include "ZNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class ZDatabase {
	string ifile;
	string ofile;
	AVLTree *ztree;
public:
	ZDatabase(string filename, bool flag);
	void readFile();
	void getZips();
	virtual ~ZDatabase();
};

#endif /* ZDATABASE_H_ */
