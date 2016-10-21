//
//  mob.h
//  fantasywars
//
//  Created by Andrew Smith on 12/10/2016.
//  Copyright © 2016 Andrew Smith. All rights reserved.
//

#ifndef mob_h
#define mob_h

class Mob{
    
    private:
        int healthPoints;
        int colPos;
        int rowPos;
    public:
    
        int getHealthPoints(){
            return healthPoints;
        }
    
        void setInitialHealth(){
            healthPoints = 100;
        }
    
        void setHealthPoints(int damage);
        int getDamage();
        void placeOnGrid();
        void setRowPos(int number);
        void setColPos(int number);

    
        int getRowPos(){
            return rowPos;
        }
    
        int getColPos(){
            return colPos;
        }
    
    


    

    
    
};





#endif /* mob_h */
