/*
 * hashNode.cpp
 *
 *  Created on: May 5, 2017
 *      Author: Christian Sutton
 */


#include "hashNode.h"
using namespace std;

hashNode::hashNode(){ //constructor-initializes keyword to “” , values to 0, and array
	//to NULL
	keyword = "";
	values = NULL; //dynamically allocated array of words
	valuesSize = 0; //size of values array
	currSize = 0; //how many words in values array - if larger than valuesSize, double array
}

hashNode::hashNode(string s){ // initializes keyword to s, the arraysize to 100 (or
	//whatever you like for starting), the currSize to 0, and the valuesSize to 100
	valuesSize =100;
	values = new string[valuesSize]; // create array of values
	int i =0;
	while(i < valuesSize){ // initialize all the values inthe array to ""
		values[i] = "";
		i++;
	}
	keyword =s;
	currSize =0;
}

hashNode::hashNode(string s, string v){ // in addition, puts a value in the values
	//array and initializes currSize to 1
    valuesSize = 100;
    values = new string[valuesSize];
    keyword = s; // add keyword
    currSize = 1;

    for (int i = 0; i < valuesSize; i++){
        if (values[i] == ""){
            values[i] = v; //add new value to values array
            break;
        }
    }
}

void hashNode::addValue(string v){ // adds a new value to the end of the values array,
	//increases currSize, checks to make sure there’s more space, and, if not, calls
	//dblArray()
	if(currSize == valuesSize){
		dblArray();
	}else{
		int i = 0;
		while( values[i] != ""){ // advance index to first open spot in array
				i++;
		}
		values[i] = v; // add new value at index
		currSize++; // increase size
	}
}

void hashNode::dblArray(){ //creates a new array, double the length, and copies over the
	//values. Sets the values array to be the newly allocated array.
	valuesSize = valuesSize*2; // double the size of the array
	    string *tmp = new string[valuesSize]; // temporary new array
	    for (int i = 0; i <= valuesSize/2; i++){
	        if (values[i] != "") {
	            tmp[i] = values[i]; //put old values in new array
	        }
	    }
	    for (int i = (valuesSize/2)+1; i <= valuesSize; i++){
	        tmp[i] = ""; //set rest of array as empty strings
	    }
	    delete [] values; //delete old array
	    values = tmp; // set values equal to new array


}
string hashNode::getRandValue(){ // returns a random string from the values array. If
	//there’s no values in the value array, then it returns an empty string.
	int randValue = rand() % ( currSize - 0 + 1 ); //pick rand value
	if(currSize == 0){
		return "";
	}else{
	return values[randValue];
	}
}

 hashNode::~hashNode(){

}

