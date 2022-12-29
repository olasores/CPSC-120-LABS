// Daniel Marinca
// CPSC 120-10
// 2022-12-01
// dmarinca73@csu.fullerton.edu
// @DanielMarinca
//
// Lab 12-01
// Partners: @Olasores
//
// This program creates a moving gradient image.
//

#include <Magick++.h>

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "animated_gradient_functions.h"

const int kImageWidth{512};
const int kImageHeight{512};
const int kNumberOfImages = 10;

int main(int argc, char* argv[]) {
  Magick::InitializeMagick(*argv);

  std::vector<std::string> arguments{argv, argv + argc};

  try {
    std::string output_file_name{arguments.at(1)};
    std::string extension{".gif"};

    if (!HasMatchingFileExtension(output_file_name, extension)) {
      std::cout << output_file_name
                << " is missing the required file extension .gif.\n";
      return 1;
    }

    int image_width{kImageWidth};
    std::vector<double> sine_lookup_table;
    sine_lookup_table = BuildSineLookupTable(image_width);

    Magick::ColorRGB white{1, 1, 1};

    std::vector<Magick::Image> images;

    double blue_step{M_PI / double(kNumberOfImages)};
    int row_col_step{kImageWidth / kNumberOfImages};

    for (int current_image = 0; current_image < kNumberOfImages;
         current_image++) {
      Magick::Image image(Magick::Geometry(kImageWidth, kImageHeight), white);

      std::cerr << "Image " << current_image + 1 << "...";
      double blue{std::sin(blue_step * current_image)};

      for (int column = 0; column < image.columns(); column++) {
        for (int row = 0; row < image.rows(); row++) {
          int current_step{current_image * row_col_step};
          double red{sine_lookup_table.at((row + current_step) % kImageWidth)};
          double green{
              sine_lookup_table.at((column + current_step) % kImageHeight)};

          Magick::ColorRGB color{red, green, blue};

          image.pixelColor(row, column, color);
        }
      }
      images.push_back(image);
      std::cerr << "completed.\n";
    }

    Magick::writeImages(images.begin(), images.end(), output_file_name);

    return 0;
  } catch (const std::exception& problem) {
    std::cout << "Please provide a path to a file.\n";
    return 1;
  }
}
