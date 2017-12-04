/***************************************************************************
 * Name: Michael Afrin
 * Email: mafrin@email.sc.edu
 * Date: 12/4/2017
 * Function:
 * Input:
 * Output:
 * Additional Comments:
 *                                                                         * 
 * Copyright (C) 2017 by Michael Afrin                                     *
 ***************************************************************************/

#ifndef FINALPROJECT_WORLD_H
#define FINALPROJECT_WORLD_H

#include <vector>

#include "../Human/Human.h"
#include "../Zombie/Zombie.h"

using namespace std;

class World {
public:
    World();
    World(int, int);
    void drawGrid();
    void update();

private:
    vector< vector<char> > board;
    vector<Human> humans;
    vector<Zombie> zombies;
};


#endif //FINALPROJECT_WORLD_H
