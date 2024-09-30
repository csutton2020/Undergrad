/*
 * hashMap.cpp
 *
 *  Created on: May 5, 2017
 *      Author: physi
 */

#include "hashMap.h"

hashMap::hashMap(){ // when creating the map, make sure you initialize the values to NULL so you know whether that index has a key in it or not already
	mapSize = 100;
	map = new hashNode*[mapSize];
	for(int i=0; i<mapSize; i++){
		map[i]= NULL;
	}
	first = "";
	numKeys = 0;

}

void hashMap::addKeyValue(string k, string v){
// adds a node to the map at the correct index based on the key string, and then inserts the value into the value field of the hashNode
// Must check to see whether there's already a node at that location. If there's nothing there (it's NULL), add the hashNode with the keyword and value.
// If the node has the same keyword, just add the value to the list of values.
//If the node has a different keyword, keep calculating a new hash index until either the keyword matches the node at that index's keyword, or until the
// map at that index is NULL, in which case you'll add the node there.
//This method also checks for load, and if the load is over 70%, it calls the reHash method to create a new longer map array and rehash the values

	if( (float)numKeys / (float)mapSize > .70 ){ // if load is too high, rehash
		reHash();
	}else{
		int hashedIndex = getIndex(k); // initial index of key to be added, number changes if in while loop
		int collisions= 0; // number of collisions, number changes if in while loop
		while( (map[hashedIndex] != NULL) && (map[hashedIndex]->keyword != k) ){ // find a new empty slot(NULL) or duplicate to add a value to(map[hashedIndex] == k)
			hashedIndex = dblHash(hashedIndex, collisions, k);
			collisions++;
		}
		if(map[hashedIndex] == NULL){// open space
			map[hashedIndex] = new hashNode(k,v);
			numKeys++;
		}else { // map[hashedIndex] == k
			map[hashedIndex]->addValue(v);
		}
	}
}

int hashMap::getIndex(string k){ // uses calcHash and reHash to calculate and return the index of where the keyword k should be inserted into the map array
	return calcHash(k); //addKeyValue does the rest
}

int hashMap::calcHash(string k){ // hash function

	int factor = 371;
	   int hash = 0;
	   for(unsigned int i = 0; i < k.length(); i++)
	   {
	      hash = (hash * factor) + k[i];
	   }
	   hash = hash % mapSize;
	   return hash;

}
void hashMap::getClosestPrime(){
	// I used a binary search on an array of prime numbers to find the closest prime to double the map Size, and then set mapSize to that new prime.
	//You can include as one of the fields an array of prime numbers, or you can write a function that calculates the next prime number. Whichever you prefer.
	int a = 2*mapSize;
    while (!isPrime(++a)) {// find next higher prime
    }
	mapSize = a;
}

void hashMap::reHash(){ // when size of array is at 70%, double array size and rehash keys
	int oldMapSize = mapSize; // save mapSize
	getClosestPrime(); // change mapSize

	/*
	mapSize = 2*mapSize; // double map size, next find the nearest prime
	while ( !isPrime(mapSize) ){ // increase mapSize until the next prime is found
		mapSize++;
	}
	*/

	hashNode **map2 = NULL;
	*map2 = new hashNode[mapSize];
	for(int i=0; i<mapSize; i++){
		map2[i]= NULL;
	}
	for(int i=0; i<oldMapSize; i++){ // move old nodes over to new map
		if(map[i] != NULL){
			int hashedIndex = getIndex(map[i]->keyword); // initial index of key to be added, number changes if in while loop
			int collisions= 0; // number of collisions, number changes if in while loop
			while( (map2[hashedIndex] != NULL) && (map2[hashedIndex]->keyword != map[i]->keyword) ){ // find a new empty slot(NULL) or duplicate to add a value to(map2[hashedIndex] == k)
				hashedIndex = dblHash(hashedIndex, collisions, map[i]->keyword);
				collisions++;
			}
			map2[hashedIndex] = new hashNode(); // make new hashNode in new map2 array
			map2[hashedIndex]->keyword = map[i]->keyword; //copy over info
			map2[hashedIndex]->values = map[i]->values;   //copy over info
			map2[hashedIndex]->valuesSize = map[i]->valuesSize;   //copy over info
			map2[hashedIndex]->currSize = map[i]->currSize;   //copy over info
		}
	}
	map = map2; // make map point to map2 now
}

bool hashMap::isPrime(int number){
// takes an int and determines if it is prime
    if(number % 2 == 0){ // can be divided by 2?
    	return false;
    }
    for(int i=3; (i*i)<=number; i++){
        if(number % i == 0 ){// i is a factor?
        	return false;
        }
    }
    return true;
}

int hashMap::dblHash(int h, int i, string k){ // for hashing when index is already full
	int hash = 0;
	int prime = 2;
	int vals = 0;
	for (int w = 0; w < mapSize; i++){
		if (isPrime(w)){
			prime = w; //when done, prime will be largest prime number under mapSize
		}
	}
	for (unsigned int j = 0; j < k.length(); j++){
		vals += k[j]; //ascii values of string k
	}
	hash = prime - (vals%prime); // find the hash
	int index = h+(i*hash); //use new hash
	return index; //returns new index
}

int hashMap::findKey(string k){ //finds the key in the array and returns its index. If it's not in the array, returns -1
	int keyIndex = -1; // index of possible key
	int initialIndex = calcHash(k); // initial hash
	if(map[initialIndex]->keyword == k){
		return initialIndex; //if key is found, stop
	}else if(map[initialIndex]->keyword != k) {
		int collisions= 0; // number of collisions, number changes if in while loop
		while( (map[initialIndex]->keyword != k) ){ // find duplicate using dblhash
			initialIndex = dblHash(initialIndex, collisions, k);
			collisions++;
		}
		return initialIndex;
	}else{
		return keyIndex; // couldn't be found
	}

/*
	for(int i=0; i<mapSize; i++){
		if( map[i]->keyword == k){
			keyIndex = i; // store index of matched key
			break;
		}
	}
*/


}
void hashMap::printMap(){ //I wrote this solely to check if everything was working.
	for(int i = 0; i < mapSize; i++){
		cout << "Index = " << i;
		cout << "Keyword: " << map[i]->keyword;
		for(int j = 0; j < map[i]->currSize; j++){
			string str = map[i]->values[j];
			cout << "Values" << str;
		}
		cout << endl;
	}
}

hashMap::~hashMap() {
	// TODO Auto-generated destructor stub
}

