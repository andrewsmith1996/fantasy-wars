//
//  main.cpp
//  fantasywars
//
//  Created by Andrew Smith on 12/10/2016.
//  Copyright © 2016 Andrew Smith. All rights reserved.
//

#include <iostream>
#include "kruse.h"
#include "mob.h"

using namespace std;

//Prototypes
void showMenu();
void playGame(int);
char createGrid(char);
void displayGrid(char);
string AddMob();

//Global Variables
const int rows = 12;
const int cols = 8;


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
    
    //Validation
    do{
        cout << "Which character do you wish to use?" << endl;
        cout << "1 - Kruse: A deadly Warrior with high strength and impeccable combat skills." << endl;
        cout << "2 - Mysterio: A powerful Mage who can cast mysterious spells." << endl;
        cout << "3 - Ferzo: A silent Archer who can be deadly from range." << endl;
        
        cin >> characterChoice;
    } while(characterChoice < 1 || characterChoice > 3);
    
    
    
    playGame(characterChoice);

}

string createGrid(string grid[rows][cols]){
   
    
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
        {
            grid[row][col] = " - " ;
            
        }
    
    return grid[rows][cols];

}

void displayGrid(string grid[rows][cols]){
    
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            cout << grid[row][col];
        }
        cout << endl;
        
    }

}

string addMob(string grid[rows][cols]){
    Mob enemy;
    
    enemy.placeOnGrid();
    
    grid[enemy.rowPos][enemy.colPos] = " 0 ";
    
    return grid[rows][cols];
    
    
}


void playGame(int characterChoice){
    
    
    if(characterChoice == 1){
        Kruse characterChosen;
    } else if (characterChoice == 2){
        cout << "Mysterio";
    } else{
        cout << "Ferzo";
    }
    
    
    string grid[rows][cols];
    createGrid(grid);
    displayGrid(grid);
    addMob(grid);
    displayGrid(grid);
 
    
    }







