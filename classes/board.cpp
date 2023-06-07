#include "board.hpp"

Board::Board(std::vector<std::string> config)
{
  try
  {
    for (int row = 1; row <= 8; row++)
    {
      auto& current_config_line = config.at(row - 1);
      if (current_config_line.size() > 8)
      {
        throw std::runtime_error("Invalid length in config File!");
      }
      std::vector<std::shared_ptr<Tile>> current_row;
      size_t empty_fields = 0;
      for (size_t column = 1; column <= 8; column++)
      {
        auto& current_char = current_config_line.at(column - 1 - empty_fields);
        if (current_char == 'r')
        {
          current_row.push_back(std::make_shared<Tile>(row, static_cast<Column>(column), std::make_shared<Figure>(FigureType::ROOK, Colour::BLACK)));
        }
        else if (current_char == 'n')
        {
           current_row.push_back(std::make_shared<Tile>(row, static_cast<Column>(column), std::make_shared<Figure>(FigureType::KNIGHT, Colour::BLACK)));
        }
        else if (current_char == 'b')
        {
           current_row.push_back(std::make_shared<Tile>(row, static_cast<Column>(column), std::make_shared<Figure>(FigureType::BISHOP, Colour::BLACK)));
        }
        else if (current_char == 'q')
        {
           current_row.push_back(std::make_shared<Tile>(row, static_cast<Column>(column), std::make_shared<Figure>(FigureType::QUEEN, Colour::BLACK)));
        }
        else if (current_char == 'k')
        {
           current_row.push_back(std::make_shared<Tile>(row, static_cast<Column>(column), std::make_shared<Figure>(FigureType::KING, Colour::BLACK)));
        }
        else if (current_char == 'p')
        {
           current_row.push_back(std::make_shared<Tile>(row, static_cast<Column>(column), std::make_shared<Figure>(FigureType::PAWN, Colour::BLACK)));
        }
        else if (current_char == 'R')
        {
           current_row.push_back(std::make_shared<Tile>(row, static_cast<Column>(column), std::make_shared<Figure>(FigureType::ROOK, Colour::WHITE)));
        }
        else if (current_char == 'N')
        {
           current_row.push_back(std::make_shared<Tile>(row, static_cast<Column>(column), std::make_shared<Figure>(FigureType::KNIGHT, Colour::WHITE)));
        }
        else if (current_char == 'B')
        {
           current_row.push_back(std::make_shared<Tile>(row, static_cast<Column>(column), std::make_shared<Figure>(FigureType::BISHOP, Colour::WHITE)));
        }
        else if (current_char == 'Q')
        {
           current_row.push_back(std::make_shared<Tile>(row, static_cast<Column>(column), std::make_shared<Figure>(FigureType::QUEEN, Colour::WHITE)));
        }
        else if (current_char == 'K')
        {
           current_row.push_back(std::make_shared<Tile>(row, static_cast<Column>(column), std::make_shared<Figure>(FigureType::KING, Colour::WHITE)));
        }
        else if (current_char == 'P')
        {
           current_row.push_back(std::make_shared<Tile>(row, static_cast<Column>(column), std::make_shared<Figure>(FigureType::PAWN, Colour::WHITE)));
        }
        else if ('1' <= current_char && current_char <= '8')
        {
          empty_fields += current_char - '0';
          for (size_t i = 0; i < (size_t) current_char - '0'; i++)
          {
            current_row.push_back(std::make_shared<Tile>(row, static_cast<Column>(column++), std::make_shared<Figure>(FigureType::NONE, Colour::NONE)));
          }
        }
        else
        {
          throw std::runtime_error("Invalid entry in config File!");
        }
      }
      map_.push_back(current_row);
    }
  }
  catch(const std::exception& e)
  {
    throw std::runtime_error(e.what());
  }
  
};

std::ostream& operator<<(std::ostream& stream, Board& board)
{
  stream << "----------------------------------------------" << std::endl;
  stream << "     a    b    c    d    e    f    g    h " << std::endl;
  int row_counter = 1;
  for (auto& row : board.map_)
  {
    stream << row_counter << " ";
    for (auto& column : row)
    {
      stream << " | " << *column;
    }
    stream << " | " << row_counter++ << std::endl;
  }
  stream << "     a    b    c    d    e    f    g    h " << std::endl;
  return stream;
}