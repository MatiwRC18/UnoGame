#pragma once
#include <iostream>

using namespace std;



class Card {

private:
	int* cardList[108];
	int color;
	int value;
	int cardType;


public:

	Card() {};
	Card(const int col, int val, int typ) {

		color = col;
		value = val;
		cardType = typ;
	}

	int getColor() const;
	int getValue() const;
	void setColor(const int& c);
	void setValue(int v);
};


const int red = 0;
const int green = 1;
const int yellow = 2;
const int blue = 3;

const int changeDecks = 0;
const int skipTurn = 1;
const int reverse = 2;
const int plusTow = 3;
const int plusfour = 4;
const int changeColor = 5;


