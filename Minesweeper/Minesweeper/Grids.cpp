#include "Grids.h"

Grids::Grids() : 
	gridVisible(), 
	gridHidden(), 
	width(), 
	height(),
	bombCount() {}

Grids::Grids(int numberOfRows, int numberOfColumns, int numberOfBombs)
	: gridVisible(nullptr),
	gridHidden(nullptr),
	width(numberOfRows),
	height(numberOfColumns),
	bombCount(numberOfBombs)
{
	InitializeVisibleGrid();
	InitializeHiddenGrid();
}

Grids::Grids(const Grids& other)
	: width(other.width),
	height(other.height),
	bombCount(other.bombCount)
{

	gridVisible = new CellType * [width];
	gridHidden = new CellType * [width];

	for (int i = 0; i < width; i++)
	{
		gridVisible[i] = new CellType[height];
		gridHidden[i] = new CellType[height];

		for (int j = 0; j < height; j++)
		{
			gridVisible[i][j] = other.gridVisible[i][j];
			gridHidden[i][j] = other.gridHidden[i][j];
		}
	}
}

void Grids::InitializeGridInfo(int numberOfRows, int numberOfColumns, int numberOfBombs)
{
	width = numberOfRows;
	height = numberOfColumns;
	bombCount = numberOfBombs;
}

void Grids::InitializeVisibleGrid() 
{
	// aloca memorie si seteaza valoarea implicita la enum
	gridVisible = new CellType*[width];

	for (int i = 0; i < width; i++) 
	{
		gridVisible[i] = new CellType[height]();
	}

}

void Grids::InitializeHiddenGrid() 
{
	// aloca memorie si seteaza fiecare celula manual sa fie la fel
	gridHidden = new CellType * [width];

	for (int i = 0; i < width; i++) 
	{
		gridHidden[i] = new CellType[height];

		for (int j = 0; j < height; j++)
		{
			gridHidden[i][j] = CellType::Empty;
		}
	}


	// pune bombe la intamplare
	int bombsPlaced = 0;
	while (bombsPlaced < bombCount)
	{
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				if (gridHidden[i][j] == CellType::Empty && Random::GetRandomNumber(1, 10) == 3)
				{
					gridHidden[i][j] = CellType::Bomb;
					bombsPlaced++;
				}

				if (bombsPlaced == bombCount) break;
			}
			if (bombsPlaced == bombCount) break;
		}
	}

	int bombsAroundCurrentCell = 0;
	// pune numerele de langa bombe
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++) 
		{
			// treci peste daca celula e o bomba
			if (gridHidden[i][j] != CellType::Empty) continue;

			// caz mijloc
			if (0 < i && i < width - 1 && 0 < j && j < height - 1) 
			{
				bombsAroundCurrentCell += CheckTopForBomb(i, j);
				bombsAroundCurrentCell += CheckBottomForBomb(i, j);
				bombsAroundCurrentCell += CheckLeftForBomb(i, j);
				bombsAroundCurrentCell += CheckRightForBomb(i, j);
				bombsAroundCurrentCell += CheckBottomRightForBomb(i, j);
				bombsAroundCurrentCell += CheckBottomLeftForBomb(i, j);
				bombsAroundCurrentCell += CheckTopLeftForBomb(i, j);
				bombsAroundCurrentCell += CheckTopRightForBomb(i, j);
				
			}
			// caz coltul stanga sus
			else if (i == 0 && j == 0)
			{
				bombsAroundCurrentCell += CheckBottomForBomb(i, j);
				bombsAroundCurrentCell += CheckBottomRightForBomb(i, j);
				bombsAroundCurrentCell += CheckRightForBomb(i, j);
			}
			// caz coltul dreapta jos
			else if (i == width - 1 && j == height - 1)
			{

				bombsAroundCurrentCell += CheckLeftForBomb(i, j);
				bombsAroundCurrentCell += CheckTopForBomb(i, j);
				bombsAroundCurrentCell += CheckTopLeftForBomb(i, j);
			}
			// caz coltul dreapta sus
			else if (i == 0 && j == height - 1)
			{
				bombsAroundCurrentCell += CheckLeftForBomb(i, j);
				bombsAroundCurrentCell += CheckBottomForBomb(i, j);
				bombsAroundCurrentCell += CheckBottomLeftForBomb(i, j);
			}
			// caz coltul stanga jos
			else if (i == width - 1 && j == 0)
			{
				bombsAroundCurrentCell += CheckTopForBomb(i, j);
				bombsAroundCurrentCell += CheckRightForBomb(i, j);
				bombsAroundCurrentCell += CheckTopRightForBomb(i, j);
			}
			// caz mijloc sus
			else if (i == 0 && j != height - 1)
			{
				bombsAroundCurrentCell += CheckBottomForBomb(i, j);
				bombsAroundCurrentCell += CheckLeftForBomb(i, j);
				bombsAroundCurrentCell += CheckRightForBomb(i, j);
				bombsAroundCurrentCell += CheckBottomRightForBomb(i, j);
				bombsAroundCurrentCell += CheckBottomLeftForBomb(i, j);
			}
			// caz mijloc stanga
			else if (i != width - 1 && j == 0)
			{
				bombsAroundCurrentCell += CheckTopForBomb(i, j);
				bombsAroundCurrentCell += CheckBottomForBomb(i, j);
				bombsAroundCurrentCell += CheckRightForBomb(i, j);
				bombsAroundCurrentCell += CheckBottomRightForBomb(i, j);
				bombsAroundCurrentCell += CheckTopRightForBomb(i, j);
			}
			// caz mijloc jos
			else if (i == width - 1 && j != height - 1)
			{
				bombsAroundCurrentCell += CheckTopForBomb(i, j);
				bombsAroundCurrentCell += CheckLeftForBomb(i, j);
				bombsAroundCurrentCell += CheckRightForBomb(i, j);
				bombsAroundCurrentCell += CheckTopLeftForBomb(i, j);
				bombsAroundCurrentCell += CheckTopRightForBomb(i, j);
			}
			// caz mijloc dreapta
			else if (i != width - 1 && j == height - 1)
			{
				bombsAroundCurrentCell += CheckTopForBomb(i, j);
				bombsAroundCurrentCell += CheckBottomForBomb(i, j);
				bombsAroundCurrentCell += CheckLeftForBomb(i, j);
				bombsAroundCurrentCell += CheckBottomLeftForBomb(i, j);
				bombsAroundCurrentCell += CheckTopLeftForBomb(i, j);
			}

			gridHidden[i][j] = (CellType)bombsAroundCurrentCell;
			bombsAroundCurrentCell = 0;
		}
	}

	// ??
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (gridHidden[i][j] == CellType::Unchecked)
			{
				gridHidden[i][j] = CellType::Empty;
			}
		}
	}


}

