//============================================================================
// Name       : lab2.cpp
// Author      : Christian Sutton
// cisc220-011
// cisc220-032L
//============================================================================

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

bool order1(int *a, int *b); // problem 1
bool order2(int &a, int &b); // problem2
void problem3(int arr[], int size); // problem3
void problem4(int arr[], int size); // problem4
void problem5(int arr[], int size, int &small, int &smallIndex); // problem5
void problem6(int arr[], int arraySize, int &smallValue, int &index); // problem6
int problem6Helper1(int arr[], int arraySize, int &smallIndex2); // recursive helper
int problem7a(int arr[], int lengthOfElementsToSumOver); // problem 7
int problem7b(int arr[], int arraySize);
void problem7bHelper(int *arr, int lengthOfElementsToSumOver, int *currentStoredSum, int *currentStoredIndex, int InputIndex);
void problem8(int arr[], int arrayLength);
bool problem9(int arr[], int sizeOfPalindrome);
bool problem10(int arr[], int sizeOfPalindrome, int recursiveIndex);
bool problem11(int arr[],int sizeOfArray, int sizeOfPalindrome, int &indexOfPalindrome);
void problem12(int arr[], int arraySize, int &indexOfPalinddrome, int &lengthOfPalindrome);
int * problem13(int *anInt);
int* problem14(int &returnedArraySize);
int* problem15(int arr[], int *returnedArraySize);
int* problem16(int arr1[], int arr2[], int size1, int size2, int &sizeNew );
int** problem17(int arr[], int length, int *lengthOfFirstArray, int &lengthOfSecondArray);
int main() {

	srand(time(NULL));

	cout<< "problem1"<<endl;
	int x1 = rand()%52; // variables for problem 1
	int x2 = rand()%52; // variables for problem 1

	cout << "x1 : "<< x1<<endl;//before
	cout << "x2 : "<< x2<<endl;
	cout <<  order1(&x1, &x2) <<endl;
	cout << "x1 : "<< x1<<endl; // after
	cout << "x2 : "<< x2 << endl;
	cout << endl;

	cout<<"problem2"<<endl;
	int x3 = rand()%52; // variables for problem 2
	int x4 = rand()%52; // variables for problem 2

	cout << "x3 : "<< x3<<endl; //before
	cout << "x4 : "<< x4<<endl;
	cout << order1(&x3, &x4) <<endl;
	cout << "x3 : "<< x3<<endl; // after
	cout << "x4 : "<< x4<<endl;
	cout<< endl;

	int arrOne[20]; // array of int size 20

	problem3(arrOne, 20); //problem 3

	/*
	for(int i =0;i<5;i++){           //debugging
		cout << arrOne[i] << ",";
	}
	cout << endl;

	*/
	cout << "problem 4"<<endl;
	problem4(arrOne, 20); // problem4
	cout<<endl;

	cout << "problem 5" <<endl;
	int sm =-1; // int needed for problem 5
	int idx =-1; // int needed for problem 5
	problem5(arrOne, 20, sm, idx);
	cout << "problem 5 sm = " << sm <<endl;
	cout << "problem 5 idx = " << idx << endl;
	cout<< endl;

	cout<< "problem 6" <<endl;
	int sm2 = -1; // int needed for problem 6
	int idx2 = -1; // int needed for problem6
	problem6(arrOne, 20, sm2, idx2);
	cout << "problem 6 sm2 = " << sm2 <<endl;
	cout << "problem 6 idx2 = " << idx2 << endl;
	cout<< endl;

	cout << "problem7a" <<endl;
	problem4(&arrOne[3],17);
	cout << problem7a(&arrOne[3], 3) << endl;
	cout<<endl;

	cout<<"problem7b"<<endl;
	problem4(arrOne,20);
	cout << problem7b(arrOne, 20) << endl;
	cout<<endl;

	cout<< "problem8"<<endl;
	problem4(arrOne,20); //check before problem8
	problem8(arrOne,20); // sort
	problem4(arrOne,20); // check after8
	cout<<endl;

	cout<<"problem9"<<endl;
	int arr[6] = {1,2,3,4,3,2};
	problem4(arr,6);
	cout <<problem9(&arr[1], 5)<< endl;
	cout<<endl;
	cout<<problem9(&arr[0],5)<<endl;
	cout<<endl;


	cout<<"problem 10"<<endl;
	cout<< problem10(&arr[1], 5,0)<<endl;
	cout<< endl;
	cout<< problem10(&arr[0], 5,0)<<endl;
	cout<< endl;

	cout<<"problem11"<<endl;
	int arr2[10]={1,2,3,4,5,1,2,3,2,1};
	int ind =-1;
	cout <<problem11(arr2,10,5,ind) <<endl;
	cout <<"index of palindrome (if true > -1) "<< ind<< endl;
	cout<<endl;
	int ind2 =-1;
	cout <<problem11(arr2,10,4,ind2) <<endl;
	cout<<"index of palindrome (if true > -1) "<< ind2<< endl;
	cout<<endl;

	cout<<"problem12" <<endl;
	int lengthOfPal=-1;
	int indexOfDrome=-1;
	problem4(arr2,10);
	problem12(arr2,10,indexOfDrome,lengthOfPal);
	problem4(&arr2[indexOfDrome],lengthOfPal);
	cout<<endl;

	cout<<"problem13"<<endl;
	int anInt =-1;
	int *z;
	z= problem13(&anInt);
	cout<<"length of array in problem13 :" << anInt<<endl;
	cout<<"array for problem13"<<endl;
	problem4(z,anInt);
	cout<< sizeof(z)<<endl;

	cout<<"problem14"<<endl;
	int size14;
	int *z1;
	z1 = problem14(size14);
	cout<<"main printout"<<endl;
	problem4(z1,size14);


	cout<<"problem15"<<endl;
	int size =20;
	int *z2;
	problem4(arrOne,20);
	z2 = problem15(arrOne,&size);
	problem4(z2,size);

	cout<<"problem16"<<endl;
	int arr16a[5] ={1,3,5,7,9};
	int arr16b[7] ={2,4,6,8,10,11,12};
	int sizeNewArr =-1;
	int *z3;
	z3 = problem16(arr16a, arr16b, 5, 7, sizeNewArr);
	problem4(z3,sizeNewArr);

	cout<<"problem17"<<endl;
	int row1=-1;
	int row2=-1;
	int arr17[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int **z17;
	z17=problem17(arr17,20,&row1,row2);
	cout<<"row1 = "<<row1<<endl;
	cout<<"row2 = "<<row2<<endl;
	for (int i = 0; i < 2; i++) {
		if(i<1){
			for (int j = 0; j < row1; j++){
				cout <<"x["<<i<<"]["<<j<<"] = "<< z17[i][j] <<endl;
			}
		}else{
			for (int j = 0; j < row2; j++){
				cout <<"x["<<i<<"]["<<j<<"] = "<< z17[i][j] <<endl;
			}
	    }
	}





	cout<<"testing"<<endl;



	return 0;
}
/*
 * bool order1(int pointer, int pointer)
 * the function takes two int pointers and compares them. If a < b then returns true
 * if a>b return false and swap values outside of function.
 */
bool order1(int *a, int *b){ // problem1
	int c,d; // temp variables
	if(*a < *b){
		return true;
	}else{
		c = *a; // save values
		d = *b; // save values
		*a = d; // swap
		*b = c; // swap
		return false;
	}
}

/*
 * bool order2(int ref, int ref)
 * the function takes two int pointers and compares them. If a < b then returns true
 * if a>b return false and swap values outside of function.
 */
bool order2(int &a, int &b){ // problme2
	int c,d; // temp variables
	if(&a < &b){
		return true;
	}else{
		c = a; // save values
		d = b; // save values
		a = d; // swap
		b = c; // swap
		return false;
	}
}

/*
 * void problem3(int array-pointer, int)
 * the function takes an array-pointer and it's size. it
 *  fills an empty array in the main function
 */
void problem3(int arr[], int size){ // problem3
	for(int i = 0; i <size; i++){
		arr[i] = rand() % 101; // build array
	}
}

/*
 * void problem4(int array-pointer, int)
 * the function takes array=pointer and an int representing the size of the array
 *  and prints the elements via cout
 */
void problem4(int arr[], int size){
	for(int i =0; i<size ; i++){
		cout << arr[i] << ","; // print array
	} cout << endl;
}

/*
 *  void problem5(int array-pointer, int ref, int ref)
 *  the function takes an array-pointer and two int refs. It sets small to the
 *  smallest value in the array and sets index to the index of the small value in the
 *  array
 */
void problem5(int arr[], int size, int &small, int &smallIndex){
	int a = arr[0]; // set first value
	for(int i =0 ; i< size; i++){
		if(arr[i] <= a){ // change values if needed
			a= arr[i];
			small = arr[i];
			smallIndex = i;
		}else{
			continue;

		}
	}
}

/*
 *  void problem6(int array-pointer, int ref, int ref)
 *  the function takes an array-pointer and two int refs. It sets small to the
 *  smallest value in the array and sets index to the index of the small value in the
 *  array
 */
void problem6(int arr[], int arraySize, int &smallValue, int &index){
int ind = -1; // set local variable
smallValue = problem6Helper1(arr,arraySize,ind); // set small value
index = ind; // set index


}

/*
 *  int problem6Helper1(int array-pointer, int, int ref)
 *  the function takes an array-pointer and int and an int ref. It sets index2 to the
 *  index value of the smallest value in the array and returns the smallest value as an int
 */
int problem6Helper1(int arr[], int arraySize, int &smallIndex2){
	int a; // initial small value
	if(arraySize == 0){
		return arr[0]; // if 1 element
	}else {
		a= problem6Helper1(arr, arraySize -1, smallIndex2); // call itself
		if(a < arr[arraySize -1]){ // if (a) small, return (a)
			return a;
		}else{
			smallIndex2 = arraySize -1; // change values
			return arr[arraySize-1]; // change values
		}
	}
}

/*
 * int problem7a(int array-pointer, int)
 * the function takes and array-pointer and an int representing the
 * length of elements to sum over. it returns the sum of elements over that length
 */
int problem7a(int *arr, int lengthOfElementsToSumOver){
	int sum =0;
	for(int i = 0; i < lengthOfElementsToSumOver; i++){
		sum+= arr[i]; // add all values from address up to x
	}
	return sum; // answer
}


/*
 * int problem7b(int array-pointer, int)
 * the function take an array-pointer and another int representing it's size
 * it then returns a sum of elements based on a randomly selected size within the input array
 */
int problem7b(int arr[], int arraySize){

	int randNumber= ( rand() % (7 + 1 - 3) + 3); //rand number (3,8)
	int val =100000000; // initial large value
	int index =-1;

	for(int i = 0; i < (arraySize - randNumber); i++){
		problem7bHelper(&arr[i],randNumber,&val,&index,i); // find sum  in current iteration
	}
	 problem4(&arr[index],randNumber); // print values
	return index;
}


/*
 * void problem7bHelper(int array-pointer, int, int ref, int ref, int)
 * the function takes an array-pointer, a length of values to be summed over, a ref to a current stored value
 * the ref of current stored index of that value, and a current index. the function searches for the smallest sum of a randomly
 * generated length of the input array
 *
 */
void problem7bHelper(int *arr, int lengthOfElementsToSumOver, int *currentStoredSum, int *currentStoredIndex, int InputIndex){
	int sum = problem7a(arr, lengthOfElementsToSumOver); // sum over length
		*currentStoredSum = sum;
		*currentStoredIndex = InputIndex;
	}


/*
 * void problem8(int array-pointer, int)
 * the function takes an array and a length of that array and then sorts the array
 */
void problem8(int arr[], int arrayLength){
	int smallest = -1; // set values
	int index = -1; // set values
	for(int i =0; i <arrayLength; i++){
		problem5(&arr[i],((arrayLength)-i),smallest,index); // smallest value in current array
		//cout << "i:" << i << " ((length-1)-i):" << ((length-1)-i)  << " smallest:" << smallest << " index:" << index << endl; //debugging

		arr[index+i] = arr[i]; //swap
		arr[i] = smallest;   //swap

		/*
		for(int j=0;j<length;j++){      //debugging
			cout << arr[j] << ",";
		}
		*/
		//cout << endl;
	}
}

/*
 * bool problem9(int array-pointer, int)
 * the function take an array-pointer and a length and returns
 * bool if the array is a palindrome over the length
 */
bool problem9(int arr[], int sizeOfPalindrome){
	bool state= false; // initial state
//problem4(arr,sizeOfPalindrome);
	for(int i =0; i<sizeOfPalindrome; i++){

		if( (arr[i] == arr[sizeOfPalindrome -1 -i]) ){ // check elements are equal
			state = true;
		}else{
			return false;
		}
	}
		return state;
}


/*
 *bool problem10(int array-pointer, int, int)
 *the function takes a pointer to an array, an in representing the size of a wanted palindrome
 *and it also takes an int representing a recursive index. The function compares all the elements of the
 *array and determins of it is a palindrome. it returns bool.
 */
bool problem10(int arr[], int sizeOfPalindrome, int recursiveIndex){
//problem4(arr,5); //debugging
bool state = false;
	if( (arr[recursiveIndex] == arr[sizeOfPalindrome-1 -recursiveIndex]) ){ // if the first elements check ok then..
		// cout<<"y = " <<y<<endl; // debugging
		problem10(arr,sizeOfPalindrome, recursiveIndex+1); //// continue
		state= true; /// set true until

		}else{
			return false;  // there is a false condition
		}
	return state; // if it made it this far, return state
}


/*
 * bool problem11(int array-pointer, int, int, int ref)
 * the function takes an array-pointer, the size of that array, size of wanted palindrome and ref inde to
 * be stored if palindrome found. returns bool
 */
bool problem11(int arr[],int sizeOfArray, int sizeOfPalindrome, int &indexOfPalindrome){
//	problem4(arr,sizeOfArray);
	bool state = false;
	for(int i=0; i<= (sizeOfArray-sizeOfPalindrome);i++){
		if( problem9(&arr[i],sizeOfPalindrome) ){// palindrome?
			indexOfPalindrome = i; // store index
		//	cout<<endl;
		//	cout<< "i = "<<i<<endl;
					state =true; // set true
		}else {
			continue; //else keep checking
		}
	} return state;
}


/*
 * void problem12(int array-pointer, int, int ref, int ref)
 * the function takes and array-pointer and its size along with two ref variables
 * the searches the array for any palindromes. if it finds one it changes the reference variables
 * to the index and length of the palindrome and then returns bool
 */
void problem12(int arr[], int arraySize, int &indexOfPalinddrome, int &lengthOfPalindrome){
	//problem4(arr,size);
	//bool state= false;
	int indOfPal=-1;
	for(int i =arraySize; i>= 2; i--){
		if( problem11(arr, arraySize,i,indOfPal ) ){ //ispalindrome?
		//	state=true;
			indexOfPalinddrome = indOfPal;      //store values
			lengthOfPalindrome = i;  // store values

			return;
		}else{
			continue;
		}
	}
}
/*
 * int array problem13(int pointer)
 * the function takes a int pointer and creates an array stored dynamically
 * then changes the int pointer value to be the length of the array that was created from
 * an internal random value. it then returns the array
 */
int* problem13(int *anInt){
	int randNumber1= ( rand() % (32 + 1 - 8) + 8);
	*anInt= randNumber1;
	int *arr  =new int[randNumber1]; //array
	for(int i =0; i< randNumber1; i++){

		arr[i]= rand()% 51;
	}
	return arr;
}


/*
 * int array problme14(int ref)
 * the function takes a int ref representing the size of the returned array. The function generates a random number and then creates an array
 * of digits from the number, then it returns the array
 */
int* problem14(int &returnedArraySize){        // piazza note by instructor: needs to set a size.
	int randNumber= ( rand() % (9999 + 1 - 100) + 100);
		int tenthousand = randNumber/10000;
		int thousand = randNumber/1000;
		int hundred = randNumber/100;
		cout<< randNumber<<endl; // print random number

	int *arr = NULL;
	if(tenthousand > 0){ // is the array size 5?
		arr =new int[5];
		arr[0] =randNumber/10000; //tenthousands
		arr[1] = (randNumber % 10000)/1000; //thousands
		arr[2] = ((randNumber % 10000) % 1000)/100;    //hundreds
		arr[3] = (((randNumber % 10000) % 1000) % 100) /10; //tens
		arr[4] = ((((randNumber % 10000) % 1000) % 100) % 10);
		problem4(arr,5);
		returnedArraySize= 5;
		//return arr;
	}else if( (tenthousand == 0 ) && (thousand >0) ){ // array size 4
		arr =new int[4];
		arr[0] = randNumber /1000;
		arr[1] = (randNumber % 1000)/100;
		arr[2] = ((randNumber % 1000)%100)/10;
		arr[3] = ((randNumber % 1000)%100)%10;
		problem4(arr,4);
		returnedArraySize = 4;
		//return arr;
	}else if(  (tenthousand == 0 ) && (thousand == 0) && ( hundred > 0 ) ){ //array size 3
		arr =new int[3];
		arr[0] = randNumber/100;
		arr[1] = (randNumber%100)/10;
		arr[2] = (randNumber%100)%10;
		problem4(arr,3);
		returnedArraySize =3;
		//return arr;
	}
	return arr; // return array
}


/*
 * int array problem15(int array pointer, int pointer)
 * function takes an array and then copies over values outside (10 & 40)
 * it then changes the value of size to the size of the new array then returns
 * the new array
 */
int* problem15(int arr[], int *returnedArraySize){
	int w=0;// new array length
	int z=0; // stored size
	int *array= NULL;

	for(int i=0;i< *returnedArraySize;i++){ // count size of new array
		if( arr[i]<= 40 && arr[i] >= 10 ){
			w++; // count length of new array
		}
	}array = new int[w]; // build new array
	for(int i=0;i<*returnedArraySize;i++){
		if( arr[i]<= 40 && arr[i] >= 10 ){
				array[z++] = arr[i];
		  }else {
			  continue;
		  }
	}
	 *returnedArraySize = z;
	return array;  // return array
}


/*
 * int array problem16(int array-pointer. int array-pointer, int, int, int ref)
 * the function takes two arrays along with their sizes and one int ref it then copies
 * both array into a new array based on coping one element from array1 then the next from array2
 * until one array finished then the rest of the second array is completed
 * it then returns this array
 */
int* problem16(int arr1[], int arr2[], int size1, int size2, int &sizeNew ){
	int *array= NULL;
	int z=0; // new array index start
	sizeNew= size1 + size2;
	array = new int[sizeNew];
	if( size1<= size2 ){
		for(int i=0;i<size1;i++){ // copy elements from both while both still have elements
			array[z++] = arr1[i];
			array[z++] = arr2[i];
		}for(int i=size1; i< size2; i++){ // finish coping when one array is done
			array[z++] = arr2[i];
		}
	}else{
		for(int i=0;i<size2;i++){ // copy elements from both while both still have elements
					array[z++] = arr1[i];
					array[z++] = arr2[i];
				}for(int i=size2; i< size1; i++){ // finish coping when one array is done
					array[z++] = arr1[i];
				}
	}return array;
}

/*int (array of array) problem17(int array-pointer, int, int pointer, int ref)
 * the function takes an array, the length of the array, an int pointer and an int ref
 * the function filters the input array and sends all the values below a random value to
 * the first row and all equal and higher values to the second row.
 * the function then sets the length of row one (a) and row 2 (b)
 *
 *
 */
int** problem17(int arr[], int length, int *lengthOfFirstArray, int &lengthOfSecondArray){
	int randNumber= ( rand() % (19 + 1 - 0) + 0); // rand (0,20)
	int w=0;// new array length counting
	int **x = NULL;

	int j=0;
	int k=0;
      cout<< "rand = " << randNumber<<endl;
		for(int i=0;i< length;i++){ // count size of new array
			if( arr[i]< randNumber){
				w++; // count length of new array

			}
		}cout<< "w = "<<w<<endl;
		 x  = new int *[2];// create 2d array
		 x[0]= new int[w]; //
		 x[1]= new int[length-w];

		 for(int i=0;i<length;i++){
			 if(arr[i]<randNumber){
				   x[0][j++]=arr[i];
			 }else{
					x[1][k++]=arr[i];
			 }
		 }

		*lengthOfFirstArray = w;
		lengthOfSecondArray= length-w;
		return x;

}






