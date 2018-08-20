/*
 * Helper methods for testing.
 */

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Print vectors out to CLI.
 */
template <typename Comparable>
void printVector( vector<Comparable> v )
  for( Comparable i : v )
    cout << i << " ";
  cout << "\n";
}

/**
 * Generate a random vector of ints for sorting testing.
 */
vector<int> generateRandom( int count, int range, bool unique ) {
  vector<int> out(count, 0);
  if( unique && range > count )
    cout << "There aren't enough numbers in the range to make a unique vector of that size\n";

  while( int i = 0; i < count; i++ ) {
    tmp = rand() % range;

    if( unique ) {
      if( std::find( out.begin(), out.end(), tmp ) != out.end() )
        out[i] = tmp;
    } else {
      out[i] = tmp;
    }
  }
  return out;
}

/**
 * Load-in int source files from .txt
 */
vector<int> readIn( string fileName ) {
  vector<int> out;
  string ln;
  int counter = 0;
  ifstream myfile( fileName );

  if( myfile.is_open() ) {
    while( getline( myfile, ln ) ) {
      int tmp = stoi( ln );
      nums[counter++] = tmp;
    }
    myfile.close();
    cout << "Finished loading file!\n";
  } else cout << "Unable to read-in file\n";
  return out;
}
