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
    //srand(time(NULL));

    World world;
     world.init();

    int day = 1;
    while(true) {
        cout << "Day " << day++ << endl;
        world.drawGrid();

        cout << "Press Enter to Continue. Type 'q' and Press Enter to Quit" << endl;
        char ans;
        cin.get(ans);
        if(ans == 'q') {
            break;
        }
    }

    return 0;
}
