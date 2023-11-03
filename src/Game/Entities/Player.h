#pragma once

#include <vector>
#include "Animation.h"
#include "EntityManager.h"
#include "Powerup.h" // Include the Powerup header

enum MOVING {
    MUP,
    MDOWN,
    MLEFT,
    MRIGHT,
};

class Player : public Entity {

private:
    int spawnX, spawnY;
    int health = 3;
    int score = 0;
    bool canMoveUp, canMoveDown, canMoveRight, canMoveLeft;
    int speed = 4;
    bool walking = false;
    MOVING moving;
    FACING facing = DOWN;
    ofImage up, down, left, right;
    Animation *walkUp;
    Animation *walkDown;
    Animation *walkLeft;
    Animation *walkRight;
    EntityManager* em;

    // Vector to store power-ups
    std::vector<Powerup*> powerups; // New attribute for power-ups

public:
    Player(int, int, int , int, EntityManager*);
    ~Player();
    int getHealth();
    int getScore();
    FACING getFacing();
    void setHealth(int);
    void setScore(int);
    void setFacing(FACING facing);
    void tick();
    void render();
    void keyPressed(int);
    void keyReleased(int);
    void damage(Entity* damageSource);
    void mousePressed(int, int, int);
    void reset();
    void checkCollisions();
    void die();

    // New methods for power-up functionality
    void addPowerup(Powerup* p); // Add a power-up to the collection
    void activatePowerup();      // Activate the next power-up
};
