#ifndef MOB_H
#define MOB_H

#include <SFML/Graphics.hpp>
#include "Entity/Mob.h"
#include "Entity/Entity.h"
#include <Animation.h>
#include <iostream>
#include <math.h>

#define FRICTION 0.9
typedef std::vector<std::vector<int>> VI;

class Mob : public Entity {
public:
    Mob();
    ~Mob();

    virtual void load(sf::Vector2f pos, sf::Texture &texture, float MAX_VEL, sf::Vector2i mSize);
    virtual void unload();
    virtual void update(VI colMap, sf::Time delta);


    void moveM(VI colMap, sf::Time delta);
    void checkCollision(VI colMap, sf::Time delta);

    void jump();

    void setAccelerationX(float a);
    void setAccelerationY(float a);
    void setVelocityX(float v);
    void setVelocityY(float v);
    void setState(int state);
    void addAcceleration(sf::Vector2f v);

    Animation &getAnimation();
    int getState();

    float getHP();
    float getSTR();
    float getDEF();
    void subHP(float dmg);
    void addHP(float heal);
protected:
    // Physics
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    float MAX_VEL;

    // Graphics
    sf::Vector2i mSize;
    Animation animation;

    // Collision
    std::vector<sf::FloatRect> collidable;
    sf::FloatRect collision;
    sf::FloatRect bounds;
    int startX, endX, startY, endY;
private:
    void collidableTiles(VI colMap, int startX, int endX, int startY, int endY);
    enum direction { UP, DOWN, LEFT, RIGHT };
    enum state { STILL, MOVING, JUMPING, FALLING };
    bool contains(sf::FloatRect x, sf::FloatRect y);
    int STATE;

    // Jumping
    float jumpF = 0;
    sf::Time jumpDelta = sf::Time::Zero;

    // Attributes
    float hp;
    float str;
    float def;
};

#endif // MOB_H
