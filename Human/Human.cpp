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

#include "../World/World.h"
#include "../Human/Human.h"

using namespace std;

Human::Human() {}

Human::Human(int _col, int _row){
    col = _col;
    row = _row;
}

int Human::getRow() {
    return row;
}

int Human::getCol() {
    return col;
}

void Human::move(int _col, int _row) {
    col = _col;
    row = _row;
}


