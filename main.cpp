#include "game.hpp"
#include <memory>

int main ()
{
  try
  {
    std::shared_ptr<Game> game = std::make_shared<Game>();
    game->run();
  }
  catch(const std::exception& e)
  {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}