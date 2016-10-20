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
        int healthPoints = 100;
    public:
        int getHealthPoints();
        void setHealthPoints(int damage);
        int getDamage();
        void placeOnGrid();
        int colPos;
        int rowPos;
    

    

    
    
};





#endif /* mob_h */
