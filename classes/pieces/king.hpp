#ifndef KING_HPP
#define KING_HPP

#include "figure.hpp"

class King : public Figure
{
  public:
    King(Colour colour);
    ~King() = default;
    King() = delete;
  
  private:
};

#endif // KING_HPP