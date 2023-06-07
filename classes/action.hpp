#ifndef ACTION_HPP
#define ACTION_HPP

#include "pieces/figure.hpp"
#include "tile.hpp"

#include <vector>
#include <string>

enum class ActionType
{
  QUIT,
  MOVE_UNIQUE,
  MOVE_NORMAL,
  INVALID,
};

class Action
{
  public:
    Action(std::string parameters);
    ~Action() = default;
    Action(const Action& action) = default;
    ActionType getActionType();
    std::string getActionAsString();

  private:
    FigureType figure_to_move_;
    char disambiugationg_info_;
    Column column_;
    int row_;
    ActionType current_action_;
    bool is_capture_;
    Column move_from_column_;
    void pawnMove(std::string parameters);
};

#endif // ACTION_HPP