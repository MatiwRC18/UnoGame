#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>

const int red = 1;
const int green = 2;
const int blue = 3;
const int yellow = 4;

const int changeDeck = 0;
const int reverse = 10;
const int skip = 11;
const int plusTwo = 12;
const int plusFour = 13;
const int changeColor = 14;

class Card {
private:
    int color;
    int value;
    int type;

public:
    Card();
    Card(int ccolor, int vvalue, int ttype);

    int getColor() const;
    int getValue() const;
    std::string toString() const;
};

#endif