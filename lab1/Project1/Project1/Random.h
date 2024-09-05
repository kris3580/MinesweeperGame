#pragma once

class Random
{
	int currentSeed;

	void GenerateSeed();

public:
	void GetRandomInt(int a, int b);

};