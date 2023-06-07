#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "board.hpp"
#include "player.hpp"
#include "commandline.hpp"

class Game
{
  private:
    std::shared_ptr<Board> board_;
    std::vector<std::shared_ptr<Player>> players_;
    std::vector<std::string> config_;
    std::vector<std::string> getConfig(std::string path);
    int execute(std::shared_ptr<Action> action);
    int firstRound();

  public:
    Game();
    Game(Game& game) = delete;
    ~Game() = default;
    int run();
};

#endif // GAME_HPP