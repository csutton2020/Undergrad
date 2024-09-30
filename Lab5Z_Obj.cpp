/*
 * Olivia liepa
 * chris sutton
 * cisc220 032L
 */

#include "Z_Obj.h"
#include <iostream>

Z_Obj::Z_Obj(int z, string ct, string st, string ab, string cnty, float la, float lo){
    zip = z;
    city = ct;
    state = st;
    abbr = ab;
    county = cnty;
    lat = la;
    lon = lo;
}

void Z_Obj::printZ(){
    cout << "Zip: " << zip << endl;
    cout << "City: " << city << endl;
    cout << "State: " << state << endl;
    cout << "Abbr.: " << abbr << endl;
    cout << "County: " << county << endl;
    cout << "Latitude: " << lat << endl;
    cout << "Longitude: " << lon << endl;
}

bool Z_Obj::lessThan(Z_Obj *z){
    if (zip < z->zip){
        return true;
    }
    else return false;
}
