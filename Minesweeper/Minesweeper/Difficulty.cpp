#include "Difficulty.h"

Difficulty::Difficulty() : 
	rowsDifficulty{ 10, 18, 24 }, 
	columnsDifficulty{ 8, 14, 20 }, 
	bombNumberPerDifficulty {10, 40, 99}, 
	chosenDifficulty(DifficultyType::Easy)
{
}

void Difficulty::ChooseDifficulty()
{
	bool isInputInvalid = false;
	char userInput;

	do
	{
		std::cout << "Alegeti o dificultate. \n1 - Usor; 2 - Intermediar; 3 - Greu" << std::endl;

		std::cin >> userInput;

		switch (userInput) 
		{
			case '1': chosenDifficulty = DifficultyType::Easy; break;
			case '2': chosenDifficulty = DifficultyType::Medium; break;
			case '3': chosenDifficulty = DifficultyType::Hard; break;
		}

		system("cls");

		if (userInput == '1' || userInput == '2' || userInput == '3') {
			isInputInvalid = true;
		}

	} while (!isInputInvalid);

}

int Difficulty::GetRowDifficulty()
{
	return rowsDifficulty[(int)chosenDifficulty];
}

int Difficulty::GetColumnDifficulty()
{
	return columnsDifficulty[(int)chosenDifficulty];
}

int Difficulty::GetBombCountDifficulty() 
{
	return bombNumberPerDifficulty[(int)chosenDifficulty];
}
