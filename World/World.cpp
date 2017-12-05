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

World::World(int _width, int _height) {
    height = _height;
    width = _width;

    board.resize(height);
    for (int i = 0; i < height; i++) {
        board[i].resize(width);
        for (int j = 0; j < width; j++) {
            board[i][j] = ' ';
        }
    }
}

void World::init() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            double r = (double) rand() / RAND_MAX;
            if(r < 0.50) {
                board[i][j] = 'H';
            }
        }
    }
    board[rand() % height][rand() % width] = 'Z';
}

void World::drawGrid() {
    for (int i = 0; i < height; i++) {
        // Print top border for the row
        for (int k = 0; k < width; k++) {
            cout << "+---";
        }
        cout << "+" << endl << "| ";
        // Print each value in the row
        for (int j = 0; j < width; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
    }

    // Print bottom border for the grid
    for (int k = 0; k < width; k++) {
        cout << "+---";
    }
    cout << "+" << endl;
}
