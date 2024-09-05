#pragma once
#include "Grids.h"
#include "Timer.h"
class Game 
{


public:
	GameState gameState;

	Grids _grids;

	Timer _timer;


	void ShowWinScreen();

	void ShowLossScreen();

	void StartGame();

	void RestartGame();

	void GoToMenu();

};

enum class GameState {
	Win, Loss, Ongoing
};