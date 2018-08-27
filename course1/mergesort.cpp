/*
 * @author Thomas Duffy
 * Testing environment for mergesort algorithm.
 */

#include "mergesort.h"
#include "helper.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {

  // test case 1: mergeSort
  vector<int> a = {1, 5, 9, 2, 7, 3, 10, 4, 15};
  printVector( a );
  mergeSort( a );
  printVector( a );

  return 0;
}
