// Daniel Marinca
// CPSC 120-10
// 2022-11-07
// dmarinca73@csu.fullerton.edu
// @DanielMarinca
//
// Lab 10-01
// Partners: @Olasores
//
// This program calculates the area of a rectangle.
//

#include <iostream>
#include <string>
#include <vector>

#include "rectangle_area_functions.h"

int main(int argc, char const* argv[]) {
  std::vector<std::string> args{argv, argv + argc};
  if (args.size() < 3) {
    std::cout << "Please provide two arguments, a rectangle's length and "
                 "width.\nFor example:\n./rectangle_area 23 17\n";
    return 1;
  }

  try {
    int length = std::stoi(args.at(1));
    int width = std::stoi(args.at(2));
    int area = RectangleArea(length, width);

    std::cout << length << " x " << width << " = " << area << "\n";

    return 0;

  } catch (std::exception& ex) {
    std::cout << "There was a problem reading the input numbers\n";
    return 1;
  }
}