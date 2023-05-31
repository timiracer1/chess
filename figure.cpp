#include "figure.hpp"

Figure::Figure(FigureType type, Colour colour) : type_(type), colour_(colour) {};

FigureType Figure::getType() {return type_;};