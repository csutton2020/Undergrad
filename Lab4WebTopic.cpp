/*
 * 
 * Chris Sutton
 * cisc220-32L
 * lab4
 */
#include "SLL.h"
#include "SNode.h"
#include "WebTopic.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <cctype>


using namespace std;

WebTopic::WebTopic(string filename) {  //constructor
	file = filename;
	wordlist = new SLL();
	currpriority = 3;
}
void WebTopic::getPriority(string line) {
	// determine the current priority, based on the tag that starts the line
	//See the header file for more details
	if( line.compare(0,5, "title") == 0){
		this->currpriority = 1; // title is priority 1
	}else if( (line.compare(0,5, "h1") == 0) || (line.compare(0,5, "h2") == 0) ){
		this->currpriority = 1;  // header1 & 2 priority 1
	}else if( (line.compare(0,5, "h3") == 0) ||
			(line.compare(0,5, "h4") == 0) ||
			(line.compare(0,5, "h5") == 0) ||
			(line.compare(0,5, "h6") == 0) ){
		this->currpriority = 2;  //header 3-6 priority 2
	}else{
		this->currpriority = 3; // else priority 3
	}


}
void WebTopic::printPage() {
	//Prints out the list of web page words and their priority. You can
	//look at my output below to see what mine looks like
	wordlist->printSLL();

}
void WebTopic::ReadFile() {
	//reads in the web page, character by character, into a a line, setting the
	//current priority based on the latest tag read in. This method calls
	//getPriority when a tag has been read in, and it calls parseString when the
	//text between tags has been read in.
	ifstream infile(file.c_str(),ios::in); // open file
	string line = "";
	char c;
	while (infile.get(c)) {
		if (c == '<') {
			if (!line.empty()) {  // if opening a new title/header and line has data, parse it
				parseString(line);
				line = "";
			}
		}
		else if (c == '>') { // set new priority based on what was read in between the brackets
			getPriority(line);
			line = "";
		}
		else { // fill line with txt from page
			line += c;
		}
	}
	cout << endl;
	infile.close();
}

string WebTopic::stripSpace(string s) {
	//Strips out any character that isn’t alphanumeric and returns the stripped
	//string
	unsigned int i = 0;
	while (i < s.length()) { // over length
		if (!isalpha(s[i])) {
			s.erase(i);// erase non alpha
		}
		i++;
	}
	return s;
}

void WebTopic::parseString(string line) {
	//takes the line and breaks it down into words (separated by space), calls
	//stripSpace to get rid of anything not alphanumeric, and then inserts each
	//word into the list along with its priority
	string stringForList ;
	int count =0;
	for(unsigned int i=0; i< line.size(); i++){ // take all extra spaces out
		if( isalpha(line[i]) ){ // if normal alpha add to new string
			stringForList += line[i];
			count = 0;
		}else if ( (i == 0) && line[i] == ' ' ){ // if first is ' '? skip
			continue;
		}else if( (i == line.size() -1) && !isalpha(line[i]) ){ // if last is two spaces? skip
			continue;
		}else if( (line[i] == ' ') && count !=1){
			stringForList += ' ';
			count++;
		}else{
			continue;
		}
	}if( stringForList.size()  > 1){ // cleans empty strings of size 0 or 1
		string strInArray ;
		for(unsigned int i =0 ; i< stringForList.size(); i++){ // break strings into word to feed into stripSpace then to wordlist field
			if( stringForList[i] != ' '){ // if a letter then copy
				strInArray += stringForList.at(i);
			}else if ( stringForList[i] == ' '){ // if hit a space send to stripspace then worldlist, also reset string
				wordlist->priorityInsert( stripSpace(strInArray), this->currpriority);
				strInArray = "";
			}else if ( i == stringForList.size() -1 ){ // if the end, send to stripspace then worldlist, also reset string
				wordlist->priorityInsert( stripSpace(strInArray), this->currpriority);
				strInArray = "";
			}
		} // outside the loop, send any remaining string to stripSpace then to wordlist
		wordlist->priorityInsert( stripSpace(strInArray), this->currpriority);
		strInArray = "";
	}
}


