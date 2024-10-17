#pragma once

#include "Difficulty.h"
#include "Grids.h"
#include "State.h"

class Minesweeper {
public:
    Minesweeper();

    Minesweeper(Difficulty& d, Grids& g);

    Minesweeper(const Minesweeper& other);

    void InitializeGame();

    void GameCycle();

    void DisplayGame();

    void EndGame();

private:
    Grids grids;
    Difficulty difficulty;
public:
    Minesweeper& operator=(const Minesweeper& other);

    bool operator==(const Minesweeper& other) const;
};
