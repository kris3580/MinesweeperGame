#include <iostream>
#include <cstdlib>
#include "Minesweeper.h"
#include "Input.h"

Minesweeper::Minesweeper() {
    difficulty = Difficulty();
    grids = Grids();
}

Minesweeper::Minesweeper(Difficulty& d, Grids& g) : difficulty(d), grids(g) {
    InitializeGame();
}

Minesweeper::Minesweeper(const Minesweeper& other)
    : grids(other.grids), difficulty(other.difficulty) {
}

void Minesweeper::InitializeGame() {
    difficulty.ChooseDifficulty();
    grids.InitializeGridInfo(difficulty.GetRowDifficulty(), difficulty.GetColumnDifficulty(), difficulty.GetBombCountDifficulty());
    grids.InitializeHiddenGrid();
    grids.InitializeVisibleGrid();
}

void Minesweeper::GameCycle() {
    while (State::gameState == GameState::Ongoing) {
        DisplayGame();
        grids.ClickCell(Input::GetCoordinates());
        grids.CheckForWin();
    }
}

void Minesweeper::DisplayGame() {
    system("cls");
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    grids.ShowGrid(grids.GetGrid('v'));
    std::cout << std::endl;
}

void Minesweeper::EndGame() {
    switch (State::gameState) {
    case GameState::Won:
        std::cout << "Ai castigat!"; break;
    case GameState::Lost:
        std::cout << "Ai pierdut!"; break;
    }
}

Minesweeper& Minesweeper::operator=(const Minesweeper& other) {
    if (this != &other) {
        grids = other.grids;
        difficulty = other.difficulty; 
    }
    return *this;
}

bool Minesweeper::operator==(const Minesweeper& other) const
{
    return grids == other.grids && difficulty == other.difficulty;
}
