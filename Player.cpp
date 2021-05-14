#include "Player.h"
#include "iostream"

// The following code is used to test saving a game
Player::Player(string name) {
    this->name = name;
    this->score = 0;
    this->hand = std::make_shared<LinkedList>();
}

string Player::getName() {
    return this->name;
}

string Player::toString() {
    return this->name + "\n" + std::to_string(this->score) + "\n" + this->hand->toString();
}

std::shared_ptr<LinkedList> Player::getHand() {
    return this->hand;
}

SharedTile Player::hasTile(Colour color, Shape shape) {
    SharedTile tile = std::make_shared<Tile>(color, shape);
    return hand->getTile(tile);
}

void Player::setHand(std::shared_ptr<LinkedList> hand) {
    this->hand = hand;
}

void Player::setScore(int score) {
    this->score = score;
}

Player::~Player() = default;

SharedTile Player::getTile(string tile) {
    return nullptr;
}

void Player::addTile(SharedTile tile) {
    hand->addTile(std::move(tile));

}

bool Player::removeTile(const SharedTile & toRemove) {
    return this->hand->deleteTile(toRemove) != nullptr;
}

int Player::getScore() {
    return score;
}

void Player::addScore(int score) {
    this->score += score;
}
