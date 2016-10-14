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


int Mob::getHealthPoints(){
    return healthPoints;
}

//Method for reducing the health points based on how much damage has been given to a character
void Mob::reduceHealthPoints(int damageGiven){
    healthPoints -= damageGiven;
}

//Method for dealing a random amount of damage
int Mob::getDamage(){
   
    int damageDealt = rand()%10 ;
    return damageDealt;
}

void Mob::placeOnGrid(){
 
    int row = rand()% 11;
    int col = rand()% 7;
    
    colPos = col;
    rowPos = row;
    
}
