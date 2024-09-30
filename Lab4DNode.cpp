/*
 *Olivia Liepa
 * Chris Sutton
 * cisc220-32L
 * lab4
 */

#include "DNode.h"
#include "DNode.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

DNode::DNode(int x) { // arg constructor
    data = x;
    next = NULL;
    prev = NULL;
}

DNode::~DNode() { // deconstructor
    if (next != NULL || prev != NULL) {
        cout << "deleting this DNode may cause a memory leak" << endl;
    }
}
