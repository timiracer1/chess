#include "player.hpp"

Player::Player(Colour colour) : colour_(colour) {};

Colour Player::getColour() {return colour_;};

std::vector<std::string> Player::getInput()
{
  while (true)
  {
    std::string input;
    std::cout << static_cast<char>(colour_) << " enter your next turn: ";
    std::getline(std::cin, input);

    std::vector<std::string> moves;
    std::istringstream iss(input);
    std::string move;

    while (iss >> move) {
        moves.push_back(move);
    }

    if (moves.size() == 2)
    {
      return moves;    
    }
    std::cout << "Enter in format FROM TO!" << std::endl;
  }
}