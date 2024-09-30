/*
 * Olivia Liepa
 * Chris Sutton
 * cisc220-32L
 * lab4
 */

/* 
 * File:   SNode.h
 * Author: olivialiepa
 *
 * Created on March 17, 2017, 2:52 PM
 */

#ifndef SNODE_H
#define SNODE_H
#include <stdlib.h>
#include <iostream>
using namespace std;

class SNode {
    friend class SLL;
    friend class WebTopic;
    string word; // instead of int data, now the data is a string 
    int priority; // the priority of a node (1,2, or 3)
    SNode *next;
public:
    SNode(string word, int p);
    ~SNode();
    void printNode();
};


#endif /* SNODE_H */

