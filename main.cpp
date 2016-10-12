//
//  main.cpp
//  fantasywars
//
//  Created by Andrew Smith on 12/10/2016.
//  Copyright © 2016 Andrew Smith. All rights reserved.
//

#include <iostream>
#include "kruse.h"

using namespace std;

//Prototypes
void showMenu();
void playGame(Kruse);

int main(){
    
    //Call the main menu
    showMenu();

    return 0;
}

void showMenu(){
    
    cout << "Welcome to Fantasy Wars!" << endl;
    
    //Get user input
    int playChoice;
    
    do{
        cout << "Press 1 to Play!" << endl;
        cin >> playChoice;
    } while (playChoice != 1);
    
    //Character choice, show character description
    int characterChoice;
    
    do{
        cout << "Which character do you wish to use?" << endl;
        cout << "1 - Kruse: A deadly Warrior with high strength and impeccable combat skills." << endl;
        cout << "2 - Mysterio: A powerful Mage who can cast mysterious spells." << endl;
        cout << "3 - Ferzo: A silent Archer who can be deadly from range." << endl;
        
        cin >> characterChoice;
    } while(characterChoice < 1 || characterChoice > 3);
    
    
    Kruse characterChosen;
    
    playGame(characterChosen);

}


void playGame(Kruse character){
 
    cout <<
}







