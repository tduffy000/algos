/*
 * @author Thomas Duffy
 * Testing environment for quicksort algorithm.
 */

#include "quicksort.h"
#include "helper.h"
#include <vector>
#include <iostream>
#include <fstream>


using namespace std;

int main() {

  // TEST quickSort
  cout << "First test: \n";
  vector<int> a = generateRandomVector( 15, 30 );
  printVector( a );
  quickSort( a, "first", true );
  printVector( a );

  cout << "Second test: \n";
  vector<int> b = {3, 7 , 8, 2, 1, 6, 10, 12 , 4, 5};
  printVector( b );
  quickSort( b );
  printVector( b );

  cout << "Third test: \n";
  vector<int> c = {9, 4, 5, 3, 1, 6, 12, 15, 7, 8, 2};
  printVector( c );
  quickSort( c, "random", true);
  printVector( c );

  // QUIZ Question
  vector<int> nums = readIn( "QuickSort.txt", 10000 );
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
