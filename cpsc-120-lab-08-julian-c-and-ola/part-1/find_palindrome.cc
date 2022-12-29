// Oyinkansola Olayinka
// CPSC 120-10
// 2022-10-27
// oyinkansola11@csu.fullerton.edu
// @olasores
//
// Lab 08-01
// Partners: @Julianizceja
//
// This program checks for palindromes in a file.
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool IsPalindrome(const std::string& word) {
  bool d = false;
  std::string revered_word{word.rbegin(), word.rend()};
  if (word == revered_word) {
    d = true;
  }
  return d;
}

int main(int argc, char const* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);
  if (arguments.size() <= 1) {
    std::cout << "Please Provide a path to a file. Existing \n";
    return 1;
  }

  std::string file_name = arguments[1];
  std::ifstream input_file_stream{file_name};
  if (!input_file_stream.is_open()) {
    std::cout << "Could not open the file " << file_name << ". Exiting.\n";
    return 1;
  }

  std::string line_buffer;
  while (input_file_stream.good()) {
    std::string line_buffer;
    std::getline(input_file_stream, line_buffer);
    if (IsPalindrome(line_buffer) && line_buffer.length() >= 4) {
      std::cout << line_buffer << "\n";
    }
  }

  input_file_stream.close();
  return 0;
}
