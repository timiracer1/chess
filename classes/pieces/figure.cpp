#include "figure.hpp"

Figure::Figure(FigureType type, Colour colour) : type_(type), colour_(colour), has_moved_(false) {};

FigureType Figure::getType() {return type_;};

Colour Figure::getColour() {return colour_;};

bool Figure::moveValid(Colour current_colour, std::pair<Column, int> starting_pos, std::pair<Column, int> destination)
{
  //placeholder
  return false;
}