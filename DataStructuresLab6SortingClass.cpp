/*
 * SortingClass.cpp
 *
 *  Created on: Apr 21, 2017
 *      Author: Christian Sutton
 */

#include "SortingClass.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

SortingClass::SortingClass(int si, int sm, int la){
	//(5 pts) random numbers should be between the smallest and largest numbers,
	//in-order should start at smallest
	//reverse order should start at largest
	//all should be of size size
	size = si;
	smallest = sm;
	largest = la;
	randArr = new int[size];
	inOrderArr = new int[size];
	revOrderArr = new int[size];
	for (int i = 0; i < size; i++){
		randArr[i] = rand() %  ((largest - smallest) + 1) + smallest;
		cout << randArr[i] << endl;
	}
	for (int j = 0; j < size; j++){
		inOrderArr[j] = smallest + j;
		cout << inOrderArr[j] << endl;
	}
	for (int k = 0; k < size; k++){
		revOrderArr[k] = largest - k;
		cout << revOrderArr[k] << endl;
	}
}

SortingClass::SortingClass(int si){
	//(2 pts) largest should be 5000, smallest should be 10
	//SortingClass(si, 10, 5000);
	size = si;
	smallest = 10;
	largest = 5000;
	randArr = new int[size];
	inOrderArr = new int[size];
	revOrderArr = new int[size];
	for (int i = 0; i < size; i++){
		randArr[i] = rand() %  ((largest - smallest) + 1) + smallest;
		cout << randArr[i] << endl;
	}
	for (int j = 0; j < size; j++){
		inOrderArr[j] = smallest + j;
		cout << inOrderArr[j] << endl;
	}
	for (int k = 0; k < size; k++){
		revOrderArr[k] = largest - k;
		cout << revOrderArr[k] << endl;
	}
}

SortingClass::SortingClass(){
	// (2 pts)Start with a smaller size to make sure your sorting algorithms are working
	// and build up to 50000
	size = 5000;
	smallest = 10;
	largest = 5000;
	randArr = new int[size];
	inOrderArr = new int[size];
	revOrderArr = new int[size];
	for (int i = 0; i < size; i++){
		randArr[i] = rand() %  ((largest - smallest) + 1) + smallest;
		//cout << randArr[i] << ", ";
	}
	for (int j = 0; j < size; j++){
		inOrderArr[j] = smallest + j;
		//cout << inOrderArr[j] << endl;
	}
	for (int k = 0; k < size; k++){
		revOrderArr[k] = largest - k;
		//cout << revOrderArr[k] << endl;
	}
}

int *SortingClass::copyArr(string s) {
	//(7 pts) based on s (which can be “rev”, “ord”, or “rand”, creates a new array,
	// copies over the old array, and returns the address of the new array
	string str1 = "rand";
	string str2 = "ord";
	string str3 = "rev";
	int *r = new int[size]; // new array
	if( s == str1 ){ //rand array
		for(int i=0; i<size; i++){
			r[i] = randArr[i];
		}
	}else if( s == str2 ){ //ord array
		for(int i=0; i<size; i++){
			r[i] = inOrderArr[i];
		}
	}else if( s == str3 ){ //rev array
		for(int i=0; i<size; i++){
			r[i] = revOrderArr[i];
		}
	}
	return r; //return array
}

void SortingClass::selectionSort(int arr[]) {
	// (4 pts) Does what you’d think to the array passed into the method.
	int minimum;
	int tmp;
	for (int i = 0; i < size - 1; i++) {
		minimum = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[minimum]) {
				minimum = j;
			}
		}
		if (minimum != i) {
			tmp = arr[i];
			arr[i] = arr[minimum];
			arr[minimum] = tmp;
		}
	}
}

void SortingClass::insertionSort(int arr[]){
	// (4 pts) Does what you think to the array passed into the method.
	int indexToInsertAt;
	int valBeingMoviedIndex;
	for(int i=0; i<size -1; i++){
		if( arr[i+1] < arr[i] ){ // is first val outside the sorted array smaller than last val in sorted array?
			for(int j=i; j>=0; j--){
				if( arr[i+1] > arr[j] ){// if so, find the first smaller value to insert after in the sorted array
					indexToInsertAt = j+1; // save index value where value is being moved to
					valBeingMoviedIndex = i+1; // save index of value being moved
					break;
				}else if(j==0 && (arr[i+1]< arr[j]) ){ // if my value is smaller than the first in my sorted array, then move all up by one index
					indexToInsertAt = j; // save index value where value is being moved to
					valBeingMoviedIndex = i+1; // save index of value being moved
				}else{
					continue;
				}
			}
			int movedValue = arr[valBeingMoviedIndex]; //save value being moved before its overwritten
			for(int k=valBeingMoviedIndex; k>=indexToInsertAt; k--){
				if(k == indexToInsertAt){
					arr[k] = movedValue; // insert into sorted array
				}else{
					arr[k] = arr[k-1]; //shift sorted values up by one index
				}
			}
		}else{
			continue; // grow sorted list if value at next index is sorted
		}
	}
}

