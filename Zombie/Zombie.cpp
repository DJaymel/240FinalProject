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

#include "Zombie.h"

Zombie::Zombie(int _col, int _row) : Human(_col, _row) {
}

bool Zombie::isLegalMove(char moveChar) {
    return moveChar == 'H' || moveChar == ' ';
}
