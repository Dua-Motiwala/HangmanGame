#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player {
private:
    string name;
    int score;

public:
    Player(const string& name);
    void incrementScore();
    string getName() const;
    int getScore() const;
};

#endif