// Daniel Marinca
// CPSC 120-10
// 2022-11-15
// dmarinca73@csu.fullerton.edu
// @DanielMarinca
//
// Lab 11-01
// Partners: @Olasores
//
// This program calculates the densities of different states.
//

#include "states.h"

#include <fstream>

std::vector<std::vector<std::string>> ReadCSV(const std::string& csv_filename,
                                              int columns) {
  std::vector<std::vector<std::string>> table;
  std::ifstream file(csv_filename);

  // read each row
  while (file.good()) {
    std::vector<std::string> row;
    // read each column
    for (int i = 0; i < columns; ++i) {
      std::string cell;
      file.ignore(1, '"');  // leading quote
      std::getline(file, cell, '"');
      if (i < (columns - 1)) {
        file.ignore(1, ',');  // comma
      }
      row.push_back(cell);
    }
    if (file.good()) {
      table.push_back(row);
    }
  }

  return table;
}

State::State(const std::string& name, int population, double land_area)
    : name_(name), population_(population), land_area_(land_area) {}

State::State() : name_(""), population_(0), land_area_(0.0) {}

const std::string& State::Name() const { return name_; }

int State::Population() const { return population_; }

double State::LandArea() const { return land_area_; }

double State::PopulationDensity() const {
  double population_density{0};
  population_density = population_ / land_area_;
  return population_density;
}

std::vector<State> ReadStates(const std::string& csv_filename) {
  std::vector<State> states_vector;
  std::vector<std::vector<std::string>> readcsv;
  readcsv = ReadCSV(csv_filename, 48);
  for (int index = 1; index < readcsv.size(); index++) {
    int population{0};
    double land_area{0};
    std::string name{readcsv.at(index).at(0)};
    std::string temp_population{readcsv.at(index).at(2)};
    population = std::stoi(temp_population);
    std::string temp_land_area{readcsv.at(index).at(47)};
    land_area = std::stod(temp_land_area);
    State state{name, population, land_area};
    states_vector.push_back(state);
  }

  return states_vector;
}
