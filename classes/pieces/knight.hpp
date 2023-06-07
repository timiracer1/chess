#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "figure.hpp"

class Knight : public Figure
{
  public:
    Knight(Colour colour);
    ~Knight() = default;
    Knight() = delete;
  
  private:
};

#endif // KNIGHT_HPP