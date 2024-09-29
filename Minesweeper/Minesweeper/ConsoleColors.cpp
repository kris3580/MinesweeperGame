#include "ConsoleColors.h"

void ConsoleColors::SetColors(int backgroundColor, int textColor) 
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (backgroundColor << 4) | textColor);

}

void ConsoleColors::ResetColors() 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 0x07);
}
