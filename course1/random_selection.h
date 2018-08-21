#ifndef RANDOMSELECT
#define RANDOMSELECT

#include <vector>
#include <iostream>
#include <stdlib.h>
#include "helper.h"
#include "quicksort.h"

using namespace std;

/**
 * Implement a random selector to find the ith order static of an input array a.
 */
template <typename Comparable>
Comparable randomSelect( vector<Comparable> & a, int left, int right, int n, int i ) {
  // base case, array size = 1
  if( right <= left ) {
    return a[right];
  }

  int partIdx = partition( a, left, right, "random" );

  if( partIdx == i ) {
    return a[partIdx];
  } else if( partIdx < i ) {
    return randomSelect( a, left, partIdx - 1 );
  } else if( partIdx > i) { // need else if?
    return randomSelect( a, partIdx + 1, right );
  }
}
