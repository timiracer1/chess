#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "board.hpp"

class Game
{
  private:
    std::shared_ptr<Board> board_;

  public:
    Game();
    Game(Game& game) = delete;
    ~Game() = default;
    void run();
    std::vector<std::string> getConfig(std::string path);
};