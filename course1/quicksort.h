/**
 * @author Thomas Duffy
 * Implementation of QuickSort based on 4 separate pivot-selection strategies.
 */

#ifndef QUICKSORT
#define QUICKSORT

#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

static long long comparisons;
static int CUTOFF = 3; // pass from quick to insertion sort (in Hybrid)

/* Return the first element of array a which is the pivot */
template <typename Comparable>
Comparable & firstElementToPivot( vector<Comparable> & a, int left, int right ) {
  return a[left];
}

/* Swap the last element and first element of array a to use as pivot */
template <typename Comparable>
void lastElementToPivot( vector<Comparable> & a, int left, int right ) {
  std::swap( a[left], a[right] );
}

/**
 * Return the median of the left-most, right-most, and middle (int division)
 * elements of a. Move the pivot over to left-most of a.
 */
template <typename Comparable>
void medianOf3ToPivot( vector<Comparable> & a, int left, int right ) {

  int mid = ( left + right ) / 2;
  if( a[mid] < a[left] )
    std::swap( a[left], a[mid] );
  if( a[right] < a[left] )
    std::swap( a[left], a[right] );
  if( a[right] < a[mid] )
    std::swap( a[mid], a[right] );

  std::swap( a[left], a[mid] );
}

/* Swap a random element and the first element of array a to use as a pivot */
template <typename Comparable>
void randomElementToPivot( vector<Comparable> & a, int left, int right ) {
  int randomPos = rand() % ( right - left );
  std::swap( a[left], a[randomPos] );
}

/**
 * Perform insertion sort on an array a.
 * @param a is the array to be sorted.
 * @return a is then sorted by its natural ordering.
 */
template <typename Comparable>
void insertionSort( vector<Comparable> & a ) {
  for( int i = 1; i < a.size( ); ++i ) {
    Comparable tmp = std::move( a[i] );
    int j;
    for( j = i; j > 0 && tmp < a[j - 1]; --j )
      a[j] = std::move( a[j-1] );
    a[j] = std::move( tmp );
  }
}

/**
 * Perform the partition sub-routine for an array a to section everything larger
 * or smaller than the pivot.
 * @param a is the array to be sorted
 * @param left, right are the left-most and right-most indices in a
 * @param pivotType defines how to pick the pivot element
 * @return the index of the pivot element in a
 */
template <typename Comparable>
int partition( vector<Comparable> & a, int left, int right, string pivotType ) {
  // pre-processing re-arrangement steps (if pivot != left-most element)
  if( pivotType == "last" ) {
    lastElementToPivot( a, left, right );
  } else if( pivotType == "median" ) {
    medianOf3ToPivot( a, left, right );
  } else if( pivotType == "random" ) {
    randomElementToPivot( a, left, right );
  }
  const Comparable & pivot = firstElementToPivot( a, left, right );

  int i = left;
  for( int j = left + 1; j <= right; j++ ) {
    if( a[j] <= pivot ) {
      std::swap( a[++i], a[j] );
    }
  }

  std::swap( a[left], a[i] );  // restore pivot
  return i;
}

/* Implementation method of quickSort that makes recursive calls */
template<typename Comparable>
void quickSort( vector<Comparable> & a, int left, int right, string pivotType ) {
  // BASE CASE: two element array
  if( right - left == 1 ) {
    if( a[right] < a[left] ) {
      std::swap( a[left], a[right] );
    }
    comparisons++;
  } else if( right <= left) {
    // BASE CASE: one element array: do nothing
  } else {
      comparisons += right - left;
      int partIdx = partition( a, left, right, pivotType );
      quickSort( a, left, partIdx - 1, pivotType );
      quickSort( a, partIdx + 1, right, pivotType );
  }
}

/* Implementation method of quickSort using pass-off to insertionSort method */
template<typename Comparable>
void quickSortHybrid( vector<Comparable> & a, int left, int right, string pivotType ) {
  // BASE CASE: pass to insertionSort
  comparisons += right - left;
  if( left + CUTOFF <= right )
    insertionSort( a );
  else {
    int partIdx = partition( a, left, right, pivotType );
    quickSortHybrid( a, left, partIdx - 1, pivotType );
    quickSortHybrid( a, partIdx + 1, right, pivotType );
  }
}

/**
 * Public implementer of quickSort on an unordered vector of
 * Comparable objects, using 3 possible pivot finder implementations.
 * @param a is a vector of unordered Comparable objects
 * @param pivotType is the method for selecting the pivot element of a.
 * @param hybrid defines whether or not to use pass-off to insertionSort method.
 * @return a ordered by natural ordering.
 */
template <typename Comparable>
void quickSort( vector<Comparable> & a, string pivotType = "first", bool hybrid = false ) {
  comparisons = 0;
  if( !hybrid )
    quickSort( a, 0, a.size() - 1, pivotType );
  else
    quickSortHybrid( a, 0, a.size() - 1, pivotType );
  cout << "Performed " << comparisons << " comparisons\n";
}

#endif
