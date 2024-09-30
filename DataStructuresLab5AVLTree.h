/*
 * 
 * chris sutton
 * cisc220 032L
 */

/* 
 * File:   AVLTree.h
 * Author: olivialiepa
 *
 * Created on April 7, 2017, 3:08 PM
 */

#ifndef AVLTREE_H
#define AVLTREE_H

#include "ZNode.h"
#include "Z_Obj.h"

class AVLTree {
    friend class ZDatabase;
    ZNode *root;
    bool AVLflag;

public:
    AVLTree(); // constructor, sets AVLflag to false
    AVLTree(bool flag); // constructor, sets AVLflag to flag
    ZNode *findZip(int z, ZNode *n); // returns the ZNode that contains
    //that zip code in its z_Obj field. If it does not 
    //find the zip, it returns NULL
    //Note: if you don’t write this recursively, you 
    //shouldn’t need the ZNode field
    void addNode(Z_Obj *n, ZNode *r); // adds a new node to the tree.  It starts
    // traversing the tree at r
    // if you don’t do this recursively, you don’t need
    // the ZNode field.
    ZNode *addHelper(Z_Obj *n, ZNode *r);
    ZNode *addHelper2(Z_Obj *n, ZNode *r);
    ZNode *addHelper3(Z_Obj *n, ZNode *r);
    void adjustBalances(ZNode *n); // adjusts the heights and checks balances
    void updateHeight(ZNode *n); //updates heights for adjustBalances
    ZNode *rotateRight(ZNode *n); // rotates right around n 
    ZNode *rotateLeft(ZNode *n); // rotates left around n 
    void printIO(ZNode *root); // print tree in order
    void printPre(ZNode *root); // print tree in preorder 
    void printPost(ZNode *root); // print tree in postorder
    virtual ~AVLTree();
};

#endif /* AVLTREE_H */

