#ifndef FIGURE_HPP
#define FIGURE_HPP

#include "../settings.hpp"
#include <vector>
#include <memory>

enum class FigureType : char
{
  PAWN = 'P',
  KING = 'K',
  QUEEN = 'Q',
  ROOK = 'R',
  BISHOP = 'B',
  KNIGHT = 'N',
  NONE = ' '
};

class Figure
{
  protected:
    FigureType type_;
    Colour colour_;
    bool has_moved_;
  
  public:
    Figure(FigureType type, Colour colour);
    Figure(FigureType& figure) = delete;
    ~Figure() = default;
    FigureType getType();
    Colour getColour();
    virtual bool moveValid(Colour current_colour, std::pair<Column, int> starting_pos, std::pair<Column, int> destination);
};

#endif // FIGURE_HPP