/*
 * 
 * chris sutton
 * cisc220 032L
 */

#include "Z_Obj.h"
#include "ZNode.h"
#include "ZDatabase.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <istream>
using namespace std;

ZDatabase::ZDatabase(string filename, bool flag) {
	ztree = new AVLTree(flag);
	ifile = filename;
	readFile();
cout<< "readfile complete"<<endl;
	getZips();
	cout << "In order: " << endl;
	ztree->printIO(ztree->root);
	cout << endl << "PreOrder:"<<endl;
	ztree->printPre(ztree->root);
	cout << endl << "PostOrder:"<<endl;
	ztree->printPost(ztree->root);
}
void ZDatabase::getZips() {
	cout << "Enter a zip" << endl;
	int z;
	cin >> z;
	while (z > -1) {
		ZNode *x = ztree->findZip(z, ztree->root);
		x->printZ(); //printing simple node
		cout << "Enter a zip" << endl;
		cin >> z;
	}
}
void ZDatabase::readFile() {
	ifstream file(ifile.c_str());
	string line = "";
	string zip = "";
	string city = "";
	string county = "";
	string abbr = "";
	string state="";
	string lats="";
	string lons="";
	getline(file,line);
	while (getline(file,line)) {
		unsigned int start = 0;
		unsigned int end = line.find('\t');
		if (end > start ) {
			if (end != line.npos) {
				zip = line.substr(start,end-start);
				start = end+1;
				end = line.find('\t',start);
			}
			if (end != line.npos) {
				city = line.substr(start,end-start);
				start = end+1;
				end = line.find('\t',start);
			}
			if (end != line.npos) {
				state = line.substr(start,end-start);
				start = end+1;
				end = line.find('\t',start);
			}
			if (end != line.npos) {
				abbr = line.substr(start,end-start);
				start = end+1;
				end = line.find('\t',start);
			}
			if (end != line.npos) {
				county = line.substr(start,end-start);
				start = end+1;
				end = line.find('\t',start);
			}
			if (end != line.npos) {
				lats = line.substr(start,end-start);
				start = end+1;
				end = line.find('\t',start);
			}
			if (end != line.npos) {
				lons = line.substr(start,end-start);
			}
			float lat = atof(lats.c_str());
			float lon = atof(lons.c_str());
			int zz = atoi(zip.c_str());
			//cout <<zz<<", "<< city <<", "<<state<<", "<<abbr<<", "<<county<<",
			//"<< lat <<"-"<< lon << endl;
			// for testing to make sure the read in file works
			Z_Obj *z = new Z_Obj(zz,city,state,abbr,county,lat,lon);
			ztree->addNode(z,ztree->root);
		}
	}

}

ZDatabase::~ZDatabase() {
	// TODO Auto-generated destructor stub
}

