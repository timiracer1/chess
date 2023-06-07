#ifndef ROOK_HPP
#define ROOK_HPP

#include "figure.hpp"

class Rook : public Figure
{
  public:
    Rook(Colour colour);
    ~Rook() = default;
    Rook() = delete;
  
  private:
};

#endif // ROOK_HPP