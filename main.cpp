#include "board.hpp"
#include <memory>

int main ()
{
  std::shared_ptr<Board> board = std::make_shared<Board>();
  std::cout << *board << std::endl;
  return 0;
}