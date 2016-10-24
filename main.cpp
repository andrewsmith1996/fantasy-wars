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
#include <fstream>

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
void dealDamageToMob(int, int, string, Mob&);
Mob checkMob(Mob, string, Character, string);

//Global Variables
const int rows = 12;
const int cols = 8;
const int numberOfMobs = 8;

const int daggerDamage = 40;
const int daggerPercent = 30;

const int bowDamage = 30;
const int bowPercent = 50;

const int swordDamage = 20;
const int swordPercent = 70;



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
   
    //Loop to create the initial grid
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
        {
            grid[row][col] = " - " ;
            
        }
    
    //Return the 2D array
    return grid[rows][cols];

}

void displayGrid(string grid[rows][cols]){
    
    //Function that displays the grid row by row
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            //output the rows
            cout << grid[row][col];
        }
        //output a new line
        cout << endl;
        
    }

}

void addMob(string grid[rows][cols], Mob& enemy){
    
    //Sets the enemy to a random point on the grid
    
    enemy.placeOnGrid();
    enemy.setInitialHealth();
    
    //Actually places the enemy
    //If an enemy already occupies the space then recursively replaces it
    if(grid[enemy.getRowPos()][enemy.getColPos()] == " - "){
        grid[enemy.getRowPos()][enemy.getColPos()] = " 0 ";
        
    } else{
        addMob(grid, enemy);
    }
    
}


void placeCharacter(string grid[rows][cols], Character& player){
   
    //Place the player on the grid
    player.setRowPos(rows - 1);
    player.setColPos((cols - 1) / 2);
    
    //Place the symbol of the player
    grid[player.getRowPos()][player.getColPos()] = " K ";
    

}

bool checkMove(string movement, Character& player, string grid[rows][cols]){
 
    bool validMove = true;
    
    //Checks the movement and sees if the movement would be out of the grid
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

    //Checks the movement and then sets the new space for the character
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
    
    //Checks the movement and if the new movement position is an enemy or not
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
    
    //Menu for choosing the weapon
    cout << "\nPlease Choose your Weapon" << endl;
    cout << "1 - Dagger. Chance: " << daggerPercent << "% Damage: " << daggerDamage << " HP" << endl;
    cout << "2 - Bow. Chance: " << bowPercent << "% Damage: " << bowDamage << " HP" << endl;
    cout << "3 - Sword. Chance: " << swordPercent << "% Damage: " << swordDamage << " HP" << endl;

    //Input the weapon choice
    int choice;
    string weapon;
    
    cin >> choice;
    
    //Convert choice to the string version
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

void dealDamageToMob(int damage, int percent, string weapon, Mob& mob){
    
    //Gets a random numebr between 0 and 100
    int randomNumber = rand() % 100;
    
    //If the percentage of hit probability is less than the random number then a hit has been successful
    if(randomNumber <= percent){
        if(weapon == "Sword"){
            cout << "\nYou swing your sword and successfully strike the Goblin!" << endl << endl;
        } else if(weapon == "Bow"){
            cout << "\nYou fire an arrow at the Goblin and successfully hit it!" << endl << endl;
        } else{
            cout << "\nYou successfully stab the Goblin!" << endl << endl;
        }
        
        //reduce the health of the mob being attacked
        mob.setHealthPoints(damage);
        
        
    } else{
        //Else if they miss the Mob
        if(weapon == "Sword"){
            cout << "\nYou swing your sword but the Goblin dodges it!" << endl << endl;
        } else if(weapon == "Bow"){
            cout << "\nYou fire an arrow but miss!" << endl << endl;
        } else{
            cout << "\nThe Goblin avoids your dagger!" << endl << endl;
        }
    }
    
    
}

bool battle(Character& player, string grid[rows][cols], Mob& mob){
    bool battleWon;
    
    battleWon = false;
    
    //while the mob is still alive the battle continues
    while(mob.getHealthPoints() > 0 || player.getHealthPoints() > 0){
        
        //output the HP points of the mob being attacked
        cout << "\nMob Health: " << mob.getHealthPoints() << endl ;
        cout << "Your Health: " << player.getHealthPoints() << endl;
        
        //Choose the weapon to use
        string weapon = chooseWeapon();
        
        //deal damage to the mob
        if(weapon == "Dagger"){
            dealDamageToMob(daggerDamage, daggerPercent, weapon, mob);
        } else if(weapon == "Bow"){
            dealDamageToMob(bowDamage, bowPercent, weapon, mob);
        } else{
            dealDamageToMob(swordDamage, swordPercent, weapon, mob);
        }
        
        //Check to see if mob has died yet
        if(mob.getHealthPoints() <= 0){
                battleWon = true;
            break;
        }
        
        
        int randomNumber = mob.getDamage();
        //Mob attacks the player with a random 0 to 15 damage rate
        cout << "The Goblin attacks you and hits you!" << endl;
        player.reduceHealthPoints(randomNumber);
        
        //Check to see if the player has died
        if(player.getHealthPoints() <= 0){
            break;
        }

    }
    
    return battleWon;

}

Mob checkMob(Mob (&mobs)[numberOfMobs], string grid[rows][cols], Character& player, string movement){
    
    //gets the current position on the grid of the player
    int row = player.getRowPos();
    int col = player.getColPos();
    
    int check = 0;
    
    //Add 1 onto coordinates as the player hasn't actually occupied this spot yet
    if(movement == "L"){
        col -= 1;
    } else if(movement == "R"){
        col += 1;
    } else if(movement == "F"){
        row -= 1;
    } else{
        row += 1;
    }
    
    //check to see which Mob is being attacked
    for(int x = 0; x < numberOfMobs; x++){
        if(mobs[x].getRowPos() == row && mobs[x].getColPos() == col){
            check = x;
        }
    }
    
    //Return the mob in question from the array
    return mobs[check];
}

void saveGame(string grid[rows][cols]){
    
    ofstream saveFile;
    
    saveFile.open("Fantasy Wars - Saved Game.txt", ios::out);
    
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            saveFile << grid[row][col] << "";
        }
        saveFile << "\n";
    }
    
    
    
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
    
    player.setInitialHealth();
    
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
            cout << "Move Left (L), Forward (F), Backward (B), Right (R)" << endl << endl;;
            cin >> movement;
            
            //Convert to uppercase
            transform(movement.begin(), movement.end(), movement.begin(), ::toupper);
            
            //Check to see if move is valid
            validMove = checkMove(movement, player, grid);
            
            
            if(validMove == false){
                cout << "Invalid Move" << endl;
            } else{
                
                //Check to see if there's an enemy in the new grid position
                enemyCheck = checkEnemy(movement, player, grid);
                
                //Check for enemy
                if(enemyCheck == true){
                    
                    //find which mob it is being attacked
                    Mob whichMob = checkMob(mobs, grid, player, movement);
                    
                    //do actual battling
                    bool battleWon = battle(player, grid, whichMob);
                    
                    
                    if(battleWon == true){
                        cout << "You kill the Goblin!" << endl;
                    } else{
                        cout << "GAME OVER! You have died!" << endl;
                        characterAlive = false;
                    }
                }
                
                moveCharacter(movement, player, grid);
               
                displayGrid(grid);
                
                saveGame(grid);
                
            }
            
        
        } while(validMove == true);
        
        
        
    }
 
    
}







