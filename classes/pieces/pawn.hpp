#ifndef PAWN_HPP
#define PAWN_HPP

#include "figure.hpp"
#include <iostream>

class Pawn : public Figure
{
  public:
    Pawn(Colour colour);
    ~Pawn() = default;
    Pawn() = delete;
    bool moveValid(Colour current_colour, std::pair<Column, int> starting_pos, std::pair<Column, int> destination) override;
};

#endif // PAWN_HPP