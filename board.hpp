#ifndef BOARD_HPP
#define BOARD_HPP

#include "tile.hpp"
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>

class Board
{
  private:
    std::vector<std::vector<std::shared_ptr<Tile>>> map_;
  
  public:
    Board(std::vector<std::string> config);
    Board(Board& board) = delete;
    ~Board() = default;
    friend std::ostream& operator<<(std::ostream& stream, Board& board);
};

#endif // BOARD_HPP