#include <iostream>
#include <string>

using namespace std;

// write a function to print the contents of your array
//   bonus! try to implement your function so that it can accept
//     many types of data (int, char, string, etc.)
template <typename flexibleType> // ???
void printArray(flexibleType inArray[], int length) {
    for(int i = 0; i < length; i++){
        cout << " " << inArray[i];
    }
}

// Implement a sequential search algorithm
// your function should search for a target value (target)
//    within the indices of "start" to "end"
// return true if target exists in the array within this range,
//    return false otherwise
bool seqSearch(string target, string arr[], int start, int end) {
    // cleaner for loop
    for(start; start <= end; start++){
        if(arr[start] == target){
            return true;
        }
    }

   return false;
}

// Implement an iterative binary search 
// Return true if target exists in the array with size n,
//    return false otherwise 
bool binSearch(float target, float arr[], int n) {
    // start
    int start = 0;

    while(start < n){
        int center = n/2;
        float mid = arr[center];

        if(mid == target){
            return true;
        }
        // search left 
        else if(mid > target){
            n /= 2;
            center = n / 2;
            mid = arr[center];
            center--;
        }
        // search right
        else if(mid < target){
            arr += (center+1);
            n /= 2;
            center = n / 2;
            mid = arr[center];
            center++;
        }
        
        start++;
    }


    return false;	
}

// Implement a recursive binary search 
// Return true if target exists in the array with size n
//   return false otherwise
bool binSearchR(char target, char charray[], int n) {
    int center = n/2;
    char mid = charray[center];

    // base case
    if(n == 0){
        return false;
    }
    if(n == 1){
        if(charray[0] == target){
            return true;
        }
    }
    //general case
    if(mid == target){
        return true;
    }
    else if(mid > target){
        return binSearchR(target, charray, n/2);
    }
    else if(mid < target){
        charray = charray + (center);
        return binSearchR(target, charray, n/2);
    }

    return false;
}

// Implement a brand new sorting algorithm
//    Don't use a reference for this!
//    Be sure to do your best to implement the algorithm's logical steps
// Step 1: implement a function swap() that will swap any two elements in an array,
//          given their indices
// Step 2: implement a function minFind() that will find and return 
//          the **index** of the smallest element in an array
/*
Step 3: Finally, use your two functions above to complete the following in newSort():
        1 - search through the array to find the location of the smallest value
        2 - swap this value with the value at the start of the array
        3 - the first element is now sorted! 
            Redo your sort on the remaining elements (from index 1 to end)
            On the next iteration, you should be swapping the smallest remaining value 
                with the second index value in the array
            ...then swapping the smallest remaining value with the third indexed value... etc.
            
        4 - continue iterating until you reach the end of the list
        *** You can make this recursive, if you wish!
*/

void swap(double darray[], int a, int b) {
    // temp variable
    int temp;

    temp = darray[a];
    darray[a] = darray[b];
    darray[b] = temp;

}

int minFind(double darray[], int n) {
    // start
    double start = darray[0];
    //minimum index
    int mini;

    for(int index = 0; index < n; index++){
        if(darray[index] < start){
            start = darray[index];
            mini = index;
        }
    }
    return mini;
}

void newSort(double darray[], int n) {
    // minimum index
    int mini;
    
    // base
    if(n <= 1){
        return;
    }
    // general
    else if(n > 1){
        mini = minFind(darray, n);
        swap(darray, mini, 0);

        return newSort(darray+1, n-1);
    }
}
