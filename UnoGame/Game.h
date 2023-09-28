#include "Card.h"
#include <iostream>
#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Card.h"

class Game {
private:
    Card* listD[108];
    int player;
    int point1, point2;
    int currentColor;
    Player player1;
    Player player2;

public:
    Game();

    void plusTwo(Player& currentPlayer, Player& nextPlayer);

    void plusFour(Player& currentPlayer, Player& nextPlayer);

    bool counterPlusFour(Player& currentPlayer);

    void changeColor(Player& currentPlayer);

    void startGame();

    void playerTurn();

    void putCard();

    void takeCards();

    void sayUno();

    void winGame();
};

#endif