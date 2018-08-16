/*
 * Testing environment for inversion counter (merge sort derived) algorithm.
 */

#include "inversion_counter.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printVector( vector<int> v ) {
  for( int i : v )
    cout << i << " ";
  cout << "\n";
}

int main() {
  // test case 1: mergeSortAndCount  
  vector<int> a = { 1, 5, 9, 2, 7, 3, 10, 4, 15 };
  cout << "Unsorted array: ";
  printVector( a );
  mergeSortAndCount( a );
  cout << "Sorted array: ";
  printVector( a );

  // test case 2
  vector<int> b = { 1, 3, 5, 2, 4, 6 };
  cout << "Unsorted array: ";
  printVector( b );
  mergeSortAndCount( b );
  cout << "Sorted array: ";
  printVector( b );

  // quiz case
  vector<int> nums(100000, 0);
  string ln;
  int counter = 0;
  ifstream myfile( "IntegerArray.txt" );
  
  if( myfile.is_open() ) {

    string progress = "";
    while( getline( myfile, ln ) ) {
      
      int tmp = stoi( ln );
      nums[counter] = tmp;
      counter++;
      if( counter % 5000 == 0 ){
	progress += "#";
	cout << progress << "\n";
      }
    }
    myfile.close();
    cout << "Finished loading file!\n";
  } else cout << "Unable to read-in file\n";

  mergeSortAndCount( nums );
  
  return 0;
}
