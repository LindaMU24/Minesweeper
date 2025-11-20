#include "Game.h"
#include <iostream>
#include <limits>

bool Game::loadFromFile(const std::string& filename) {
    return board->loadFromFile(filename);
}

Game::Game(int level) {
    int rows, cols, mines;
    switch (level) {
        case 1: // Beginner
            rows = 9;
            cols = 9;
            mines = 10;
            break;
        case 2: // Intermediate
            rows = 16;
            cols = 16;
            mines = 40;
            break;
        case 3: // Advanced
            rows = 24;
            cols = 24;
            mines = 99;
            break;
        default:
            std::cout << "Invalid level. Standardlevel (Beginner) is being used." << std::endl;
            rows = 9;
            cols = 9;
            mines = 10;
            break;
    }
    board = std::make_unique<Board>(rows, cols, mines);
}

void Game::start() {
    board->printBoard();
    while (true) {
        char action;
        int row, col;
        std::cout << "Make your move (R to reveal, M to mark, S to save, Q to quit) followed by row and column (eg. R 3 2): ";
        std::cin >> action;

        if (action == 'S' || action == 's') {
            board->saveToFile("saved_game.txt");
            std::cout << "Game saved!" << std::endl;
            continue; // Fortsätt spelet efter att ha sparat
        }
        if (action == 'Q' || action == 'q') {
        char saveChoice;
        std::cout << "Do you want to save the game before quitting? (Y/N): ";
        std::cin >> saveChoice;
        if (saveChoice == 'Y' || saveChoice == 'y') {
            board->saveToFile("saved_game.txt");
            std::cout << "Game saved!" << std::endl;
        }
        break;
    }

        std::cin >> row >> col;

        if (!std::cin) {
            std::cout << "Invalid input, try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (action == 'R' || action == 'r') {
            if (!board->revealTile(row, col)) {
                std::cout << "Game over! You stepped on a mine." << std::endl;
                board->printBoard();
                break;
            }
        } else if (action == 'M' || action == 'm') {
            board->markTile(row, col);
        } else {
            std::cout << "Invalid input, try again." << std::endl;
            continue;
        }

        board->printBoard();

        if (board->isGameWon()) {
            std::cout << "Congratulations! You won the game!" << std::endl;
            break;
        }
    }
}