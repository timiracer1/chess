#include "action.hpp"

Action::Action(std::string parameters)
{
  try
  {
    if (parameters == "quit")
    {
      current_action_ = ActionType::QUIT;
      return;
    }

    // pawn move
    if (parameters.length() == 2)
    {
      current_action_ = ActionType::MOVE_NORMAL;
      pawnMove(parameters);
    }

    // check for disambiugating pawn move
    else if (parameters.length() == 3 && (('1' <= static_cast<int>(parameters.at(0)) && static_cast<int>(parameters.at(0)) <= '8')
        || ('a' <= parameters.at(0) && parameters.at(0) <= 'h')))
    {
      disambiugationg_info_ = parameters.at(0);
      parameters.erase(0,1);
      current_action_ = ActionType::MOVE_UNIQUE;
      pawnMove(parameters);
      
    }
    // normal move
    else if (parameters.length() == 3 || parameters.length() == 4)
    {
      char first_par = parameters.at(0);
      if (first_par == 'K' || first_par == 'Q' || first_par == 'Q' || first_par == 'R' || first_par == 'B' || first_par == 'N')
      {
        current_action_ = ActionType::MOVE_NORMAL;
        figure_to_move_ = static_cast<FigureType>(first_par);
      }
      else
        throw std::runtime_error("Invalid Figure!");

      // disambiugating move
      if (parameters.length() == 4)
      {
        current_action_ = ActionType::MOVE_UNIQUE;
        if ('1' <= static_cast<int>(parameters.at(1)) && static_cast<int>(parameters.at(1)) <= '8')
        {
          disambiugationg_info_ = parameters.at(1);
        }
        else if ('a' <= parameters.at(1) && parameters.at(1) <= 'h')
        {
          disambiugationg_info_ = parameters.at(1);
        }
        else
          throw std::runtime_error("Invalid disambiugating move!");

        parameters.erase(1,1);
      }

      if ('a' <= parameters.at(1) && parameters.at(1) <= 'h')
      {
        column_ = static_cast<Column>(parameters.at(1));
      }
      else
        throw std::runtime_error("Invalid Column!");
      if ('1' <= parameters.at(2) && parameters.at(2) <= '8')
      {
        row_ = static_cast<int>(parameters.at(2));
      }
      else
        throw std::runtime_error("Invalid Row!");
    }
    else
      throw std::runtime_error("Invalid Input!");
  }
  catch(const std::exception& e)
  {
    std::cout << e.what() << std::endl;
    current_action_ = ActionType::INVALID;
  }
}

ActionType Action::getActionType()
{
  return current_action_;
}

std::string Action::getActionAsString()
{
  std::string output;
  if (figure_to_move_ != FigureType::PAWN)
    output.push_back(static_cast<char>(figure_to_move_));
  if (current_action_ == ActionType::MOVE_UNIQUE)
    output.push_back(disambiugationg_info_);
  if (is_capture_)
  {
    if (figure_to_move_ == FigureType::PAWN)
    {
      // get the move from for pawn (exd6, bxc6, ...)
    }
    output.push_back('x');
  }
  output.push_back(static_cast<int>(column_));
  output.push_back(row_);
  return output;
}

void Action::pawnMove(std::string parameters)
{
    figure_to_move_ = FigureType::PAWN;
    if ('a' <= parameters.at(0) && parameters.at(0) <= 'h')
    {
      column_ = static_cast<Column>(parameters.at(0));
    }
    else
      throw std::runtime_error("Invalid Column!");
    
    if ('1' <= parameters.at(1) && parameters.at(1) <= '8')
    {
      row_ = static_cast<int>(parameters.at(1));
    }
    else
      throw std::runtime_error("Invalid Row!");
}