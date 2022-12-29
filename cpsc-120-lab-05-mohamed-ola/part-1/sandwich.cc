// Mohamed Khalifa
// CPSC 120-05
// 2022-10-06
// mkhalifa@csu.fullerton.edu
// @mkhalifa21-byte
//
// Lab 05-01
// Partners: @olasores
//
// This program makes a sandwich
//

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);
  
  // TODO: Validate that the number of arguments is correct.
  if (arguments.size() <= 3) {
    std::cout <<"Error" ;
  }
  // If not, print an error message and return a non-zero value.
 
  // TODO: Declare three std::string variables to hold the
  // protein, bread, and condiment input.
  // Initialize each variable with an element of the arguments vector
  // declared above.
 

  std::string PROTEIN{arguments[1]};
  std::string BREAD{arguments[2]};
  std::string CONDIMENT{arguments[3]};

  std::cout << "A " << arguments[1] << " sandwich on " << arguments[2] << " with " << arguments[3] << "\n";


  // TODO: Use cout to print output following the pattern
  // Your order: A *PROTEIN* sandwich on *BREAD* with *CONDIMENT*.
  // on its own line.

  return 0;
}
