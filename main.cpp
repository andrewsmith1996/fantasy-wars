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
void placeCharacter(string, Character);
void moveCharacter(string, Character, string);
bool checkMove(string, Character, string);
bool checkEnemey(string, Character, string);
bool battle(Character, string, Mob);
string chooseWeapon();
void dealDamageToMob(int, int, string, Mob);
Mob checkMob(Mob, string, Character);

//Global Variables
const int rows = 12;
const int cols = 8;
const int numberOfMobs = 8;

const int daggerDamage = 40;
const int daggerPercent = 20;

const int bowDamage = 30;
const int bowPercent = 30;

const int swordDamage = 20;
const int swordPercent = 50;



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
    if(grid[enemy.getRowPos()][enemy.getColPos()] == " - "){
        grid[enemy.getRowPos()][enemy.getColPos()] = " 0 ";
    } else{
        addMob(grid, enemy);
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
        }
    } else if(movement == "R"){
        int boundry = player.getColPos() + 1;
        if(boundry > 7){
            validMove = false;
        }
    } else if(movement == "B"){
        int boundry = player.getRowPos() + 1;
        if(boundry > 11){
            validMove = false;
        }
    } else if(movement == "F"){
        int boundry = player.getRowPos() - 1;
        if(boundry < 0){
            validMove = false;
        }
        
}
    
    
    return validMove;
    

}

void moveCharacter(string movement, Character& player, string grid[rows][cols]){
    
    //Reset the board
    grid[player.getRowPos()][player.getColPos()] = " - ";

    if(movement == "L"){
            grid[player.getRowPos()][player.getColPos() - 1] = " K ";
            player.setColPos(player.getColPos() - 1);
    } else if(movement == "R"){
            grid[player.getRowPos()][player.getColPos() + 1] = " K ";
            player.setColPos(player.getColPos() + 1);
    } else if(movement == "B"){
            grid[player.getRowPos() + 1][player.getColPos()] = " K ";
            player.setRowPos(player.getRowPos() + 1);
    } else if(movement == "F"){
            grid[player.getRowPos() - 1][player.getColPos()] = " K ";
            player.setRowPos(player.getRowPos() - 1);

    }
    
}

bool checkEnemy(string movement, Character player, string grid[rows][cols]){
    bool enemy = false;
    
    if(movement == "L"){
        if(grid[player.getRowPos()][player.getColPos() - 1] == " 0 "){
            enemy = true;
        }
    } else if(movement == "R"){
        if(grid[player.getRowPos()][player.getColPos() + 1] == " 0 "){
            enemy = true;
        }
    } else if(movement == "F"){
        if(grid[player.getRowPos() - 1][player.getColPos()] == " 0 "){
            enemy = true;
        }
    } else if(movement == "B"){
        if(grid[player.getRowPos() + 1][player.getColPos()] == " 0 "){
            enemy = true;
        }
    }
        
    return enemy;
    
}

string chooseWeapon(){
    cout << "Please Choose your Weapon" << endl;
    cout << "1 - Dagger. Chance: " << daggerPercent << "% Damage: " << daggerDamage << " HP" << endl;
    cout << "2 - Bow. Chance: " << bowPercent << "% Damage: " << bowDamage << " HP" << endl;
    cout << "3 - Sword. Chance: " << swordPercent << "% Damage: " << swordDamage << " HP" << endl;

    
    int choice;
    string weapon;
    
    cin >> choice;
    
    switch(choice){
        case 1:
            weapon = "Dagger";
            break;
        case 2:
            weapon = "Bow";
            break;
        case 3:
            weapon = "Sword";
            break;
        default:
            cout << "Error choosing Weapon, please restart Fantasy Wars" << endl;
    }
    
    return weapon;
}

void dealDamageToMob(int damage, int percent, string weapon, Mob mob){
    
    int randomNumber = rand() % 100;
    
    if(randomNumber <= percent){
        if(weapon == "Sword"){
            cout << "You swing your sword and successfully strike the Goblin!" << endl;
        } else if(weapon == "Bow"){
            cout << "You fire an arrow at the Goblin and successfully hit it!" << endl;
        } else{
            cout << "You successfully stab the Goblin!" << endl;
        }
        
        mob.setHealthPoints(damage);
        cout << "Mob Health: " << mob.getHealthPoints() << endl;
        
        
    } else{
        if(weapon == "Sword"){
            cout << "You swing your sword but the Goblin dodges it!" << endl;
        } else if(weapon == "Bow"){
            cout << "You fire an arrow but miss!" << endl;
        } else{
            cout << "The Goblin avoids your dagger!" << endl;
        }
    }
    
    
    
}

bool battle(Character player, string grid[rows][cols], Mob mob){
    bool battleWon;
    
    battleWon = true;
    
    string weapon = chooseWeapon();
    
    
    if(weapon == "Dagger"){
        dealDamageToMob(daggerDamage, daggerPercent, weapon, mob);
    } else if(weapon == "Bow"){
        dealDamageToMob(bowDamage, bowPercent, weapon, mob);
    } else{
        dealDamageToMob(swordDamage, swordPercent, weapon, mob);
    }
    
    
    
    return battleWon;

}

Mob checkMob(Mob mobs[numberOfMobs], string grid[rows][cols], Character player){
    
    int row = player.getRowPos();
    int col = player.getColPos();
    
    Mob mob;
    
    for(int x = 0; x < numberOfMobs; x++){
        if(mobs[x].getRowPos() == row && mobs[x].getColPos() == col){
            mob = mobs[x];
        }
    }
    
    cout << "Mob Health: " << mob.getHealthPoints() << endl;
    
    
    return mob;
}



void playGame(){
    
    //Set the random numebr seed for a "more random" set of numbers
    srand(time(NULL));
    
    //declare and create the grid
    string grid[rows][cols];
    createGrid(grid);
    
    //Create mobs
    //Set the list of Mobs and create the Mobs in the game
    Mob mobs[numberOfMobs];
    
    //Actually add the mobs to the grid
    for(int x = 0; x < numberOfMobs; x++){
        addMob(grid, mobs[x]);
    }
    
    
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
    bool enemyCheck;
    
    while(characterAlive == true){
        
        do{
            cout << "Move Left (L), Forward (F), Backward (B), Right (R)" << endl;
            cin >> movement;
            
            validMove = checkMove(movement, player, grid);
            
            
            if(validMove == false){
                cout << "Invalid Move" << endl;
            } else{
                
                
                enemyCheck = checkEnemy(movement, player, grid);
                
                
                //Check for enemy
                if(enemyCheck == true){
                    
                    Mob whichMob = checkMob(mobs, grid, player);
                    
                    bool battleWon = battle(player, grid, whichMob);
                    if(battleWon == true){
                        
                        } else{
                        cout << "you lose";
                    }
                }
                
                moveCharacter(movement, player, grid);
               
                displayGrid(grid);
                
            }
            
        
        } while(validMove == true);
        
        
        
    }
 
    
}