void Grids::ShowGrid(CellType** grid)
{
	// board coordinates
	std::cout << "    ";
	for (char letter = 'a'; letter < 'a' + height && letter <= 'z'; letter++)
	{
		std::cout << " " << letter << " ";
	}
	std::cout << std::endl; 
	std::cout << std::endl;

	for (int i = 0; i < width; i++) 
	{
		// board coordinates
		if(i < 10) std::cout << i << "   ";
		else std::cout << i << "  ";
		
		// print grid
		for (int j = 0; j < height; j++) 
		{
			switch (grid[i][j])
			{
				case CellType::Unchecked: ConsoleColors::SetColors(15, 15);  std::cout << "   "; ConsoleColors::ResetColors(); break;
				case CellType::Bomb: ConsoleColors::SetColors(4, 15); std::cout << "   "; ConsoleColors::ResetColors(); break;
				case CellType::Empty: ConsoleColors::SetColors(7, 0); std::cout << "   "; ConsoleColors::ResetColors(); break;
				case CellType::One: ConsoleColors::SetColors(7, 1); std::cout << " 1 "; ConsoleColors::ResetColors(); break;
				case CellType::Two: ConsoleColors::SetColors(7, 2); std::cout << " 2 "; ConsoleColors::ResetColors(); break;
				case CellType::Three: ConsoleColors::SetColors(7, 13); std::cout << " 3 "; ConsoleColors::ResetColors(); break;
				case CellType::Four: ConsoleColors::SetColors(7, 11); std::cout << " 4 "; ConsoleColors::ResetColors(); break;
				case CellType::Five: ConsoleColors::SetColors(7, 4); std::cout << " 5 "; ConsoleColors::ResetColors(); break;
				case CellType::Six: ConsoleColors::SetColors(7, 3); std::cout << " 6 "; ConsoleColors::ResetColors(); break;
				case CellType::Seven: ConsoleColors::SetColors(7, 0);std::cout << " 7 "; ConsoleColors::ResetColors(); break;
				case CellType::Eight: ConsoleColors::SetColors(7, 8); std::cout << " 8 "; ConsoleColors::ResetColors(); break;
			}
		}
		std::cout << std::endl;
	}
}


void Grids::CheckForWin()
{
	int cellsToCheckForReveal = width * height - bombCount; 
	int cellsChecked = 0;

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (gridHidden[i][j] != CellType::Bomb && gridVisible[i][j] != CellType::Unchecked)
			{
				cellsChecked++;
			}
		}
	}
	if (cellsChecked == cellsToCheckForReveal)
	{
		State::gameState = GameState::Won;
	}
}



