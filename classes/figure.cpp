#include "figure.hpp"

Figure::Figure(FigureType type, Colour colour) : type_(type), colour_(colour) {};

FigureType Figure::getType() {return type_;};

Colour Figure::getColour() {return colour_;};