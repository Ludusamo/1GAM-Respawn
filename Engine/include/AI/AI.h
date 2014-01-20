#ifndef AI_H
#define AI_H

#include <SFML/Graphics.hpp>
#include "Entity/Entity.h"
#include "Entity/Mob.h"

class AI : public Mob {
public:
    AI();
    ~AI();

    void load(sf::Vector2f pos, sf::Texture &texture, float MAX_VEL, sf::Vector2i mSize, int t);
    void update(VI colMap, sf::Time delta);
    virtual void attack();
protected:
private:
    enum team { FRIEND, FOE };
    int TEAM;

    int rng;
};

#endif // AI_H
