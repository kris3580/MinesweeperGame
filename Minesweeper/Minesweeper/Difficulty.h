#pragma once
#include <iostream>
#include "DifficultyType.h"
#include <cstdlib> 

class Difficulty 
{
private:
	int rowsDifficulty[3];

	int columnsDifficulty[3];

	int bombNumberPerDifficulty[3];

	DifficultyType chosenDifficulty;

public:
	Difficulty();

	void ChooseDifficulty();

	int GetRowDifficulty();

	int GetColumnDifficulty();

	int GetBombCountDifficulty();
};
