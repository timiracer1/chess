#include "tile.hpp"
#include <vector>
#include <iostream>

class Board
{
  private:
    std::vector<std::vector<std::shared_ptr<Tile>>> map_;
  
  public:
    Board();
    Board(Board& board) = delete;
    ~Board() = default;
    friend std::ostream& operator<<(std::ostream& stream, Board& board);
};