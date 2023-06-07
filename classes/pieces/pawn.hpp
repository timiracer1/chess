#ifndef PAWN_HPP
#define PAWN_HPP

#include "figure.hpp"

class Pawn : public Figure
{
  public:
    Pawn(Colour colour);
    ~Pawn() = default;
    Pawn() = delete;
  
  private:
};

#endif // PAWN_HPP