#pragma once

class Difficulty
{

	enum class DifficultyType
	{
		Easy, Medium, Hard
	};

	DifficultyType currentDifficulty;

	int* bombsPerDifficulty;

	struct GridSize 
	{
		int width;
		int height;
	};

	GridSize* gridSizePerDifficulty;

	
};



