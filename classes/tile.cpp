#include "tile.hpp"

Tile::Tile(int row, Column column, std::shared_ptr<Figure> figure) : row_(row), column_(column), figure_on_(figure) {};

const std::shared_ptr<Figure> Tile::getFigure()
{
  return figure_on_;
}

std::ostream& operator<<(std::ostream& stream, Tile& tile)
{
  stream << static_cast<char>(tile.figure_on_->getColour()) << static_cast<char>(tile.figure_on_->getType());
  return stream;
}

std::pair<Column, int> Tile::getCoords()
{
  return std::make_pair(column_, row_);
}