void SortingClass::quickSort(int first, int last, int arr[]){
	// (4 pts) first and last are the indices indicating
	// the current part of the array you're sorting
	  if (last - first > 1) {  // There is data to be sorted.
	    // Partition the table.
	    int pivot = partition(first, last, arr);
	    // Sort the left half.
	    quickSort(first, pivot-1, arr);
	    // Sort the right half.
	    quickSort(pivot + 1, last,arr);
	  }
}


int SortingClass::partition(int first, int last, int arr[]){
	//(7 pts)again, because you're only partitioning part of the array
	int  p = first; // pivot index
	int pivot = arr[first]; // pivot value
	int i = first+1;
	int j = last;
	int tmp;
	int tmp2;
	while (i <= j) { // while sorting around future pivot location
		while (arr[i] < pivot) // value is in agreement with low side partition
			i++;
		while (arr[j] > pivot) // value is in  agreement high side partition
			j--;
		if (i <= j) { // swap values
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++; // keep moving
			j--;
		}
	}
	tmp2 =arr[p];  // store pivot value
	arr[p] = arr[j];  // swap value where pivot was
	arr[j] = tmp2; // place pivot value in between both partitions
	return j; // return pivot index
}

void SortingClass::merge(int arr[], int f, int m, int l){
	// (7 pts)f is first index, m is middle index (end of first sorted array portion)
	// and l is the last index of the second array portion
	int a = f;
	    int b = f;
	    int c = m+1;
	    int arr2[size];
	    while ((a <= m)&&(c <= l)) {
	        if (arr[a] <= arr[c]) {
	            arr2[b] = arr[a];
	            a++;
	        } else {
	            arr2[b] = arr[c];
	            c++;
	        }
	        b++;
	    }
	    if (a > m) {
	        for (int i = c; i <= l; i++) {
	            arr2[b] = arr[i];
	            b++;
	        }
	    } else {
	        for (int j = a; j <= m; j++) {
	            arr2[b] = arr[j];
	            b++;
	        }
	    }
	    for (int k = f; k <= l; k++) {
	        arr[k] = arr2[k];
	    }
}


void SortingClass::mergeSort(int arr[], int low, int hi) {
	// (4 pts)keeps dividing the portion of the array between the low index and the hi
	// index by dividing by 2
	int mid;
    if (low < hi) {
        mid = (low + hi) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, hi);
        merge(arr, low, mid, hi);
    }
}

void SortingClass::compareSorts() {
	clock_t startTime = clock();
	double timePassed;

	//SELECTION SORT
	int *arr = copyArr("rand");
	startTime = clock();
	selectionSort(arr);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Selection: rand "<<timePassed << endl;

	arr = copyArr("rev");
	startTime = clock();
	selectionSort(arr);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Selection: rev "<<timePassed << endl;

	arr = copyArr("ord");
	startTime = clock();
	selectionSort(arr);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Selection: ord "<<timePassed << endl;

	//INSERTION

	arr = copyArr("rand");
	startTime = clock();
	insertionSort(arr);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Insertion: rand "<<timePassed << endl;

	arr = copyArr("rev");
	startTime = clock();
	insertionSort(arr);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Insertion: rev "<<timePassed << endl;

	arr = copyArr("ord");
	startTime = clock();
	insertionSort(arr);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Insertion: ord "<<timePassed << endl;

	//QUICKSORT
	arr = copyArr("rand");
	startTime = clock();
	quickSort(0,size-1,arr);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Quick: rand "<<timePassed << endl;

	arr = copyArr("rev");
	startTime = clock();
	quickSort(0,size-1,arr);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Quick: rev "<<timePassed << endl;

	arr = copyArr("ord");
	startTime = clock();
	quickSort(0,size-1,arr);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Quick: ord "<<timePassed << endl;

	//MERGE

	arr = copyArr("rand");
	startTime = clock();
	mergeSort(arr,0,size-1);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Merge: rand "<<timePassed << endl;


	arr = copyArr("rev");
	startTime = clock();
	mergeSort(arr,0,size-1);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Merge: rev "<<timePassed << endl;

	arr = copyArr("ord");
	startTime = clock();
	mergeSort(arr,0,size-1);
	timePassed = clock() - startTime;
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<", ";
	}
	cout << endl;
	delete [] arr;
	cout << "Merge: ord "<<timePassed << endl;

}

SortingClass::~SortingClass() {
	// TODO Auto-generated destructor stub
}

