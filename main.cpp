#include "Game.h"
#include "Board.h"
#include <iostream>

int main() {
    char choice;
    std::cout << "Would you like to load a saved game? (Y/N): ";
    std::cin >> choice;

    Game game(1); // Temporär initialisering, ändras om vi laddar ett spel

    if (choice == 'Y' || choice == 'y') {
        if (!game.loadFromFile("saved_game.txt")) {
            std::cout << "Unable to load game, starting a new game." << std::endl;
        }
    } else {
        int level;
        std::cout << "Chose level: 1 (Beginner), 2 (Intermediate), 3 (Advanced): ";
        std::cin >> level;
        game = Game(level); // Skapa ett nytt spel baserat på svårighetsgrad
    }

    game.start();

    return 0;
}