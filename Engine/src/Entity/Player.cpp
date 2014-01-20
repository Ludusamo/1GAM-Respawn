#include "Entity/Player.h"

Player::Player() {
    //ctor
}

Player::~Player() {
    //dtor
}

void Player::load(sf::Vector2f pos, sf::Texture &texture, float MAX_VEL, sf::Vector2i mSize) {
    Mob::load(pos, texture, MAX_VEL, mSize);

    animation.load(0, 0, 3, .2);
}

void Player::update(VI colMap, sf::Time delta) {
    Mob::update(colMap, delta);
}
