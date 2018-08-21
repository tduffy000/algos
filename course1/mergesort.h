#ifndef MERGE_SORT
#define MERGE_SORT

#include "helper.h"
#include <vector>
#include <functional>

using namespace std;

/**
 * Implementation method that merges two sorted sub-arrays into one.
 * @param a is an array of Comparable objects
 * @param tmp is the array where to merged result is placed
 * @param leftPos is the left-most index of the sub-array
 * @param rightPos is the index of the start of the right half of the sub-array
 * @param end is the right-most index of the sub-array
 */
template <typename Comparable>
void mergeVectors( vector<Comparable> & a, vector<Comparable> & tmp, int leftPos, int rightPos, int end ) {
  int leftEnd = rightPos - 1;
  int tmpPos = leftPos;
  int n = end - leftPos + 1;

  while( leftPos <= leftEnd && rightPos <= end ) {

    if( a[leftPos] <= a[rightPos] ) {
      tmp[tmpPos++] = std::move( a[leftPos++] );
    } else {
      tmp[tmpPos++] = std::move( a[rightPos++] );
    }
  }

  while( leftPos <= leftEnd ) {
    tmp[tmpPos++] = std::move( a[leftPos++] );
  }

  while( rightPos <= end ) {
    tmp[tmpPos++] = std::move( a[rightPos++] );
  }

  for( int i = 0; i < n; ++i, --end ) {
    a[ end ] = std::move( tmp[end] );
  }
}

/**
 * Implementation method that makes recursive calls to mergeSort an array.
 * @param a is an unsorted array of Comparable objects.
 * @param tmp is the array where the sorted array is placed.
 * @param left is the left-most index of an object in the sub-array.
 * @param right is the right-most index of an object in the sub-array.
 */
template <typename Comparable>
void mergeSort( vector<Comparable> & a, vector<Comparable> & tmp, int left, int right ) {
  if( left < right ) {
    int mid = (left + right) / 2;

    mergeSort(a, tmp, left, mid);
    mergeSort(a, tmp, mid + 1, right);
    mergeVectors(a, tmp, left, mid + 1, right);
  }
}

/**
 * Calls the mergeSort algorithm on an array.
 * @param a is an unsorted array of Comparable objects that we want to sort.
 */
template <typename Comparable>
void mergeSort( vector<Comparable> & a ) {
  vector<Comparable> tmp( a.size() );
  mergeSort( a, tmp, 0, a.size() - 1 );
}

#endif
