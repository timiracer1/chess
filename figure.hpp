enum class FigureType : char
{
  PAWN = 'P',
  KING = 'K',
  QUEEN = 'Q',
  ROOK = 'R',
  BISHOP = 'B',
  KNIGHT = 'N',
  NONE = ' '
};

enum class Colour : char
{
  BLACK = 'b',
  WHITE = 'w',
  NONE = ' ',
};

class Figure
{
  private:
    FigureType type_;
    Colour colour_;
  
  public:
    Figure(FigureType type, Colour colour);
    Figure(FigureType& figure) = delete;
    ~Figure() = default;
    FigureType getType();
    Colour getColour();
};