#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>

class Board {
public:
    Board(int rows, int cols, int mines);
        void printBoard();
        bool revealTile(int row, int col);
        void markTile(int row, int col);
        bool isGameWon() const;
        
        void saveToFile(const std::string& filename);
        bool loadFromFile(const std::string& filename);


    private:
        void placeMines();
        int countAdjacentMines(int row, int col) const;

        std::vector<std::vector<char>> board;
        int rows;
        int cols;
        int mines;
    };

#endif
    