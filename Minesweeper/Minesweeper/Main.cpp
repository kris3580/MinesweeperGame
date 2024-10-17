#include <iostream>
#include "Minesweeper.h"

int main() 
{
    Difficulty difficulty;
    Grids grids; 
    Minesweeper minesweeper(difficulty, grids); 

    minesweeper.InitializeGame(); 
    minesweeper.GameCycle(); 
    minesweeper.DisplayGame();
    minesweeper.EndGame(); 

    return 0;
}
