// Daniel Marinca
// CPSC 120-10
// 2022-11-10
// dmarinca73@csu.fullerton.edu
// @DanielMarinca
//
// Lab 10-02
// Partners: @Olasores
//
// This program is a function for printing out county populations.
//

#include "counties_functions.h"

std::string AllCountiesString(
    const std::vector<std::vector<std::string>>& ca_counties) {
  std::string all_counties_string;
  for (auto const& elem : ca_counties.at(0)) {
    all_counties_string += elem + " ";
  }
  return all_counties_string;
}

int CountyIndex(const std::vector<std::vector<std::string>>& ca_counties,
                const std::string& match_county) {
  int index{-1};
  for (int index = 0; index < ca_counties.at(0).size(); index++) {
    if (ca_counties.at(0).at(index) == match_county) {
      return index;
    }
  }
  return index;
}
