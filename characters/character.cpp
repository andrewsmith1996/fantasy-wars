//
//  kruse.cpp
//  fantasywars
//
//  Created by Andrew Smith on 12/10/2016.
//  Copyright © 2016 Andrew Smith. All rights reserved.
//

#include <stdio.h>
#include "character.h"
#include <cstdlib>

//Method for returning the number of health points a character has
int Character::getHealthPoints(){
    return healthPoints;
}

//Method for reducing the health points based on how much damage has been given to a character
void Character::reduceHealthPoints(int damageGiven){
    healthPoints -= damageGiven;
}

//Method for dealing a random amount of damage
int Character::getDamage(){
    int damageDealt = (rand() % 20) + 1;
    return damageDealt;
}

string Character::getName(){
    return name;
}

void Character::setRowPos(int pos){
    rowPos = pos;
}

void Character::setColPos(int pos){
    colPos = pos;
}
