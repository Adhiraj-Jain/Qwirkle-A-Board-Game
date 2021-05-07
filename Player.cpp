#include "Player.h"

// The following code is used to test saving a game
Player::Player(std::string name) {
    this->name = name;
    this->score = 0;
    this->hand = new LinkedList();
}

std::string Player::getName() {
    return this->name;
}

std::string Player::toString() {
    return this->name + "\n" + std::to_string(this->score) + "\n" + this->hand->toString();
}

LinkedList *Player::getHand() {
    return this->hand;
}

void Player::setScore(int score) {
    this->score = score;
}