#ifndef COMMANDLINE_HPP
#define COMMANDLINE_HPP

#include <vector>
#include <iostream>
#include <sstream>
#include <memory>
#include "action.hpp"
#include "figure.hpp"

class CommandLine
{
  public:
    CommandLine() = default;
    ~CommandLine() = default;
    CommandLine(CommandLine& command) = delete;
    Action readCommand(Colour colour);
};

#endif // COMMANDLINE_HPP