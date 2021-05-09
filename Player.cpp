#include "Player.h"

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
    SharedTile found = nullptr;
    for (int i = 0; i < hand->size() && !found; i++) {
        auto tile = hand->getTile(i);
        if (tile->getColour() == color && tile->getShape() == shape) {
            found = tile;
        }

    }
    return found;
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

bool Player::removeTile(const SharedTile& toRemove) {
    bool removed = false;
    for (int i = 0; i < hand->size() && !removed; i++) {
        SharedTile tile = hand->getTile(i);
        if (tile == toRemove) {
            hand->deleteTile(i);
            removed = true;
        }
    }
    return removed;
}

int Player::getScore() {
    return score;
}
