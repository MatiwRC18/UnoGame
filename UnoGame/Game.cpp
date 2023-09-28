#include "Game.h"
#include "Card.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

Game::Game() : currentColor(1), player1("Player 1"), player2("Player 2"), player(1) {}

void Game::plusTwo(Player& currentPlayer, Player& nextPlayer) {
    cout << currentPlayer.getName() << " played a +2 card!" << endl;
    cout << nextPlayer.getName() << " must draw 2 cards from the main deck." << endl;
    nextPlayer.addToHand(2);
};

void Game::plusFour(Player& currentPlayer, Player& nextPlayer) {
    cout << currentPlayer.getName() << " played a +4 card!" << endl;
    cout << nextPlayer.getName() << " must draw 4 cards from the main deck." << endl;
    nextPlayer.addToHand(4);
}

bool Game::counterPlusFour(Player& currentPlayer) {
    bool hasPlusTwoCard = (rand() % 2) == 0;

    if (hasPlusTwoCard) {
        cout << currentPlayer.getName() << " countered the +4 card with a +2 card!" << endl;
    }

    return hasPlusTwoCard;
}

void Game::changeColor(Player& currentPlayer) {
    int newColor = 1 + rand() % 4;
    currentColor = newColor;

    cout << currentPlayer.getName() << " played a changeColor card!" << endl;
    cout << currentPlayer.getName() << " chose the new color: ";

    switch (currentColor) {
    case 1:
        cout << "RED" << endl;
        break;
    case 2:
        cout << "GREEN" << endl;
        break;
    case 3:
        cout << "BLUE" << endl;
        break;
    case 4:
        cout << "YELLOW" << endl;
        break;
    }
}

void Game::startGame() {
    cout << "Welcome to the Uno game!" << endl;
    cout << "Let's start the game." << endl;
  
}

void Game::playerTurn() {
    Player& currentPlayer = (player == 1) ? player1 : player2;
    std::cout << currentPlayer.getName() << "'s turn. Hand: ";

    
    for (int i = 0; i < currentPlayer.getCardsInHand(); ++i) {
        std::cout << "[" << i << "] " << currentPlayer.getCard(i).toString() << " ";
    }
    std::cout << std::endl;

    
    std::cout << "Elige la carta que deseas jugar (): ";
    int cardIndex;
    std::cin >> cardIndex;

    
    if (cardIndex >= 0 && cardIndex < currentPlayer.getCardsInHand()) {
        Card playedCard = currentPlayer.getCard(cardIndex);

        
        currentPlayer.removeCard(cardIndex);  

      
        player = (player == 1) ? 2 : 1;
    }
    else {
        std::cout << "Índice de carta inválido. Intenta de nuevo." << std::endl;
    }
}