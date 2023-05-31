#include "game.hpp"

Game::Game()
{
  try
  {
    std::vector<std::string> config = getConfig("config.txt");
    board_ = std::make_shared<Board>(config);
  }
  catch(const std::exception& e)
  {
    throw e;
  }
  
};

void Game::run()
{
  std::cout << *board_;
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
    std::cout << "Exception occurred: " << e.what() << std::endl;
    throw e;
  }
};