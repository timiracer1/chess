#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "pieces/figure.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

class Player
{
  private:
    Colour colour_;

  public:
    Player(Colour colour);
    Player(Player& player) = delete;
    ~Player() = default;
    Colour getColour();
    std::vector<std::string> getInput();
};

#endif // PLAYER_HPP