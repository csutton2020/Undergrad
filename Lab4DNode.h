/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 

 * Chris Sutton
 * cisc220-32L
 * lab4
 */

#ifndef DNODE_H
#define DNODE_H
#include <string>
using namespace std;

class DNode {         //node
    friend class DLL;
    int data;
    DNode *next;
    DNode *prev;
public:
    DNode(int x); //arg constructor

    ~DNode(); // deconstructor
};



#endif /* DNODE_H */

