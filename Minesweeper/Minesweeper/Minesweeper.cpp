#include <iostream>
#include "Difficulty.h"
#include "Grids.h"
#include "Random.h"
#include "Input.h"
#include <cstdlib> 
#include "State.h";
#include "Minesweeper.h"



int main()
{
    Difficulty difficulty;
    Grids grids;
    
    InitializeGame(grids, difficulty);
    GameCycle(grids);

    DisplayGame(grids);
    EndGame();
}




void InitializeGame(Grids& grids, Difficulty& difficulty)
{
    difficulty.ChooseDifficulty();
    grids.InitializeGridInfo(difficulty.GetRowDifficulty(), difficulty.GetColumnDifficulty(), difficulty.GetBombCountDifficulty());
    grids.InitializeHiddenGrid();
    grids.InitializeVisibleGrid();
}

void GameCycle(Grids& grids)
{
    while (State::gameState == GameState::Ongoing)
    {
        DisplayGame(grids);
        grids.ClickCell(Input::GetCoordinates());
        grids.CheckForWin();

    }
}

void DisplayGame(Grids& grids)
{
    system("cls");
    //grids.ShowGrid(grids.GetGrid('h'));
    std::cout << std::endl; std::cout << std::endl; std::cout << std::endl;
    grids.ShowGrid(grids.GetGrid('v'));
    std::cout << std::endl;
}

void EndGame()
{
    switch (State::gameState)
    {
    case GameState::Won:
        std::cout << "Ai castigat!"; break;
    case GameState::Lost:
        std::cout << "Ai pierdut!"; break;
    }
}


