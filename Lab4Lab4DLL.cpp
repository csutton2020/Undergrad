/*

 * Chris Sutton
 * cisc220-32L
 * lab4
 */

#include "DLL.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

DLL::DLL() {
	first = NULL;
	last = NULL;
	size = 0;
}//constructor

DLL::DLL(int x) {
	//constructor, generates x random nums between 0 and 100,
	// insert into list in order, prints list forwards and backwards
	addFirst( rand()%101 ); //create an initial node
	DNode *tmp = first;
	for(int i=0; i<x-1; i++){ // add nodes rest of nodes called for
		insertInOrder( rand()%101 );
	}while( tmp->next != NULL){  // find last node
		tmp = tmp->next;
	}last = tmp;  // set pointer to last
	printDLL();
	printReverse();
}

DLL::~DLL() {
	DNode *tmp = first;
	while (first != NULL) {
		tmp = first->next;
		delete first;  // delete nodes
		first = tmp;
		size--;
	}
	first = NULL;
	last = NULL;
}//destructor

void DLL::printDLL() {
	cout<<endl;
	DNode *tmp = first;
	while (tmp != NULL) {
		cout << tmp->data << "->";  //print
		tmp = tmp->next;
	}
	cout << endl;
}//prints the list

void DLL::printReverse() {
	DNode *tmp = last;
	while (tmp != NULL) {
		cout << tmp->data << "->"; // print
		tmp = tmp->prev;
	}
	cout << endl;
}//prints the list in reverse

void DLL::addFirst(int x) {
	//add very first element to list
	first = new DNode(x);
	last = first;
	size++;
}//adds the very first node to the list (when size is 0) 

void DLL::addAtFront(int x) {
	DNode *n = new DNode(x);
	n->next = first;
	first->prev = n;
	first = n;
	size++;
}//adds a node to beginning of the list (when size>0) 

void DLL::push(int x) {
	DNode *n = new DNode(x);
	last->next = n;
	n->prev = last;
	last = last->next;
	size++;
}//adds node to the end of the list

void DLL::insertInOrder(int x) {
	//creates a new node and inserts it in order into the existing list
	DNode *tmp = first;
	while( (tmp != NULL) && (tmp->data) < x ){  // not last and not smaller
		tmp = tmp->next;
	}
	if(tmp == NULL){ // if last, push
		push(x);
	}else if(first->data > x){ // if first is larger
		addAtFront(x);
	}
	else if( tmp->data > x ){  // else insert somewhere in the middle
		DNode *n = new DNode(x);
		n->next = tmp;
		n->prev = tmp->prev;
		tmp->prev->next = n;
		tmp->prev = n;
		size++;
	}
}
