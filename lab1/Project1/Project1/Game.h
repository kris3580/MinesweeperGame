#pragma once
#include "Grids.h"
#include "Timer.h"
#include "GameState.h"

class Game 
{

public:
	GameState gameState;

	Grids grids;

	Timer timer;


	void ShowWinScreen();

	void ShowLossScreen();

	void StartGame();

	void RestartGame();

	void GoToMenu();

};

