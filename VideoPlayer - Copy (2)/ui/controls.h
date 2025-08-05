#ifndef CONTROLS_H
#define CONTROLS_H

#include "../core/player.h"

class Controls {
public:
    Controls(Player* player); // Ensure this matches the implementation
    void handleInput();

private:
    Player* player;
};

#endif