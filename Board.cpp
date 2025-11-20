#include "Board.h"
#include <iostream>
#include <random>
#include <fstream>

Board::Board(int rows, int cols, int mines) 
    : rows(rows), cols(cols), mines(mines), board(rows, std::vector<char>(cols, ' ')) {
    placeMines(); // Placera minor när brädet skapas
}

void Board::printBoard() {
    std::cout << "   ";
    for (int c = 0; c < cols; ++c) {
        std::cout << c << ' ';
    }
    std::cout << std::endl;

    std::cout << "  +" << std::string(cols * 2 - 1, '-') << "+" << std::endl;

    for (int r = 0; r < rows; ++r) {
        std::cout << r << " |";
        for (int c = 0; c < cols; ++c) {
            if (board[r][c] == '*') {
                std::cout << ' '; // Dölj minan
            } else {
                std::cout << board[r][c];
            }
            if (c < cols - 1) std::cout << '|'; // Vertikalt skiljestreck mellan kolumner
        }
        std::cout << "|" << std::endl;
        std::cout << "  +" << std::string(cols * 2 - 1, '-') << "+" << std::endl;
    }
}


void Board::placeMines() {
    std::random_device rd; //Placera minor slumpmässigt
    std::mt19937 gen(rd()); //Placera minor slumpmässigt
    std::uniform_int_distribution<> disRow(0, rows - 1);
    std::uniform_int_distribution<> disCol(0, cols - 1);

    int placedMines = 0;
    while (placedMines < mines) {
        int r = disRow(gen);
        int c = disCol(gen);
        if (board[r][c] != '*') {
            board[r][c] = '*'; // Placera en mina
            ++placedMines;
        }
    }
}

bool Board::revealTile(int row, int col) {
    if (board[row][col] == '*') {
        board[row][col] = 'X'; // Markera minans plats med 'X'
        return false; // Spelet förloras
    } else {
        int adjacentMines = countAdjacentMines(row, col);
        board[row][col] = '0' + adjacentMines; // Visa antalet angränsande minor
        return true; // Spelet fortsätter
    }
}

int Board::countAdjacentMines(int row, int col) const {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int newRow = row + i;
            int newCol = col + j;
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                if (board[newRow][newCol] == '*') {
                    ++count;
                }
            }
        }
    }
    return count;
}

void Board::markTile(int row, int col) {
    if (board[row][col] == ' ') {
        board[row][col] = 'M'; // Markera som potentiell mina
    } else if (board[row][col] == 'M') {
        board[row][col] = ' '; // Avmarkera
    }
}

bool Board::isGameWon() const {
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (board[r][c] == ' ' && board[r][c] != '*') {
                return false; // Det finns fortfarande icke-avslöjade rutor
            }
        }
    }
    return true; // Alla icke-minorutor är avslöjade
}

void Board::saveToFile(const std::string& filename) {
    std::cout << "Saving game to file..." << std::endl; // Debug-utskrift

    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Not able to open file to save." << std::endl;
        return;
    }

    outFile << rows << " " << cols << " " << mines << std::endl;
    for (const auto& row : board) {
        for (char c : row) {
            outFile << c;
        }
        outFile << std::endl;
    }

    outFile.close();
    std::cout << "Game saved successfully!" << std::endl; // Bekräftelseutskrift
}


bool Board::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Not able to load file." << std::endl;
        return false;
    }

    inFile >> rows >> cols >> mines;
    board.resize(rows, std::vector<char>(cols, ' '));
    for (auto& row : board) {
        for (char& c : row) {
            inFile >> c;
        }
    }

    inFile.close();
    return true;
}
