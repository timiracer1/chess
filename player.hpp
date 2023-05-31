#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "figure.hpp"
#include <string>
#include <iostream>

class Player
{
  private:
    Colour colour_;

  public:
    Player(Colour colour);
    Player(Player& player) = delete;
    ~Player() = default;
    Colour getColour();
    std::string getInput();
};

#endif // PLAYER_HPP