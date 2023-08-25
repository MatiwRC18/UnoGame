#pragma once
#include <iostream>
#include "Card.h"

class UnoGame {

private:

	    Card* deck[108];
		int player;
	    int pointA, pointB;

public:
    UnoGame();

    void initializeDeck();
    void shuffleDeck();
    void dealInitialCards();
    void startGame();

    void shift();
    void sayUno();
    void useCard();
    void useCardAndSkip();
    void takeCards();

};