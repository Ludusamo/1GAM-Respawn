#include "Animation.h"

Animation::Animation() {
    //ctor
}

Animation::~Animation() {
    //dtor
}

void Animation::load(int startIndexX, int startIndexY, int totalFrames, float delay) {
    this->startIndexX = startIndexX;
    this->startIndexY = startIndexY;
    this->totalFrames = totalFrames;
    this->delay = delay;
    elapsedTime = 0;
    currentAnimationIndex = 0;
    modifier = 0;
}

void Animation::unload() {

}

void Animation::update(sf::VertexArray &vertices, float mSize, sf::Time delta) {
    elapsedTime += delta.asSeconds();
    if (elapsedTime > delay) {
        if (currentAnimationIndex + 1 < totalFrames) currentAnimationIndex++;
        else currentAnimationIndex = 0;
        elapsedTime = 0;
    }
    vertices[0].texCoords = sf::Vector2f((startIndexX * mSize) + (currentAnimationIndex * mSize), (startIndexY * mSize) + (modifier * mSize));
    vertices[1].texCoords = sf::Vector2f((startIndexX * mSize) + (currentAnimationIndex * mSize) + mSize, (startIndexY * mSize) + (modifier * mSize));
    vertices[2].texCoords = sf::Vector2f((startIndexX * mSize) + (currentAnimationIndex * mSize) + mSize, (startIndexY * mSize) + mSize + (modifier * mSize));
    vertices[3].texCoords = sf::Vector2f((startIndexX * mSize) + (currentAnimationIndex * mSize), (startIndexY * mSize) + mSize + (modifier * mSize));
}

void Animation::setModifier(int x) {
    modifier = x;
}
