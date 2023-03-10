// TODO: Add your header

#include <Magick++.h>

#include <iostream>
#include <string>
#include <vector>

#include "make_message_functions.h"

/// Main function - Entry point for our ray tracer
/// The program takes two arguments which is the output file name and a
/// a brief message. The image generated by the main function is written
/// out as a GIF file.
int main(int argc, char const* argv[]) {
  Magick::InitializeMagick(*argv);
  // Initialize the GraphicsMagick library. It must be the first thing
  // that happens in the main function.
  // Do not change or remove the line below.
  Magick::InitializeMagick(*argv);
  // TODO: convert the command line arguments to a
  // std::vector of std::strings.
  // TODO: Check to make sure you have enough arguments. If you have
  // too few, print an error message and exit.
  // TODO: Declare a std::string variable named output_file_name.
  // TODO: Assign the first argument to output_file_name

  // TODO: Declare a std::string variable named image_format and
  // initialize it to ".gif"
  // TODO: Using HasMatchingFileExtension(), check to see if
  // output_file_name has the extension defined as image_format. If
  // output_file_name does not, then print an error message and return 1.

  // TODO: Declare a std::string variable nmaed message and initialize it to
  // the args.at(2)

  const double aspect_ratio = 16.0 / 9.0;
  // Set the image width to 1024 pixels
  const int image_width = 1024;
  // Calculate the height of the image using the width and aspect ratio.
  // Remember to round the number to the closest integer.
  const int image_height = int(lround(image_width / aspect_ratio));
  Magick::ColorRGB yellow(1, 1, 0);
  Magick::Image image(Magick::Geometry(image_width, image_height), yellow);
  // Print out some information about the image to help us debug what's
  // going on.
  std::cout << "Your image has " << image.columns()
            << " columns (x direction) and " << image.rows()
            << " rows (y direction).\n";

  const int number_of_images = 5;
  // TODO: Declare a std::vector of Magick::Image, name the variable images.

  for (int image_count = 0; image_count < number_of_images; image_count++) {
    std::cerr << "Image " << image_count + 1 << "...";

    // TODO: Create an inner and outer loop to visit each pixel.
    // For example:
    // for (int row = 0; row < image.rows(); row++) {
    //   for (int column = 0; column < image.columns(); column++) {
    // TODO: Declare a double variable named random_color_intensity and assign
    // it RandomDouble01()
    // TODO: Declare a double variable named red and assign it 0.0;
    // TODO: Declare a double variable named green and assign it 0.0;
    // TODO: Declare a double variable named blue and assign it 0.0;
    // TODO: If CoinFlip() is true, then assign random_color_intensity to red
    // TODO: If CoinFlip() is true, then assign random_color_intensity to green
    // TODO: If CoinFlip() is true, then assign random_color_intensity to blue
    // TODO: Declare a Magick::ColorRGB variable named color and initialize
    // it with the values from the red, green, blue variables.
    // TODO: Set the current pixel color in the image to the new color.
    // For example:
    // image.pixelColor(row, column, color);
    // TODO: Declare a Magick::ColorRGB variable named color and initialize
    // it with the values from the red, green, blue variables.
    // TODO: Set the current pixel color in the image to the new color.
    // For example:
    // image.pixelColor(column, row, color);
    //   }
    // }
    // TODO: Once you are generating a noisy image with random colors,
    // uncomment the lines below to add your message to the center of the
    // image.
    // image.font("Helvetica");
    // image.fontPointsize(image.rows() / 3.0);
    // image.fillColor(Magick::Color("yellow"));
    // image.annotate(message, Magick::CenterGravity);

    // TODO: Use push_back to add the current image to the vector images.
    std::cerr << "completed.\n";
  }

  // TODO: Write the images to an output file using Magick::writeImages()
  // For example:
  // Magick::writeImages(images.begin(), images.end(), output_file_name);

  return 0;
}
