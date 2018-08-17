#ifndef QUICKSORT
#define QUICKSORT

#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

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

static int CUTOFF = 1; // pass from quick to insertion sort

/**
 * QuickSort using the first (left-most) position as the pivot.
 */
template <typename Comparable>
void quickSortFirst( vector<Comparable> & a, int left, int right ) {

    if( left + CUTOFF <= right ) {
      comparisons += right - left;
      const Comparable & pivot = a[left];
      int i = left + 1, j = right;

      while( i < j ) {

        // walk over i & j until both find values on wrong side
        while( a[++i] < pivot ) { }
        while( pivot < a[--j] ) { }
        // change places!
        std::swap( a[i], a[j] );
      }

      // put the pivot back
      std::swap( a[i], a[left] );

      quickSortFirst( a, left, i - 1 );
      quickSortFirst( a, i + 1, right );
    }
    // call insertion sort under threshold (CUTOFF)
    else
      insertionSort( a );
}

/**
 * QuickSort using the last (right-most) position as the pivot.
 */
template <typename Comparable>
void quickSortLast( vector<Comparable> & a, int left, int right ) {

    if( left + CUTOFF <= right ) {
      const Comparable & pivot = a[right];
      int i = left, j = right - 1;

      while( i < j ) {

        // walk over i & j until both find values on wrong side
        while( a[++i] < pivot ) { }
        while( pivot < a[--j] ) { }
        // change places!
        std::swap( a[i], a[j] );
      }

      // put the pivot back
      std::swap( a[i], a[right] );

      quickSortLast( a, left, i - 1 );
      quickSortLast( a, i + 1, right );
    }
    // call insertion sort under threshold (CUTOFF)
    else
      insertionSort( a );
}

/**
 * Return the median of the left-most, right-most, and middle (int division)
 * elements of a. Move the pivot over in a.
 * @param a the array to be sorted
 * @param left the index of the left-most element of the sub-array
 * @param right the index of the right-most element of the sub-array
 */
template <typename Comparable>
const Comparable & medianOf3( vector<Comparable> & a, int left, int right ) {

  int mid = ( left + right ) / 2;
  if( a[mid] < a[left] )
    std::swap( a[left], a[mid] );
  if( a[right] < a[left] )
    std::swap( a[left], a[right] );
  if( a[right] < a[mid] )
    std::swap( a[mid], a[right] );

  std::swap( a[mid], a[right - 1] );
  return a[right - 1];
}

/**
 * Heavy lifter of quickSort recursive implementation of picking
 * medianOf3 to create pivot and then sorting left and right sub-
 * arrays, passing to insertionSort if the sub-array size falls below
 * the global CUTOFF.
 * @param a is the vector of Comparable objects to be sorted.
 * @param left is the left-most index of the sub-array
 * @param right is the right-most index of the sub-array
 * @return a is then sorted using quickSort/insertionSort hybrid.
 */
template <typename Comparable>
void quickSortMedian( vector<Comparable> & a, int left, int right ) {

  if( left + CUTOFF <= right ) {
    // find the pivot & swap
    const Comparable & pivot = medianOf3( a, left, right );
    int i = left, j = right - 1;

    while( i < j ) {

      // walk over i & j until both find values on wrong side
      while( a[++i] < pivot ) { }
      while( pivot < a[--j] ) { }
      // change places!
      std::swap( a[i], a[j] );
    }

    // put the pivot back
    std::swap( a[i], a[right - 1] );

    quickSortMedian( a, left, i - 1 );
    quickSortMedian( a, i + 1, right );
  }
  // call insertion sort under threshold (CUTOFF)
  else
    insertionSort( a );
}

template <typename Comparable>
void quickSortRandom( vector<Comparable> & a, int left, int right ) {

  if( left + CUTOFF <= right ) {
    // find the pivot & swap
    int randomPos = std::rand() % ( a.size() - 1 );
    std::swap( a[randomPos], a[right] );
    const Comparable & pivot = a[right];
    int i = left, j = right - 1;

    while( i < j ) {

      // walk over i & j until both find values on wrong side
      while( a[++i] < pivot ) { }
      while( pivot < a[--j] ) { }
      // change places!
      std::swap( a[i], a[j] );
    }

    // put the pivot back
    std::swap( a[i], a[right] );

    quickSortRandom( a, left, i - 1 );
    quickSortRandom( a, i + 1, right );
  }
  // call insertion sort under threshold (CUTOFF)
  else
    insertionSort( a );
}

/**
 * Public implementer of quickSort on an unordered vector of
 * Comparable objects, using 3 possible pivot finder implementations.
 * @param a is a vector of unordered Comparable objects
 * @param pivotType is the method for selecting the pivot element of a.
 * @return a gets ordered by natural ordering.
 */
template <typename Comparable>
void quickSort( vector<Comparable> & a, string pivotType ) {
  comparisons = 0;

  if( pivotType == "first" ) {
    quickSortFirst( a, 0, a.size() - 1);
  } else if( pivotType == "last" ) {
    quickSortLast( a, 0, a.size() - 1);
  } else if( pivotType == "median" ) {
    quickSortMedian( a, 0, a.size() - 1);
  } else if( pivotType == "random" ) {
    quickSortRandom( a, 0, a.size() - 1);
  } else cout << "That is not a valid pivot type!\n";

  cout << comparisons << " comparisons were performed\n";
}

#endif
