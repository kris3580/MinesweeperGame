#pragma once

struct Cell
{
	int x;
	int y;
};

enum class CellType
{
	Flagged, WrongfullyFlagged, Number, Bomb, Checked, Unchecked
};
