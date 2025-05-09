#include "Player.h"

using namespace std;

Player::Player(const string& name) : name(name), score(0) {
}

void Player::incrementScore() {
    score++;
}

string Player::getName() const {
    return name;
}

int Player::getScore() const {
    return score;
}