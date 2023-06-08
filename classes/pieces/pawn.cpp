#include "pawn.hpp"

Pawn::Pawn(Colour colour) : Figure(FigureType::PAWN, colour) {};

bool Pawn::moveValid(Colour current_colour, std::pair<Column, int> starting_pos, std::pair<Column, int> destination)
{
  std::pair<Column, int> current_field;
  if (colour_ == Colour::WHITE && colour_ == current_colour)
  {
    // add normal move
    current_field.first = starting_pos.first;
    current_field.second = starting_pos.second - 1;
    if ((current_field.second == destination.second) && (current_field.first == destination.first))
      return true;
    // add double move
    if (!has_moved_)
    {
      current_field.second -= 1;
      if ((current_field.second == destination.second) && (current_field.first == destination.first))
        return true;
    }
  }
  else if (colour_ == Colour::BLACK && colour_ == current_colour)
  {
    // add normal move
    current_field.first = starting_pos.first;
    current_field.second = starting_pos.second + 1;
    if ((current_field.second == destination.second) && (current_field.first == destination.first))
      return true;
    // add double move
    if (!has_moved_)
    {
      current_field.second += 1;
      if ((current_field.second == destination.second) && (current_field.first == destination.first))
        return true;
    }
  }
  return false;
}