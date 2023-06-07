#include "commandline.hpp"

Action CommandLine::readCommand(Colour colour)
{
  while(true)
  {
    std::cout << static_cast<char>(colour) << " your next move > ";
    std::string input;

    if(!std::getline(std::cin, input))
    {
      std::string quit = "quit";
      return Action(quit);
    }
    
    // ????
    if (input.empty())
      continue;

    Action action{input};
    if (action.getActionType() != ActionType::INVALID)
      return action;
  }
}