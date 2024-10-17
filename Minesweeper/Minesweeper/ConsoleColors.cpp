#include "ConsoleColors.h"

ConsoleColors::ConsoleColors() : backgroundColor(0), textColor(7)
{
    SetColors(backgroundColor, textColor);
}


ConsoleColors::ConsoleColors(int bgColor, int txtColor) : backgroundColor(bgColor), textColor(txtColor)
{
    SetColors(backgroundColor, textColor);
}

ConsoleColors::ConsoleColors(const ConsoleColors& other)
    : backgroundColor(other.backgroundColor), textColor(other.textColor)
{
    SetColors(backgroundColor, textColor);
}





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



ConsoleColors& ConsoleColors::operator=(const ConsoleColors& other)
{
    if (this != &other)
    {
        backgroundColor = other.backgroundColor;
        textColor = other.textColor;
        SetColors(backgroundColor, textColor);
    }
    return *this;
}


bool ConsoleColors::operator==(const ConsoleColors& other) const
{
    return backgroundColor == other.backgroundColor && textColor == other.textColor;
}
