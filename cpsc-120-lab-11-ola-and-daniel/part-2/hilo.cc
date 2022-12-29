// Daniel Marinca
// CPSC 120-10
// 2022-11-17
// dmarinca73@csu.fullerton.edu
// @DanielMarinca
//
// Lab 11-02
// Partners: @Olasores
//
// This program is a hi-lo game.
//

#include "hilo.h"

#include "rng.h"

GameState::GameState(int secret) : secret_(secret) {
  secret = secret_;
  guesses_left_ = 4;
}

int GameState::Secret() const { return secret_; }

int GameState::GuessesLeft() const { return guesses_left_; }

bool GameState::GuessCorrect(int guess) const { return (guess == secret_); }

bool GameState::GuessTooBig(int guess) const { return (guess > secret_); }

bool GameState::GuessTooSmall(int guess) const { return (guess < secret_); }

void GameState::CountGuess() { guesses_left_--; }

bool GameState::GameOver() const { return (guesses_left_ == 0); }

int RandomSecretNumber() {
  srand(time(nullptr));
  int secret = rand() % 10 + 1;
  return secret;
}
