#ifndef MERGE_SORT
#define MERGE_SORT
#endif

#include <vector>
#include <iostream>

using namespace std;

/**
   Implementation method that makes recursive calls to mergeSort an array. 
   @param a is an unsorted array of Comparable objects.
   @param tmp is the array where the sorted array is placed.
   @param left is the left-most index of an object in the sub-array.
   @param right is the right-most index of an object in the sub-array.
*/
template <typename Comparable>
void mergeSort( vector<Comparable> & a, vector<Comparable> tmp, int left,
		int right) {
  if( left < right ) {
    int mid = (left + right) / 2;
    // split into two (left & right) sub-arrays
    mergeSort(a, tmp, left, mid);
    mergeSort(a, tmp, mid + 1, right);
    // merge sorted sub-arrays together
    merge(a, tmp, left, mid + 1, right);
  }
}

/**
   Calls the mergeSort algorithm on an array.
   @param a is an unsorted array of Comparable objects that we want to sort.
*/
template<typename Comparable>
void mergeSort( vector<Comparable> & a) {
  vector<Comparable> tmp( a.size() );
  mergeSort( a, tmp, 0, a.size() - 1 );
}

/**
   Implementation method that merges two sorted sub-arrays into one.
   @param a is an array of Comparable objects
   @param tmp is the array where to merged result is placed
   @param leftPos is the left-most index of the sub-array
   @param rightPos is the index of the start of the right half of the sub-array
   @param end is the right-most index of the sub-array
*/
template<typename Comparable>
void merge( vector<Comparable> a, vector<Comparable> tmp, int leftPos, int rightPos, int end ) {
  int leftEnd = rightPos - 1;
  int tmpPos = leftPos;
  int n = end - leftPos + 1;

  // while both sub-arrays are not empty
  while( leftPos <= leftEnd && rightPos <= end ) {

    if( a[leftPos] <= a[rightPos] ) {
      tmp[tmpPos++] = std::move( a[leftPos++] );
    } else {
      tmp[tmpPos++] = std::move( a[rightPos++] );
    }
  }
  // now fill with remaining non-empty sub-array
  // whichever did not break above loop
  while( leftPos <= leftEnd ) {
    tmp[tmpPos++] = std::move( a[leftPos++] );
  }

  while( rightPos <= end ) {
    tmp[tmpPos++] = std::move( a[rightPos++] );
  }

  // over-write a with tmp results
  for( int i = 0; i < n; ++i ) {
    a[ --end ] = std::move( tmp[end] );
  }
}
