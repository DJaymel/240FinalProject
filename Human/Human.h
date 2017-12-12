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

#ifndef FINALPROJECT_HUMAN_H
#define FINALPROJECT_HUMAN_H


class Human {
public:
    Human();
    //~Human();
    Human(int, int);
    void move(int, int);
    char generateRandomMove();
    int getRow();
    int getCol();
    virtual bool isLegalMove(char);


private:
    int row;
    int col;
};



#endif //FINALPROJECT_HUMAN_H
