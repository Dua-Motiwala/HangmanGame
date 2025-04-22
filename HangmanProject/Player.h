#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    int score;

public:
    Player(const std::string& name);
    void incrementScore();
    std::string getName() const;
    int getScore() const;
};

#endif
