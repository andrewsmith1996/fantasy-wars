//
//  kruse.h
//  fantasywars
//
//  Created by Andrew Smith on 12/10/2016.
//  Copyright © 2016 Andrew Smith. All rights reserved.
//

#ifndef character_h
#define character_h

#include <string>

using namespace std;

//Class for the  character

class Character{
    private:
        int healthPoints;
        string name = "Kruse";
        string weapon = "Sword";
        int rowPos;
        int colPos;
    public:
        int getHealthPoints();
        void reduceHealthPoints(int damage);
        int getDamage();
        string getName();
        void setRowPos(int number);
        void setColPos(int number);
    
        int getRowPos(){
            return rowPos;
        }
    
        int getColPos(){
            return colPos;
        }
    
        void setInitialHealth(){
            healthPoints = 100;
        }
};


#endif /* kruse_h */
