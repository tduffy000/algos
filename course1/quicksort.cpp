/*
 * Testing environment for quicksort algorithm.
 */

#include "quicksort.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void printVector( vector<int> v ) {
  for( int i : v )
    cout << i << " ";
  cout << "\n";
}

int main() {
/*
  // TEST quickSort
  // medianOf3
  cout << "Testing median of 3\n";
  vector<int> a = {1, 5, 9, 2, 4, 6, 10, 15, 3};
  printVector( a );
  quickSort( a, "median" );
  printVector( a );

  // left pivot
  cout << "Testing first element pivot\n";
  vector<int> b = {3, 7 , 8, 2, 1, 6, 10, 12 , 4, 5};
  printVector( b );
  quickSort( b, "first" );
  printVector( b );

  // right pivot
  cout << "Testing last element pivot\n";
  vector<int> c = {9, 4, 5, 3, 1, 6, 12, 15, 7, 8, 2};
  printVector( c );
  quickSort( c, "last" );
  printVector( c );
*/
  // Question
  vector<int> nums( 10000, 0 );
  string ln;
  int counter = 0;
  ifstream myfile( "QuickSort.txt" );

  if( myfile.is_open() ) {

    while( getline( myfile, ln ) ) {
      int tmp = stoi( ln );
      nums[counter] = tmp;
      counter++;
    }
    myfile.close();
    cout << "Finished loading file!\n";
  } else cout << "Unable to read-in file\n";

  // make 2 copies of nums
  vector<int> numsTwo = nums;
  vector<int> numsThree = nums;

  // PIVOT V1
  quickSort( nums,  "first" );
  // PIVOT V2
  quickSort( numsTwo, "last" );
  // PIVOT V3
  quickSort( numsThree, "median");

  return 0;
}
