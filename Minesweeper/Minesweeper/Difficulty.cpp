#include "Difficulty.h"

Difficulty::Difficulty() :
    rowsDifficulty{ 10, 18, 24 },
    columnsDifficulty{ 8, 14, 20 },
    bombNumberPerDifficulty{ 10, 40, 99 },
    chosenDifficulty(DifficultyType::Easy)
{
}

Difficulty::Difficulty(int rows[3], int columns[3], int bombs[3], DifficultyType difficulty) :
    chosenDifficulty(difficulty)
{
    for (int i = 0; i < 3; ++i) {
        rowsDifficulty[i] = rows[i];
        columnsDifficulty[i] = columns[i];
        bombNumberPerDifficulty[i] = bombs[i];
    }
}

Difficulty::Difficulty(const Difficulty& other) :
    chosenDifficulty(other.chosenDifficulty)
{
    for (int i = 0; i < 3; ++i) {
        rowsDifficulty[i] = other.rowsDifficulty[i];
        columnsDifficulty[i] = other.columnsDifficulty[i];
        bombNumberPerDifficulty[i] = other.bombNumberPerDifficulty[i];
    }
}

void Difficulty::ChooseDifficulty()
{
    bool isInputInvalid = false;
    char userInput;

    do {
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

int Difficulty::GetRowDifficulty() const
{
    return rowsDifficulty[static_cast<int>(chosenDifficulty)];
}

int Difficulty::GetColumnDifficulty() const
{
    return columnsDifficulty[static_cast<int>(chosenDifficulty)];
}

int Difficulty::GetBombCountDifficulty() const
{
    return bombNumberPerDifficulty[static_cast<int>(chosenDifficulty)];
}

Difficulty& Difficulty::operator=(const Difficulty& other)
{
    if (this != &other) {
        chosenDifficulty = other.chosenDifficulty;
        for (int i = 0; i < 3; ++i) {
            rowsDifficulty[i] = other.rowsDifficulty[i];
            columnsDifficulty[i] = other.columnsDifficulty[i];
            bombNumberPerDifficulty[i] = other.bombNumberPerDifficulty[i];
        }
    }
    return *this;
}

bool Difficulty::operator==(const Difficulty& other) const
{
    return chosenDifficulty == other.chosenDifficulty &&
        std::equal(rowsDifficulty, rowsDifficulty + 3, other.rowsDifficulty) &&
        std::equal(columnsDifficulty, columnsDifficulty + 3, other.columnsDifficulty) &&
        std::equal(bombNumberPerDifficulty, bombNumberPerDifficulty + 3, other.bombNumberPerDifficulty);
}

std::istream& operator>>(std::istream& in, Difficulty& difficulty)
{
    int rows[3], columns[3], bombs[3];
    int chosenDiff;

    std::cout << "Introduceti numarul de randuri pentru fiecare dificultate: ";
    for (int i = 0; i < 3; ++i) {
        in >> rows[i];
    }

    std::cout << "Introduceti numarul de coloane pentru fiecare dificultate: ";
    for (int i = 0; i < 3; ++i) {
        in >> columns[i];
    }

    std::cout << "Introduceti numarul de bombe pentru fiecare dificultate: ";
    for (int i = 0; i < 3; ++i) {
        in >> bombs[i];
    }

    std::cout << "Alegeti o dificultate. \n1 - Usor; 2 - Intermediar; 3 - Greu: ";
    in >> chosenDiff;

    difficulty = Difficulty(rows, columns, bombs, static_cast<DifficultyType>(chosenDiff));
    return in;
}

std::ostream& operator<<(std::ostream& out, const Difficulty& difficulty)
{
    out << "Dificultate: " << static_cast<int>(difficulty.chosenDifficulty) << "\n"
        << "Randuri: " << difficulty.rowsDifficulty[static_cast<int>(difficulty.chosenDifficulty)] << "\n"
        << "Coloane: " << difficulty.columnsDifficulty[static_cast<int>(difficulty.chosenDifficulty)] << "\n"
        << "Bombe: " << difficulty.bombNumberPerDifficulty[static_cast<int>(difficulty.chosenDifficulty)] << "\n";
    return out;
}
