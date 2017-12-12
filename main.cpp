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

#include <iostream>
#include <stdlib.h>
#include <ctime>

#include "World/World.h"

int main() {
    // Sets the c++ random seed to the current time. Ensures random generates different numbers for each execution
    srand(time(NULL));

    World world;
    world.init();

    int day = 1;
    char ans;
    cout << "Press Enter to Start" << endl;
    while(cin.get(ans) && ans != 'q') {
        cout << "Day " << day++ << endl;
        world.drawGrid();
        if(world.gameOver()) {
            cout << "GAME OVER!." << endl;
            exit(0);
        }
        cout << "Press Enter to Continue. Type 'q' and Press Enter to Quit" << endl;
        world.update(true);
    }

    return 0;
}
