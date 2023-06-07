#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "figure.hpp"

class Queen : public Figure
{
  public:
    Queen(Colour colour);
    ~Queen() = default;
    Queen() = delete;
  
  private:
};

#endif // QUEEN_HPP