// Mohamed Khalifa
// CPSC 120-05
// 2022-10-06
// mkhalifa@csu.fullerton.edu
// @mkhalifa21-byte
//
// Lab 05-03
// Partners: @olasores
//
// This program calculates black jack
//

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);
  int score = 0;
  for (int i = 1; i < arguments.size(); i++) {
    if (arguments[i] == "A") {
      if (score + 11 > 21) {
        score += 1;
      } else if (score + 11 <= 21) {
        score += 11;
      }

    } else if (arguments[i] == "Q" || arguments[i] == "K" || arguments[i] == "J") {
      score += 10;
    } else if (stoi(arguments[i]) <= 10 && stoi(arguments[i]) >= 2) {
      score += stoi(arguments[i]);
    } else {
      std::cout << "error: unknown card"
                << "'" << arguments[i] << "'\n";
      return 1;
    }
  }
  if (score > 21) {
    std::cout << "Score is " << score << ",BUST\n";
  } else {
    std::cout << "Score is " << score << "\n";
  }

  return 0;
}