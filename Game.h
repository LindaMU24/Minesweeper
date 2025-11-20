#ifndef GAME_H
#define GAME_H

#include <memory>
#include "Board.h"

class Game {
public:
    Game(int level);
    bool loadFromFile(const std::string& filename);
    void start();

private:
    void processInput();
    std::unique_ptr<Board> board;
};

#endif
    