// Oyinkansola Olayinka
// CPSC 120-10
// 2022-10-27
// oyinkansola11@csu.fullerton.edu
// @olasores
//
// Lab 08-01
// Partners: @Julianizceja
//
// This program saves a secret message to a file.
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void Prompt() {
  std::cout
      << "What's a secret message that you'd like to write into a file? \n";
  std::cout
      << "Type your message out and when you're done press return or enter. \n";
}

int main(int argc, char* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);
  if (arguments.size() <= 1) {
    std::cout << "Please provide a path to a file. Exiting.\n";
    return 1;
  }
  std::string file_name = arguments[1];
  std::ofstream output_file_stream{file_name};
  if (!output_file_stream.is_open()) {
    std::cout << "Could not open the file " << file_name << ". Exiting.\n";
    return 1;
  }
  Prompt();
  std::string secret_message;
  std::getline(std::cin, secret_message);

  operator<<(output_file_stream, secret_message);
  std::cout << "Your secret message was saved into " << file_name << ".\n";
  output_file_stream.close();
  return 0;
}
