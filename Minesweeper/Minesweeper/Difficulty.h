#pragma once
#include <iostream>
#include "DifficultyType.h"
#include <cstdlib> 

class Difficulty 
{
public:
    Difficulty();

    Difficulty(int rows[3], int columns[3], int bombs[3], DifficultyType difficulty);

    Difficulty(const Difficulty& other);

    int rowsDifficulty[3];

    int columnsDifficulty[3];

    int bombNumberPerDifficulty[3];

    DifficultyType chosenDifficulty;

    void ChooseDifficulty();

    int GetRowDifficulty() const;

    int GetColumnDifficulty() const;

    int GetBombCountDifficulty() const;

    Difficulty& operator=(const Difficulty& other);

    bool operator==(const Difficulty& other) const;
};

std::istream& operator>>(std::istream& in, Difficulty& difficulty);

std::ostream& operator<<(std::ostream& out, const Difficulty& difficulty);
