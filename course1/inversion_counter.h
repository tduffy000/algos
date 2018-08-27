/**
 * @author Thomas Duffy
 * Implementation of inversion counter when using mergeSort to sort vectors.
 */

#ifndef INVERSION_COUNTER
#define INVERSION_COUNTER

#include <vector>
#include <functional>
#include <iostream>

using namespace std;

static long long inversions;  // global count of inversions

/**
 * Implementation method that merges two sorted sub-arrays into one.
 * @param a is an array of Comparable objects
 * @param tmp is the array where to merged result is placed
 * @param leftPos is the left-most index of the sub-array
 * @param rightPos is the index of the start of the right half of the sub-array
 * @param end is the right-most index of the sub-array
 */
template <typename Comparable>
void mergeVectorsAndCount( vector<Comparable> & a, vector<Comparable> & tmp, int leftPos, int rightPos, int end ) {
  int leftEnd = rightPos - 1;
  int tmpPos = leftPos;
  int n = end - leftPos + 1;

  while( leftPos <= leftEnd && rightPos <= end ) {

    if( a[leftPos] <= a[rightPos] ) {
      tmp[tmpPos++] = std::move( a[leftPos++] );
    } else {
      tmp[tmpPos++] = std::move( a[rightPos++] );
      inversions += leftEnd - leftPos + 1;
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
void mergeSortAndCount( vector<Comparable> & a, vector<Comparable> & tmp, int left, int right ) {
  if( left < right ) {
    int mid = (left + right) / 2;

    mergeSortAndCount(a, tmp, left, mid);
    mergeSortAndCount(a, tmp, mid + 1, right);
    mergeVectorsAndCount(a, tmp, left, mid + 1, right);
  }
}

/* Calls the mergeSort algorithm on an (un)sorted vector. */
template <typename Comparable>
void mergeSortAndCount( vector<Comparable> & a ) {
  inversions = 0;
  vector<Comparable> tmp( a.size() );
  mergeSortAndCount( a, tmp, 0, a.size() - 1 );
  cout << "Number of inversions: " << inversions << "\n";
}

#endif
