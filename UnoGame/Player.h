#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <string>

const int MAX_HAND_SIZE = 7;

class Player {
private:
    std::string name;
    int cardsInHand;
    Card hand[MAX_HAND_SIZE];

public:
    Player(std::string playerName);

    void addToHand(Card card);
    Card getCard(int index) const;
    void removeCard(int index);
    int getCardsInHand() const;

    const std::string& getName() const;
    void addToHand(int numCards);
};

#endif