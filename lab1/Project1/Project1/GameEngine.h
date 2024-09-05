#pragma once
#include "Game.h"
#include "Input.h"


class GameEngine {
	
	Game game;

	Input input;
	

public:
	GameEngine();

	void Init();

	void Run();
};