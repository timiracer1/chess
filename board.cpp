#include "board.hpp"

// Board::Board(std::vector<std::string> config)
// {
//   std::shared_ptr<Figure> current_figure;
//   Colour current_color;
//   for (int row = 1; row <= 8; row++)
//   {
//     std::vector<std::shared_ptr<Tile>> current_row;
//     for (int column = 1; column <= 8; column++)
//     {
//       if (row == 1 || row == 8)
//       {
//         if (row == 1)
//           current_color = Colour::WHITE;
//         else
//           current_color = Colour::BLACK;
//         if (column == static_cast<int>(Column::a) || column == static_cast<int>(Column::h))
//           current_figure = std::make_shared<Figure>(FigureType::ROOK, current_color);
//         else if (column == static_cast<int>(Column::b) || column == static_cast<int>(Column::g))
//           current_figure = std::make_shared<Figure>(FigureType::KNIGHT, current_color);
//         else if (column == static_cast<int>(Column::c) || column == static_cast<int>(Column::f))
//           current_figure = std::make_shared<Figure>(FigureType::BISHOP, current_color);
//         else if (column == static_cast<int>(Column::d))
//           current_figure = std::make_shared<Figure>(FigureType::QUEEN, current_color);
//         else if (column == static_cast<int>(Column::e))
//           current_figure = std::make_shared<Figure>(FigureType::KING, current_color);
//       }
//       else if (row == 2 || row == 7)
//       {
//         if (row == 2)
//           current_color = Colour::WHITE;
//         else
//           current_color = Colour::BLACK;
//         current_figure = std::make_shared<Figure>(FigureType::PAWN, current_color);
//       }
//       else
//         current_figure = std::make_shared<Figure>(FigureType::NONE, Colour::NONE);
//       current_row.push_back(std::make_shared<Tile>(row, static_cast<Column>(column), current_figure));
//     }
//     map_.push_back(current_row);
//   }
// };


Board::Board(std::vector<std::string> config)
{
  try
  {
    for (int row = 1; row <= 8; row++)
    {
      auto& current_config_line = config.at(row - 1);
      if (current_config_line.size() > 8)
      {
        throw std::runtime_error("INVALID LENGTH IN CONFIG FILE!");
      }
      std::vector<std::shared_ptr<Tile>> current_row;
      for (size_t column = 1; column <= current_config_line.size(); column++)
      {
        auto& current_char = current_config_line.at(column - 1);
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
          int empty_fields = current_char - '0';
          for (int i = 0; i < empty_fields; i++)
          {
            current_row.push_back(std::make_shared<Tile>(row, static_cast<Column>(column++), std::make_shared<Figure>(FigureType::NONE, Colour::NONE)));
          }
        }
        else
        {
          throw std::runtime_error("INVALID ENTRY IN CONFIG FILE!");
        }
      }
      map_.push_back(current_row);
    }
  }
  catch(const std::exception& e)
  {
    std::cout << "ERROR: " << e.what() << std::endl;
    throw e;
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