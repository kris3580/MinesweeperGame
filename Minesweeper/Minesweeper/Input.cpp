#include "Input.h"

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
