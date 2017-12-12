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

char Human::generateRandomMove() {
    int r = rand() % 4;

    if(r == 0) return 'R';
    else if(r == 1) return 'D';
    else if(r == 2) return 'L';
    else if(r == 3) return 'U';
}

bool Human::isLegalMove(char moveChar) {
    return moveChar == 'Z' || moveChar == ' ';
}


