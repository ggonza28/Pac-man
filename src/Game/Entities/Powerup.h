#ifndef POWERUP_H
#define POWERUP_H

#include "Entity.h"

class Powerup : public Entity {
public:
    // Constructor
    Powerup();

    // Virtual destructor to ensure proper cleanup of data that might be used by subclasses
    virtual ~Powerup();

    // The activate function that must be implemented by all subclasses
    virtual void activate() = 0;


};

#endif // POWERUP_H
