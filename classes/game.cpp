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

int Game::firstRound()
{
  try
  {
    auto& config_colour = config_.at(8);
    if (config_colour == "w" || config_colour == "W")
    {
      for (auto& player : players_)
      {
        std::cout << *board_;
        while(true)
        {
          std::shared_ptr<CommandLine> cli;
          std::shared_ptr<Action> current_action = std::make_shared<Action>(cli->readCommand(player->getColour()));
          if (current_action->getActionType() == ActionType::QUIT)
            return 1;
          // DEBUG
          std::cout << current_action->getActionAsString() << std::endl;
          try
          {
            execute(player, current_action); // throws exception if not valid
          }
          catch(const std::exception& e)
          {
            std::cout << e.what() << std::endl;
            continue;
          }
          break;
        }
      }
    }
    else if (config_colour == "b" || config_colour == "B")
    {
      // TODO REST
      //auto& player = players_.at(1);
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
  return 0;
}

int Game::run()
{
  if(firstRound() == 1)
  {
    return 1;
  }
  return 0;
}

void Game::execute(std::shared_ptr<Player> player, std::shared_ptr<Action> action)
{
  ActionType action_type = action->getActionType();
  FigureType action_figure = action->getFigureType();
  std::pair<Column, int> action_destination = action->getDestination();
  Colour current_colour = player->getColour();
  std::vector<std::shared_ptr<Tile>> possible_figure_tiles; // the tiles with figures on it that are ok to move
  switch (action_figure)
  {
    case FigureType::PAWN:
      possible_figure_tiles = board_->getPossibleFigureTiles(current_colour, action_figure, action_destination);
      break;
  
  default:
    break;
  }

  if (possible_figure_tiles.size() == 0)
  {
    throw std::runtime_error("No possible Move!");
  }

  if (action_type == ActionType::MOVE_NORMAL)
  {
    if (possible_figure_tiles.size() == 1)
    {
      //check if no piece and move
    }
    else
      throw std::runtime_error("More than one Possible Figure!");
  }
  else if (action_type == ActionType::MOVE_UNIQUE)
  {
    // insert code here
    throw std::exception();
  }
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