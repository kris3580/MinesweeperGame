#pragma once
#include "Cell.h"

class Grids 
{
	CellType** gridVisible;

	CellType** gridHidden;

	void BombGenerationHandler();

	void NumbersGenerationHandler();

	bool BombCheck(Cell cell);

	void RevealCells();

	void RevealAllCells();

	bool AreAllCellsRevealed();


public:

	void ResetGrid(CellType** grid);

	void GenerateGrid();

	bool IsClickedCellValid(Cell cell);

};






