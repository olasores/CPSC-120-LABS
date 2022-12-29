// Daniel Marinca
// CPSC 120-10
// 2022-12-01
// dmarinca73@csu.fullerton.edu
// @DanielMarinca
//
// Lab 12-01
// Partners: @Olasores
//
// This program is functions for a gradient color changer.
//

#include "animated_gradient_functions.h"

#include <cmath>
#include <iostream>

bool HasMatchingFileExtension(const std::string& file_name,
                              const std::string& extension) {
  if (file_name.size() >= extension.size()) {
    if ((file_name.compare((file_name.size() - extension.size()),
                           (extension.size()), extension)) == 0) {
      return true;
    }
  }
  return false;
}

std::vector<double> BuildSineLookupTable(int image_width) {
  std::vector<double> lookup_table;

  double radians = M_PI / image_width;

  for (int index = 0; index < image_width; index++) {
    double value = std::sin(radians * index);
    lookup_table.push_back(value);
  }
  return lookup_table;
}
