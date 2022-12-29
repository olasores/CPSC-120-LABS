// Oyinkansola Olayinka
// CPSC 120-10
// 2022-10-13
// Oyinkansola11@csu.fullerton.edu
// @olasores
//
// Lab 06-01
// Partners: @mkhalifa21-byte
//
// This is a program to check for patterns
//

#include <iostream>

int k_counter_max = 22;

int main(int argc, char const *argv[]) {
  for (int num = 0; num < k_counter_max; num++) {
    for (int num_2 = num; num_2 > 0; num_2--) {
      std::cout << "-";
    }
    std::cout << "*";

    for (int num_3 = num; num_3 < k_counter_max; num_3++) {
      std::cout << "|";
    }
    std::cout << "\n";
  }

  return 0;
}
