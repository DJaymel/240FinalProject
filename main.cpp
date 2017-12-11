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
    while(true) {
        cout << "Day " << day++ << endl;
        world.drawGrid();
        if(world.gameOver()) {
            cout << "GAME OVER. ALL HUMANS ARE DEAD." << endl;
            exit(0);
        }
        cout << "Type 'c' and Press Enter to Continue. Type 'q' and Press Enter to Quit" << endl;
        char ans;
        cin >> ans;
        if(ans == 'q') {
            break;
        } else if (ans == 'c') {
            // Update method takes in a bool which when true, will print debug statements
            world.update(false);
        }
    }

    return 0;
}
