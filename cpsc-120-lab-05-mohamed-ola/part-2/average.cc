// Mohamed Khalifa
// CPSC 120-05
// 2022-10-06
// mkhalifa@csu.fullerton.edu
// @mkhalifa21-byte
//
// Lab 05-02
// Partners: @olasores
//
// This program calculates average
//

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
   std::vector<std::string> arguments(argv, argv + argc);
   if (arguments.size() <= 1) {
     std::cout << "Error ";
    }
   double sum(0.0);
   bool first = true;
   for (std::string& argument : arguments) {
     if (first) {
       first = false;
       continue;
     }
     sum += std::stod(argument);
   }
   std::cout << "Average = " << double(sum) / double(arguments.size() - 1);
   std::cout << "\n";
   return 0;
 }
