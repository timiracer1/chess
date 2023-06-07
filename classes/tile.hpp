#ifndef TILE_HPP
#define TILE_HPP

#include "pieces/figure.hpp"
#include "pieces/pawn.hpp"
#include "pieces/bishop.hpp"
#include "pieces/king.hpp"
#include "pieces/queen.hpp"
#include "pieces/knight.hpp"
#include "pieces/rook.hpp"
#include <memory>
#include <iostream>

enum class Column : int
{
  a = 1,
  b = 2,
  c = 3,
  d = 4,
  e = 5,
  f = 6,
  g = 7,
  h = 8,
};

class Tile
{
  public:
    Tile(int row_, Column column_, std::shared_ptr<Figure> figure);
    Tile(Tile& tile) = delete;
    ~Tile() = default;
    std::shared_ptr<Figure> getFigure();
    friend std::ostream& operator<<(std::ostream& stream, Tile& tile);

  private:
    int row_;
    Column column_;
    std::shared_ptr<Figure> figure_on_;
};

#endif // TILE_HPP