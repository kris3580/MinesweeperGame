#include "Input.h"

Input::Input() : x(0), y(0) {}

Input::Input(int x, int y) : x(x), y(y) {}

Input::Input(const Input& other) : x(other.x), y(other.y) {}

Cell Input::GetCoordinates()
{
    int x, y;
    char userInput;

    std::cout << "Introduceti x, y: ";

    std::cin >> userInput;
    x = userInput - 'a';
    std::cin >> y;

    Cell cell;
    cell.x = y;
    cell.y = x;

    return cell;
}

Input& Input::operator=(const Input& other)
{
    if (this != &other)
    {
        x = other.x;
        y = other.y;
    }
    return *this;
}

bool Input::operator==(const Input& other) const
{
    return x == other.x && y == other.y;
}
