#include "board.hpp"

Board::Board()
{
  std::shared_ptr<Figure> current_figure;
  Colour current_color;
  for (int row = 1; row <= 8; row++)
  {
    std::vector<std::shared_ptr<Tile>> current_row;
    for (int column = 1; column <= 8; column++)
    {
      if (row == 1 || row == 8)
      {
        if (row == 1)
          current_color = Colour::WHITE;
        else
          current_color = Colour::BLACK;
        if (column == static_cast<int>(Column::a) || column == static_cast<int>(Column::h))
          current_figure = std::make_shared<Figure>(FigureType::ROOK, current_color);
        else if (column == static_cast<int>(Column::b) || column == static_cast<int>(Column::g))
          current_figure = std::make_shared<Figure>(FigureType::KNIGHT, current_color);
        else if (column == static_cast<int>(Column::c) || column == static_cast<int>(Column::f))
          current_figure = std::make_shared<Figure>(FigureType::BISHOP, current_color);
        else if (column == static_cast<int>(Column::d))
          current_figure = std::make_shared<Figure>(FigureType::QUEEN, current_color);
        else if (column == static_cast<int>(Column::e))
          current_figure = std::make_shared<Figure>(FigureType::KING, current_color);
      }
      else if (row == 2 || row == 7)
      {
        if (row == 2)
          current_color = Colour::WHITE;
        else
          current_color = Colour::BLACK;
        current_figure = std::make_shared<Figure>(FigureType::PAWN, current_color);
      }
      else
        current_figure = std::make_shared<Figure>(FigureType::NONE, Colour::NONE);
      current_row.push_back(std::make_shared<Tile>(row, static_cast<Column>(column), current_figure));
    }
    map_.push_back(current_row);
  }
};

std::ostream& operator<<(std::ostream& stream, Board& board)
{
  stream << "--------------------------------------" << std::endl;
  stream << "     a   b   c   d   e   f   g   h" << std::endl;
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
  stream << "     a   b   c   d   e   f   g   h" << std::endl;
  return stream;
}