// Oyinkansola Olayinka
// CPSC 120-10
// 2022-10-21
// Oyinkansola11@csu.fullerton.edu
// @olasores
//
// Lab 07-02
// Partners: @Julianizceja
//
// This program calculates date difference between dates
//

#include <iostream>
#include <string>
#include <vector>

int score{0};

bool IsAce(const std::string& card_name) { return (card_name == "A"); }

bool IsFaceCard(const std::string& card_name) {
  return (card_name == "J" || card_name == "Q" || card_name == "K");
}

bool IsNumberCard(const std::string& card_name) {
  return (card_name == "2" || card_name == "3" || card_name == "4" ||
          card_name == "5" || card_name == "6" || card_name == "7" ||
          card_name == "8" || card_name == "9" || card_name == "10");
}

bool IsCardName(const std::string& str) {
  return (IsAce(str) || IsFaceCard(str) || IsNumberCard(str));
}

bool AllArgumentsValid(const std::vector<std::string>& arguments) {
  for (int i = 1; i < arguments.size(); i++) {
    if (!IsCardName(arguments[i])) {
      return false;
    }
  }
  return true;
}

int CardPoints(const std::string& card_name) {
  int points{0};
  if (IsAce(card_name)) {
    points = 1;
  } else if (IsFaceCard(card_name)) {
    points = 10;
  } else if (IsNumberCard(card_name)) {
    points = std::stoi(card_name);
  }
  return points;
}

bool HandContainsAce(const std::vector<std::string>& arguments) {
  for (int i = 1; i < arguments.size(); i++) {
    if (IsAce(arguments[i])) {
      return true;
    }
  }
  return false;
}

bool IsBust(int score) { return (score > 21); }

int HandScore(const std::vector<std::string>& arguments) {
  int score = 0;
  for (int i = 1; i < arguments.size(); i++) {
    score += CardPoints(arguments[i]);
  }
  if (HandContainsAce(arguments) && !IsBust(score + 10)) {
    score += 10;
  }
  return score;
}

void PrintScore(int score) {
  if (IsBust(score)) {
    std::cout << "Score is " << score << ", BUST \n";
  } else {
    std::cout << "Score is " << score << "\n";
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);
  if (!AllArgumentsValid(arguments)) {
    std::cout << "error: unknown card \n";
    return 1;
  }
  PrintScore(HandScore(arguments));
  return 0;
}