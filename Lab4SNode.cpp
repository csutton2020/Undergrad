/*
 * Chris Sutton
 * cisc220-32L
 * lab4
 */

#include "SNode.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

SNode::SNode(string w, int p) { 
    word = w;
    priority = p;
    next = NULL;
} //makes node with given word and priority

SNode::~SNode(){
    if (next != NULL) {
	cout << "deleting may cause memory leak." << endl;
    }
} //destructor


void SNode::printNode(){
    cout << "|Word: " << word << "  Priority: " << priority << " |" <<endl;
    return;
} //prints word and priority of a node
