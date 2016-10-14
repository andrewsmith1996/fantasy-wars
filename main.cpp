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
#include <vector>

using namespace std;

//Prototypes
void showMenu();
void playGame(int);
char createGrid(char);
void displayGrid(char);
string AddMob(string, Mob);
void createMobs(string);

//Global Variables
const int rows = 12;
const int cols = 8;
const int numberOfMobs = 8;


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
    
    //Function that displays the grid row by row
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            cout << grid[row][col];
        }
        cout << endl;
        
    }

}

void addMob(string grid[rows][cols], Mob enemy){
    
    //Sets the enemy to a random point on the grid
    enemy.placeOnGrid();
    
    //Actually places the enemy
    //If an enemy already occupies the space then recursively replaces it
    if(grid[enemy.rowPos][enemy.colPos] == " - "){
        grid[enemy.rowPos][enemy.colPos] = " 0 ";
    } else{
        addMob(grid, enemy);
    }
    
}

void createMobs(string grid[rows][cols]){
    //Set the list of Mobs and create the Mobs in the game
    Mob mobs[numberOfMobs];
    
    //Actually add the mobs to the grid
    for(int x = 0; x < numberOfMobs; x++){
        addMob(grid, mobs[x]);
    }

}

void placeCharacter(int characterChoice, string grid[rows][cols]){
    //Generate the correct character symbol
    
    string characterSymbol;
    
    if(characterChoice == 1){
        characterSymbol = "K";
    } else if (characterChoice == 2){
        characterSymbol = "M";
    } else{
        characterSymbol = "F";
    }

    grid[rows - 1][(cols - 1) / 2] =  " " + characterSymbol + " ";
    

}


void playGame(int characterChoice){
    
    //Set the random numebr seed for a "more random" set of numbers
    srand(time(NULL));
    
    
    //declare and create the grid
    string grid[rows][cols];
    createGrid(grid);
    
    //Create mobs
    createMobs(grid);
    
    //Put character on screen
    placeCharacter(characterChoice, grid);
    
    //display the grid
    displayGrid(grid);
 
    
}







