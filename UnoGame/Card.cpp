#include <iostream>
#include "Card.h"

Card::Card() {}

Card::Card(int ccolor, int vvalue, int ttype) : color(ccolor), value(vvalue), type(ttype) {}

int Card::getColor() const {
    return color;
}

int Card::getValue() const {
    return value;
}

std::string Card::toString() const {
    std::string colorStr;
    switch (color) {
    case red:
        colorStr = "RED";
        break;
    case green:
        colorStr = "GREEN";
        break;
    case blue:
        colorStr = "BLUE";
        break;
    case yellow:
        colorStr = "YELLOW";
        break;
    default:
        colorStr = "UNKNOWN";
        break;
    }

    return "Color: " + colorStr + ", Value: " + std::to_string(value);
}