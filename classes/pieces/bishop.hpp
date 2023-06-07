#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "figure.hpp"

class Bishop : public Figure
{
  public:
    Bishop(Colour colour);
    ~Bishop() = default;
    Bishop() = delete;
  
  private:
};

#endif // BISHOP_HPP