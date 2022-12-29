// Oyinkansola Olayinka
// CPSC 120-10
// 2022-11-04
// oyinkansola11@csu.fullerton.edu
// @olasores
//
// Lab 09-01
// Partners: @Julianizceja
//
// This program checks for average of numbers.
//

#include <iostream>
#include <string>
#include <vector>

double JudgeAverage(const std::vector<double>& scores) {
  double mininmum = scores[0];
  double maximum = scores[0];
  double total = 0.0;

  for (const double& score : scores) {
    if (score < mininmum) {
      mininmum = score;
    }
  }
  for (const double& score : scores) {
    if (score > maximum) {
      maximum = score;
    }
  }
  for (const double& score : scores) {
    total += score;
  }
  total = total - mininmum - maximum;
  return total / double(scores.size() - 2);
}
int main(int argc, char* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);
  if (arguments.size() <= 3) {
    std::cout << "error: you must give at least three scores \n";
    return 1;
  }

  std::vector<double> scores;
  double number{0.0};
  for (int i = 1; i < arguments.size(); i++) {
    number = std::stod(arguments.at(i));
    scores.push_back(number);
    std::string number = arguments.at(i);
  }

  double average = JudgeAverage(scores);
  std::cout << "average is " << average << std::endl;
  return 0;
}