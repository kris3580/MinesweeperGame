#pragma once

class Cell 
{
public:
	Cell() : x(0), y(0) {}

	Cell(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}

	Cell(const Cell& other) : x(other.x), y(other.y) {}

	int x;

	int y;

	Cell& operator=(const Cell& other) {
		if (this != &other) {
			x = other.x;
			y = other.y;
		}
		return *this;
	}

	bool operator==(const Cell& other) const
	{
		return x == other.x && y == other.y;
	}
};