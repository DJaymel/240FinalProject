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

#ifndef FINALPROJECT_ZOMBIE_H
#define FINALPROJECT_ZOMBIE_H

#include "../Human/Human.h"

class Zombie : public Human{
public:
    Zombie(int, int);
    bool isLegalMove(char);
};


#endif //FINALPROJECT_ZOMBIE_H
