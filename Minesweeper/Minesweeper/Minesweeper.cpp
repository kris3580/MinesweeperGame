#include <iostream>
#include "Difficulty.h"
#include "Grids.h"
#include "Random.h"
#include "Input.h"
#include <cstdlib> 
#include "Game.h";
int main()
{
    Difficulty difficulty;

    difficulty.ChooseDifficulty();

    Grids grids;

    grids.InitializeGridInfo(difficulty.GetRowDifficulty(), difficulty.GetColumnDifficulty(), difficulty.GetBombCountDifficulty());
    grids.InitializeHiddenGrid();
    grids.InitializeVisibleGrid();

    while (Game::gameState == GameState::Ongoing)
    {
        system("cls");
        //grids.ShowGrid(grids.GetGrid('h'));
        std::cout << std::endl; std::cout << std::endl; std::cout << std::endl;
        grids.ShowGrid(grids.GetGrid('v'));
        std::cout << std::endl;
        grids.ClickCell(Input::GetCoordinates());
        grids.CheckForWin();
        
    }
    system("cls");
    //grids.ShowGrid(grids.GetGrid('h'));
    std::cout << std::endl; std::cout << std::endl; std::cout << std::endl;
    grids.ShowGrid(grids.GetGrid('v'));
    std::cout << std::endl;

    switch (Game::gameState)
    {
    case GameState::Won:
        std::cout << "Ai castigat!"; break;
    case GameState::Lost:
        std::cout << "Ai pierdut!"; break;
    }


}


