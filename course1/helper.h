/*
 * @author Thomas Duffy
 * Helper methods for testing searching/sorting algoritms.
 */

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <fstream>

using namespace std;

/* Print vectors out to CLI */
template <typename Comparable>
void printVector( vector<Comparable> v ) {
  for( Comparable i : v )
    cout << i << " ";
  cout << "\n";
}

/* Generate a random vector of ints for sorting testing */
vector<int> generateRandomVector( int count, int range, bool unique = true ) {
  vector<int> out(count, 0);
  if( unique && range < count )
    cout << "There aren't enough numbers in the range to make a unique vector of that size\n";
  int i = 0;
  while( i < count ) {
    int tmp = rand() % range;
    if( unique ) {
      if( std::find( out.begin(), out.end(), tmp ) == out.end() )
        out[i++] = tmp;
    } else {
      out[i++] = tmp;
    }
  }
  return out;
}

/* Load-in int source vector file(s) from .txt */
vector<int> readIn( string fileName, int size ) {
  vector<int> out(size , 0);
  string ln;
  int counter = 0;
  ifstream myfile( fileName );

  if( myfile.is_open() ) {
    while( getline( myfile, ln ) ) {
      int tmp = stoi( ln );
      out[counter++] = tmp;
    }
    myfile.close();
    cout << "Finished loading file!\n";
  } else cout << "Unable to read-in file\n";
  return out;
}
