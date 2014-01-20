#include "AI/AI.h"

AI::AI() {
    //ctor
}

AI::~AI() {
    //dtor
}

void AI::load(sf::Vector2f pos, sf::Texture &texture, float MAX_VEL, sf::Vector2i mSize, int t) {
    Mob::load(pos, texture, MAX_VEL, mSize);
    this->TEAM = t;

    animation.load(0, 0, 3, .2);
}

void AI::update(VI colMap, sf::Time delta) {
    setAccelerationY(0);
    if (velocity.x < 1) jump();
    if (TEAM == FRIEND && STATE != JUMPING) setAccelerationX(2);
    Mob::update(colMap, delta);
}

void AI::attack() {

}
