/***************************************************************************
 * Name: Michael Afrin & Jaymel Dash                                                                                     *
 * Email: mafrin@email.sc.edu | jwdash@email.sc.edu                                                             *
 * Date: 12/4/2017                                                                                                                       *
 * Function:
 * Input:
 * Output:
 * Additional Comments:
 *                                                                                                                                                  *
 * Copyright (C) 2017 by Michael Afrin & Jaymel Dash                                                           *
 ***************************************************************************/

#ifndef FINALPROJECT_WORLD_H
#define FINALPROJECT_WORLD_H

#include <vector>
#include <stdlib.h>

#include "../Human/Human.h"
#include "../Zombie/Zombie.h"

using namespace std;

class World {
public:
    World();
    World(int, int);
    void init();
    void drawGrid();
    void update();

private:
    int width;
    int height;
    vector< vector<char> > board;
    vector<Human> humans;
    vector<Zombie> zombies;
};


#endif //FINALPROJECT_WORLD_H
