/*Olivia Liepa
 * Chris Sutton
 * cisc220-32L
 * lab4
 */
#include "DLL.h"
#include "SLL.h"
#include "SNode.h"
#include "WebTopic.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <time.h>
using namespace std;

int main() {

	srand(time(NULL));
	WebTopic *x = new WebTopic("C:/Users/physi/workspace/CISC220CODE/lab4/src/DogsandPuppies.html"); //or another web page – I haven’t
	//tested it extensively, but it should work for any basic html page
	x->ReadFile();
	x->printPage();


	DLL( (20-10+1)+10 );



	return 0;
}
