#include "figure.hpp"

Figure::Figure(FigureType type, Colour colour) : type_(type), colour_(colour), has_moved_(false) {};

FigureType Figure::getType() {return type_;};

Colour Figure::getColour() {return colour_;};