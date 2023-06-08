#ifndef TILE_HPP
#define TILE_HPP

#include "pieces/figure.hpp"
#include "pieces/pawn.hpp"
#include "pieces/bishop.hpp"
#include "pieces/king.hpp"
#include "pieces/queen.hpp"
#include "pieces/knight.hpp"
#include "pieces/rook.hpp"
#include "settings.hpp"
#include <memory>
#include <iostream>

class Tile
{
  public:
    Tile(int row_, Column column_, std::shared_ptr<Figure> figure);
    Tile(Tile& tile) = delete;
    ~Tile() = default;
    const std::shared_ptr<Figure> getFigure();
    friend std::ostream& operator<<(std::ostream& stream, Tile& tile);
    std::pair<Column, int> getCoords();

  private:
    int row_;
    Column column_;
    std::shared_ptr<Figure> figure_on_;
};

#endif // TILE_HPP