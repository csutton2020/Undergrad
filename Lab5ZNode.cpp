/*Olivia liepa
 * chris sutton
 * cisc220 032L
 */

#include "ZNode.h"
#include <iostream>
using namespace std;

ZNode::ZNode(Z_Obj *z) { //Node constructor with zip set to *z
    zObj = z; // data
    height = 0;// max(left == NULL? NULL: left->height , right == NULL? NULL: right->height) + 1; // height of greatest child
    left = NULL; // left node
    right = NULL; // right node
    parent = NULL; //root node
}

ZNode::ZNode() { //Node constructor with fields set to NULL
    zObj = NULL; // data
    height = 0; // height of greatest child
    left = NULL; // left node
    right = NULL; //right node
    parent = NULL; // root node
}

void ZNode::printZ(){ // print for class data
    cout << "Zip: " << this->zObj->zip << endl;
    cout << "City: " << this->zObj->city << endl;
    cout << "State: " << this->zObj->state << endl;
    cout << "Abbr.: " << this->zObj->abbr << endl;
    cout << "County: " << this->zObj->county << endl;
    cout << "Latitude: " << this->zObj->lat << endl;
    cout << "Longitude: " << this->zObj->lon << endl;
}

ZNode::~ZNode() {// deconstructor
    if (left != NULL) {
        cout << "deleting may cause memory leak." << endl;
    }else if( right != NULL){
        cout << "deleting may cause memory leak." << endl;
    }
}
