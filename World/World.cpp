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

#include <iostream>

#include "World.h"

using namespace std;

World::World() : World(8, 8){}

World::World(int width, int height) {
    board.resize(height);
    for (int i = 0; i < height; i++) {
        board[i].resize(width);
        for (int j = 0; j < width; j++) {
            board[i][j] = 'H';
        }
    }
}

void World::drawGrid() {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
