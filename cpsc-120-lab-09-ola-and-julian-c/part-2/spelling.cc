// Oyinkansola Olayinka
// CPSC 120-10
// 2022-11-04
// oyinkansola11@csu.fullerton.edu
// @olasores
//
// Lab 09-02
// Partners: @Julianizceja
//
// This program checks for spellings.
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> ReadWords(const std::string& filename) {
  std::vector<std::string> read;
  std::ifstream ifs;
  std::string word;
  ifs.open(filename, std::ifstream::in);

  while (ifs >> word) {
    read.push_back(word);
  }

  ifs.close();
  return read;
}

bool InDictionary(const std::vector<std::string>& dictionary,
                  const std::string& word) {
  for (const std::string& dictionary_word : dictionary) {
    if (dictionary_word == word) {
      return true;
    }
  }
  return false;
}

std::vector<std::string> MisspelledWords(
    const std::vector<std::string>& dictionary,
    const std::vector<std::string>& document) {
  std::vector<std::string> misspelled_words;
  for (const std::string& word : document) {
    if (!InDictionary(dictionary, word)) {
      misspelled_words.push_back(word);
    }
  }
  return misspelled_words;
}
int main(int argc, char* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);
  if (arguments.size() != 2) {
    std::cout << "error: you must give a document filename \n";
    return 1;
  }
  std::string dictionary_filename = "words.txt";
  std::string document_filename = arguments.at(1);

  ReadWords(dictionary_filename);
  std::vector<std::string> read_dict = ReadWords(dictionary_filename);
  std::vector<std::string> read_file = ReadWords(document_filename);

  std::vector<std::string> misspelled_words =
      MisspelledWords(read_dict, read_file);
  std::cout << "spelling errors: " << std::endl;

  for (const std::string& word : misspelled_words) {
    std::cout << word << std::endl;
  }
  return 0;
}
