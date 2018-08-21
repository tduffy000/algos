/**
 * Testing environment for the sum & multiplication implementations.
 */

#include "multiplication.h"
#include <iostream>

using namespace std;

int main() {

  string a = "3141592653589793238462643383279502884197169399375105820974944592";
  string b = "2718281828459045235360287471352662497757247093699959574966967627";

  // string result = multiply( a , b );

  // can check it here --> https://www.javascripter.net/math/calculators/100digitbigintcalculator.htm
  string answer = "8539734222673567065463550869546574495034888535765114961879601127067743044893204848617875072216249073013374895871952806582723184";

  cout << "Answer should be: \n" << answer << "\n";

  return 0;
}
