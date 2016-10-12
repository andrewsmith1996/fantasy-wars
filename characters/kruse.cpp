//
//  kruse.cpp
//  fantasywars
//
//  Created by Andrew Smith on 12/10/2016.
//  Copyright © 2016 Andrew Smith. All rights reserved.
//

#include <stdio.h>
#include "kruse.h"
#include <cstdlib>

//Method for returning the number of health points a character has
int Kruse::getHealthPoints(){
    return healthPoints;
}

//Method for reducing the health points based on how much damage has been given to a character
void Kruse::reduceHealthPoints(int damageGiven){
    healthPoints -= damageGiven;
}

//Method for dealing a random amount of damage
int Kruse::getDamage(){
    int damageDealt = (rand() % 20) + 1;
    return damageDealt;
}

string Kruse::getName(){
    return name;
}
