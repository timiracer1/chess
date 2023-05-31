#include "player.hpp"

Player::Player(Colour colour) : colour_(colour) {};

Colour Player::getColour() {return colour_;};

std::string Player::getInput()
{
  std::string input;
  std::cout << static_cast<char>(colour_) << " enter your next turn: ";
  std::cin >> input;
  return input;
}