void Grids::ClickCell(Cell cell)
{
	// if already checked
	if (gridVisible[cell.x][cell.y] != CellType::Unchecked) return;

	// reveal clicked cell
	gridVisible[cell.x][cell.y] = gridHidden[cell.x][cell.y];


	// on bomb hit
	if (gridHidden[cell.x][cell.y] == CellType::Bomb)
	{
		State::gameState = GameState::Lost;

		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				if (gridHidden[i][j] == CellType::Bomb)
				{
					gridVisible[i][j] = CellType::Bomb;
				}
			}
		}
		return;
	}

	// reveal
	RecursiveCellRevealing(cell.x, cell.y);
}

bool Grids::IsCellANumber(int x, int y)
{
	if (gridHidden[x][y] == CellType::One ||
		gridHidden[x][y] == CellType::Two ||
		gridHidden[x][y] == CellType::Three ||
		gridHidden[x][y] == CellType::Four ||
		gridHidden[x][y] == CellType::Five ||
		gridHidden[x][y] == CellType::Six ||
		gridHidden[x][y] == CellType::Seven ||
		gridHidden[x][y] == CellType::Eight
		) 
		return true;
	else 
		return false;
}

bool Grids::IsCellEmpty(int x, int y)
{
	if (gridHidden[x][y] == CellType::Empty)
		return true;
	else
		return false;
}



void Grids::RecursiveCellRevealing(int x, int y)
{
	
	// caz mijloc
	if (0 < x && x < width - 1 && 0 < y && y < height - 1)
	{
		RevealLeftHandler(x, y);
		RevealRightHandler(x, y);
		RevealTopHandler(x, y);
		RevealBottomHandler(x, y);
		RevealTopLeftHandler(x, y);
		RevealTopRightHandler(x, y);
		RevealBottomLeftHandler(x, y);
		RevealBottomRightHandler(x, y);
	}
	// caz coltul stanga sus
	else if (x == 0 && y == 0)
	{
		RevealBottomHandler(x, y);
		RevealBottomRightHandler(x, y);
		RevealRightHandler(x, y);
	}
	// caz coltul dreapta jos
	else if (x == width - 1 && y == height - 1)
	{
		RevealLeftHandler(x, y);
		RevealTopHandler(x, y);
		RevealTopLeftHandler(x, y);
	}
	// caz coltul dreapta sus
	else if (x == 0 && y == height - 1)
	{
		RevealLeftHandler(x, y);
		RevealBottomHandler(x, y);
		RevealBottomLeftHandler(x, y);
	}
	// caz coltul stanga jos
	else if (x == width - 1 && y == 0)
	{
		RevealTopHandler(x, y);
		RevealRightHandler(x, y);
		RevealTopRightHandler(x, y);
	}
	// caz mijloc sus
	else if (x == 0 && y != height - 1)
	{
		RevealBottomHandler(x, y);
		RevealLeftHandler(x, y);
		RevealRightHandler(x, y);
		RevealBottomLeftHandler(x, y);
		RevealBottomRightHandler(x, y);
	}
	// caz mijloc stanga
	else if (x != width - 1 && y == 0)
	{
		RevealTopHandler(x, y);
		RevealBottomHandler(x, y);
		RevealRightHandler(x, y);
		RevealTopRightHandler(x, y);
		RevealBottomRightHandler(x, y);
	}
	// caz mijloc jos
	else if (x == width - 1 && y != height - 1)
	{
		RevealTopHandler(x, y);
		RevealLeftHandler(x, y);
		RevealRightHandler(x, y);
		RevealTopRightHandler(x, y);
		RevealTopLeftHandler(x, y);
	}
	// caz mijloc dreapta
	else if (x != width - 1 && y == height - 1)
	{
		RevealTopHandler(x, y);
		RevealBottomHandler(x, y);
		RevealLeftHandler(x, y);
		RevealBottomLeftHandler(x, y);
		RevealTopLeftHandler(x, y);

	}
}





void Grids::RevealLeftHandler(int x, int y)
{

	if (IsCellEmpty(x, y) && gridVisible[x][y - 1] == CellType::Unchecked)
	{
		if (gridHidden[x][y - 1] == CellType::Empty);
		{
			gridVisible[x][y - 1] = gridHidden[x][y - 1];
			
			RecursiveCellRevealing(x, y - 1);
		}
	}



}

void Grids::RevealRightHandler(int x, int y)
{

	if (IsCellEmpty(x, y) && gridVisible[x][y + 1] == CellType::Unchecked)
	{
		if (gridHidden[x][y + 1] == CellType::Empty);
		{
			gridVisible[x][y + 1] = gridHidden[x][y + 1];
			RecursiveCellRevealing(x, y + 1);
		}
	}
}

