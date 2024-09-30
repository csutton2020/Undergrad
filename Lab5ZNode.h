/*Olivia liepa
 * chris sutton
 * cisc220 032L
 */

#ifndef ZNODE_H_
#define ZNODE_H_

#include <string>
#include <cstdlib>
#include "Z_Obj.h"
#include <iostream>
using namespace std;

class ZNode {
	friend class AVLTree;
	friend class ZDatabase;//


	Z_Obj *zObj; // data
	int height; // max(left->height,right->height) + 1 // height of greatest child
	ZNode *left;  // left node
	ZNode *right; // right node
	ZNode *parent; //root
public:
	ZNode(Z_Obj *z);  //Node constructor with zip set to *z
	ZNode(); //Node constructor with fields set to NULL
	void printZ(); // print for class data
	virtual ~ZNode(); // deconstructor
};

#endif /* ZNODE_H_ */
