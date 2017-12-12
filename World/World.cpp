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
                Human human(j, i);
                humans.push_back(human);
            }
        }
    }
    int rY = rand() % height;
    int rX = rand() % width;
    board[rY][rX] = 'Z';
    Zombie zombie(rX, rY);
    zombies.push_back(zombie);
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

void World::update(bool debug) {
    // Looping through vector backwards, to prevent skipping if a index is erased mid loop
    for(int i = zombies.size()-1; i >= 0; i--) {
        Zombie & zombie = zombies.at(i);
        int col = zombie.getCol();
        int row = zombie.getRow();

        char move = zombie.generateRandomMove();

        if(move == 'R') col += 1;
        else if(move == 'D') row += 1;
        else if(move == 'L') col -= 1;
        else if(move == 'U') row -= 1;

        // If move is off the board, continue to next human
        if(col < 0 || col >= board.size() || row < 0 || row >= board.size()) continue;
        char type = board[row][col];
        if(zombie.isLegalMove(type)) {
            if(type == ' ') {
                if(debug) cout << "Zombie moving from (" << zombie.getRow() << ", " << zombie.getCol() << ") to (" << row << ", " << col << ")" << endl;
                board[zombie.getRow()][zombie.getCol()] = ' ';
                board[row][col] = 'Z';
                zombie.move(col, row);
            }
            else if (type == 'H') {
                if(debug) cout << "Human turning into zombie at (" << row << ", " << col << ")" << endl;
                board[row][col] = 'Z';
                Zombie zombie(col, row);
                zombies.push_back(zombie);
                for(int j = 0; j < humans.size(); j++) {
                    Human human = humans.at(j);
                    if(human.getRow() == row && human.getCol() == col) {
                        humans.erase(humans.begin() + j);
                        break;
                    }
                }
            }
        }
    }

    for(int i = humans.size()-1; i >= 0; i--) {
        Human & human = humans.at(i);
        int col = human.getCol();
        int row = human.getRow();
        char move = human.generateRandomMove();

        if(move == 'R') col += 1;
        else if(move == 'D') row += 1;
        else if(move == 'L') col -= 1;
        else if(move == 'U') row -= 1;

        // If move is off the board, continue to next human
        if(col < 0 || col >= board.size() || row < 0 || row >= board.size()) continue;
        char type = board[row][col];

        if(human.isLegalMove(type)) {
            if(type == ' ') {
                if(debug) cout << "Human moving from (" << human.getRow() << ", " << human.getCol() << ") to (" << row << ", " << col << ")" << endl;
                board[human.getRow()][human.getCol()] = ' ';
                board[row][col] = 'H';
                human.move(col, row);
            }
            else if (type == 'Z') {
                if((rand() / RAND_MAX) < 0.50) {
                    if(debug) cout << "Human turning to zombie at (" << human.getRow() << ", " << human.getCol() << ")" << endl;
                    board[human.getRow()][human.getCol()] = 'Z';
                    Zombie zombie(human.getCol(), human.getRow());
                    humans.push_back(zombie);
                    humans.erase(humans.begin()+i);
                } else {
                    if(debug) cout << "Human killed zombie on spot (" << row << ", " << col << ")" << endl;
                    board[human.getRow()][human.getCol()] = ' ';
                    board[row][col] = 'H';
                    human.move(col, row);
                    for(int j = 0; j < zombies.size(); j++) {
                        Zombie zombie = zombies.at(j);
                        if(zombie.getRow() == row && zombie.getCol() == col) {
                            zombies.erase(zombies.begin() + j);
                            break;
                        }
                    }
                }

            }
        }
    }
}

bool World::gameOver() {
    return humans.empty() || zombies.empty();
}
