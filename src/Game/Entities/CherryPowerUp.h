#ifndef CHERRYPOWERUP_H
#define CHERRYPOWERUP_H

#include "Powerup.h"

class CherryPowerUp : public Powerup {
public:
    // Constructor
    CherryPowerUp();

    // Override the activate method to teleport Pacman
    void activate() override;
};

#endif // CHERRYPOWERUP_H
