// Oyinkansola Olayinka
// CPSC 120-10
// 2022-09-01
// oyinkansola11@csu.fullerton.edu
// @olasores
//
// Lab 02-01
// Partners: @ldt4me
//
// Converts fahrenheit to celsius.
//

#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  // For integer variables assigning them 0 or other integer value is a good
  // practice. For doubles and floats using NAN which means 'not a number' is a
  // good value to use.
  int fahrenheit = 0;
  double celsius = NAN;
  fahrenheit = 451;
  celsius = fahrenheit * 9.0 / 5.0 + 32.0;
  cout << fahrenheit << " degrees Fahrenheit is " << celsius
       << " degrees Celsius.\n";
  return 0;
}