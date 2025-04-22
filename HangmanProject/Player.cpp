#include "Player.h"

Player::Player(const std::string& name) : name(name), score(0) {}

void Player::incrementScore() { score++; }

std::string Player::getName() const { return name; }

int Player::getScore() const { return score; }
