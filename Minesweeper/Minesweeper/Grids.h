#pragma once
#include <iostream>
#include "CellType.h"
#include "Random.h"
#include "ConsoleColors.h"
#include "Cell.h"
#include "State.h"

class Grids 
{
private:
	CellType** gridVisible;

	CellType** gridHidden;

	int width;

	int height;

	int bombCount;

	void RecursiveCellRevealing(int x, int y);

	bool IsCellANumber(int x, int y);

	bool IsCellEmpty(int x, int y);

	int CheckLeftForBomb(int i, int j);
	int CheckRightForBomb(int i, int j);
	int CheckTopForBomb(int i, int j);
	int CheckBottomForBomb(int i, int j);
	int CheckTopLeftForBomb(int i, int j);
	int CheckTopRightForBomb(int i, int j);
	int CheckBottomLeftForBomb(int i, int j);
	int CheckBottomRightForBomb(int i, int j);
	
	void RevealLeftHandler(int x, int y);
	void RevealRightHandler(int x, int y);
	void RevealTopHandler(int x, int y);
	void RevealBottomHandler(int x, int y);
	void RevealTopLeftHandler(int x, int y);
	void RevealTopRightHandler(int x, int y);
	void RevealBottomLeftHandler(int x, int y);
	void RevealBottomRightHandler(int x, int y);

public:
	Grids();

	void InitializeGridInfo(int numberOfRows, int numberOfColumns, int numberOfBombs);

	void InitializeVisibleGrid();

	void InitializeHiddenGrid();

	void ShowGrid(CellType** grid);

	void CheckForWin();

	void ClickCell(Cell cell);

	CellType** GetGrid(char gridType);
};