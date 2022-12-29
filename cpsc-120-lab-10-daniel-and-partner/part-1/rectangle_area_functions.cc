// Daniel Marinca
// CPSC 120-10
// 2022-11-07
// dmarinca73@csu.fullerton.edu
// @DanielMarinca
//
// Lab 10-01
// Partners: @Olasores
//
// This program is a function for calculating the rectangle area.
//

int RectangleArea(int length, int width) {
  int area{0};
  if (length >= 0 && width >= 0) {
    area = length * width;
  }
  return area;
}
