#ifndef GAME_H
#define GAME_H

using namespace std;

class Game {
public:
    virtual void startGame() = 0;
    virtual ~Game() {}
};

#endif
