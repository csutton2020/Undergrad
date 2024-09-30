/*
 *Olivia liepa
 * chris sutton
 * cisc220 032L
 */


#ifndef Z_OBJ_H
#define Z_OBJ_H

#include <string>
#include <cstdlib>
using namespace std;

class Z_Obj {
    friend class ZNode;
    friend class AVLTree;
    int zip;
    string city;
    string state;
    string abbr;
    string county;
    float lat;
    float lon;
public:
    Z_Obj(int z, string ct, string st, string ab, string cnty, float la, float lo);
    void printZ();
    // friend ostream& operator<<(ostream& os, const Z_Obj& z);
    // If you want to override << so you can just use cout to print your Z_Objs.
    bool lessThan(Z_Obj *z);
};



#endif /* Z_OBJ_H */

