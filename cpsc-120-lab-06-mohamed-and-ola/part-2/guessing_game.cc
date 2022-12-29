// Oyinkansola Olayinka
// CPSC 120-10
// 2022-10-13
// Oyinkansola11@csu.fullerton.edu
// @olasores
//
// Lab 06-02
// Partners: @mkhalifa21-byte
//
// This is a guessing game program
//

#include <cmath>
#include <iostream>
#include <string>

int k_secret_number = 42;
int main(int argc, char const *argv[]) {
  int guess = 0;
  int last_guess = 0;
  std::string answer;

  std::cout << "Hi - I'm a computer and I've thought of a number between "
               "1 and 100.\n";
  std::cout << "Let's play a guessing game...\n";

  bool is_game_over{false};
  std::string input;
  while (!is_game_over) {
    std::cin >> input;
    if (input == "n") {
      is_game_over = true;
    }
    std::cout << "What's your guess: ";
    std::cin >> guess;
    if (guess <= 1 || guess >= 100) {
      std::cout << "Please enter another number: ";
      std::cin >> guess;
    }
    if (guess == k_secret_number) {
      std::cout << "Hooray! You guessed the secret number!!";
      std::cout << "Do you want to play again? (y or n): ";
      std::cin >> answer;
      if (answer == "n") {
        break;
      }
    }
    if (std::abs(k_secret_number - guess) <
        std::abs(k_secret_number - last_guess)) {
      std::cout << "You're getting warmer!\n";
    } else {
      std::cout << "You're getting colder.\n";
    }
    last_guess = guess;
  }
  return 0;
}