//
//  mob.cpp
//  fantasywars
//
//  Created by Andrew Smith on 12/10/2016.
//  Copyright © 2016 Andrew Smith. All rights reserved.
//

#include <stdio.h>
#include "mob.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;






//Method for reducing the health points based on how much damage has been given to a character
void Mob::setHealthPoints(int damageGiven){
    healthPoints -= damageGiven;
}

//Method for dealing a random amount of damage
int Mob::getDamage(){
    
    int doesDamage = (rand() % 2) + 1;
    int damageDealt;
    
    switch(doesDamage){
        case 1:
             damageDealt = (rand() % 20) + 1;
            break;
        case 2:
            damageDealt = 0;
            break;
        default:
            damageDealt = 0;
            cout << "Error - Please Restart Fantasy Wars" << endl;
    }
    
    return damageDealt;
}

void Mob::placeOnGrid(){
    
    //Minus 1 row to allow character spawing not on enemy
    int row = rand() % 19;
    int col = rand() % 13;
    
    colPos = col;
    rowPos = row;
    
}

void Mob::setRowPos(int pos){
    rowPos = pos;
}

void Mob::setColPos(int pos){
    colPos = pos;
}
