//
//  kruse.h
//  fantasywars
//
//  Created by Andrew Smith on 12/10/2016.
//  Copyright © 2016 Andrew Smith. All rights reserved.
//

#ifndef kruse_h
#define kruse_h

#include <string>

using namespace std;

//Class for the Kruse character

class Kruse{
    private:
        int healthPoints = 100;
        string name = "Kruse";
        string weapon = "Sword";
    public:
        int getHealthPoints();
        void reduceHealthPoints(int damage);
        int getDamage();
        string getName();
    
};


#endif /* kruse_h */
