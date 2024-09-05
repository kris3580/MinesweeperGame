#pragma once
#include "Game.h"
#include "Input.h"


class GameEngine {
	
	Game _game;
	Input _input;
	

public:
	GameEngine();
	void Init();
	void Run();
};