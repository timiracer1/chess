#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "board.hpp"
#include "player.hpp"

class Game
{
  private:
    std::shared_ptr<Board> board_;
    std::vector<std::shared_ptr<Player>> players_;
    std::vector<std::string> config_;

  public:
    Game();
    Game(Game& game) = delete;
    ~Game() = default;
    void run();
    void firstRound();
    std::vector<std::string> getConfig(std::string path);
};

#endif // GAME_HPP