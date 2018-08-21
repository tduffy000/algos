#ifndef MULTIPLICATION
#define MULTIPLICATION

#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <stdexcept>

// UPDATE TO INCLUDE MINUS OPERATION
// https://www.geeksforgeeks.org/divide-and-conquer-set-2-karatsuba-algorithm-for-fast-multiplication/
// https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/
// Debug

using namespace std;

/**
 * Recursively check if string representations of operands a and b
 * are of equal length, appending zeros to beginning of shorter until they are.
 * @param a is the string representation of the first operand
 * @param b is the string representation of the second operand
 */
bool checkLengths(string & a, string & b) {

  // base case -> a and b of equal length
  if( a.length() == b.length() ) {
    return true;
  }

  if( a.length() < b.length() ) {
    a.insert(0, "0");
    return checkLengths(a, b);
  } else {
    b.insert(0, "0");
    return checkLengths(a, b);
  }
}


// change to ignore not just first digit place for zeroes
/**
 * Convert a vector of digits (strings) to a single string
 * representation of a number.
 * @param v the vector to be transformed
 * @return the string representation of the number
 */
string vecToString( vector<string> v ) {
  int start;
  for( int i = 0; i < v.size(); i++ ) {
    if( v[i] != "0" ) {
      start = i;
      break;
    }
  }
  string s;
  for( int j = start; j < v.size(); j++ )
    s += v[j];
  return s;
}

/**
 * Sum the string representations of two integers together. Helper method
 * for some multiplication routines.
 * @param a the string representation of the first operand
 * @param b the string representation of the second operand
 * @return a vector representation (element for each place) of the sum (a + b)
 */
string sumStrings(string a, string b) {

  // force a to be longer so as not to check at each step (remove to optimize)
  if( a.size() < b.size() )
    swap( a,b );
  vector<string> result( a.size() + 1, "0" );

  // sum the overlap of a & b
  int i = a.size() - 1;
  for( int j = b.size() - 1; j >= 0; j--, i-- ) {
    int x = a[i] - 48;
    int y = b[j] - 48;
    int tmpSum = x + y + stoi( result[i + 1] );
    result[i + 1] = to_string( tmpSum % 10 );
    result[i] = to_string( tmpSum / 10 );
  }

  // pull over remaining of a w/o leaving final carried behind
  for(int k = a.size() - b.size() - 1; k >= 0; k-- ) {
    int x = a[k] - 48;
    int tmpSum = x + stoi( result[k + 1] );
    result[k + 1] = to_string( tmpSum % 10 );
    result[k] = to_string( tmpSum / 10 );
  }

  return vecToString( result );
}

/**
 * Helper method to multiply single digit represented as strings.
 * @param a the first operand
 * @param b the second operand
 * @return the product of a and b
 * @throw invalid_argument if a and b are not single digits
 */
string singleMultiply( string a, string b ) {
  if( a.length() > 1 || b.length () > 1 ) {
    throw std::invalid_argument( "A and B must be single digits!" );
  }
  vector<string> result( 2, "0" );
  int x = a[0] - 48;
  int y = b[0] - 48;
  int prod = x * y;
  result[1] = to_string( prod % 10 );
  result[0] = to_string( prod / 10 );
  return vecToString( result );
}

/**
 *
 */
/*
string gradeSchoolMultiply( string a, string b ) {
  checkLengths( a, b );
  string result = "0";
  int shift = 0;
  vector<string> rowResult( 2 * a.length() + 1, "0" );
  for( int i = 0; i < a.length(); i++ ) {

    result = sumStrings( result, rowResult );
    vector<string> rowResult( 2 * a.length() + 1, "0" );

    for( int j = 0; j < b.length(); j++ ) {

      int prod = std::stoi(a[i], nullptr) * std::stoi(b[j], nullptr);
      int digit = prod % 10;
      int carry = (prod - digit) / 10;

      // add prod to sum for row

      // move carry over to next part of b
    }
  }
  return result;
}
*/
/* ###########
   ## TO DO ##
   ###########
*/

/**
 * Implementation of Karatsuba's algorithm for Integer multiplication.
 * @param a is the string representation of the first operand
 * @param b is the string representation of the second operand
 * @return a string representation of the product of a and b
 */
/*
string karatsubaMultiply(string a, string b) {
  checkLengths(a, b);
  vector<int> result( 2 * a.length(), 0 );
  return "null";
}
*/

/**
 * Implementation of a recursive algorithm for Integer multiplication.
 * @param a is the string representation of the first operand
 * @param b is the string representation of the second operand
 * @return a string representation of the product of a and b
 */
/*
string recursiveMultiply(string a, string b) {
  checkLengths(a, b);
  vector<int> result( 2 * a.length(), 0);
  return "null";
}
*/

/**
 * Converts a string representation of an integer to base 2.
 * @param a is the string representation of the base 10 operand
 * @return a string representation of a in base 2.
 */
/*
string toBase2(string a) {
  return "null";
}
*/

/**
 * Implementation of a recursive algorithm for Integer multiplication
 * translating the base 10 input into base 2 to perform operations.
 * @param a is the string representation of the first operand
 * @param b is the string representation of the second operand
 * @return a string representation of the product of a and b
 */
/*
string base2Multiply(string a, string b) {
  checkLengths(a, b);
  vector<int> result( 2 * a.length(), 0);
  return "null";

}
*/
#endif
