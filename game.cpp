#include "game.hpp"

Game::Game()
{
  try
  {
    config_ = getConfig("config.txt");
    board_ = std::make_shared<Board>(config_);
    players_.push_back(std::make_shared<Player>(Colour::WHITE));
    players_.push_back(std::make_shared<Player>(Colour::BLACK));
  }
  catch(const std::exception& e)
  {
    throw std::runtime_error(e.what());
  }
};

void Game::firstRound()
{
  try
  {
    auto& config_colour = config_.at(8);
    if (config_colour == "w" || config_colour == "W")
    {
      players_.at(0)->getInput();
      players_.at(1)->getInput();
    }
    else if (config_colour == "b" || config_colour == "B")
    {
      players_.at(1)->getInput();
    }
    else
    {
      throw std::runtime_error("Invalid config colour!");
    }
  }
  catch(const std::exception& e)
  {
    throw std::runtime_error(e.what());
  }
}

void Game::run()
{
  std::cout << *board_;
  firstRound();
}

std::vector<std::string> Game::getConfig(std::string path)
{
  try
  {
    std::ifstream file(path); // Open the file for reading
    if (file.is_open()) { // Check if the file was opened successfully
      std::string input;
      if (std::getline(file, input))
      {
        std::vector<std::string> tokens;
        std::istringstream iss(input);

        std::string token;
        while (std::getline(iss, token, '/'))
        {
          tokens.push_back(token);
        }

        std::string lastToken = tokens.back();
        tokens.pop_back();

        std::istringstream iss2(lastToken);
        while (std::getline(iss2, token, ' ')) {
          if (token != "-")
          {
            tokens.push_back(token);
          }
        }
        return tokens;
      }
      else
      {
        file.close(); // Close the file
        throw std::runtime_error("File is empty.");
      }
    }
    else
      throw std::runtime_error("Failed to open the file.");
  } 
  catch (const std::exception& e)
  {
    throw std::runtime_error(e.what());
  }
};