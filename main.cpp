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
    std::cout << "Exit_code 1" << std::endl;
    return 1;
  }
  // DEBUG
  int debug;
  std::cout << "Enter any to end: ";
  std::cin >> debug; 
  // END 
  return 0;
}