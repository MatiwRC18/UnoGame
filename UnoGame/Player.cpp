#include "Player.h"

Player::Player(std::string playerName) : name(playerName), cardsInHand(0) {}

void Player::addToHand(Card card) {
    if (cardsInHand < MAX_HAND_SIZE) {
        hand[cardsInHand] = card;
        cardsInHand++;
    }
}

Card Player::getCard(int index) const {
    return hand[index];
}

void Player::removeCard(int index) {
    
    for (int i = index; i < cardsInHand - 1; i++) {
        hand[i] = hand[i + 1];
    }
    cardsInHand--;
}

int Player::getCardsInHand() const {
    return cardsInHand;
}

const std::string& Player::getName() const {
    return name;
}

void Player::addToHand(int numCards) {
  
}