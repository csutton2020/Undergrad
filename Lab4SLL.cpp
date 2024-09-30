/*
 * Olivia Liepa
 * Chris Sutton
 * cisc220-32L
 * lab4
 */

#include "SLL.h"



SLL::SLL() { // constructor
	first =NULL;
	last = NULL;
	p2 = NULL;
	size =0;
}


SLL::~SLL() {
	//  destructor
	SNode *n = first; // make something point to first node in the list
	for(int i=0; i<size;i++){
		SNode *tmp = n; // make tmp point to the node thats going to be deleted
		n= n->next; // move downt the list by one node
		delete tmp; // delete the node behind
		cout<< "Deleting SNode :( "<<endl;
	}
}


void SLL::printSLL(){
	//takes no args and returns void but prints out the linked list
	// to the console for testing purposes
	SNode *n = first;
	int buildHeaderOne=0;
	int buildHeaderTwo=0;
	int buildHeaderThree=0;
	for(int i=0; i<size; i++){
		if(n->priority == 1){
			buildHeaderOne++;
			if( buildHeaderOne == 1){ // build header for p1
				cout<<endl;
				cout<<endl;
				cout<< "Priority 1:"<<endl;
				cout<< n->word << ":" << n->priority <<", ";  // write first p1 node under the header
				n = n->next;
			}else{
				cout<< n->word << ":" << n->priority <<", ";  //write the rest of p1 nodes under header
				n = n->next;
			}
		}else if(n->priority == 2){   // build header for p2
			buildHeaderTwo++;
			if( buildHeaderTwo == 1){
				cout<<endl;
				cout<<endl;
				cout<< "Priority 2:"<<endl;
				cout<< n->word << ":" << n->priority <<", ";   // write first p2 node under the header
				n = n->next;
			}else{
				cout<< n->word << ":" << n->priority <<", ";  //write the rest of p2 nodes under header
				n = n->next;
			}
		}else {     // build header for p3
			buildHeaderThree++;
			if( buildHeaderThree == 1){
				cout<<endl;
				cout<<endl;
				cout<< "Priority 3:"<<endl;
				cout<< n->word << ":" << n->priority <<", ";   // write first p3 node under the header
				n = n->next;
			}else{
				cout<< n->word << ":" << n->priority <<", ";   //write the rest of p3 nodes under header
				n = n->next;
			}
		}
	} //end of for
}


void SLL::priorityInsert(string s, int p){
	//(8 pts)
	//This method creates a new node with s as the word and p as the priority and,
	//if the priority is 1, adds the new node to the beginning of the list, if it
	//is 3, adds the node to the end of the list, and if it’s 2, it will insert it
	//into the list right after pointer p2 (which is the last node with a priority
	//of 2. In essence, all the nodes with a priority of 1 are at the beginning
	//of the list, all the nodes with a priority of 2 are in the middle of the
	//list, and all the nodes with a priority of 3 are at the end of the list.
	if( p ==1 ){
		if((first == NULL ) && (last == NULL) ){ // if first node in list
			SNode *n = new SNode(s, p); // new
			first = n; // set  pointers
			last = n; // set points
			size += 1; // increase size
			//	cout<< " nodefirst s "<< s << " p: " << p <<endl;
		}else{
			addAtFront( new SNode(s, p) ); // else add at front of list because it's priority 1
		}
	}else if( p== 2 ){
		if((first == NULL ) && (last == NULL) ){ // if first node in list
			SNode *n = new SNode(s, p);  // new
			first = n;  // set  pointers
			last = n;  // set  pointers
			p2 = n; // if this is the first p2 node set p2 to point at it
			size += 1;  // increase size
		}else{                         // else there are already other nodes add priority 2 node
			SNode *tmp1 = first;
			SNode *tmp2 = last;
			if( (tmp1->priority == 1) && (tmp2->priority == 3) && p2== NULL){ // if there are p1 and p3 nodes and no p2 nodes
				while( tmp1->priority ==1 ){ // loop down list
					if(tmp1->next->priority == 3){ // next is the first priority 3
						break;
					}else{						// else keep moving
						tmp1=tmp1->next;
					}
					/*
					SNode *n = new SNode(s, p); // new priority 2
					p2 = n;                     // point to new node
					n->next = tmp1->next;       //
					tmp1->next = n;
					size += 1;  // increase size
					 */
				}SNode *n = new SNode(s, p); // new priority 2
				p2 = n;                     // point to new node
				n->next = tmp1->next;       //
				tmp1->next = n;
				size += 1;  // increase size
			}else if( (tmp1->priority ==1) && (tmp2->priority ==3) && p2 != NULL  ){ // all three types of nodes exist
				SNode *n = new SNode(s, p); // new priority 2
				while( tmp1->priority != 3){
					if( tmp1->next->priority ==3){
						break;
					}else{
						tmp1 = tmp1->next; //// can use this if needed points to last p2 before change
					}
				}
				n->next = p2->next; // n points to first p3 node
				p2->next = n;  // p2 now last p2 node
				p2 = n;
				size += 1;  // increase size
			}else if( tmp1->priority==1 ){ //there are only p1 nodes
				SNode *n = new SNode(s, p); // new priority 2
				p2 = n;                     // point to new node
				n->next = last->next;       //
				last->next = n;
				last = n;
				size += 1;  // increase size
			}else{ // there are only p3 nodes
				SNode *n = new SNode(s, p); // new priority 2
				p2 = n;                     // point to new node
				n->next = first;       //
				first = n;
				size += 1;  // increase size
			}
		}
	}else{      // no nodes, add priority 3
		if((first == NULL ) && (last == NULL) ){  // if first node in list
			SNode *n = new SNode(s, p);  // new
			first = n; // set  pointers
			last = n;  // set  pointers
			size += 1; // increase size
		}else{
			push( new SNode(s, p ) );  // else add at end of list because it's priority 3
		}
	}
}


void SLL::push(SNode *n){
	//takes a new node as an arg and returns void. this method sets node to be the last node in the list priority 3
	//(4 pts)
	// pushes n onto the end of the stack (remember to reset the last pointer)
	last->next = n; // set second to last to point at new
	last = n; // set last to new end
	size += 1;
}


void SLL::addAtFront(SNode *n){
	//(5 pts)
	//adds n to the beginning of the list (remember to reset the first pointer)
	n->next = first; // set the next field of the new node to point at the old first node
	first = n; // now first points to the new node at the beginning of the list
	size += 1;
	//cout<< " nodeaddatfront: "<< n->word << " p: " << n->priority <<endl;
}

