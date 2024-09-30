/*
 * makeSeuss.cpp
 *
 *  Created on: May 22, 2017
 *      Author: physi
 */

#include "makeSeuss.h"
#include "hashMap.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

makeSeuss::makeSeuss(){
	ht = NULL;
	fn ="nothing1";
	newfile	= "nothing2";
}

makeSeuss::makeSeuss(string f1,string f2) {
	ht = new hashMap();
	newfile = f2;
	fn = f1;
	cout<< "ent readfile"<<endl;//////////////////////////////////////
	readFile();
	cout<< "ent write"<<endl;/////////////////////////////////////////
	writeFile();
}

void makeSeuss::readFile() {
	ifstream infile(fn.c_str(),ios::in); // open file
	string key = "";
	string value= "";
	infile>> key;
	ht->first = key;
	cout<< "ent while"<< endl;/////////////////////////////////////////////////////////////////////////////
	while (infile >> value) { // loop getting single characters
		cout << key <<": " << value << endl;

		ht->addKeyValue(key,value);
		key = value;
		value = "";
	}
	cout<< "exit while"<<endl; //////////////////////////////////////////////////////////////////////////
	cout<< "key = "<<key<<"value = "<<value<<endl; //////////////////////////////////////////////////
	ht->addKeyValue(key,value);
	cout << endl;
	infile.close();
}

void makeSeuss::writeFile() {
	ofstream outfile(newfile.c_str(),ios::out);
	outfile << ht->first << " ";
	string key = "";
	string value = ht->map[ht->getIndex(ht->first)]->getRandValue();
	int ct = 0;
	while (ct < 500 && value != "") {
		key = value;
		outfile << key << " ";
		value = ht->map[ht->getIndex(key)]->getRandValue();
		ct ++;
	}
	outfile.close();
}



