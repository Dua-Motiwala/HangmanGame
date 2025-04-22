#ifndef GAME_H
#define GAME_H

#include <string>

class Game {
public:
    virtual void startGame() = 0;
    virtual ~Game() {}
};

#endif