void Grids::RevealTopHandler(int x, int y)
{

	if (IsCellEmpty(x, y) && gridVisible[x - 1][y] == CellType::Unchecked)
	{
		if (gridHidden[x - 1][y] == CellType::Empty);
		{
			gridVisible[x - 1][y] = gridHidden[x - 1][y];
			RecursiveCellRevealing(x - 1, y);
		}
	}
}

void Grids::RevealBottomHandler(int x, int y)
{

	if (IsCellEmpty(x, y) && gridVisible[x + 1][y] == CellType::Unchecked)
	{
		if (gridHidden[x + 1][y] == CellType::Empty);
		{
			gridVisible[x + 1][y] = gridHidden[x + 1][y];
			RecursiveCellRevealing(x + 1, y);
		}
	}
}

void Grids::RevealTopLeftHandler(int x, int y)
{

	if (IsCellEmpty(x, y) && gridVisible[x - 1][y - 1] == CellType::Unchecked)
	{
		if (gridHidden[x - 1][y - 1] == CellType::Empty);
		{
			gridVisible[x - 1][y - 1] = gridHidden[x - 1][y - 1];
			RecursiveCellRevealing(x - 1, y - 1);
		}
	}
}

void Grids::RevealTopRightHandler(int x, int y)
{

	if (IsCellEmpty(x, y) && gridVisible[x - 1][y + 1] == CellType::Unchecked)
	{
		if (gridHidden[x - 1][y + 1] == CellType::Empty);
		{
			gridVisible[x - 1][y + 1] = gridHidden[x - 1][y + 1];
			RecursiveCellRevealing(x - 1, y + 1);
		}
	}
}

void Grids::RevealBottomLeftHandler(int x, int y)
{
	if (IsCellEmpty(x, y) && gridVisible[x + 1][y - 1] == CellType::Unchecked)
	{
		if (gridHidden[x + 1][y - 1] == CellType::Empty);
		{
			gridVisible[x + 1][y - 1] = gridHidden[x + 1][y - 1];
			RecursiveCellRevealing(x + 1, y - 1);
		}
	}
}

void Grids::RevealBottomRightHandler(int x, int y)
{

	if (IsCellEmpty(x, y) && gridVisible[x + 1][y + 1] == CellType::Unchecked)
	{
		if (gridHidden[x + 1][y + 1] == CellType::Empty);
		{
			gridVisible[x + 1][y + 1] = gridHidden[x + 1][y + 1];
			RecursiveCellRevealing(x + 1, y + 1);
		}
	}
}


CellType** Grids::GetGrid(char gridType)
{
	switch (gridType)
	{
		case 'v': return gridVisible;
		case 'h': return gridHidden;
	}
}

int Grids::CheckLeftForBomb(int i, int j)
{
	if (gridHidden[i][j - 1] == CellType::Bomb) return 1;
	else return 0;
}

int Grids::CheckRightForBomb(int i, int j)
{
	if (gridHidden[i][j + 1] == CellType::Bomb) return 1;
	else return 0;
}

int Grids::CheckTopForBomb(int i, int j)
{
	if (gridHidden[i - 1][j] == CellType::Bomb) return 1;
	else return 0;
}

int Grids::CheckBottomForBomb(int i, int j)
{
	if (gridHidden[i + 1][j] == CellType::Bomb) return 1;
	else return 0;
}

int Grids::CheckTopLeftForBomb(int i, int j)
{
	if (gridHidden[i - 1][j - 1] == CellType::Bomb) return 1;
	else return 0;
}

int Grids::CheckTopRightForBomb(int i, int j)
{
	if (gridHidden[i - 1][j + 1] == CellType::Bomb) return 1;
	else return 0;
}

int Grids::CheckBottomLeftForBomb(int i, int j)
{
	if (gridHidden[i + 1][j - 1] == CellType::Bomb) return 1;
	else return 0;
}

int Grids::CheckBottomRightForBomb(int i, int j)
{
	if (gridHidden[i + 1][j + 1] == CellType::Bomb) return 1;
	else return 0;
}

Grids& Grids::operator=(const Grids& other)
{
	if (this == &other) {
		return *this;
	}
	
	width = other.width;
	height = other.height;
	bombCount = other.bombCount;

	gridVisible = new CellType * [width];
	gridHidden = new CellType * [width];

	for (int i = 0; i < width; i++)
	{
		gridVisible[i] = new CellType[height];
		gridHidden[i] = new CellType[height];

		for (int j = 0; j < height; j++)
		{
			gridVisible[i][j] = other.gridVisible[i][j];
			gridHidden[i][j] = other.gridHidden[i][j];
		}
	}

	return *this;
}

bool Grids::operator==(const Grids& other) const
{
	return gridVisible == other.gridVisible && gridHidden == other.gridHidden && width == other.width && height == other.height && bombCount == other.bombCount;
}



