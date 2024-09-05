#pragma once
#include "Cell.h"
class Input 
{
	Cell clickedCell;

	Cell GetClickedCell();

public:
	void OnRightClick();

	void OnLeftClick();

	void OnDualClick();
};