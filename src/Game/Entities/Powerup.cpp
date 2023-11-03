#include "Powerup.h"
#include "Entity.h"

// Constructor definition
Powerup::Powerup() : Entity(0, 0, 1, 1){
    // Initialization specific to Powerup
}

// Virtual destructor definition
Powerup::~Powerup() {
    // Cleanup
}
