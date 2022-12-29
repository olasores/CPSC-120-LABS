// Daniel Marinca
// CPSC 120-10
// 2022-11-10
// dmarinca73@csu.fullerton.edu
// @DanielMarinca
//
// Lab 10-03
// Partners: @Olasores
//
// This program is a function for printing out a gradient image.
//

#include "gradient_functions.h"

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
