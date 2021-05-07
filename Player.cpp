#include "Player.h"

// The following code is used to test saving a game
Player::Player(std::string name) {
    this->name = name;
    this->score = 0;
    this->hand = std::make_shared<LinkedList>();
}

std::string Player::getName() {
    return this->name;
}

std::string Player::toString() {
    return this->name + "\n" + std::to_string(this->score) + "\n" + this->hand->toString();
}

std::shared_ptr<LinkedList> Player::getHand() {
    return this->hand;
}

void Player::setScore(int score) {
    this->score = score;
}

Player::~Player() {

}

std::shared_ptr<Tile> Player::getTile(std::string tile) {
    return nullptr;
}

void Player::addTile(std::string tile) {

}

void Player::addTile(std::shared_ptr<Tile> tile) {

}

int Player::getScore() {
    return 0;
}
