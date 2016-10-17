//
//  main.cpp
//  fantasywars
//
//  Created by Andrew Smith on 12/10/2016.
//  Copyright © 2016 Andrew Smith. All rights reserved.
//

#include <iostream>
#include "character.h"
#include "mob.h"
#include <vector>

using namespace std;

//Prototypes
void showMenu();
void playGame();
char createGrid(string);
void displayGrid(string);
string AddMob(string, Mob);
void createMobs(string);
void placeCharacter(string, Character);
void moveCharacter(string, Character, string);
bool checkMove(string, Character, string);

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
    
    
    playGame();

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

void placeCharacter(string grid[rows][cols], Character& player){
    //Generate the correct character symbol
   
    player.setRowPos(rows - 1);
    player.setColPos((cols - 1) / 2);
    
    grid[player.getRowPos()][player.getColPos()] = " K ";
    

}

bool checkMove(string movement, Character& player, string grid[rows][cols]){
    bool validMove = true;
    
    if(movement == "L"){
        int boundry = player.getColPos() - 1;
        if(boundry < 0){
            validMove = false;
        } else{
            //Reset the board
            grid[player.getRowPos()][player.getColPos()] = " - ";
            player.setColPos(boundry);
            grid[player.getRowPos()][player.getColPos()] = " K ";
            
        }
    } else if(movement == "R"){
        int boundry = player.getColPos() + 1;
        if(boundry > 7){
            validMove = false;
        } else{
            //Reset the board
            grid[player.getRowPos()][player.getColPos()] = " - ";
            player.setColPos(boundry);
            grid[player.getRowPos()][player.getColPos()] = " K ";
            
        }
    } else{
        int boundry = player.getRowPos() - 1;
        if(boundry < 1){
            validMove = false;
        } else{
            //Reset the board
            grid[player.getRowPos()][player.getColPos()] = " - ";
            player.setRowPos(boundry);
            grid[player.getRowPos()][player.getColPos()] = " K ";
            
        }
        
    }
    
    
    return validMove;
    

}

void moveCharacter(string movement, Character& player, string grid[rows][cols]){
    
    //Reset the board
    grid[player.getRowPos()][player.getColPos()] = " - ";

    if(movement == "L"){
            grid[player.getRowPos()][player.getColPos()] = " K ";
    } else if(movement == "R"){
            grid[player.getRowPos()][player.getColPos()] = " K ";
    } else{
            grid[player.getRowPos()][player.getColPos()] = " K ";

    }
    
}




void playGame(){
    
    //Set the random numebr seed for a "more random" set of numbers
    srand(time(NULL));
    
    //declare and create the grid
    string grid[rows][cols];
    createGrid(grid);
    
    //Create mobs
    createMobs(grid);
    
    //Create character
    Character player;
    
    //Put character on screen
    placeCharacter(grid, player);
    
    //display the grid
    displayGrid(grid);
    
    //Start actual gameplay
    bool characterAlive = true;
    
    string movement;
    bool check = false;
    bool validMove;
    
    while(characterAlive == true){
        
        do{
            cout << "Move Left (L), Forward (F), Right (R)" << endl;
            cin >> movement;
            
            validMove = checkMove(movement, player, grid);
            
            if(validMove == false){
                cout << "Invalid Move" << endl;
            } else{
                //Do the actual movement
                moveCharacter(movement, player, grid);
                displayGrid(grid);
            }
            
        
        } while(validMove == true);
        
        
        
    }
 
    
}







