/*
 * Testing environment for mergesort algorithm.
 */

#include "mergesort.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

void printVector( vector<int> v ) {
  for( int i : v )
    cout << i << " ";
  cout << "\n";
}

int main() {
  // test case 1: mergeSort  
  vector<int> a = {1, 5, 9, 2, 7, 3, 10, 4, 15};
  printVector( a );
  mergeSort( a );
  printVector( a );
  
  // test case 2: insertionSort

  // test case 3: selectionSort
  return 0;
}
